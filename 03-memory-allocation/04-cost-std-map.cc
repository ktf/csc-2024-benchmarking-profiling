#include <map>

// Calculate the overhead of filling a map
int main(int argc, char **) {
  std::map<int, int> m;

  for (int i = 0; i < 1000; ++i) {
    m[i] = i;
  }
  return 0;
}
