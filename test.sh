#!/bin/bash
cd src
rm *.gch
cd ../build
rm tests
#rm CMakeCache.txt
cmake .. -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=ON
make
./tests
