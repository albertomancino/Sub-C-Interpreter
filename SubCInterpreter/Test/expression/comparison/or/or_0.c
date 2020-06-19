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

  value = 0 || 0;
  printf("OK. Costant 0 or 0 comparison. Value %d.\n", value);

  value = 0 || 1;
  printf("OK. Costant 0 or 1 comparison. Value %d.\n", value);

  value = 0 || 10;
  printf("OK. Costant 0 or costant positive integer comparison. Value %d.\n", value);

  value = 0 || -1;
  printf("OK. Costant 0 or costant negative integer comparison. Value %d.\n", value);

  value = 0 || int_var;
  printf("OK. Costant 0 or variable integer comparison. Value %d.\n", value);

  value = 0 || char_var;
  printf("OK. Costant 0 or variable char comparison. Value %d.\n", value);

  value = 0 || int_array[1];
  printf("OK. Costant 0 or int array element comparison. Value %d.\n", value);

  value = 0 || char_array[1];
  printf("OK. Costant 0 or char array element comparison. Value %d.\n", value);

  value = 0 || 'a';
  printf("OK. Costant 0 or costant char comparison. Value %d.\n", value);

  value = 0 || int_fun();
  printf("OK. Costant 0 or int function call comparison. Value %d.\n", value);

  value = 0 || char_fun();
  printf("OK. Costant 0 or char function call comparison. Value %d.\n", value);

  value = 0 || (1+1*10/10%10);
  printf("OK. Costant 0 or costant operation comparison. Value %d.\n", value);

  value = 0 || ++int_var;
  printf("OK. Costant 0 or pre increment comparison. Value %d.\n", value);

  value = 0 || --int_var;
  printf("OK. Costant 0 or pre decrement comparison. Value %d.\n", value);

  value = 0 || int_var++;
  printf("OK. Costant 0 or post increment comparison. Value %d.\n", value);

  value = 0 || int_var--;
  printf("OK. Costant 0 or post decrement comparison. Value %d.\n", value);

  value = 0 || (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Costant 0 or costant comparisons comparison. Value %d.\n", value);

  return 0;
}

int main(){

  test();

  return 0;
}
