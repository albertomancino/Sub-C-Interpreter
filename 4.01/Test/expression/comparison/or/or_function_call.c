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

  value = int_fun() || 0;
  printf("OK. Int function call or 0 comparison. Value = %d.\n", value);

  value = int_fun() || 1;
  printf("OK. Int function call or 1 comparison. Value = %d.\n", value);

  value = int_fun() || 10;
  printf("OK. Int function call or costant positive integer comparison. Value = %d.\n", value);

  value = int_fun() || -1;
  printf("OK. Int function call or costant negative integer comparison. Value = %d.\n", value);

  value = int_fun() || int_var;
  printf("OK. Int function call or variable integer comparison. Value = %d.\n", value);

  value = int_fun() || char_var;
  printf("OK. Int function call or variable char comparison. Value = %d.\n", value);

  value = int_fun() || int_array[1];
  printf("OK. Int function call or int array element comparison. Value = %d.\n", value);

  value = int_fun() || char_array[1];
  printf("OK. Int function call or char array element comparison. Value = %d.\n", value);

  value = int_fun() || 'a';
  printf("OK. Int function call or costant char comparison. Value = %d.\n", value);

  value = int_fun() || int_fun();
  printf("OK. Int function call or int function call comparison. Value = %d.\n", value);

  value = int_fun() || char_fun();
  printf("OK. Int function call or char function call comparison. Value = %d.\n", value);

  value = int_fun() || (1+1*10/10%10);
  printf("OK. Int function call or costant operation comparison. Value = %d.\n", value);

  value = int_fun() || ++int_var;
  printf("OK. Int function call or pre increment comparison. Value = %d.\n", value);

  value = int_fun() || --int_var;
  printf("OK. Int function call or pre decrement comparison. Value = %d.\n", value);

  value = int_fun() || int_var++;
  printf("OK. Int function call or post increment comparison. Value = %d.\n", value);

  value = int_fun() || int_var--;
  printf("OK. Int function call or post decrement comparison. Value = %d.\n", value);

  value = int_fun() || (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Int function call or costant comparisons comparison. Value = %d.\n", value);

  value = char_fun() || 0;
  printf("OK. Char function call or 0 comparison. Value = %d.\n", value);

  value = char_fun() || 1;
  printf("OK. Char function call or 1 comparison. Value = %d.\n", value);

  value = char_fun() || 10;
  printf("OK. Char function call or costant positive integer comparison. Value = %d.\n", value);

  value = char_fun() || -1;
  printf("OK. Char function call or costant negative integer comparison. Value = %d.\n", value);

  value = char_fun() || int_var;
  printf("OK. Char function call or variable integer comparison. Value = %d.\n", value);

  value = char_fun() || char_var;
  printf("OK. Char function call or variable char comparison. Value = %d.\n", value);

  value = char_fun() || int_array[1];
  printf("OK. Char function call or int array element comparison. Value = %d.\n", value);

  value = char_fun() || char_array[1];
  printf("OK. Char function call or char array element comparison. Value = %d.\n", value);

  value = char_fun() || 'a';
  printf("OK. Char function call or costant char comparison. Value = %d.\n", value);

  value = char_fun() || int_fun();
  printf("OK. Char function call or int function call comparison. Value = %d.\n", value);

  value = char_fun() || char_fun();
  printf("OK. Char function call or char function call comparison. Value = %d.\n", value);

  value = char_fun() || (1+1*10/10%10);
  printf("OK. Char function call or costant operation comparison. Value = %d.\n", value);

  value = char_fun() || ++int_var;
  printf("OK. Char function call or pre increment comparison. Value = %d.\n", value);

  value = char_fun() || --int_var;
  printf("OK. Char function call or pre decrement comparison. Value = %d.\n", value);

  value = char_fun() || int_var++;
  printf("OK. Char function call or post increment comparison. Value = %d.\n", value);

  value = char_fun() || int_var--;
  printf("OK. Char function call or post decrement comparison. Value = %d.\n", value);

  value = char_fun() || (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Char function call or costant comparisons comparison. Value = %d.\n", value);

  return 0;
}

int main(){

  test();

  return 0;
}
