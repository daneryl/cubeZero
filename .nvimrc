let g:neoinclude#_paths = [
            \ '/usr/local/Cellar/glew/1.13.0/include/'
            \ ]
let g:deoplete#sources#clang#clang_complete_database = '/Users/daneryl/workspace/cubeZero'

let g:neomake_cpp_clang_args = [ 
            \ '-isystem', 
            \ '/usr/local/Cellar/glew/1.13.0/include/',
            \ '-isystem', 
            \ '/Users/daneryl/workspace/cubeZero/external/glm',
            \ '-isystem', 
            \ '/Users/daneryl/workspace/cubeZero/external/glfw/include' 
            \ ]
