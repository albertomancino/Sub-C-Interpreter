int test(){

  int i = 0;
  while('a'){
    printf("OK. While loop with costant char condition %d.\n", i);
    if (i++ == 10) return 0;
  }

  return 0;
}

int main(){

  test();

  return 0;
}
