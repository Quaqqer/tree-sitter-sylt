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
  (mutable)
  (immutable)
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

(call function: (variable) @function)
(call function: (variable_member member: (variable) @method))
(prim_call
[
  "'"
] @operator)
(arrow_call
[
  "->" 
] @operator)

(variable_member member: (variable) @property)
(variant_member member: (variant) @constructor)

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

(blob_construct variant: (variant) @constructor)
(enum_construct variant: (variant_member member: (variant) @constructor))

(ERROR) @error
