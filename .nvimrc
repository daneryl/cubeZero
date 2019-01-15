let g:neoinclude#_paths = [
            \ '/usr/local/Cellar/glew/1.13.0/include/'
            \ ]

let g:deoplete#sources#clang#clang_complete_database = '/Users/daneryl/workspace/cubeZero'

" let g:ale_cpp_clang_executable = 'clangtidy'
let g:ale_cpp_clang_options =  
            \ '-std=c++14 -Wall
            \ -isystem /usr/local/Cellar/glew/1.13.0/include/
            \ -isystem /Users/daneryl/workspace/cubeZero/external/glm
            \ -isystem /Users/daneryl/workspace/cubeZero/external/glfw/include
            \ -isystem /Users/daneryl/workspace/cubeZero/external/Catch/
            \ -isystem /Users/daneryl/workspace/cubeZero/external/FakeIt/single_header/catch/'


let g:deoplete#sources#clang#std = {'cpp': 'c14'}
