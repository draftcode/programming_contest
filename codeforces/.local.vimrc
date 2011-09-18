autocmd BufEnter */contest/codeforces/*/*.cpp nnoremap <silent> [Space]r  :<C-u>QuickRun oj<CR>
let g:quickrun_config['oj'] = {
      \ 'exec' : '%C %o %a',
      \ 'command' : '~/src/OnlineJudgeScript/oj.py',
      \ 'cmdopt' : '--codeforces',
      \ 'args' : '%{expand("%:p:h:t")}/%{expand("%:t:r")}'}

