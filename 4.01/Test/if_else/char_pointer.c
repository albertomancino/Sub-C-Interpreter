int test(){

  char array[2] = {1,0};
  char var = 1;

  if(array)  printf("OK\n");
  else printf("UNEXPECTED BEHAVIOUR\n");

  if(&var)  printf("OK\n");
  else printf("UNEXPECTED BEHAVIOUR\n");

  if(&array[1])  printf("OK\n");
  else printf("UNEXPECTED BEHAVIOUR\n");
  
  return 0;
}

int main(){

  test();

  return 0;
}
