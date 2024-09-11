#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>
#include <map>
#include <vector>

#define DATASET_SIZE 128
#define STRIDE 118
#define ITERATIONS 1000000

using DataType = int;

// Here is a simple example which measures lookups from a vector.
//
// - How do measurements change when changing the DATASET_SIZE?
// - How do the measuments change when you change the STRIDE?
// - How many samples do you need to have to have stable results?
// - How do results change when using different DataTypes?
TEST_CASE("Trivial Vector") {
  std::vector<DataType> v;

  BENCHMARK_ADVANCED("Vector Lookup")(Catch::Benchmark::Chronometer meter) {
    std::vector<DataType> v;
    v.resize(DATASET_SIZE);
    for (size_t i = 0; i < DATASET_SIZE; i++) {
      v.emplace_back(i * 2);
    }
    meter.measure([&] {
      size_t idx = 0;
      size_t sum = 0;
      for (size_t i = 0; i < ITERATIONS; ++i) {
        sum += v[idx % DATASET_SIZE];
        idx += STRIDE;
      }
      return sum;
    });
  };
}
