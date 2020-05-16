int test(){

  int true_int = 1;
  int false_int = 0;
  int int_value = 170394;
  int array[2] = {1,0};

  if(true_int)  printf("OK\n");
  else printf("UNEXPECTED BEHAVIOUR\n");

  if(false_int)  printf("UNEXPECTED BEHAVIOUR\n");
  else printf("OK\n");

  if(int_value)  printf("OK\n");
  else printf("UNEXPECTED BEHAVIOUR\n");

  if(array[0])  printf("OK\n");
  else printf("UNEXPECTED BEHAVIOUR\n");

  if(array[1])  printf("UNEXPECTED BEHAVIOUR\n");
  else printf("OK\n");

  return 0;
}

int main(){

  test();

  return 0;
}
