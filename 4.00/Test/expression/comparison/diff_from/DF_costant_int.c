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

  value = 10 != 10;
  printf("OK. Costant int different from costant positive comparison. Value %d.\n", value);

  value = 10 != -1;
  printf("OK. Costant int different from costant negative integer comparison. Value %d.\n", value);

  value = 10 != int_var;
  printf("OK. Costant int different from variable integer comparison. Value %d.\n", value);

  value = 10 != char_var;
  printf("OK. Costant int different from variable char comparison. Value %d.\n", value);

  value = 10 != int_array[1];
  printf("OK. Costant int different from int array element comparison. Value %d.\n", value);

  value = 10 != char_array[1];
  printf("OK. Costant int different from char array element comparison. Value %d.\n", value);

  value = 10 != 'a';
  printf("OK. Costant int different from costant char comparison. Value %d.\n", value);

  value = 10 != int_fun();
  printf("OK. Costant int different from int function call comparison. Value %d.\n", value);

  value = 10 != char_fun();
  printf("OK. Costant int different from char function call comparison. Value %d.\n", value);

  value = 10 != (1+1*10/10%10);
  printf("OK. Costant int different from costant operation comparison. Value %d.\n", value);

  value = 10 != ++int_var;
  printf("OK. Costant int different from pre increment comparison. Value %d.\n", value);

  value = 10 != --int_var;
  printf("OK. Costant int different from pre decrement comparison. Value %d.\n", value);

  value = 10 != int_var++;
  printf("OK. Costant int different from post increment comparison. Value %d.\n", value);

  value = 10 != int_var--;
  printf("OK. Costant int different from post decrement comparison. Value %d.\n", value);

  value = 10 != (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Costant int different from costant comparisons comparison. Value %d.\n", value);

  return 0;
}

int main(){

  test();

  return 0;
}
