-- General
vim.opt.hidden = true
vim.opt.history = 500
vim.cmd('filetype plugin on')
vim.cmd('filetype plugin indent on')
vim.opt.autoread = true
vim.opt.laststatus = 2
vim.opt.showmode = false
vim.opt.textwidth = 80
vim.opt.formatoptions:append('t')
vim.cmd('au FocusGained,BufEnter * checktime')

-- VIM user interface
vim.opt.so = 18
vim.opt.number = true
vim.opt.relativenumber = true
vim.opt.wildmenu = true
vim.opt.ruler = true
vim.opt.cmdheight = 1
vim.opt.hidden = true
vim.opt.backspace:append('eol,start,indent')
vim.opt.ignorecase = true
vim.opt.smartcase = true
vim.opt.hlsearch = true
vim.opt.incsearch = true
vim.opt.magic = true
vim.opt.showmatch = true
vim.opt.mat = 1

-- Colors and Fonts
vim.cmd('syntax enable')
vim.opt.background = 'dark'
vim.opt.termguicolors = true
vim.opt.encoding = 'utf8'

-- Files, backups and undo
vim.opt.backup = false
vim.opt.writebackup = false
vim.opt.swapfile = false

-- Text, tab and indent related
vim.opt.expandtab = true
vim.opt.smarttab = true
vim.opt.shiftwidth = 2
vim.opt.tabstop = 2
vim.opt.lbr = true
vim.opt.wrap = true

-- Moving around, tabs, windows and buffers
vim.api.nvim_set_keymap('n', '<SPACE>', '<Nop>', {noremap = true})
vim.api.nvim_set_keymap('n', '<Up>', ':10winc -<CR>', {noremap = true})
vim.api.nvim_set_keymap('n', '<Down>', ':10winc +<CR>', {noremap = true})
vim.api.nvim_set_keymap('n', '<Left>', ':10winc <<CR>', {noremap = true})
vim.api.nvim_set_keymap('n', '<Right>', ':10winc ><CR>', {noremap = true})
vim.g.mapleader = ' '

vim.api.nvim_set_keymap('n', '<leader><leader>', ':w!<CR>', {})
vim.api.nvim_set_keymap('n', '<leader><ESC>', ':noh<CR>', {})
vim.api.nvim_set_keymap('n', '<C-j>', '<C-W>j', {})
vim.api.nvim_set_keymap('n', '<C-k>', '<C-W>k', {})
vim.api.nvim_set_keymap('n', '<C-h>', '<C-W>h', {})
vim.api.nvim_set_keymap('n', '<C-l>', '<C-W>l', {})

-- Lazy
local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not vim.loop.fs_stat(lazypath) then
  vim.fn.system({
    "git",
    "clone",
    "--filter=blob:none",
    "https://github.com/folke/lazy.nvim.git",
    "--branch=stable", -- latest stable release
    lazypath,
  })
end
vim.opt.rtp:prepend(lazypath)
require('lazy').setup('plugins', {})
