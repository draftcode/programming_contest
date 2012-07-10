autocmd BufEnter */Contest/*/* nnoremap <silent> [Space]r  :<C-u>QuickRun oj<CR>
let g:quickrun_config['oj'] = {
      \ 'exec' : '%C %o %a',
      \ 'command' : 'oj',
      \ 'cmdopt' : '--test-dir t --source %{expand("%:p")}',
      \ 'args' : '%{expand("%:p:h:t")} %{split(expand("%:t"), "\\.")[0]}'}
