#cmake -S . -B build -GNinja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER_ID="Clang" -DCMAKE_CXX_COMPILER_ID="Clang"
cmake -S . -B build -GNinja -DCMAKE_BUILD_TYPE=Debug 
cd build
ninja
cd ..
