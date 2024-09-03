int g(int w) {
  int w2 = w*w;
  return w2;
}

int f(int x, int y,  int z) {
  int sum = x + y + z;
  return g(sum);
}

int main(int argc, char**) {
  int a = 3;
  int b = 4;
  int c = 5;
  f(a, b, c);
  return 0;
}
