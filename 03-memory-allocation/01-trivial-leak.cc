// - Check with igprof that main leaks 1 bytes.
// - Change the type being allocated (e.g. double, float) and verify what changes
int main(int argc, char**argv) {
  auto *ptr = new char;
  // delete ptr;
}
