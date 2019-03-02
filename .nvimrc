
let g:ale_cpp_clang_options =  
            \ '-std=c++14 -Wall
            \ -isystem /usr/local/Cellar/glew/1.13.0/include/
            \ -isystem /Users/daneryl/workspace/cubeZero/external/glm
            \ -isystem /Users/daneryl/workspace/cubeZero/external/glfw/include
            \ -isystem /Users/daneryl/workspace/cubeZero/external/Catch/
            \ -isystem /Users/daneryl/workspace/cubeZero/external/FakeIt/single_header/catch/'

let g:ale_cpp_gcc_options =  
            \ '-std=c++14 -Wall
            \ -isystem /usr/local/Cellar/glew/1.13.0/include/
            \ -isystem /Users/daneryl/workspace/cubeZero/external/glm
            \ -isystem /Users/daneryl/workspace/cubeZero/external/glfw/include
            \ -isystem /Users/daneryl/workspace/cubeZero/external/Catch/
            \ -isystem /Users/daneryl/workspace/cubeZero/external/FakeIt/single_header/catch/'



let g:ncm2_pyclang#library_path = '/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/libclang.dylib'
