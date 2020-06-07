int positive(){

  return 1;
}

int test(){

  int i = 0;
  while(positive()){
    printf("OK. While loop with function call condition %d.\n", i);
    if (i++ == 10) return 0;
  }
}

int main(){

  test();

  return 0;
}
