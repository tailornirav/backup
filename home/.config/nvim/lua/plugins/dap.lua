return {
  'mxsdev/nvim-dap-vscode-js',
  'mfussenegger/nvim-dap',
  'microsoft/vscode-js-debug',
  config = function()
    require("dap-vscode-js").setup({
      adapters = { 'pwa-node', 'pwa-chrome', 'pwa-msedge', 'node-terminal', 'pwa-extensionHost' }, -- which adapters to register in nvim-dap
    })

    for _, language in ipairs({ "typescript", "javascript" }) do
      require("dap").configurations[language] = {
        {
          type = "pwa-node",
          request = "launch",
          name = "Launch file",
          program = "${file}",
          console = "integratedTerminal",
        },
      }
    end
  end,
}
