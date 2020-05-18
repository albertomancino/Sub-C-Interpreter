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

  value = 1 || 0;
  printf("OK. Costant 1 or 0 comparison. Value = %d.\n", value);

  value = 1 || 1;
  printf("OK. Costant 1 or 1 comparison. Value = %d.\n", value);

  value = 1 || 10;
  printf("OK. Costant 1 or costant positive integer comparison. Value = %d.\n", value);

  value = 1 || -1;
  printf("OK. Costant 1 or costant negative integer comparison. Value = %d.\n", value);

  value = 1 || int_var;
  printf("OK. Costant 1 or variable integer comparison. Value = %d.\n", value);

  value = 1 || char_var;
  printf("OK. Costant 1 or variable char comparison. Value = %d.\n", value);

  value = 1 || int_array[1];
  printf("OK. Costant 1 or int array element comparison. Value = %d.\n", value);

  value = 1 || char_array[1];
  printf("OK. Costant 1 or char array element comparison. Value = %d.\n", value);

  value = 1 || 'a';
  printf("OK. Costant 1 or costant char comparison. Value = %d.\n", value);

  value = 1 || int_fun();
  printf("OK. Costant 1 or int function call comparison. Value = %d.\n", value);

  value = 1 || char_fun();
  printf("OK. Costant 1 or char function call comparison. Value = %d.\n", value);

  value = 1 || (1+1*10/10%10);
  printf("OK. Costant 1 or costant operation comparison. Value = %d.\n", value);

  value = 1 || ++int_var;
  printf("OK. Costant 1 or pre increment comparison. Value = %d.\n", value);

  value = 1 || --int_var;
  printf("OK. Costant 1 or pre decrement comparison. Value = %d.\n", value);

  value = 1 || int_var++;
  printf("OK. Costant 1 or post increment comparison. Value = %d.\n", value);

  value = 1 || int_var--;
  printf("OK. Costant 1 or post decrement comparison. Value = %d.\n", value);

  value = 1 || (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Costant 1 or costant comparisons comparison. Value = %d.\n", value);

  return 0;
}

int main(){

  test();

  return 0;
}
