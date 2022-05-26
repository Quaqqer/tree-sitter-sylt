const repeat_separator = (elem, separator, trailing) =>
  seq(repeat(seq(elem, separator)), elem, ...(trailing ? [separator] : []));

const terminator = "\n";

module.exports = grammar({
  name: "sylt",

  precedences: $ => [
    ["unary", "mulDiv", "addSub", "compare", "and", "or"],
    [$.expression, $.arrow_call],
  ],

  extras: $ => [$.comment, /\s/],

  supertypes: $ => [$.type, $.expression, $.statement],

  rules: {
    source_file: $ => repeat(seq($.statement, terminator)),

    // General stuff
    identifier: $ => /[A-Za-z_][A-Za-z0-9_]*/,
    generic: $ => /\*[A-Za-z_][A-Za-z0-9_]*/,
    filename: $ => /\/?([A-Za-z\d]+\/)*[A-Za-z\d]+/,
    comment: $ => seq("//", /[^\r\n]*/),

    /// Types
    t_primitive: $ => choice("void", "bool", "int", "float", "str"),
    t_any: $ => "*",
    t_tup: $ => seq("(", repeat_separator($.type, ",", true), ")"),
    t_list: $ => seq("[", repeat_separator($.type, ",", true), "]"),
    t_fn: $ =>
      seq(
        choice("fn", "pu"),
        optional(
          alias(
            repeat_separator(
              seq($.identifier, optional(seq(":", $.type))),
              ","
            ),
            "parameter_list"
          )
        ),
        "->",
        $.type
      ),
    t_generic: $ => $.generic,
    t_blob: $ => seq(field("name", $.identifier)),

    type: $ =>
      choice(
        $.t_primitive,
        $.t_any,
        $.t_tup,
        $.t_list,
        $.t_fn,
        $.t_generic,
        $.t_blob
      ),

    /// Expression

    int: $ => /\d+/,
    float: $ => choice(/\d+\.\d*/, /\d*\.\d+/, /\d+e(-|\+)?\d+/),
    nil: $ => "nil",
    bool: $ => choice("true", "false"),
    str: $ => /"[^"]*"/,

    parens: $ => seq("(", $.expression, ")"),

    binary_expression: $ =>
      choice(
        ...[
          ["+", "addSub"],
          ["-", "addSub"],
          ["*", "mulDiv"],
          ["/", "mulDiv"],
          ["<", "compare"],
          ["<=", "compare"],
          [">", "compare"],
          [">=", "compare"],
          ["==", "compare"],
          ["!=", "compare"],
          ["and", "and"],
          ["or", "or"],
        ].map(([op, precedence]) =>
          prec.left(precedence, seq($.expression, op, $.expression))
        )
      ),

    unary_expression: $ =>
      prec.left("unary", seq(choice("not", "+", "-"), $.expression)),

    function: $ =>
      seq(
        choice("fn", "pu"),
        field(
          "parameters",
          optional(
            alias(
              repeat_separator(
                seq($.identifier, optional(seq(":", $.type))),
                ","
              ),
              "parameter_list"
            )
          )
        ),
        choice(field("return", seq("->", $.type), optional("do")), "do"),
        field("body", repeat(seq($.statement, terminator))),
        "end"
      ),

    call: $ =>
      seq(
        $.expression,
        "(",
        field(
          "parameters",
          optional(alias(repeat_separator($.expression, ","), "parameter_list"))
        ),
        ")"
      ),
    arrow_call: $ =>
      seq(field("param1", $.expression), "->", field("call", $.call)),

    if: $ =>
      seq(
        "if",
        field("condition", $.expression),
        "do",
        field(
          "if_body",
          alias(optional(repeat(seq($.expression, terminator))), "if_body")
        ),
        field(
          "else_body",
          alias(
            optional(
              seq(
                "else",
                choice($.if, seq("do", repeat(seq($.expression, terminator))))
              )
            ),
            "else_body"
          )
        ),
        "end"
      ),

    list: $ =>
      seq("[", alias(repeat_separator($.expression, ",", true), "values"), "]"),
    tuple: $ =>
      seq(
        "(",
        alias(
          seq(
            $.expression,
            ",",
            optional(seq(repeat_separator($.expression, ","), ","))
          ),
          "values"
        ),
        ")"
      ),
    blob: $ =>
      seq(
        choice("blob", "externblob"),
        field(
          "generics",
          optional(alias(repeat_separator($.generic, ","), "generic_list"))
        ),
        "{",
        alias(
          optional(repeat_separator(seq($.identifier, ":", $.type), ",", true)),
          "fields"
        ),
        "}"
      ),
    blob_construct: $ =>
      seq(
        $.identifier,
        "{",
        field(
          "fields",
          optional(
            repeat_separator(
              seq(
                field("field", $.identifier),
                ":",
                field("value", $.expression)
              ),
              ",",
              true
            )
          )
        ),
        "}"
      ),

    enum: $ =>
      seq(
        "enum",
        field(
          "generics",
          optional(alias(repeat_separator($.generic, ","), "generic_list"))
        ),
        field(
          "variants",
          optional(
            alias(
              repeat_separator(
                seq($.identifier, optional(field("type", $.type))),
                ",",
                true
              ),
              "variant_list"
            )
          )
        ),
        "end"
      ),

    member: $ => seq($.expression, ".", field("member", $.identifier)),

    external: $ => seq("external", $.str),

    expression: $ =>
      choice(
        $.identifier,
        $.int,
        $.float,
        $.nil,
        $.bool,
        $.str,
        $.parens,
        $.binary_expression,
        $.unary_expression,
        $.function,
        $.call,
        $.arrow_call,
        $.if,
        $.list,
        $.tuple,
        $.blob,
        $.blob_construct,
        $.enum,
        $.member,
        $.external
      ),

    /// Statement

    use: $ => seq("use", $.filename),
    from_use: $ =>
      seq(
        "from",
        $.filename,
        "use",
        choice(
          $.identifier,
          seq("(", repeat_separator($.identifier, ",", true), ")")
        )
      ),

    declaration: $ =>
      seq($.identifier, ":", optional($.type), choice(":", "="), $.expression),

    assignment: $ => seq(choice($.identifier, $.member), "=", $.expression),
    augmented_assignment: $ =>
      choice(
        ...["+=", "-=", "*=", "/="].map(op =>
          seq(choice($.identifier, $.member), op, $.expression)
        )
      ),

    assert_eq: $ => seq($.expression, "<=>", $.expression),
    unreachable: $ => "<!>",

    statement: $ =>
      choice(
        $.expression,
        $.use,
        $.from_use,
        $.declaration,
        $.assignment,
        $.augmented_assignment,
        $.assert_eq,
        $.unreachable
      ),
  },
});
