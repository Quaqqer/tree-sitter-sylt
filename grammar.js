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
    field("body", $._fn_body)
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

module.exports = grammar({
  name: "sylt",

  rules: {
    source_file: $ => repeat($._outer_statement),

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

    // Statements

    // Declarations
    const_declaration: $ => declaration($, false),
    mut_declaration: $ => declaration($, true),
    _declaration: $ => choice($.mut_declaration, $.const_declaration),

    // Functions
    t_fn: $ => t_fn_pu($, "fn"),
    t_pu: $ => t_fn_pu($, "pu"),
    _fn_body: $ => seq(seq($._inner_statement), "end"),
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
    _type: $ => choice($._t_primitive, $.t_fn, $.t_pu),

    // Statements
    _inner_statement: $ => choice($._declaration, $._expression),
    _outer_statement: $ => $._inner_statement,

    // Tuple or parameters for a function call
    _tup_params: $ => seq("(", repeat_separator($._expression, ","), ")"),

    // Function calls
    fn_call: $ =>
      prec(
        2,
        seq(
          field("function", $.identifier),
          field("params", alias($._tup_params, $.parameter_list))
        )
      ),

    arrow_call: $ => seq(field("param1", $._expression), "->", $.fn_call),

    // Tuple
    tuple: $ => $._tup_params,

    // An expression
    _expression: $ =>
      choice(
        $.identifier,
        $._primitive,
        $.fn,
        $.pu,
        $.fn_call,
        $.arrow_call,
        $.tuple
      ),
  },
});
