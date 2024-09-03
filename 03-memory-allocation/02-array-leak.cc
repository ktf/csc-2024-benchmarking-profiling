// Check the leak and verify what happens when you
// uncomment one of the two delete statements
int main(int argc, char**argv) {
  auto *ptr = new char[100];
  // delete ptr;
  // delete ptr[];
}
