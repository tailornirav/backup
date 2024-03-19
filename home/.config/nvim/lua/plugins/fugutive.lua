return {
  'tpope/vim-fugitive',
  config = function()
    vim.cmd [[
      nnoremap <leader>gs :Gstatus<CR>
      nnoremap <leader>gd :Gdiff<CR>
      nnoremap <leader>gc :Gcommit<CR>
      nnoremap <leader>gb :Gblame<CR>
      nnoremap <leader>gl :Glog<CR>
      nnoremap <leader>gp :Gpush<CR>
      nnoremap <leader>gP :Gpull<CR>
      nnoremap <leader>gj :diffget //3<CR>
      nnoremap <leader>gk :diffget //2<CR>
      nnoremap <leader>g< :diffget //1<CR>
      nnoremap <leader>g> :diffget //4<CR>
    ]]
  end
}
