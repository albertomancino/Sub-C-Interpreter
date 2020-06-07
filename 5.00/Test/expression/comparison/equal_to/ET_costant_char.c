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

  value = 'a' == 10;
  printf("OK. Costant char equal to costant positive integer comparison. Value = %d.\n", value);

  value = 'a' == -1;
  printf("OK. Costant char equal to costant negative integer comparison. Value = %d.\n", value);

  value = 'a' == int_var;
  printf("OK. Costant char equal to variable integer comparison. Value = %d.\n", value);

  value = 'a' == char_var;
  printf("OK. Costant char equal to variable char comparison. Value = %d.\n", value);

  value = 'a' == int_array[1];
  printf("OK. Costant char equal to int array element comparison. Value = %d.\n", value);

  value = 'a' == char_array[1];
  printf("OK. Costant char equal to char array element comparison. Value = %d.\n", value);

  value = 'a' == 'a';
  printf("OK. Costant char equal to costant char comparison. Value = %d.\n", value);

  value = 'a' == int_fun();
  printf("OK. Costant char equal to int function call comparison. Value = %d.\n", value);

  value = 'a' == char_fun();
  printf("OK. Costant char equal to char function call comparison. Value = %d.\n", value);

  value = 'a' == (1+1*10/10%10);
  printf("OK. Costant char equal to costant operation comparison. Value = %d.\n", value);

  value = 'a' == ++int_var;
  printf("OK. Costant char equal to pre increment comparison. Value = %d.\n", value);

  value = 'a' == --int_var;
  printf("OK. Costant char equal to pre decrement comparison. Value = %d.\n", value);

  value = 'a' == int_var++;
  printf("OK. Costant char equal to post increment comparison. Value = %d.\n", value);

  value = 'a' == int_var--;
  printf("OK. Costant char equal to post decrement comparison. Value = %d.\n", value);

  value = 'a' == (1 && 1)||(10 > 5)||(10 < 5)||('a' == 10)||(10 != 20);
  printf("OK. Costant char equal to costant comparisons comparison. Value = %d.\n", value);

  return 0;
}

int main(){

  test();

  return 0;
}
