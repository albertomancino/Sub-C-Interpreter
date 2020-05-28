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

  value = 10 == 10;
  printf("OK. Costant int equal to costant positive comparison. Value %d.\n", value);

  value = 10 == -1;
  printf("OK. Costant int equal to costant negative integer comparison. Value %d.\n", value);

  value = 10 == int_var;
  printf("OK. Costant int equal to variable integer comparison. Value %d.\n", value);

  value = 10 == char_var;
  printf("OK. Costant int equal to variable char comparison. Value %d.\n", value);

  value = 10 == int_array[1];
  printf("OK. Costant int equal to int array element comparison. Value %d.\n", value);

  value = 10 == char_array[1];
  printf("OK. Costant int equal to char array element comparison. Value %d.\n", value);

  value = 10 == 'a';
  printf("OK. Costant int equal to costant char comparison. Value %d.\n", value);

  value = 10 == int_fun();
  printf("OK. Costant int equal to int function call comparison. Value %d.\n", value);

  value = 10 == char_fun();
  printf("OK. Costant int equal to char function call comparison. Value %d.\n", value);

  value = 10 == (1+1*10/10%10);
  printf("OK. Costant int equal to costant operation comparison. Value %d.\n", value);

  value = 10 == ++int_var;
  printf("OK. Costant int equal to pre increment comparison. Value %d.\n", value);

  value = 10 == --int_var;
  printf("OK. Costant int equal to pre decrement comparison. Value %d.\n", value);

  value = 10 == int_var++;
  printf("OK. Costant int equal to post increment comparison. Value %d.\n", value);

  value = 10 == int_var--;
  printf("OK. Costant int equal to post decrement comparison. Value %d.\n", value);

  value = 10 == (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Costant int equal to costant comparisons comparison. Value %d.\n", value);

  return 0;
}

int main(){

  test();

  return 0;
}
