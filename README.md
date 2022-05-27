# Tree sitter for Sylt

Included in this repository is a minimal Neovim plugin for installing this
grammar and highlights.

## Usage

If you are using [packer.nvim](https://github.com/wbthomason/packer.nvim), the
following example should suffice.

```lua
use {
   'Quaqqer/tree-sitter-sylt',
   requires = 'nvim-treesitter/nvim-treesitter',
   config = function()
      require('tree-sitter-sylt').setup()
   end,
   run = ':TSUpdate sylt'
}
```
