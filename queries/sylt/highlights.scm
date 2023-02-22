[
  "def"
  "enum"
  "foreign"
  "let"
  "in"
] @keyword

[
  "forall"
] @repeat

[
  "if"
  "match"
  "with"
  "end"
] @conditional

[
  "+"
  "-"
  "*"
  "/"
  "'"
  "#"
  "<"
  "<="
  "=="
  "!="
] @operator

[
  "("
  ")"
  "{"
  "}"
] @punctuation.bracket

[
  "@"
] @punctuation.special

[
  ":"
] @punctuation.delimiter

[
  "and"
  "or"
  "not"
] @keyword.operator

[
  "type"
] @type.definition

(comment) @comment
(string) @string
(number) @float
(identifier) @variable
(field) @variable

(type) @type

(ERROR) @error
