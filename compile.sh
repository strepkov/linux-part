#!/bin/bash
# $1 name of the model
# $2 unique folder

echo "compilation script"
java -jar ../emam2cpp.jar --models-dir=../models/$2/. --output-dir=../target/$2/. --root-model=$1 --flag-use-armadillo-backend

echo "process .cpp template"
cp ../sample-controller-cpp/mainController.cpp ../target/$2/.
sed -i "s/controller00/$(echo $1| cut -d'.' -f 1)/g" ../target/$2/mainController.cpp

echo "compile with emcc"
mkdir outgoingData/$2
../../emsdk/emscripten/1.38.13/emcc ../target/$2/$(echo $1| cut -d'.' -f 2).cpp -I../armadillo-8.500.1-linux/include -s  WASM=1 -o3 --bind -o outgoingData/$2/mainController.js
