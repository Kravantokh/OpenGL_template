cmake -S . -B build -GNinja -DCMAKE_BUILD_TYPE=Debug -DBUILD_EXAMPLES=true
cd build
ninja
cd ..
