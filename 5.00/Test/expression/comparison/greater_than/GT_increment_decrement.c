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

  value = ++int_var > 10;
  printf("OK. Pre increment greather than costant positive integer comparison. Value = %d.\n", value);

  value = ++int_var > -1;
  printf("OK. Pre increment greather than costant negative integer comparison. Value = %d.\n", value);

  value = ++int_var > int_var;
  printf("OK. Pre increment greather than variable integer comparison. Value = %d.\n", value);

  value = ++int_var > char_var;
  printf("OK. Pre increment greather than variable char comparison. Value = %d.\n", value);

  value = ++int_var > int_array[1];
  printf("OK. Pre increment greather than int array element comparison. Value = %d.\n", value);

  value = ++int_var > char_array[1];
  printf("OK. Pre increment greather than char array element comparison. Value = %d.\n", value);

  value = ++int_var > 'a';
  printf("OK. Pre increment greather than costant char comparison. Value = %d.\n", value);

  value = ++int_var > int_fun();
  printf("OK. Pre increment greather than int function call comparison. Value = %d.\n", value);

  value = ++int_var > char_fun();
  printf("OK. Pre increment greather than char function call comparison. Value = %d.\n", value);

  value = ++int_var > (1+1*10/10%10);
  printf("OK. Pre increment greather than costant operation comparison. Value = %d.\n", value);

  value = ++int_var > ++int_var;
  printf("OK. Pre increment greather than pre increment comparison. Value = %d.\n", value);

  value = ++int_var > --int_var;
  printf("OK. Pre increment greather than pre decrement comparison. Value = %d.\n", value);

  value = ++int_var > int_var++;
  printf("OK. Pre increment greather than post increment comparison. Value = %d.\n", value);

  value = ++int_var > int_var--;
  printf("OK. Pre increment greather than post decrement comparison. Value = %d.\n", value);

  value = ++int_var > (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Pre increment greather than costant comparisons comparison. Value = %d.\n", value);

  value = --int_var > 10;
  printf("OK. Pre decrement greather than costant positive integer comparison. Value = %d.\n", value);

  value = --int_var > -1;
  printf("OK. Pre decrement greather than costant negative integer comparison. Value = %d.\n", value);

  value = --int_var > int_var;
  printf("OK. Pre decrement greather than variable integer comparison. Value = %d.\n", value);

  value = --int_var > char_var;
  printf("OK. Pre decrement greather than variable char comparison. Value = %d.\n", value);

  value = --int_var > int_array[1];
  printf("OK. Pre decrement greather than int array element comparison. Value = %d.\n", value);

  value = --int_var > char_array[1];
  printf("OK. Pre decrement greather than char array element comparison. Value = %d.\n", value);

  value = --int_var > 'a';
  printf("OK. Pre decrement greather than costant char comparison. Value = %d.\n", value);

  value = --int_var > int_fun();
  printf("OK. Pre decrement greather than int function call comparison. Value = %d.\n", value);

  value = --int_var > char_fun();
  printf("OK. Pre decrement greather than char function call comparison. Value = %d.\n", value);

  value = --int_var > (1+1*10/10%10);
  printf("OK. Pre decrement greather than costant operation comparison. Value = %d.\n", value);

  value = --int_var > ++int_var;
  printf("OK. Pre decrement greather than pre increment comparison. Value = %d.\n", value);

  value = --int_var > --int_var;
  printf("OK. Pre decrement greather than pre decrement comparison. Value = %d.\n", value);

  value = --int_var > int_var++;
  printf("OK. Pre decrement greather than post increment comparison. Value = %d.\n", value);

  value = --int_var > int_var--;
  printf("OK. Pre decrement greather than post decrement comparison. Value = %d.\n", value);

  value = --int_var > (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Pre decrement greather than costant comparisons comparison. Value = %d.\n", value);

  value = int_var++  > 10;
  printf("OK. Post increment greather than costant positive integer comparison. Value = %d.\n", value);

  value = int_var++  > -1;
  printf("OK. Post increment greather than costant negative integer comparison. Value = %d.\n", value);

  value = int_var++  > int_var;
  printf("OK. Post increment greather than variable integer comparison. Value = %d.\n", value);

  value = int_var++  > char_var;
  printf("OK. Post increment greather than variable char comparison. Value = %d.\n", value);

  value = int_var++  > int_array[1];
  printf("OK. Post increment greather than int array element comparison. Value = %d.\n", value);

  value = int_var++  > char_array[1];
  printf("OK. Post increment greather than char array element comparison. Value = %d.\n", value);

  value = int_var++  > 'a';
  printf("OK. Post increment greather than costant char comparison. Value = %d.\n", value);

  value = int_var++  > int_fun();
  printf("OK. Post increment greather than int function call comparison. Value = %d.\n", value);

  value = int_var++  > char_fun();
  printf("OK. Post increment greather than char function call comparison. Value = %d.\n", value);

  value = int_var++  > (1+1*10/10%10);
  printf("OK. Post increment greather than costant operation comparison. Value = %d.\n", value);

  value = int_var++  > ++int_var;
  printf("OK. Post increment greather than pre increment comparison. Value = %d.\n", value);

  value = int_var++  > --int_var;
  printf("OK. Post increment greather than pre decrement comparison. Value = %d.\n", value);

  value = int_var++  > int_var++;
  printf("OK. Post increment greather than post increment comparison. Value = %d.\n", value);

  value = int_var++  > int_var--;
  printf("OK. Post increment greather than post decrement comparison. Value = %d.\n", value);

  value = int_var++  > (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Post increment greather than costant comparisons comparison. Value = %d.\n", value);

  value = int_var-- > 10;
  printf("OK. Post decrement greather than costant positive integer comparison. Value = %d.\n", value);

  value = int_var-- > -1;
  printf("OK. Post decrement greather than costant negative integer comparison. Value = %d.\n", value);

  value = int_var-- > int_var;
  printf("OK. Post decrement greather than variable integer comparison. Value = %d.\n", value);

  value = int_var-- > char_var;
  printf("OK. Post decrement greather than variable char comparison. Value = %d.\n", value);

  value = int_var-- > int_array[1];
  printf("OK. Post decrement greather than int array element comparison. Value = %d.\n", value);

  value = int_var-- > char_array[1];
  printf("OK. Post decrement greather than char array element comparison. Value = %d.\n", value);

  value = int_var-- > 'a';
  printf("OK. Post decrement greather than costant char comparison. Value = %d.\n", value);

  value = int_var-- > int_fun();
  printf("OK. Post decrement greather than int function call comparison. Value = %d.\n", value);

  value = int_var-- > char_fun();
  printf("OK. Post decrement greather than char function call comparison. Value = %d.\n", value);

  value = int_var-- > (1+1*10/10%10);
  printf("OK. Post decrement greather than costant operation comparison. Value = %d.\n", value);

  value = int_var-- > ++int_var;
  printf("OK. Post decrement greather than pre increment comparison. Value = %d.\n", value);

  value = int_var-- > --int_var;
  printf("OK. Post decrement greather than pre decrement comparison. Value = %d.\n", value);

  value = int_var-- > int_var++;
  printf("OK. Post decrement greather than post increment comparison. Value = %d.\n", value);

  value = int_var-- > int_var--;
  printf("OK. Post decrement greather than post decrement comparison. Value = %d.\n", value);

  value = int_var-- > (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Post decrement greather than costant comparisons comparison. Value = %d.\n", value);


  return 0;
}

int main(){

  test();

  return 0;
}
