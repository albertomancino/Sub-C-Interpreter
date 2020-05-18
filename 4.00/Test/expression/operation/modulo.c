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


  1 % 1;
  printf("OK. Costant integer modulo.\n");

  1 % +1;
  printf("OK. Costant positive integer modulo.\n");

  1 % -1;
  printf("OK. Costant negative integer modulo.\n");

  int_var % int_var;
  printf("OK. Integer variable modulo.\n");

  char_var % char_var;
  printf("OK. Char variable modulo.\n");

  int_array[0] % int_array[0];
  printf("OK. Integer array element variable modulo.\n");

  char_array[0] % char_array[0];
  printf("OK. Char array element modulo.\n");

  'a' % 'b';
  printf("OK. Costant Char modulo.\n");

  int_fun() % char_fun();
  printf("OK. Function calls modulo.\n");

  (1+10/10) % (1-10%10);
  printf("OK. Operations modulo.\n");

  ++int_var % --char_var;
  printf("OK. Pre increment and decrement modulo.\n");

  int_var++ % char_var--;
  printf("OK. Post increment and decrement modulo.\n");

  (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20) % (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Comparison modulo.\n");


  return 0;
}

int main(){

  test();

  return 0;
}
