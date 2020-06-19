int test1(){

  int i = 0;

  int a[10];
  while(a){
    printf("OK. While loop with int pointer condition %d.\n", i);
    if (i++ == 10) return 0;
  }
}

int test2(){

  int i = 0;

  int a[] = {1,2,3};
  while(a){
    printf("OK. While loop with int pointer condition %d.\n", i);
    if (i++ == 10) return 0;
  }
}

int test3(){

  int i = 0;

  int a;
  while(&a){
    printf("OK. While loop with int pointer condition %d.\n", i);
    if (i++ == 10) return 0;
  }
}

int main(){

  test1();
  test2();
  test3();

  return 0;
}
