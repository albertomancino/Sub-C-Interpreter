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

  int value;

  value = (1);
  printf("OK. Costant integer in parenthesis. Value %d.\n", value);

  value = (+1);
  printf("OK. Costant positive integer in parenthesis. Value %d.\n", value);

  value = (-1);
  printf("OK. Costant negative integer in parenthesis. Value %d.\n", value);

  value = (int_var);
  printf("OK. Integer variable in parenthesis. Value %d.\n", value);

  value = (char_var);
  printf("OK. Char variable in parenthesis. Value %d.\n", value);

  value = (int_array[0]);
  printf("OK. Integer array element variable in parenthesis. Value %d.\n", value);

  value = (char_array[0]);
  printf("OK. Char array element in parenthesis. Value %d.\n", value);

  value = ('b');
  printf("OK. Costant Char in parenthesis. Value %d.\n", value);

  value = (char_fun());
  printf("OK. Function calls in parenthesis. Value %d.\n", value);

  value = (1-10%10);
  printf("OK. Operations in parenthesis. Value %d.\n", value);

  value = (--char_var);
  printf("OK. Pre increment and decrement in parenthesis. Value %d.\n", value);

  value = (char_var--);
  printf("OK. Post increment and decrement in parenthesis. Value %d.\n", value);

  value = ((1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20));
  printf("OK. Comparison in parenthesis. Value %d.\n", value);

  value = (int_array);
  printf("OK. Array pointer in parenthesis. Value %d.\n", value);

  value = (&int_var);
  printf("OK. Variable pointer in parenthesis. Value %d.\n", value);

  value = (&int_array);
  printf("OK. Array pointer in parenthesis. Value %d.\n", value);

  value = (&int_array[0]);
  printf("OK. Array element pointer in parenthesis. Value %d.\n", value);


  return 0;
}

int main(){

  test();

  return 0;
}
