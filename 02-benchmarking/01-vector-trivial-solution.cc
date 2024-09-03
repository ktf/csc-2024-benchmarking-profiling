#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>
#include <map>
#include <vector>
#include <iostream>

#define DATASET_SIZE 128
#define STRIDE 118
#define ITERATIONS_LOT 100000000
#define ITERATIONS_FEW 100

using DataType = int;

// Here is a simple example which measures lookups from a vector.
//
// - How do measurements change when changing the DATASET_SIZE?
// - How do the measuments change when you change the STRIDE?
// - How many samples do you need to have to have stable results?
// - How do results change when using different DataTypes?
void measure_lookup(Catch::Benchmark::Chronometer &meter, size_t datasetSize, size_t stride, size_t iterations) {
    std::vector<DataType> v;
    v.resize(datasetSize);
    for (size_t i = 0; i < datasetSize; i++) {
      v.emplace_back(i * 2);
    }
    meter.measure([&] {
      size_t idx = 0;
      size_t sum = 0;
      for (size_t i = 0; i < iterations; ++i) {
        sum += v[idx % datasetSize];
        idx += stride;
      }
      return sum;
    });
}

TEST_CASE("Vector: 100M lookups") {
  BENCHMARK_ADVANCED("2**3,1")(Catch::Benchmark::Chronometer meter) {
    measure_lookup(meter, (1<<3)/sizeof(DataType), 1, ITERATIONS_LOT);
  };
  BENCHMARK_ADVANCED("2**7,13*4096")(Catch::Benchmark::Chronometer meter) {
    measure_lookup(meter, (1<<7)/sizeof(DataType), 13*4096, ITERATIONS_LOT);
  };
  BENCHMARK_ADVANCED("2**10,13*4096")(Catch::Benchmark::Chronometer meter) {
    measure_lookup(meter, (1<<10)/sizeof(DataType), 13*4096, ITERATIONS_LOT);
  };
  BENCHMARK_ADVANCED("2**22,13*4096")(Catch::Benchmark::Chronometer meter) {
    measure_lookup(meter, (1<<28)/sizeof(DataType), 13*4096, ITERATIONS_LOT);
  };
  BENCHMARK_ADVANCED("2**30,13*4096")(Catch::Benchmark::Chronometer meter) {
    measure_lookup(meter, (1<<30)/sizeof(DataType), 13*4096, ITERATIONS_LOT);
  };
  BENCHMARK_ADVANCED("2**7,13")(Catch::Benchmark::Chronometer meter) {
    measure_lookup(meter, 1<<7/sizeof(DataType), 13, ITERATIONS_LOT);
  };
  BENCHMARK_ADVANCED("2**10,13")(Catch::Benchmark::Chronometer meter) {
    measure_lookup(meter, 1<<10/sizeof(DataType), 13, ITERATIONS_LOT);
  };
  BENCHMARK_ADVANCED("2**22,13")(Catch::Benchmark::Chronometer meter) {
    measure_lookup(meter, 1<<22/sizeof(DataType), 13, ITERATIONS_LOT);
  };
  BENCHMARK_ADVANCED("2**30,13")(Catch::Benchmark::Chronometer meter) {
    measure_lookup(meter, 1<<30/sizeof(DataType), 13, ITERATIONS_LOT);
  };
}

TEST_CASE("Vector: 100 lookups") {
  BENCHMARK_ADVANCED("2**3,1")(Catch::Benchmark::Chronometer meter) {
    measure_lookup(meter, (1<<3)/sizeof(DataType), 1, ITERATIONS_FEW);
  };
  BENCHMARK_ADVANCED("2**7,13*4096")(Catch::Benchmark::Chronometer meter) {
    measure_lookup(meter, (1<<7)/sizeof(DataType), 13*4096, ITERATIONS_FEW);
  };
  BENCHMARK_ADVANCED("2**10,13*4096")(Catch::Benchmark::Chronometer meter) {
    measure_lookup(meter, (1<<10)/sizeof(DataType), 13*4096, ITERATIONS_FEW);
  };
  BENCHMARK_ADVANCED("2**22,13*4096")(Catch::Benchmark::Chronometer meter) {
    measure_lookup(meter, (1<<22)/sizeof(DataType), 13*4096, ITERATIONS_FEW);
  };
  BENCHMARK_ADVANCED("2**30,13*4096")(Catch::Benchmark::Chronometer meter) {
    measure_lookup(meter, (1<<30)/sizeof(DataType), 13*4096, ITERATIONS_FEW);
  };
  BENCHMARK_ADVANCED("2**7,13")(Catch::Benchmark::Chronometer meter) {
    measure_lookup(meter, (1<<7)/sizeof(DataType), 13, ITERATIONS_FEW);
  };
  BENCHMARK_ADVANCED("2**10,13")(Catch::Benchmark::Chronometer meter) {
    measure_lookup(meter, (1<<10)/sizeof(DataType), 13, ITERATIONS_FEW);
  };
  BENCHMARK_ADVANCED("2**22,13")(Catch::Benchmark::Chronometer meter) {
    measure_lookup(meter, (1<<22)/sizeof(DataType), 13, ITERATIONS_FEW);
  };
  BENCHMARK_ADVANCED("2**30,13")(Catch::Benchmark::Chronometer meter) {
    measure_lookup(meter, (1<<30)/sizeof(DataType), 13, ITERATIONS_FEW);
  };
}
