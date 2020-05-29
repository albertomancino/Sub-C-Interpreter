int test(){

  char i = 'a' - 1;
  while(i++ != 'z'){
    printf("OK. While loop with variable char condition %c.\n", i);
  }

  return 0;
}

int main(){

  test();

  return 0;
}
