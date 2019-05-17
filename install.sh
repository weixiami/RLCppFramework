#!/bin/bash

echo 获取权限

if [ ! -d "release" ]; then
    mkdir release
fi

cd release
sudo cmake -DCMAKE_BUILD_TYPE=Release ..
sudo make
sudo make install
cd ..



