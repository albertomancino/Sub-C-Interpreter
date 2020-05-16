int test(){

  if(10 > 5)  printf("OK\n");
  else printf("UNEXPECTED BEHAVIOUR\n");

  if(10 < 5)  printf("UNEXPECTED BEHAVIOUR\n");
  else printf("OK\n");

  if(10 == 5)  printf("UNEXPECTED BEHAVIOUR\n");
  else printf("OK\n");

  if(10 != 5)  printf("OK\n");
  else printf("UNEXPECTED BEHAVIOUR\n");

  if(1 && 1)  printf("OK\n");
  else printf("UNEXPECTED BEHAVIOUR\n");

  if(0 || 0)  printf("UNEXPECTED BEHAVIOUR\n");
  else printf("OK\n");

  return 0;
}

int main(){

  test();

  return 0;
}
