set nocompatible
if has('win64') || has('win32')
	set rtp+=~/vimfiles/bundle/Vundle.vim
else
	set rtp+=~/.vim/bundle/Vundle.vim
endif
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
Plugin 'octol/vim-cpp-enhanced-highlight'
Plugin 'tomtom/tcomment_vim'
" Plugin 'jiangmiao/auto-pairs'
Plugin 'Raimondi/delimitMate'
let delimitMate_expand_cr = 1
Plugin 'Valloric/YouCompleteMe'
let g:ycm_global_ycm_extra_conf = "~/.vim/ycm_extra_conf.py"
imap <silent> <BS> <C-R>=YcmOnDeleteChar()<CR><Plug>delimitMateBS

function! YcmOnDeleteChar()
  if pumvisible()
    return "\<C-y>"
  endif
  return "" 
endfunction

call vundle#end()

filetype plugin indent on
syntax enable
# colorscheme monokai
set hidden
set number
set relativenumber
set smartindent
set shiftwidth=2
set tabstop=2
set laststatus=2
set backspace=2
set mouse=a

" Buffer switch keystrokes
" map <C-b><Right> :bn<CR>
" imap <C-b><Right> <C-c>:bn<CR>i
" map <C-b><Left> :bp<CR>
" imap <C-b><Left> <C-c>:bp<CR>i

" GUI Settings:
if has('gui_running')
	if has('win64') || has('win32')
		set guifont=Consolas:h11
	elseif has('macunix')
		set guifont=Consolas:h17
	else
		set guifont=Consolas\ 11
		set linespace=4
	endif
endif

" Handle DOS file endings
function DOSRem()
	set ff=unix
	w
	edit!
endfunction
autocmd BufReadPost * call DOSRem()
