return {
  'nvim-telescope/telescope.nvim', 
  dependencies = { 'nvim-lua/plenary.nvim' },
  keys = {
    {
      "<leader><CR>",
      function() require("telescope.builtin").find_files() end,
      desc = "Find Plugin File",
    },
    {
      "<leader>s",
      function() require("telescope.builtin").live_grep() end,
      desc = "Search Plugin",
    },
  },
  opts = {
    defaults = {
      layout_strategy = "horizontal",
      layout_config = { prompt_position = "top" },
      sorting_strategy = "ascending",
      winblend = 0,
    },
  },
},
{
  "telescope.nvim",
  dependencies = {
    "nvim-telescope/telescope-fzf-native.nvim",
    build = "make",
    config = function()
      require("telescope").load_extension("fzf")
    end,
  },
}

