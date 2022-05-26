const repeat_separator = (elem, separator, trailing) =>
  seq(
    repeat(seq(elem, separator)),
    elem,
    ...(trailing ? [optional(separator)] : [])
  );

const terminator = "\n";

module.exports = grammar({
  name: "sylt",

  precedences: $ => [
    ["unary", "mulDiv", "addSub", "compare", "and", "or"],

    [$.expression, $.arrow_call],

    [$.expression, $.enum_construct],
    [$.binary_expression, $.enum_construct],
    [$.call, $.enum_construct],
    [$.arrow_call, $.enum_construct],
    [$.prim_call, $.enum_construct],
    [$.member, $.enum_construct],

    [$.case_branch, $.expression],
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
        field(
          "body",
          alias(repeat(seq($.statement, terminator)), "function_body")
        ),
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
    prim_call: $ =>
      // This is wrong
      prec.left(
        seq(
          $.expression,
          "'",
          field(
            "parameters",
            optional(
              alias(repeat_separator($.expression, ","), "parameter_list")
            )
          )
        )
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

    case_branch: $ =>
      seq(
        field("variant", $.member),
        field("bind", optional($.identifier)),
        "->",
        field(
          "body",
          alias(repeat(seq($.statement, terminator)), "branch_body")
        ),
        "end"
      ),

    case: $ =>
      seq(
        "case",
        field("expression", $.expression),
        "do",
        field("branches", alias(repeat($.case_branch), "branch_list")),
        field(
          "else",
          alias(
            optional(
              seq(
                "else",
                field(
                  "body",
                  alias(repeat(seq($.statement, terminator)), "branch_body")
                ),
                "end"
              )
            ),
            "else_branch"
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
    enum_construct: $ =>
      seq(field("variant", $.member), field("value", $.expression)),

    // General member
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
        $.prim_call,
        $.arrow_call,
        $.if,
        $.case,
        $.list,
        $.tuple,
        $.blob,
        $.blob_construct,
        $.enum,
        $.enum_construct,
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
