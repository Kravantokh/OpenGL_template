@ECHO OFF
python lib/gl3w/gl3w_gen.py --root=lib/gl3w/
cmake -GNinja -B build
cd build
ninja
main.exe
PAUSE