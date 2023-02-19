// The sylt grammar

const sepBy1 = (p, s) => seq(p, repeat(seq(s, p)));
const sepBy = (p, s) => optional(sepBy1(p, s));

const binOp = (expr, op) => seq(expr, op, expr);

module.exports = grammar({
  name: "sylt",

  rules: {
    source_file: $ => repeat(choice($.def, $.defEnum, $.defType)),

    name: $ => /[a-z_][a-zA-Z0-9_]*/,
    properName: $ => /[A-Z][a-zA-Z0-9_]*/,

    identifier: $ => alias($.name, "_"),

    typeName: $ => alias($.properName, "_"),
    typeVar: $ => alias($.name, "_"),

    int: $ => /-?[\d]+/,
    real: $ => /\d+\.\d*|\d*\.\d+|\d+e[-+]?\d+/,

    str: $ => /"([^"]|\\.)*"/,
    bool: $ => choice("true", "false"),

    _literal: $ => choice($.int, $.real, $.str, $.bool),

    enumCons: $ => seq($.identifier, ":", $.typeName, optional($.expression)),
    record: $ =>
      seq("{", sepBy(seq($.identifier, ":", $.expression), ","), "}"),

    // Rewrite of /((?!]]-).)*/, since tree sitter does not support negative lookahead
    foreign: $ =>
      seq("foreign", optional(seq("-[[", /([^\]]|\][^\]]|\]\][^-])*/, "]]-"))),

    _binFac: $ => prec.left(7, binOp($.expression, choice("*", "/"))),
    _binTerm: $ => prec.left(6, binOp($.expression, choice("+", "-"))),
    _binComp: $ =>
      prec.left(5, binOp($.expression, choice("<", "<=", "==", "!="))),
    _binAnd: $ => prec.left(4, binOp($.expression, "and")),
    _binOr: $ => prec.left(3, binOp($.expression, "or")),
    _binCall: $ => prec.left(2, binOp($.expression, "'")),
    _binPipe: $ => prec.left(1, binOp($.expression, "#")),

    binExp: $ =>
      choice(
        $._binFac,
        $._binTerm,
        $._binComp,
        $._binAnd,
        $._binOr,
        $._binCall,
        $._binPipe
      ),

    lambda: $ => seq("\\", repeat($.identifier), "->", $.expression),

    letIn: $ => seq("let", $.identifier, "=", $.expression, "in", $.expression),

    expression: $ =>
      choice(
        $._literal,
        $.identifier,
        $.enumCons,
        $.record,
        $.foreign,
        $.binExp,
        $.lambda,
        $.letIn,
        seq("(", $.expression, ")")
      ),

    recordType: $ => seq("{", sepBy(seq($.identifier, ":", $.type), ","), "}"),
    fnType: $ => prec.left(seq($.type, "->", $.type)),
    typeAlias: $ => seq($.typeName, repeat($.typeVar)),

    type: $ =>
      choice(
        "Int",
        "Real",
        "Bool",
        "Str",
        "_",
        "foreign",
        $.fnType,
        $.recordType,
        $.typeAlias,
        $.typeVar,
        seq("(", $.type, ")")
      ),

    def: $ =>
      seq(
        "def",
        $.identifier,
        ":",
        optional(seq(repeat(seq("forall", $.typeVar, ".")), $.type)),
        ":",
        repeat($.identifier),
        "=",
        $.expression
      ),

    defEnum: $ =>
      seq(
        "enum",
        $.typeName,
        "=",
        sepBy1(seq($.typeName, optional($.type)), "|")
      ),

    defType: $ => seq("type", $.typeName, repeat($.typeVar), "=", $.type),

    lineComment: $ => seq("--", /[^\r\n]*/),
  },

  extras: $ => [/\s+/, /\n/, $.lineComment],
});
