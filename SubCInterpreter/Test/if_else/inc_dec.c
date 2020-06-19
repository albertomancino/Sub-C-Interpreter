int test(){

  int x = 0;

  if(++x)  printf("OK\n");
  else printf("UNEXPECTED BEHAVIOUR\n");

  if(--x)  printf("UNEXPECTED BEHAVIOUR\n");
  else printf("OK\n");

  if(x++)  printf("UNEXPECTED BEHAVIOUR\n");
  else printf("OK\n");

  if(x--)  printf("OK\n");
  else printf("UNEXPECTED BEHAVIOUR\n");

  return 0;
}

int main(){

  test();

  return 0;
}
