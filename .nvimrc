let g:neoinclude#_paths = '/Users/daneryl/workspace/cubeZero/external'
let g:deoplete#sources#clang#clang_complete_database = '/Users/daneryl/workspace/cubeZero'
"autocmd BufWritePost * !cd build;cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
"setlocal path+=~/workspace/cubeZero/external
"augroup project
	"autocmd!
	"autocmd BufRead,BufNewFile *.h,*.c set filetype=c.doxygen
"augroup END

"let g:marching_include_paths = [
			"\	'/Users/daneryl/workspace/cubeZero/external/glm',
			"\	'/Users/daneryl/workspace/cubeZero/external/glfw',
			"\	'/Users/daneryl/workspace/cubeZero/src'
			\]
