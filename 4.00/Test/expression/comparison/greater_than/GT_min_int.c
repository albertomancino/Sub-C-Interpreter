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

  value = -2147483648 > 10;
  printf("OK. Min int greather than costant positive comparison. Value %d.\n", value);

  value = -2147483648 > -1;
  printf("OK. Min int greather than costant negative integer comparison. Value %d.\n", value);

  value = -2147483648 > int_var;
  printf("OK. Min int greather than variable integer comparison. Value %d.\n", value);

  value = -2147483648 > char_var;
  printf("OK. Min int greather than variable char comparison. Value %d.\n", value);

  value = -2147483648 > int_array[1];
  printf("OK. Min int greather than int array element comparison. Value %d.\n", value);

  value = -2147483648 > char_array[1];
  printf("OK. Min int greather than char array element comparison. Value %d.\n", value);

  value = -2147483648 > 'a';
  printf("OK. Min int greather than costant char comparison. Value %d.\n", value);

  value = -2147483648 > int_fun();
  printf("OK. Min int greather than int function call comparison. Value %d.\n", value);

  value = -2147483648 > char_fun();
  printf("OK. Min int greather than char function call comparison. Value %d.\n", value);

  value = -2147483648 > (1+1*10/10%10);
  printf("OK. Min int greather than costant operation comparison. Value %d.\n", value);

  value = -2147483648 > ++int_var;
  printf("OK. Min int greather than pre increment comparison. Value %d.\n", value);

  value = -2147483648 > --int_var;
  printf("OK. Min int greather than pre decrement comparison. Value %d.\n", value);

  value = -2147483648 > int_var++;
  printf("OK. Min int greather than post increment comparison. Value %d.\n", value);

  value = -2147483648 > int_var--;
  printf("OK. Min int greather than post decrement comparison. Value %d.\n", value);

  value = -2147483648 > (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Min int greather than costant comparisons comparison. Value %d.\n", value);

  return 0;
}

int main(){

  test();

  return 0;
}
