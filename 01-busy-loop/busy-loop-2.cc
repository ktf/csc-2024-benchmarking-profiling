#include <cmath>

#define ITERATIONS 10000000000

int main(int c, char**argv) {
  float r = 0;
  for (size_t i = 0; i < ITERATIONS; ++i) {
    r += exp(c);
  }
  return r;
}
