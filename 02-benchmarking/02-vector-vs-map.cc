#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>
#include <map>
#include <vector>

#define DATASET_SIZE 128
#define STRIDE 118
#define ITERATIONS 1000000

using DataType = int;

// Extend the benchmark to use different kind of containers, e.g.:
//
// - std::map
// - std::unordered_map
//
// and test for different sizes of the dataset
TEST_CASE("Trivial Vector") {
  std::vector<DataType> v;

  BENCHMARK_ADVANCED("Vector Lookup")(Catch::Benchmark::Chronometer meter) {
    for (size_t i = 0; i < DATASET_SIZE; i++) {
      v.emplace_back(i * 2);
    }
    meter.measure([&] {
      for (size_t i = 0; i < ITERATIONS; i += STRIDE) {
        volatile DataType a = v[i % DATASET_SIZE];
      }
    });
  };
}
