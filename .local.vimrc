setlocal makeprg=clang\ -cc1\ -fsyntax-only\ %
nnoremap <silent> [Space]r  :<C-u>make<CR>
autocmd BufEnter */contest/*/*.cpp nnoremap <silent> [Space]t  :<C-u>QuickRun oj<CR>
let g:quickrun_config.oj = {'exec' : '../oj.py --{expand("%:p:h:t")} {expand("%:t:r")}'}

