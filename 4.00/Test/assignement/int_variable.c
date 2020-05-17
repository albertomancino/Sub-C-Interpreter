int int_fun(){

  return 10;
}

char char_fun(){

  return 'a';
}

int test(){

  int x;
  int a;
  char b;
  int int_array[3] = {1,2,3};
  char char_array[3] = {1,2,3};

  x = 10;
  printf("OK. Costant positive integer value assigned.\n");
  x = -10;
  printf("OK. Costant negative integer value assigned.\n");
  x = a;
  printf("OK. Int variable value assigned.\n");
  x = b;
  printf("OK. Char variable value assigned.\n");
  x = int_array[2];
  printf("OK. Int array element value assigned.\n");
  x = char_array[2];
  printf("OK. Char array element value assigned.\n");
  x = 'a';
  printf("OK. Costant char value assigned.\n");
  x = int_fun();
  printf("OK. Int function call value assigned.\n");
  x = char_fun();
  printf("OK. Char function call value assigned.\n");
  x = (1+1*10/10%10);
  printf("OK. Operation value assigned.\n");
  x = ++a;
  printf("OK. Pre increment  value assigned.\n");
  x = --a;
  printf("OK. Pre decrement value assigned.\n");
  x = a++;
  printf("OK. Post increment value assigned.\n");
  x = a--;
  printf("OK. Post decrement value assigned.\n");
  x = (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Comparison value assigned.\n");

  return 0;
}

int main(){

  test();

  return 0;
}
