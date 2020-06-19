char fun(int x){

  return x;
}

int test(){

  int x = 100;
  int y = 1000;
  printf("OK. Int value returned: %d\n", fun(x));
  printf("OK. Int value returned: %d\n", fun(y));

  return 0;
}

int main(){

  test();

  return 0;
}
