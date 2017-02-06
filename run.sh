#!/bin/bash
cd src
rm *.gch
cd ../build
rm cubeZero
rm CMakeCache.txt
cmake .. -DCMAKE_BUILD_TYPE=Debug
make
open cubeZero
