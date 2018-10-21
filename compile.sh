#!/bin/bash
# $1 name of the model

echo "compilation script"
java -jar ../emam2cpp.jar --models-dir=../models/. --output-dir=../target --root-model=$1 --flag-use-armadillo-backend

echo "process .cpp template"
cp ../sample-controller-cpp/mainController.cpp ../target/.
sed -i "s/controller00/$(echo $1| cut -d'.' -f 1)/g" ../target/mainController.cpp

echo "compile with emcc"
../../emsdk/emscripten/1.38.13/emcc ../target/$(echo $1| cut -d'.' -f 2).cpp -I../armadillo-8.500.1-linux/include -s  WASM=1 -o3 --bind -o outgoingData/mainController.js

