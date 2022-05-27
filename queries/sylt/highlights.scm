[
  "and"
  "or"
  "not"
] @keyword.operator

[
  "from"
  "use"
  "external"
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

(variable) @variable
(variant) @constructor

(type
[
  (t_primitive) 
  (t_any)
  (t_generic)
  (t_blob name: (variant) @type)
] @type)

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
(call function: (variable_member member: (identifier) @method))
(prim_call
[
  "'"
] @operator)
(arrow_call
[
  "->" 
] @operator)

(member member: (variable) @property)

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

(blob_construct) @constructor
(enum_construct) @constructor

(ERROR) @error
