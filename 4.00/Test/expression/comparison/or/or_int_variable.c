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

  value = int_var || 0;
  printf("OK. Int variable or 0 comparison. Value = %d.\n", value);

  value = int_var || 1;
  printf("OK. Int variable or 1 comparison. Value = %d.\n", value);

  value = int_var || 10;
  printf("OK. Int variable or costant positive integer comparison. Value = %d.\n", value);

  value = int_var || -1;
  printf("OK. Int variable or costant negative integer comparison. Value = %d.\n", value);

  value = int_var || int_var;
  printf("OK. Int variable or variable integer comparison. Value = %d.\n", value);

  value = int_var || char_var;
  printf("OK. Int variable or variable char comparison. Value = %d.\n", value);

  value = int_var || int_array[1];
  printf("OK. Int variable or int array element comparison. Value = %d.\n", value);

  value = int_var || char_array[1];
  printf("OK. Int variable or char array element comparison. Value = %d.\n", value);

  value = int_var || 'a';
  printf("OK. Int variable or costant char comparison. Value = %d.\n", value);

  value = int_var || int_fun();
  printf("OK. Int variable or int function call comparison. Value = %d.\n", value);

  value = int_var || char_fun();
  printf("OK. Int variable or char function call comparison. Value = %d.\n", value);

  value = int_var || (1+1*10/10%10);
  printf("OK. Int variable or costant operation comparison. Value = %d.\n", value);

  value = int_var || ++int_var;
  printf("OK. Int variable or pre increment comparison. Value = %d.\n", value);

  value = int_var || --int_var;
  printf("OK. Int variable or pre decrement comparison. Value = %d.\n", value);

  value = int_var || int_var++;
  printf("OK. Int variable or post increment comparison. Value = %d.\n", value);

  value = int_var || int_var--;
  printf("OK. Int variable or post decrement comparison. Value = %d.\n", value);

  value = int_var || (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Int variable or costant comparisons comparison. Value = %d.\n", value);

  return 0;
}

int main(){

  test();

  return 0;
}
