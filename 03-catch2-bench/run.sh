mkdir -p bin
c++ -O2 -I. -std=c++20 fibonacci.cxx catch_amalgamated.cxx -o bin/fibonacci
bin/fibonacci
