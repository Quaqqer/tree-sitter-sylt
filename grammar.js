const PREC = {
  fn_call: 1,
  arrow_call: 2,
  access: 3,
  addSub: 4,
  mulDiv: 5,
  comparator: 6,
  boolArithmetic: 7,
  assert: 8,
  parens: 9,
};

const t_fn_pu = ($, type) =>
  seq(
    type,
    field("parameters", optional($.parameter_list)),
    "->",
    field("return", $._type)
  );

const fn_pu = ($, type) =>
  seq(
    type,
    optional($.parameter_list),
    choice(field("return", seq("->", $._type), optional("do")), "do"),
    field("body", repeat(seq($._statement, terminator))),
    "end"
  );

const blob_externblob = ($, normal) =>
  seq(
    normal ? "blob" : "externblob",
    "{",
    optional(repeat_separator(seq($.identifier, ":", $._type), ",", true)),
    "}"
  );

const declaration = ($, mutable) =>
  seq(
    field("name", $.identifier),
    ":",
    field("type", optional($._type)),
    mutable ? "=" : ":",
    field("expression", $._expression)
  );

const repeat_separator = (elem, separator, trailing) =>
  seq(repeat(seq(elem, separator)), elem, ...(trailing ? [separator] : []));

const terminator = "\n";

module.exports = grammar({
  name: "sylt",

  precedences: $ => [
    [
      "unary",
      "mulDiv",
      "addSub",
      "compare",
      "and",
      "or",
      "access",
      "arrow_call",
      "fn_call",
    ],
  ],

  rules: {
    source_file: $ => repeat(seq($._statement, terminator)),

    // Primitive stuff

    // Variable identifier
    identifier: $ => /[A-Za-z_][A-Za-z0-9_]*/,

    filename: $ => /\/?([A-Za-z\d]+\/)*[A-Za-z\d]+/,

    // Primitive types
    t_void: $ => "void",
    t_bool: $ => "bool",
    t_int: $ => "int",
    t_float: $ => "float",
    t_str: $ => "str",
    _t_primitive: $ => choice($.t_void, $.t_bool, $.t_int, $.t_float, $.t_str),

    // Primitive values
    int: $ => /\d+/,
    float: $ => choice(/\d+\.\d*/, /\d*\.\d+/, /\d+e(-|\+)?\d+/),
    nil: $ => "nil",
    bool: $ => choice("true", "false"),
    str: $ => /"[^"]*"/,
    _primitive: $ => choice($.int, $.float, $.nil, $.bool, $.str),

    t_tup: $ => seq("(", repeat_separator($._type, ",", true), ")"),
    t_list: $ => seq("[", repeat_separator($._type, ",", true), "]"),

    // Statements

    // Declarations
    const_declaration: $ => declaration($, false),
    mut_declaration: $ => declaration($, true),
    _declaration: $ => choice($.mut_declaration, $.const_declaration),

    // Functions
    t_fn: $ => t_fn_pu($, "fn"),
    t_pu: $ => t_fn_pu($, "pu"),
    fn: $ => fn_pu($, "fn"),
    pu: $ => fn_pu($, "pu"),

    // Parameters of a function
    parameter: $ =>
      seq(
        field("name", $.identifier),
        field("type", optional(seq(":", $._type)))
      ),
    parameter_list: $ => seq(repeat(choice($.parameter, ",")), $.parameter),

    // The general type
    _type: $ =>
      choice($._t_primitive, $.t_fn, $.t_pu, $.identifier, $.t_list, $.t_tup),

    // Statements
    _statement: $ =>
      choice(
        $._declaration,
        $._expression,
        $.assign,
        $._opeq,
        $.assert_eq,
        $.unreachable,
        $.use,
        $.from_use
      ),

    assert_eq: $ =>
      seq(field("left", $._expression), "<=>", field("right", $._expression)),
    unreachable: $ => "<!>",

    // Assignments
    assign: $ => seq($._expression, "=", $._expression),

    // Operator equals
    addeq: $ => seq($._expression, "+=", $._expression),
    subeq: $ => seq($._expression, "-=", $._expression),
    muleq: $ => seq($._expression, "*=", $._expression),
    diveq: $ => seq($._expression, "/=", $._expression),
    _opeq: $ => choice($.addeq, $.subeq, $.muleq, $.diveq),

    // If statements
    if: $ =>
      seq(
        "if",
        $._expression,
        "do",
        field("body", repeat(seq($._expression, terminator))),
        optional(
          seq(
            "else",
            choice($.if, seq("do", repeat(seq($._expression, terminator))))
          )
        ),
        "end"
      ),

    // Tuple or parameters for a function call
    fn_params: $ =>
      seq("(", optional(repeat_separator($._expression, ",", false)), ")"),

    parens: $ => prec(PREC.parens, seq("(", $._expression, ")")),

    // Function calls
    // TODO: Not sure about this precedence
    fn_call: $ =>
      prec(
        PREC.fn_call,
        seq(field("function", $._expression), field("params", $.fn_params))
      ),
    // Prim call
    // TODO: Not sure about this precedence
    prim_call: $ =>
      prec.left(
        PREC.arrow_call,
        seq($._expression, "'", optional(repeat_separator($._expression, ",")))
      ),
    // Special arrow call
    arrow_call: $ =>
      prec.left(1, seq(field("param1", $._expression), "->", $.fn_call)),

    // Accessor
    access: $ =>
      prec(
        PREC.access,
        seq(field("lhs", $._expression), ".", field("field", $.identifier))
      ),

    // Tuple
    tuple: $ =>
      seq(
        "(",
        $._expression,
        ",",
        optional(seq(repeat_separator($._expression, ","), ",")),
        ")"
      ),

    // Blob
    blob: $ => blob_externblob($, true),
    externblob: $ => blob_externblob($, false),

    blob_construct: $ =>
      seq(
        $.identifier,
        "{",
        optional(
          seq(
            repeat_separator(seq($.identifier, ":", $._expression), ","),
            optional(",")
          )
        ),
        "}"
      ),

    // Binary expressions
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
          prec.left(
            precedence,
            seq(
              field("left", $._expression),
              field("operator", op),
              field("right", $._expression)
            )
          )
        )
      ),

    // Unaries
    unary_expression: $ =>
      prec.left(
        "unary",
        seq(
          field(
            "operator",
            choice("not", "+", "-"),
            field("argument", $._expression)
          )
        )
      ),

    list: $ => seq("[", repeat_separator($._expression, ",", true), "]"),

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

    external: $ => seq("external", $.str),

    // An expression
    _expression: $ =>
      choice(
        $.identifier,
        $._primitive,
        $.fn,
        $.pu,
        $.parens,
        $.fn_call,
        $.prim_call,
        $.arrow_call,
        $.access,
        $.tuple,
        $.binary_expression,
        $.unary_expression,
        $.list,
        $.blob,
        $.externblob,
        $.blob_construct,
        $.external
      ),
  },
});
