int test(){

  int x;
  char y;
  int xv[10];
  char yv[10];

  &x;
  &y;
  &xv;
  &yv;
  &xv[5];
  &yv[5];

  printf("%d\n", &x);
  printf("%d\n", &y);
  printf("%d\n", &xv);
  printf("%d\n", &yv);
  printf("%d\n", &xv[5]);
  printf("%d\n", &yv[5]);
  printf("%d\n", &xv[4]);
  printf("%d\n", &yv[4]);

  return 0;
}

int main(){

  test();

  return 0;
}
