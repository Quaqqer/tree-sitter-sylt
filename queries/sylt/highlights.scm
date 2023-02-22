[
  "def"
  "enum"
  "type"
  "foreign"
  "let"
  "in"
  "match"
  "with"
  "if"
  "end"
  "forall"
] @keyword

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
] @punctuation

[
  "and"
  "or"
  "not"
] @keyword.operator

(comment) @comment
(string) @string
(number) @number
(identifier) @variable
(field) @variable

(type) @type

(ERROR) @error
