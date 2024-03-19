return {
  'itchyny/lightline.vim',
  config = function()
    local active = {
      left = {
        {'mode', 'paste'},
        {'readonly', 'filename', 'modified'}
      },
      right = {
        {'lineinfo'},
        {'linter_checking', 'linter_errors', 'linter_warnings', 'linter_infos', 'linter_ok'},
        {'percent'},
        {'fileformat', 'fileencoding', 'filetype'}
      }
    }
    
    local component_function = {
      filename = 'LightlineFilename'
    }
    
    local component_expand = {
      linter_checking = 'lightline#ale#checking',
      linter_infos = 'lightline#ale#infos',
      linter_warnings = 'lightline#ale#warnings',
      linter_errors = 'lightline#ale#errors',
      linter_ok = 'lightline#ale#ok'
    }
    
    local component_type = {
      linter_checking = 'right',
      linter_infos = 'right',
      linter_warnings = 'warning',
      linter_errors = 'error',
      linter_ok = 'right'
    }

    return {
      active = active,
      component_function = component_function,
      component_expand = component_expand,
      component_type = component_type
    }
  end,
  indicator = {
    checking = '[C]',
    infos = '[I]',
    warnings = '[W]',
    errors = '[E]',
    ok = '[OK]'
  },
  filename = function()
    return vim.fn.expand('%:t') ~= '' and '@%' or '[No Name]'
  end
}

