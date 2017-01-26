#!/bin/bash
cd build
rm cubeZero
rm CMakeCache.txt
cmake ..
make
open cubeZero
