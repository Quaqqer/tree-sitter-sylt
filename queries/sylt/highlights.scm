[
  "and"
  "or"
  "not"
] @keyword.operator

[
  "from"
  "use"
] @keyword

[
  "+"
  "-"
  "*"
  "/"
  "<="
  "<"
  ">="
  ">"
  "=="
  "!="
  "<=>"
  (unreachable)
] @operator

[
  ":"
  ","
  "."
] @punctuation.delimiter

[
  "("
  ")"
  "["
  "]"
  "{"
  "}"
 ] @punctation.bracket

(comment) @comment

(identifier) @variable

(type) @type
(t_blob name: (identifier) @type)

[
  (int)
  (float)
] @number

(nil) @constant.builtin

(bool) @boolean

(str) @string

"ret" @keyword.return

(function
[
  "fn"
  "pu"
  "do"
  "end"
] @keyword.function)

(call function: (identifier) @function)
(prim_call
[
  "'"
] @operator)
(arrow_call
[
  "->" 
] @operator)

(if
[
  "if"
  "do"
  "else"
  "end"
] @conditional)

(case
[
  "case"
  "->"
  "do"
  "else"
  "end"
] @conditional)

(loop
[
  "loop"
  "do"
  "end"
] @repeat)

(this) @variable.builtin
