return {
  'preservim/nerdtree',
  cmd = 'NERDTree',
  setup = function()
    vim.g.NERDTreeShowHidden = 1
    vim.g.NERDTreeMinimalUI = 1
    vim.g.NERDTreeDirArrows = 1
    vim.g.NERDTreeWinSize = 30
    vim.g.NERDTreeShowFiles = 1
    vim.g.NERDTreeAutoDeleteBuffer = 1
    vim.g.NERDTreeAutoCenter = 1
    vim.g.NERDTreeQuitOnOpen = 1
  end,

  keys = {
    { "<leader>n", ":NERDTreeToggle<CR>", desc = "Toggle NERDTree" },
  }
}
