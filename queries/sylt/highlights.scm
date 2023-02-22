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
  "->"
  "@"
  "\\"
  ":"
] @operator

[
  "("
  ")"
  "{"
  "}"
  "-[["
  "]]-"
] @punctuation.bracket

[
  "and"
  "or"
  "not"
] @keyword.operator

[
  "type"
] @type.definition

(lineComment) @comment
(str) @string
(int) @number
(real) @float

(identifier) @variable
(field) @variable

(type) @type

(ERROR) @error

;; Spell checking
(str) @spell
(lineComment) @spell
