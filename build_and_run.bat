@ECHO OFF
cmake -GNinja -B build
cd build
ninja
main.exe
PAUSE