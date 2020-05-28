int test(){

  int x;
  int y[10];

  int a["Hello World"];
  int b[&x];
  int c[y];
  int c[&y];
  int c[&y[1]];


  return 0;
}

int main(){

  test();

  return 0;
}
