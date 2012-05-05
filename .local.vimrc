autocmd BufEnter */contest/*/* nnoremap <silent> [Space]r  :<C-u>QuickRun oj<CR>
let g:quickrun_config['oj'] = {
      \ 'exec' : '%C %o %a',
      \ 'command' : '~/src/OnlineJudgeScript/oj.py',
      \ 'cmdopt' : '--%{expand("%:p:h:t")} -i %{expand("%:p")}',
      \ 'args' : '%{split(expand("%:t"), "\\.")[0]}'}
