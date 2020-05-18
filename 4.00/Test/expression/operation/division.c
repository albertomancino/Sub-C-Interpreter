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


  1 / 1;
  printf("OK. Costant integer division.\n");

  1 / +1;
  printf("OK. Costant positive integer division.\n");

  1 / -1;
  printf("OK. Costant negative integer division.\n");

  int_var / int_var;
  printf("OK. Integer variable division.\n");

  char_var / char_var;
  printf("OK. Char variable division.\n");

  int_array[0] / int_array[0];
  printf("OK. Integer array element variable division.\n");

  char_array[0] / char_array[0];
  printf("OK. Char array element division.\n");

  'a' / 'b';
  printf("OK. Costant Char division.\n");

  int_fun() / char_fun();
  printf("OK. Function calls division.\n");

  (1+10/10) / (1-10%10);
  printf("OK. Operations division.\n");

  ++int_var / --char_var;
  printf("OK. Pre increment and decrement division.\n");

  int_var++ / char_var--;
  printf("OK. Post increment and decrement division.\n");

  (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20) / (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Comparison division.\n");


  return 0;
}

int main(){

  test();

  return 0;
}
