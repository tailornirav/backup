return {
  'neovim/nvim-lspconfig',
  setup = function()
    opts = {
  diagnostics = {
    underline = true,
    update_in_insert = false,
    virtual_text = {
      spacing = 4,
      source = "if_many",
      prefix = "●",
    },
    severity_sort = true,
    signs = {
      text = {
        [vim.diagnostic.severity.ERROR] = require("lazyvim.config").icons.diagnostics.Error,
        [vim.diagnostic.severity.WARN] = require("lazyvim.config").icons.diagnostics.Warn,
        [vim.diagnostic.severity.HINT] = require("lazyvim.config").icons.diagnostics.Hint,
        [vim.diagnostic.severity.INFO] = require("lazyvim.config").icons.diagnostics.Info,
      },
    },
  },
  inlay_hints = {
    enabled = true,
  },
  capabilities = {},
  format = {
    formatting_options = {
      tabSize = 2,
      insertSpaces = true,
      trimTrailingWhitespace = true,
      insertFinalNewline = true,
      endOfLine = "auto",
    },
    timeout_ms = nil,
  },
  ---@type lspconfig.options
  servers = {
    lua_ls = {
      ---@type LazyKeysSpec[]
      settings = {
        Lua = {
          workspace = {
            checkThirdParty = false,
          },
          completion = {
            callSnippet = "Replace",
          },
        },
      },
    },
    tsserver = {
      ---@type LazyKeysSpec[]
      settings = {
        typescript = {
          preferences = {
            importModuleSpecifierPreference = "non-relative",
          },
        },
      },
    },
  },
    }
  end, 
}
