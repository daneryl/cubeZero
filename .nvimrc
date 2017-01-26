set tabstop=4
set softtabstop=4
set shiftwidth=4
set noexpandtab
augroup project
	autocmd!
	autocmd BufRead,BufNewFile *.h,*.c set filetype=c.doxygen
augroup END

let &path.="src,src/external/AL"
