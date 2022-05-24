module.exports = grammar({
  name: "sylt",

  rules: {
    source_file: $ => repeat($.outer_statement),

    identifier: $ => /[A-Za-z_][A-Za-z0-9_]*/,

    type_primitive: $ => choice("void", "bool", "int", "float", "str"),

    type: $ => choice($.type_primitive),

    outer_statement: $ => choice($.assignment),

    assignment: $ =>
      seq(
        field("name", $.identifier),
        ":",
        field("type", $.type),
        field("mutability", ":"),
        field("expression", $.expression)
      ),

    int: $ => /\d+/,
    //           X._     | _.Y    | XeY
    float: $ => choice(/\d+\.\d*/, /\d*\.\d+/, /\d+e(-|\+)?\d+/),
    nil: $ => "nil",
    bool: $ => choice("true", "false"),
    str: $ => /"[^"]*"/,

    expression: $ => choice($.int, $.float, $.nil, $.bool, $.str),
  },
});
