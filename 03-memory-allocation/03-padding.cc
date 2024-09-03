struct Foo {
  char foo = 0;
  short bar = 0;
  int foobar = 0;
  char foo2 = 0;
  int foobar2 = 0;
};

void foo() {
  auto *ptr = new Foo[100];
}

int main(int argc, char**argv) {
  foo();
  return 0;
}
