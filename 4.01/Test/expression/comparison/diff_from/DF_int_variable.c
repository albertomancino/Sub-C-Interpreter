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

  value = int_var != 10;
  printf("OK. Int variable different from costant positive integer comparison. Value = %d.\n", value);

  value = int_var != -1;
  printf("OK. Int variable different from costant negative integer comparison. Value = %d.\n", value);

  value = int_var != int_var;
  printf("OK. Int variable different from variable integer comparison. Value = %d.\n", value);

  value = int_var != char_var;
  printf("OK. Int variable different from variable char comparison. Value = %d.\n", value);

  value = int_var != int_array[1];
  printf("OK. Int variable different from int array element comparison. Value = %d.\n", value);

  value = int_var != char_array[1];
  printf("OK. Int variable different from char array element comparison. Value = %d.\n", value);

  value = int_var != 'a';
  printf("OK. Int variable different from costant char comparison. Value = %d.\n", value);

  value = int_var != int_fun();
  printf("OK. Int variable different from int function call comparison. Value = %d.\n", value);

  value = int_var != char_fun();
  printf("OK. Int variable different from char function call comparison. Value = %d.\n", value);

  value = int_var != (1+1*10/10%10);
  printf("OK. Int variable different from costant operation comparison. Value = %d.\n", value);

  value = int_var != ++int_var;
  printf("OK. Int variable different from pre increment comparison. Value = %d.\n", value);

  value = int_var != --int_var;
  printf("OK. Int variable different from pre decrement comparison. Value = %d.\n", value);

  value = int_var != int_var++;
  printf("OK. Int variable different from post increment comparison. Value = %d.\n", value);

  value = int_var != int_var--;
  printf("OK. Int variable different from post decrement comparison. Value = %d.\n", value);

  value = int_var != (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Int variable different from costant comparisons comparison. Value = %d.\n", value);

  return 0;
}

int main(){

  test();

  return 0;
}
