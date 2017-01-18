#!/bin/bash
cd build
rm CMakeCache.txt
cmake ..
make
open cubeZero
