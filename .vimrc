filetype off " required



" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
" Plugin 'VundleVim/Vundle.vim'

" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo
" Plugin 'tpope/vim-fugitive'
" plugin from http://vim-scripts.org/vim/scripts.html
" Plugin 'L9'
" Git plugin not hosted on GitHub
" Plugin 'git://git.wincent.com/command-t.git'
" git repos on your local machine (i.e. when working on your own plugin)
" Plugin 'file:///home/gmarik/path/to/plugin'
" The sparkup vim script is in a subdirectory of this repo called vim.
" Pass the path to set the runtimepath properly.
" Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" Install L9 and avoid a Naming conflict if you've already installed a
" different version somewhere else.
" Plugin 'ascenator/L9', {'name': 'newL9'}
" All of your Plugins must be added before the following line
"
Plugin 'VundleVim/Vundle.vim'
Plugin 'Raimondi/delimitMate'
Plugin 'vim-airline/vim-airline'
Plugin 'scrooloose/syntastic'
Plugin 'vim-airline/vim-airline-themes'
Plugin 'The-NERD-Tree'
Plugin 'nanotech/jellybeans.vim'
Plugin 'scrooloose/nerdcommenter'
Plugin 'Syntastic'
Plugin 'SirVer/ultisnips'
Plugin 'honza/vim-snippets'
Plugin 'terryma/vim-multiple-cursors'
Plugin 'Valloric/YouCompleteMe'
Plugin 'ervandew/supertab'

call vundle#end()            " required
filetype plugin indent on    " required

" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line
"
" make YCM compatible with UltiSnips (using supertab)
let g:ycm_key_list_select_completion = ['<C-n>', '<Down>']
let g:ycm_key_list_previous_completion = ['<C-p>', '<Up>']
let g:ycm_global_ycm_extra_conf = '~/.vim/bundle/YouCompleteMe/third_party/ycmd/.ycm_extra_conf.py'
let g:ycm_confirm_extra_conf = 0
let g:ycm_autoclose_preview_window_after_completion = 1
let g:ycm_warning_symbol = '>*'
let g:SuperTabDefaultCompletionType = '<C-n>'
" let g:ycm_auto_trigger_delay=10000 " milliseconds or seconds
" imap <expr> <CR> pumvisible() ? "\<c-y>" : "<Plug>delimitMateCR"

"UltiSnipsEdit
let g:UltiSnipsExpandTrigger="<Tab>"
let g:UltiSnipsJumpForwardTrigger="<C-n>"
let g:UltiSnipsJumpBackwardTrigger="<C-p>"
"if !exists("g:UltiSnipsJumpForwardTrigger")
"    let g:UltiSnipsJumpForwardTrigger = "<tab>"
"endif



" If you want :UltiSnipsEdit to split your window.
let g:UltiSnipsEditSplit="vertical"

"NerdCommenter
" NERD Commenter
" Add spaces after comment delimiters by default
let g:NERDSpaceDelims = 1
" Use compact syntax for prettified multi-line comments
let g:NERDCompactSexyComs = 1
" Align line-wise comment delimiters flush left instead of following code indentation
let g:NERDDefaultAlign = 'left'
" Set a language to use its alternate delimiters by default
let g:NERDAltDelims_java = 1
" Add your own custom formats or override the defaults
let g:NERDCustomDelimiters = { 'c': { 'left': '/**','right': '*/' } }
" Allow commenting and inverting empty lines (useful when commenting a region)
let g:NERDCommentEmptyLines = 1
" Enable trimming of trailing whitespace when uncommenting
let g:NERDTrimTrailingWhitespace = 1


" Deoplete.
let g:deoplete#enable_at_startup = 1

" delimitMate
let delimitMate_expand_cr=2
let delimitMate_expand_space=1
let delimitMate_jump_expansion = 1
au FileType tcl let b:delimitMate_jump_expansion =1 

" au FileType c,perl let b:delimitMate_eol_marker = ";"

imap <expr> <C-f> 
			\  pumvisible() ?
			\  delimitMate#JumpAny() :
			\ "<Plug>delimitMateS-Tab"
"when pumVisible Situation, Do delimitMate#JumpAny!

" Syntastic
set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*
 
let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0
 
let g:syntastic_cpp_compiler = 'g++'
let g:syntastic_cpp_compiler_options = "-std=c++11 -Wall -Wextra -Wpedantic"
let g:syntastic_c_compiler_options = "-std=c11 -Wall -Wextra -Wpedantic"

" airline
let g:airline_theme='hybrid'
set laststatus=2 " turn on bottom bar

"NERDTree
autocmd BufEnter * lcd %:p:h
autocmd VimEnter * if !argc() | NERDTree | endif
let NERDTreeShowLineNumbers=1
let g:NERDTreeWinPos = "right"


" vim-multiple-cursor
let g:multi_cursor_use_default_mapping=0
" Default mapping
let g:multi_cursor_next_key='<C-n>'
let g:multi_cursor_prev_key='<C-p>'
let g:multi_cursor_skip_key='<C-x>'
let g:multi_cursor_quit_key='<Esc>'

"color jellybeans

syntax on "  구문강조 사용
filetype plugin indent on

set nocompatible
set hlsearch " 검색어 하이라이팅 
set nu " 줄번호 
set autoindent " 자동 들여쓰기
set scrolloff=2 
set wildmode=longest,list 
set ts=4 "tag select 
set sts=4 "st select 
set sw=1 " 스크롤바 너비
set autowrite " 다른 파일로 넘어갈 때 자동 저장
set autoread " 작업 중인 파일 외부에서 변경됬을 경우 자동으로 불러옴
set cindent " C언어 자동 들여쓰기
set history=100
set laststatus=2 " 상태바 표시 항상
set shiftwidth=4 " 자동 들여쓰기 너비 설정
" set showmatch " 일치하는 괄호 하이라이팅
set smarttab
set smartindent
set softtabstop=4
set tabstop=4
set ruler " 현재 커서 위치 표시
set statusline=\ %<%l:%v\ [%P]%=%a\ %h%m%r\ %F\
set fileencoding=utf-8 " 파일저장인코딩 
set backspace=eol,start,indent "  줄의 끝, 시작, 들여쓰기에서 백스페이스시 이전줄로
set incsearch "  키워드 입력시 점진적 검색
set ignorecase " 검색시 대소문자 무시, set ic 도 가능
" set smartcase " 검색시 대소문자 구별
set tenc=utf-8      " 터미널 인코딩
set fencs=ucs-bom,utf-8,euc-kr.latin1 " 한글 파일은 euc-kr로, 유니코드는 유니코드로


"Key mappings
let mapleader=","
"마우스 사용 여부
map <F7> <ESC>:set mouse=a<CR>
map <F8> <ESC>:set mouse-=a<CR>

"moving
inoremap jk <esc>

"nnoremap <S-j> L
"nnoremap <S-k> H
nnoremap <S-l> $
nnoremap <S-h> ^

nnoremap d<S-l> d$
nnoremap d<S-h> d^

"vnoremap <S-j> L
"vnoremap <S-k> H
vnoremap <S-l> $
vnoremap <S-h> ^

nnoremap <Tab> >>
nnoremap <S-Tab> <<

nnoremap <C-k> :m--<CR>==
nnoremap <C-j> :m +1<CR>==

nnoremap g :YcmCompleter GoTo

"nnoremap <CR> i<CR><esc>
"nnoremap <S-d> <S-j>
nnoremap <S-k> k
"help 실수로 help 열지 않기 위한 맵핑
nnoremap <leader>h <S-k>

" customize keymapping
map <Leader>cc <plug>NERDComToggleComment
map <Leader>c<space> <plug>NERDComComment

nnoremap <leader>g :YcmCompleter GoTo<CR>
nnoremap <leader>gg :YcmCompleter GoToImprecise<CR>
nnoremap <leader>d :YcmCompleter GoToDeclaration<CR>
nnoremap <leader>t :YcmCompleter GetType<CR>
nnoremap <leader>p :YcmCompleter GetParent<CR>

" map NERT Tree to key 'F6'
nmap <F6> :NERDTreeToggle<CR>
"
let g:syntastic_enable_highlighting=0
let g:syntastic_enable_signs=0
let g:colors_name = "ubloh"

highlight SyntasticErrorLine guibg=#FFF064
highlight SyntasticWarningLine guibg=#331d1e


color jellybeans
