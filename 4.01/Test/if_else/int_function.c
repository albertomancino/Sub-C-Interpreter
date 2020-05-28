int postive(){
  return 1;
}

int negative(){
  return 0;
}

int value(){
  return 123;
}

int test(){

  if(postive())  printf("OK\n");
  else printf("UNEXPECTED BEHAVIOUR\n");

  if(negative())  printf("UNEXPECTED BEHAVIOUR\n");
  else printf("OK\n");

  if(value())  printf("OK\n");
  else printf("UNEXPECTED BEHAVIOUR\n");

  return 0;
}

int main(){

  test();

  return 0;
}
