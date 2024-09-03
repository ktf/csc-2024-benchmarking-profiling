#include <cmath>

#define ITERATIONS 10000000000

int main(int, char**) {
  float r = 0;
  for (size_t i = 1; i <= ITERATIONS; ++i) {
    r = log(i);
  }
  return r;
}
