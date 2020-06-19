int test(){

  char true_char = 1;
  char false_char = 0;
  char char_value = 'a';
  char array[2] = {1,0};

  if(true_char)  printf("OK\n");
  else printf("UNEXPECTED BEHAVIOUR\n");

  if(false_char)  printf("UNEXPECTED BEHAVIOUR\n");
  else printf("OK\n");

  if(char_value)  printf("OK\n");
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
