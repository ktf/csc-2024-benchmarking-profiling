#include <vector>

// - Evaluate with the profiler the overhead of having a vector of vectors
int main(int, char**) {
  auto *foo = new std::vector<std::vector<int>>;
  foo->resize(10);
  for (int i = 0; i < 10; ++i) {
    (*foo)[i].resize(10);
  }
  return 0;
}
