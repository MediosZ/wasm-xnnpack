mkdir -p embuild
cd embuild
emcmake cmake .. \
    -DCMAKE_BUILD_TYPE=Release \
    -DXNNPACK_LIBRARY_TYPE=static \
    -GNinja
cmake --build .
cp main* ../dist/