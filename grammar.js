module.exports = grammar({
  name: "sylt",

  rules: {
    source_file: $ => repeat($._outer_statement),

    identifier: $ => /[A-Za-z_][A-Za-z0-9_]*/,

    // Primitive types
    t_void: $ => "void",
    t_bool: $ => "bool",
    t_int: $ => "int",
    t_float: $ => "float",
    t_str: $ => "str",
    _type_primitive: $ =>
      choice($.t_void, $.t_bool, $.t_int, $.t_float, $.t_str),

    // Parameters of a function
    parameter: $ =>
      seq(
        field("name", $.identifier),
        field("type", optional(seq(":", $._type)))
      ),
    parameters: $ => seq(repeat(choice($.parameter, ",")), $.parameter),

    // Function types
    t_fn: $ =>
      seq(
        "fn",
        field("parameters", optional($.parameters)),
        "->",
        field("return", $._type)
      ),
    t_pu: $ =>
      seq(
        "pu",
        field("parameters", optional($.parameters)),
        "->",
        field("return", $._type)
      ),

    // The general type
    _type: $ => choice($._type_primitive, $.t_fn, $.t_pu),

    // An outer statement
    _outer_statement: $ => choice($._declaration),

    // Declarations
    _declaration: $ => choice($.mut_declaration, $.const_declaration),
    const_declaration: $ =>
      seq(
        field("name", $.identifier),
        ":",
        field("type", optional($._type)),
        ":",
        field("expression", $._expression)
      ),
    mut_declaration: $ =>
      seq(
        field("name", $.identifier),
        ":",
        field("type", optional($._type)),
        "=",
        field("expression", $._expression)
      ),

    int: $ => /\d+/,
    //           X._     | _.Y    | XeY
    float: $ => choice(/\d+\.\d*/, /\d*\.\d+/, /\d+e(-|\+)?\d+/),
    nil: $ => "nil",
    bool: $ => choice("true", "false"),
    str: $ => /"[^"]*"/,

    _expression: $ => choice($.int, $.float, $.nil, $.bool, $.str),
  },
});
