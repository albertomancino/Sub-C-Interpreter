int int_fun(){

  return 0;
}

int char_fun(){

  return 0;
}

int test(){

  int int_var = 1;
  char char_var = 1;
  int int_array[3] = {1,2,3};
  char char_array[3] = {1,2,3};


  1 * 1;
  printf("OK. Costant integer multiplicaton.\n");

  1 * +1;
  printf("OK. Costant positive integer multiplicaton.\n");

  1 * -1;
  printf("OK. Costant negative integer multiplicaton.\n");

  int_var * int_var;
  printf("OK. Integer variable multiplicaton.\n");

  char_var * char_var;
  printf("OK. Char variable multiplicaton.\n");

  int_array[0] * int_array[0];
  printf("OK. Integer array element variable multiplicaton.\n");

  char_array[0] * char_array[0];
  printf("OK. Char array element multiplicaton.\n");

  'a' * 'b';
  printf("OK. Costant Char multiplicaton.\n");

  int_fun() * char_fun();
  printf("OK. Function calls multiplicaton.\n");

  (1+10/10) * (1-10%10);
  printf("OK. Operations multiplicaton.\n");

  ++int_var * --char_var;
  printf("OK. Pre increment and decrement multiplicaton.\n");

  int_var++ * char_var--;
  printf("OK. Post increment and decrement multiplication.\n");

  (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20) * (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Comparison multiplication.\n");


  return 0;
}

int main(){

  test();

  return 0;
}
