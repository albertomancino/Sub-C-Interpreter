int test(){

  printf("\a   \n");
  printf("\1\n");
  printf("\11\n");
  printf("\123\n");
  printf("\139\n");
  printf("%b\n");

  int x = printf("%b\n");
  x = 100;
  x = printf("Ciao zoccolette %d \123 %d\n", x, 123);
  printf("%d\n", x);

  return 0;
}

int main(){


  test();

  return 0;
}
