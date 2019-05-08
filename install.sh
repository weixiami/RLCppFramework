#!/bin/bash

csrutil disable

if [ ! -d "release" ]; then
    mkdir release
fi

cd release
cmake -DCMAKE_BUILD_TYPE=Release ..
make
make install
cd ..



