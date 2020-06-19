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

  value = int_fun() > 10;
  printf("OK. Int function call greather than costant positive integer comparison. Value = %d.\n", value);

  value = int_fun() > -1;
  printf("OK. Int function call greather than costant negative integer comparison. Value = %d.\n", value);

  value = int_fun() > int_var;
  printf("OK. Int function call greather than variable integer comparison. Value = %d.\n", value);

  value = int_fun() > char_var;
  printf("OK. Int function call greather than variable char comparison. Value = %d.\n", value);

  value = int_fun() > int_array[1];
  printf("OK. Int function call greather than int array element comparison. Value = %d.\n", value);

  value = int_fun() > char_array[1];
  printf("OK. Int function call greather than char array element comparison. Value = %d.\n", value);

  value = int_fun() > 'a';
  printf("OK. Int function call greather than costant char comparison. Value = %d.\n", value);

  value = int_fun() > int_fun();
  printf("OK. Int function call greather than int function call comparison. Value = %d.\n", value);

  value = int_fun() > char_fun();
  printf("OK. Int function call greather than char function call comparison. Value = %d.\n", value);

  value = int_fun() > (1+1*10/10%10);
  printf("OK. Int function call greather than costant operation comparison. Value = %d.\n", value);

  value = int_fun() > ++int_var;
  printf("OK. Int function call greather than pre increment comparison. Value = %d.\n", value);

  value = int_fun() > --int_var;
  printf("OK. Int function call greather than pre decrement comparison. Value = %d.\n", value);

  value = int_fun() > int_var++;
  printf("OK. Int function call greather than post increment comparison. Value = %d.\n", value);

  value = int_fun() > int_var--;
  printf("OK. Int function call greather than post decrement comparison. Value = %d.\n", value);

  value = int_fun() > (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Int function call greather than costant comparisons comparison. Value = %d.\n", value);

  value = char_fun() > 10;
  printf("OK. Char function call greather than costant positive integer comparison. Value = %d.\n", value);

  value = char_fun() > -1;
  printf("OK. Char function call greather than costant negative integer comparison. Value = %d.\n", value);

  value = char_fun() > int_var;
  printf("OK. Char function call greather than variable integer comparison. Value = %d.\n", value);

  value = char_fun() > char_var;
  printf("OK. Char function call greather than variable char comparison. Value = %d.\n", value);

  value = char_fun() > int_array[1];
  printf("OK. Char function call greather than int array element comparison. Value = %d.\n", value);

  value = char_fun() > char_array[1];
  printf("OK. Char function call greather than char array element comparison. Value = %d.\n", value);

  value = char_fun() > 'a';
  printf("OK. Char function call greather than costant char comparison. Value = %d.\n", value);

  value = char_fun() > int_fun();
  printf("OK. Char function call greather than int function call comparison. Value = %d.\n", value);

  value = char_fun() > char_fun();
  printf("OK. Char function call greather than char function call comparison. Value = %d.\n", value);

  value = char_fun() > (1+1*10/10%10);
  printf("OK. Char function call greather than costant operation comparison. Value = %d.\n", value);

  value = char_fun() > ++int_var;
  printf("OK. Char function call greather than pre increment comparison. Value = %d.\n", value);

  value = char_fun() > --int_var;
  printf("OK. Char function call greather than pre decrement comparison. Value = %d.\n", value);

  value = char_fun() > int_var++;
  printf("OK. Char function call greather than post increment comparison. Value = %d.\n", value);

  value = char_fun() > int_var--;
  printf("OK. Char function call greather than post decrement comparison. Value = %d.\n", value);

  value = char_fun() > (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Char function call greather than costant comparisons comparison. Value = %d.\n", value);

  return 0;
}

int main(){

  test();

  return 0;
}
