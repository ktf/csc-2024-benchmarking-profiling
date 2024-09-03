CXXFLAGS=-std=c++17

all: bin/03-memory-allocation-01-trivial-leak \
	bin/03-memory-allocation-02-array-leak \
	bin/03-memory-allocation-03-padding \
	bin/03-memory-allocation-04-cost-std-map \
	bin/03-memory-allocation-05-cost-vector-vector \
	bin/02-benchmarking-01-vector-trivial \
	bin/02-benchmarking-01-vector-trivial-solution \
	bin/02-benchmarking-02-vector-vs-map

.PHONEY: bin clean all

bin:
	mkdir -p bin
clean:
	rm -rf bin

bin/02-benchmarking-01-vector-trivial: bin 02-benchmarking/01-vector-trivial.cc
	c++ $(CXXFLAGS) -O2 $$(pkg-config --libs --cflags catch2-with-main) 02-benchmarking/01-vector-trivial.cc -o $@
bin/02-benchmarking-01-vector-trivial-solution: bin
	c++ $(CXXFLAGS) -O2 $$(pkg-config --libs --cflags catch2-with-main) 02-benchmarking/01-vector-trivial-solution.cc -o $@
bin/02-benchmarking-02-vector-vs-map: bin
	c++ $(CXXFLAGS) -O2 $$(pkg-config --libs --cflags catch2-with-main) 02-benchmarking/02-vector-vs-map.cc -o $@
bin/03-memory-allocation-01-trivial-leak: bin 03-memory-allocation/01-trivial-leak.cc
	c++ $(CXXFLAGS) 03-memory-allocation/01-trivial-leak.cc -o $@
bin/03-memory-allocation-02-array-leak: bin
	c++ $(CXXFLAGS) 03-memory-allocation/02-array-leak.cc -o $@
bin/03-memory-allocation-03-padding: bin
	c++ $(CXXFLAGS) 03-memory-allocation/03-padding.cc -o $@
bin/03-memory-allocation-04-cost-std-map: bin
	c++ $(CXXFLAGS) 03-memory-allocation/04-cost-std-map.cc -o $@
bin/03-memory-allocation-05-cost-vector-vector: bin
	c++ $(CXXFLAGS) 03-memory-allocation/05-cost-vector-vector.cc -o $@
