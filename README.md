# Emam2wasm toolchain for Linux(Debian based).

The toolchain compiles an EMAM model to a WebAssembly, using the emam2cpp generator and the bash script. Firstly the emam2cpp generator produces .h files, which contain the corresponding c++ code. After that, the special template for .cpp file is used to generate a main .cpp file for the current model. Later, it is used by the emscripten to generate wasm file with special key -bind. (https://kripken.github.io/emscripten-site/docs/porting/connecting_cpp_and_javascript/embind.html). When the fikes have been compiled, the web-server sends them to the front-end part.

To install the tool chain, the following steps should be done:
1. Clone this project.
```
git clone https://github.com/strepkov/linux-part.git
```
2. Install java.
```
apt install openjdk-8-jre-headless
```
3. Install emsdk into the folder of the project (https://kripken.github.io/emscripten-site/docs/getting_started/downloads.html)
```
git clone https://github.com/juj/emsdk.git
cd emsdk
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh
```
4. Run the webServer in background on the server(toolchain/web-server)
```
java -jar werServer.jar 3005 (the following port should be open in advance)
```
