int int_fun(){

  return 0;
}

int char_fun(){

  return 'a';
}

int test(){

  int int_var = 1;
  char char_var = 1;
  int int_array[3] = {1,2,3};
  char char_array[3] = {1,2,3};

  int value;

  value = 1 - 1;
  printf("OK. Costant integer subtraction. Value %d.\n", value);

  value = 1 - +1;
  printf("OK. Costant positive integer subtraction. Value %d.\n", value);

  value = 1 - -1;
  printf("OK. Costant negative integer subtraction. Value %d.\n", value);

  value = int_var - int_var;
  printf("OK. Integer variable subtraction. Value %d.\n", value);

  value = char_var - char_var;
  printf("OK. Char variable subtraction. Value %d.\n", value);

  value = int_array[0] - int_array[0];
  printf("OK. Integer array element variable subtraction. Value %d.\n", value);

  value = char_array[0] - char_array[0];
  printf("OK. Char array element subtraction. Value %d.\n", value);

  value = 'a' - 'b';
  printf("OK. Costant Char subtraction. Value %d.\n", value);

  value = int_fun() - char_fun();
  printf("OK. Function calls subtraction. Value %d.\n", value);

  value = (1+10/10) - (1-10%10);
  printf("OK. Operations subtraction. Value %d.\n", value);

  value = ++int_var - --char_var;
  printf("OK. Pre increment and decrement subtraction. Value %d.\n", value);

  value = int_var++ - char_var--;
  printf("OK. Post increment and decrement subtraction. Value %d.\n", value);

  value = (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20) - (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Comparison subtraction. Value %d.\n", value);


  return 0;
}

int main(){

  test();

  return 0;
}
