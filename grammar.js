function sep1(rule, separator, trailing) {
  return seq(
    rule,
    repeat(seq(separator, rule)),
    ...(trailing ? [optional(separator)] : [])
  );
}

function sep(rule, separator, trailing) {
  return optional(sep1(rule, separator, trailing));
}

const PREC = {
  assert_eq: 1,
  or: 2,
  and: 3,
  compare: 4,
  term: 5,
  factor: 6,
  unary: 7,
  arrow: 8,
  member: 9,
  case_branch: 10,
  call: 11,
};

const terminator = "\n";

module.exports = grammar({
  name: "sylt",

  extras: $ => [$.comment, /\s/],

  supertypes: $ => [$.expression, $.statement],

  rules: {
    source_file: $ => optional($.block),

    block: $ => sep1($.statement, terminator, true),

    // General stuff
    variable: $ => /[a-z_][A-Za-z0-9_]*/,
    variant: $ => /[A-Z][A-Za-z0-9_]*/,
    generic: $ => /\*[A-Za-z_][A-Za-z0-9_]*/,
    filename: $ => /\/?([A-Za-z\d]+\/)*[A-Za-z\d]+/,
    comment: $ => seq("//", /[^\r\n]*/),

    this: $ => "this",

    /// Types
    t_primitive: $ => choice("void", "bool", "int", "float", "str"),
    t_any: $ => "*",
    t_tup: $ => seq("(", $.type, ",", sep($.type, ",", true), ")"),
    t_list: $ => seq("[", $.type, "]"),
    t_fn: $ => seq(choice("fn", "pu"), sep($.type, ","), "->", $.type),
    t_generic: $ => $.generic,
    t_blob: $ => seq(field("name", $.variant)),

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
          ["+", PREC.term],
          ["-", PREC.term],
          ["*", PREC.factor],
          ["/", PREC.factor],
          ["<", PREC.compare],
          ["<=", PREC.compare],
          [">", PREC.compare],
          [">=", PREC.compare],
          ["==", PREC.compare],
          ["!=", PREC.compare],
          ["and", PREC.and],
          ["or", PREC.or],
        ].map(([op, precedence]) =>
          prec.left(precedence, seq($.expression, op, $.expression))
        )
      ),

    unary_expression: $ =>
      prec.left(PREC.unary, seq(choice("not", "+", "-"), $.expression)),

    function: $ =>
      seq(
        choice("fn", "pu"),
        field(
          "parameters",
          sep(seq($.variable, optional(seq(":", $.type))), ",")
        ),
        choice(field("return", seq("->", $.type), optional("do")), "do"),
        field("body", repeat(seq($.statement, terminator))),
        "end"
      ),

    call: $ =>
      prec(
        PREC.call,
        seq(
          field("function", $.expression),
          "(",
          field("parameters", sep($.expression, ",")),
          ")"
        )
      ),
    prim_call: $ =>
      prec.right(
        PREC.arrow,
        seq($.expression, "'", field("parameters", sep($.expression, ",")))
      ),
    arrow_call: $ =>
      prec(
        PREC.arrow,
        seq(field("param1", $.expression), "->", field("call", $.call))
      ),

    _if_branch: $ => seq("if", field("condition", $.expression), "do", $.block),

    _else_branch: $ => seq("else", $.block),

    if: $ =>
      seq(
        field("branch", $._if_branch),
        field("branch", repeat(prec.left(seq("else", $._if_branch)))),
        field("else", optional($._else_branch)),
        "end"
      ),

    case_branch: $ =>
      prec(
        PREC.case_branch,
        seq(
          field("variant", choice($.variant, $.variant_member)),
          field("bind", optional($.variable)),
          "->",
          field("body", repeat(seq($.statement, terminator))),
          "end"
        )
      ),

    case: $ =>
      seq(
        "case",
        field("expression", $.expression),
        "do",
        field("branches", repeat($.case_branch)),
        field(
          "else",
          optional(
            seq(
              "else",
              field("body", repeat(seq($.statement, terminator))),
              "end"
            )
          )
        ),
        "end"
      ),
    // TODO: Single statement loop true do stmt end == loop true stmt
    loop: $ =>
      seq("loop", field("condition", $.expression), "do", $.block, "end"),

    list: $ => seq("[", sep($.expression, ",", true), "]"),
    tuple: $ =>
      seq("(", seq($.expression, ",", sep($.expression, ",", true)), ")"),
    blob: $ =>
      seq(
        choice("blob", "externblob"),
        field("generics", optional(seq("(", sep1($.generic, ","), ")"))),
        "{",
        field("fields", sep(seq($.variable, ":", $.type), ",", true)),
        "}"
      ),
    blob_construct: $ =>
      seq(
        field("variant", $.variant),
        "{",
        field(
          "fields",
          sep(
            seq(field("field", $.variable), ":", field("value", $.expression)),
            ",",
            true
          )
        ),
        "}"
      ),

    enum: $ =>
      seq(
        "enum",
        field("generics", optional(seq("(", sep1($.generic, ","), ")"))),
        field(
          "variants",
          sep(seq($.variant, optional(field("type", $.type))), ",", true)
        ),
        "end"
      ),
    enum_construct: $ =>
      seq(field("variant", $.variant_member), field("value", $.expression)),

    // General member
    variable_member: $ =>
      prec(PREC.member, seq($.expression, ".", field("member", $.variable))),
    variant_member: $ =>
      prec(PREC.member, seq($.expression, ".", field("member", $.variant))),

    external: $ => seq("external", $.str),

    expression: $ =>
      choice(
        $.this,
        $.variable,
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
        $.loop,
        $.list,
        $.tuple,
        $.blob,
        $.blob_construct,
        $.enum,
        $.enum_construct,
        $.variable_member,
        $.external
      ),

    /// Statement

    use: $ => seq("use", $.filename),
    from_use: $ =>
      seq(
        "from",
        $.filename,
        "use",
        choice($.variable, seq("(", sep($.variable, ",", true), ")"))
      ),

    declaration: $ =>
      seq(
        choice($.variable, $.variant),
        ":",
        optional($.type),
        field(
          "mutability",
          choice(alias(":", $.immutable), alias("=", $.mutable))
        ),
        $.expression
      ),

    assignment: $ =>
      seq(
        choice($.variable, $.variant, $.variable_member, $.variant_member),
        "=",
        $.expression
      ),
    augmented_assignment: $ =>
      choice(
        ...["+=", "-=", "*=", "/="].map(op =>
          seq(choice($.variable, $.variable_member), op, $.expression)
        )
      ),

    ret: $ => seq("ret", field("value", $.expression)),
    break: $ => "break",

    assert_eq: $ =>
      prec(PREC.assert_eq, seq($.expression, "<=>", $.expression)),
    unreachable: $ => "<!>",

    statement: $ =>
      choice(
        $.expression,
        $.use,
        $.from_use,
        $.declaration,
        $.assignment,
        $.augmented_assignment,
        $.ret,
        $.break,
        $.assert_eq,
        $.unreachable
      ),
  },
});
