int int_fun(){

  return 0;
}

char char_fun(){

  return 'a';
}

int test(){

  int int_var = 1;
  char char_var = 1;
  int int_array[3] = {1,2,3};
  char char_array[3] = {1,2,3};

  int value;

  value = char_var == 10;
  printf("OK. Char variable equal to costant positive integer comparison. Value = %d.\n", value);

  value = char_var == -1;
  printf("OK. Char variable equal to costant negative integer comparison. Value = %d.\n", value);

  value = char_var == int_var;
  printf("OK. Char variable equal to variable integer comparison. Value = %d.\n", value);

  value = char_var == char_var;
  printf("OK. Char variable equal to variable char comparison. Value = %d.\n", value);

  value = char_var == int_array[1];
  printf("OK. Char variable equal to int array element comparison. Value = %d.\n", value);

  value = char_var == char_array[1];
  printf("OK. Char variable equal to char array element comparison. Value = %d.\n", value);

  value = char_var == 'a';
  printf("OK. Char variable equal to costant char comparison. Value = %d.\n", value);

  value = char_var == int_fun();
  printf("OK. Char variable equal to int function call comparison. Value = %d.\n", value);

  value = char_var == char_fun();
  printf("OK. Char variable equal to char function call comparison. Value = %d.\n", value);

  value = char_var == (1+1*10/10%10);
  printf("OK. Char variable equal to costant operation comparison. Value = %d.\n", value);

  value = char_var == ++int_var;
  printf("OK. Char variable equal to pre increment comparison. Value = %d.\n", value);

  value = char_var == --int_var;
  printf("OK. Char variable equal to pre decrement comparison. Value = %d.\n", value);

  value = char_var == int_var++;
  printf("OK. Char variable equal to post increment comparison. Value = %d.\n", value);

  value = char_var == int_var--;
  printf("OK. Char variable equal to post decrement comparison. Value = %d.\n", value);

  value = char_var == (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Char variable equal to costant comparisons comparison. Value = %d.\n", value);

  return 0;
}

int main(){

  test();

  return 0;
}
