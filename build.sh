#!/bin/bash

mkdir -p build
cmake -S . -B build -DLOG_LEVEL=$1 
cd build
make haberlesme_karti
cd ..
#cmake --build build --parallel $(nproc) 
