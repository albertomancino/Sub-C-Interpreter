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


  (1);
  printf("OK. Costant integer in parenthesis.\n");

  (+1);
  printf("OK. Costant positive integer in parenthesis.\n");

  (-1);
  printf("OK. Costant negative integer in parenthesis.\n");

  (int_var);
  printf("OK. Integer variable in parenthesis.\n");

  (char_var);
  printf("OK. Char variable in parenthesis.\n");

  (int_array[0]);
  printf("OK. Integer array element variable in parenthesis.\n");

  (char_array[0]);
  printf("OK. Char array element in parenthesis.\n");

  ('b');
  printf("OK. Costant Char in parenthesis.\n");

  (char_fun());
  printf("OK. Function calls in parenthesis.\n");

  (1-10%10);
  printf("OK. Operations in parenthesis.\n");

  (--char_var);
  printf("OK. Pre increment and decrement in parenthesis.\n");

  (char_var--);
  printf("OK. Post increment and decrement in parenthesis.\n");

  ((1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20));
  printf("OK. Comparison in parenthesis.\n");

  (int_array);
  printf("OK. Array pointer in parenthesis.\n");

  (&int_var);
  printf("OK. Variable pointer in parenthesis.\n");

  (&int_array);
  printf("OK. Array pointer in parenthesis.\n");

  (&int_array[0]);
  printf("OK. Array element pointer in parenthesis.\n");


  return 0;
}

int main(){

  test();

  return 0;
}
