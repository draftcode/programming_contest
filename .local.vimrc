autocmd BufEnter */contest/*/*.cpp nnoremap <silent> [Space]r  :<C-u>QuickRun oj<CR>
let g:quickrun_config['oj'] = {
      \ 'exec' : '%C %o %a',
      \ 'command' : '~/src/OnlineJudgeScript/oj.py',
      \ 'cmdopt' : '--%{expand("%:p:h:t")}',
      \ 'args' : '%{expand("%:t:r")}'}
