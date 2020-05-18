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

  value = int_array[0] > 10;
  printf("OK. Int array element greather than costant positive integer comparison. Value = %d.\n", value);

  value = int_array[0] > -1;
  printf("OK. Int array element greather than costant negative integer comparison. Value = %d.\n", value);

  value = int_array[0] > int_var;
  printf("OK. Int array element greather than variable integer comparison. Value = %d.\n", value);

  value = int_array[0] > char_var;
  printf("OK. Int array element greather than variable char comparison. Value = %d.\n", value);

  value = int_array[0] > int_array[1];
  printf("OK. Int array element greather than int array element comparison. Value = %d.\n", value);

  value = int_array[0] > char_array[1];
  printf("OK. Int array element greather than char array element comparison. Value = %d.\n", value);

  value = int_array[0] > 'a';
  printf("OK. Int array element greather than costant char comparison. Value = %d.\n", value);

  value = int_array[0] > int_fun();
  printf("OK. Int array element greather than int function call comparison. Value = %d.\n", value);

  value = int_array[0] > char_fun();
  printf("OK. Int array element greather than char function call comparison. Value = %d.\n", value);

  value = int_array[0] > (1+1*10/10%10);
  printf("OK. Int array element greather than costant operation comparison. Value = %d.\n", value);

  value = int_array[0] > ++int_var;
  printf("OK. Int array element greather than pre increment comparison. Value = %d.\n", value);

  value = int_array[0] > --int_var;
  printf("OK. Int array element greather than pre decrement comparison. Value = %d.\n", value);

  value = int_array[0] > int_var++;
  printf("OK. Int array element greather than post increment comparison. Value = %d.\n", value);

  value = int_array[0] > int_var--;
  printf("OK. Int array element greather than post decrement comparison. Value = %d.\n", value);

  value = int_array[0] > (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Int array element greather than costant comparisons comparison. Value = %d.\n", value);

  value = char_array[0] > 10;
  printf("OK. Char array element greather than costant positive integer comparison. Value = %d.\n", value);

  value = char_array[0] > -1;
  printf("OK. Char array element greather than costant negative integer comparison. Value = %d.\n", value);

  value = char_array[0] > int_var;
  printf("OK. Char array element greather than variable integer comparison. Value = %d.\n", value);

  value = char_array[0] > char_var;
  printf("OK. Char array element greather than variable char comparison. Value = %d.\n", value);

  value = char_array[0] > int_array[1];
  printf("OK. Char array element greather than int array element comparison. Value = %d.\n", value);

  value = char_array[0] > char_array[1];
  printf("OK. Char array element greather than char array element comparison. Value = %d.\n", value);

  value = char_array[0] > 'a';
  printf("OK. Char array element greather than costant char comparison. Value = %d.\n", value);

  value = char_array[0] > int_fun();
  printf("OK. Char array element greather than int function call comparison. Value = %d.\n", value);

  value = char_array[0] > char_fun();
  printf("OK. Char array element greather than char function call comparison. Value = %d.\n", value);

  value = char_array[0] > (1+1*10/10%10);
  printf("OK. Char array element greather than costant operation comparison. Value = %d.\n", value);

  value = char_array[0] > ++int_var;
  printf("OK. Char array element greather than pre increment comparison. Value = %d.\n", value);

  value = char_array[0] > --int_var;
  printf("OK. Char array element greather than pre decrement comparison. Value = %d.\n", value);

  value = char_array[0] > int_var++;
  printf("OK. Char array element greather than post increment comparison. Value = %d.\n", value);

  value = char_array[0] > int_var--;
  printf("OK. Char array element greather than post decrement comparison. Value = %d.\n", value);

  value = char_array[0] > (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Char array element greather than costant comparisons comparison. Value = %d.\n", value);


  return 0;
}

int main(){

  test();

  return 0;
}
