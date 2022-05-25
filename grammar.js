const PREC = {
  access: 1,
  addSub: 2,
  mulDiv: 3,
  comparator: 4,
  boolArithmetic: 5,
  assert: 6,
  parens: 7,
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
    optional(
      seq(repeat_separator(seq($.identifier, ":", $._type), ","), optional(","))
    ),
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

const repeat_separator = (elem, separator) =>
  seq(repeat(seq(elem, separator)), elem);

const terminator = "\n";

const op = ($, operator) =>
  seq(field("lhs", $._expression), operator, field("rhs", $._expression));

const unary = ($, un) => seq(un, $._expression);

module.exports = grammar({
  name: "sylt",

  rules: {
    source_file: $ => repeat(seq($._statement, terminator)),

    // Primitive stuff

    // Variable identifier
    identifier: $ => /[A-Za-z_][A-Za-z0-9_]*/,

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

    t_tup: $ => seq("(", repeat_separator($._type, ","), ")"),
    t_list: $ => seq("[", repeat_separator($._type, ","), "]"),

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
        $.unreachable
      ),

    assert_eq: $ => prec.left(PREC.assert, op($, "<=>")),
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
    _tup_params: $ =>
      seq("(", optional(repeat_separator($._expression, ",")), ")"),

    parens: $ => prec(PREC.parens, seq("(", $._expression, ")")),

    // Function calls
    fn_call: $ =>
      prec(
        2,
        seq(
          field("function", $._expression),
          field("params", alias($._tup_params, $.parameter_list))
        )
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

    // Operators
    add: $ => prec.left(PREC.addSub, seq($._expression, "+", $._expression)),
    sub: $ => prec.left(PREC.addSub, seq($._expression, "-", $._expression)),
    mul: $ => prec.left(PREC.mulDiv, seq($._expression, "*", $._expression)),
    div: $ => prec.left(PREC.mulDiv, seq($._expression, "/", $._expression)),
    _arithmetic: $ => choice($.add, $.sub, $.mul, $.div),

    // Comparators
    _le: $ => prec.left(PREC.comparator, op($, "<=")),
    _lt: $ => prec.left(PREC.comparator, op($, "<")),
    _ge: $ => prec.left(PREC.comparator, op($, ">=")),
    _gt: $ => prec.left(PREC.comparator, op($, ">")),
    _eq: $ => prec.left(PREC.comparator, op($, "==")),
    _ne: $ => prec.left(PREC.comparator, op($, "!=")),
    _comparator: $ => choice($._le, $._lt, $._ge, $._gt, $._eq, $._ne),

    // Bool arithmetic
    and: $ => prec.left(PREC.boolArithmetic, op($, "and")),
    or: $ => prec.left(PREC.boolArithmetic, op($, "or")),
    _bool_arithmetic: $ => choice($.and, $.or),

    // Unaries
    not: $ => unary($, "not"),
    positive: $ => unary($, "+"),
    negative: $ => unary($, "-"),
    _unary: $ => choice($.not, $.positive, $.negative),

    list: $ => seq("[", repeat_separator($._expression, ","), "]"),

    // An expression
    _expression: $ =>
      choice(
        $.identifier,
        $._primitive,
        $.fn,
        $.pu,
        $.parens,
        $.fn_call,
        $.arrow_call,
        $.access,
        $.tuple,
        $._arithmetic,
        $._comparator,
        $._bool_arithmetic,
        $._unary,
        $.list,
        $.blob,
        $.externblob,
        $.blob_construct
      ),
  },
});
