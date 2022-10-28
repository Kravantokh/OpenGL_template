let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/prog/OpenGL_template
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +1 lib/bu_glw/src/bu_glw.cpp
badd +34 ~/prog/OpenGL_template/lib/bu_glw/include/bu_glw.hpp
badd +6 src/main.cpp
badd +1 run.sh
badd +14 CMakeLists.txt
badd +1 lib/bu_glw/include/bu_glw_except.hpp
argglobal
%argdel
$argadd lib/bu_glw/src/bu_glw.cpp
edit lib/bu_glw/src/bu_glw.cpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd _ | wincmd |
split
1wincmd k
wincmd w
wincmd w
wincmd _ | wincmd |
split
1wincmd k
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe '1resize ' . ((&lines * 15 + 16) / 33)
exe 'vert 1resize ' . ((&columns * 68 + 68) / 136)
exe '2resize ' . ((&lines * 15 + 16) / 33)
exe 'vert 2resize ' . ((&columns * 68 + 68) / 136)
exe '3resize ' . ((&lines * 15 + 16) / 33)
exe 'vert 3resize ' . ((&columns * 67 + 68) / 136)
exe '4resize ' . ((&lines * 15 + 16) / 33)
exe 'vert 4resize ' . ((&columns * 67 + 68) / 136)
argglobal
balt src/main.cpp
setlocal fdm=expr
setlocal fde=nvim_treesitter#foldexpr()
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=20
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 18 - ((8 * winheight(0) + 7) / 15)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 18
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("src/main.cpp", ":p")) | buffer src/main.cpp | else | edit src/main.cpp | endif
if &buftype ==# 'terminal'
  silent file src/main.cpp
endif
balt lib/bu_glw/src/bu_glw.cpp
setlocal fdm=expr
setlocal fde=nvim_treesitter#foldexpr()
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=20
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 29 - ((0 * winheight(0) + 7) / 15)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 29
normal! 06|
wincmd w
argglobal
if bufexists(fnamemodify("~/prog/OpenGL_template/lib/bu_glw/include/bu_glw.hpp", ":p")) | buffer ~/prog/OpenGL_template/lib/bu_glw/include/bu_glw.hpp | else | edit ~/prog/OpenGL_template/lib/bu_glw/include/bu_glw.hpp | endif
if &buftype ==# 'terminal'
  silent file ~/prog/OpenGL_template/lib/bu_glw/include/bu_glw.hpp
endif
balt lib/bu_glw/src/bu_glw.cpp
setlocal fdm=expr
setlocal fde=nvim_treesitter#foldexpr()
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=20
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 36 - ((14 * winheight(0) + 7) / 15)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 36
normal! 02|
wincmd w
argglobal
if bufexists(fnamemodify("lib/bu_glw/include/bu_glw_except.hpp", ":p")) | buffer lib/bu_glw/include/bu_glw_except.hpp | else | edit lib/bu_glw/include/bu_glw_except.hpp | endif
if &buftype ==# 'terminal'
  silent file lib/bu_glw/include/bu_glw_except.hpp
endif
balt ~/prog/OpenGL_template/lib/bu_glw/include/bu_glw.hpp
setlocal fdm=expr
setlocal fde=nvim_treesitter#foldexpr()
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=20
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 16 - ((6 * winheight(0) + 7) / 15)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 16
normal! 08|
wincmd w
3wincmd w
exe '1resize ' . ((&lines * 15 + 16) / 33)
exe 'vert 1resize ' . ((&columns * 68 + 68) / 136)
exe '2resize ' . ((&lines * 15 + 16) / 33)
exe 'vert 2resize ' . ((&columns * 68 + 68) / 136)
exe '3resize ' . ((&lines * 15 + 16) / 33)
exe 'vert 3resize ' . ((&columns * 67 + 68) / 136)
exe '4resize ' . ((&lines * 15 + 16) / 33)
exe 'vert 4resize ' . ((&columns * 67 + 68) / 136)
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
nohlsearch
let g:this_session = v:this_session
let g:this_obsession = v:this_session
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
