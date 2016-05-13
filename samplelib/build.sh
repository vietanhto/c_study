cmake -B./build -H.
make -C ./build
make test -C ./build
./build/samplelib