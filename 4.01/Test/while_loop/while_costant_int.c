int test(){

  int i = 0;
  while(1){
    printf("OK. While loop with costant int condition %d.\n", i);
    if (i++ == 10) return 0;
  }

  return 0;
}

int main(){

  test();

  return 0;
}
