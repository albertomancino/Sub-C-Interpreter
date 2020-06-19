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

  value = ++int_var < 10;
  printf("OK. Pre increment less than costant positive integer comparison. Value = %d.\n", value);

  value = ++int_var < -1;
  printf("OK. Pre increment less than costant negative integer comparison. Value = %d.\n", value);

  value = ++int_var < int_var;
  printf("OK. Pre increment less than variable integer comparison. Value = %d.\n", value);

  value = ++int_var < char_var;
  printf("OK. Pre increment less than variable char comparison. Value = %d.\n", value);

  value = ++int_var < int_array[1];
  printf("OK. Pre increment less than int array element comparison. Value = %d.\n", value);

  value = ++int_var < char_array[1];
  printf("OK. Pre increment less than char array element comparison. Value = %d.\n", value);

  value = ++int_var < 'a';
  printf("OK. Pre increment less than costant char comparison. Value = %d.\n", value);

  value = ++int_var < int_fun();
  printf("OK. Pre increment less than int function call comparison. Value = %d.\n", value);

  value = ++int_var < char_fun();
  printf("OK. Pre increment less than char function call comparison. Value = %d.\n", value);

  value = ++int_var < (1+1*10/10%10);
  printf("OK. Pre increment less than costant operation comparison. Value = %d.\n", value);

  value = ++int_var < ++int_var;
  printf("OK. Pre increment less than pre increment comparison. Value = %d.\n", value);

  value = ++int_var < --int_var;
  printf("OK. Pre increment less than pre decrement comparison. Value = %d.\n", value);

  value = ++int_var < int_var++;
  printf("OK. Pre increment less than post increment comparison. Value = %d.\n", value);

  value = ++int_var < int_var--;
  printf("OK. Pre increment less than post decrement comparison. Value = %d.\n", value);

  value = ++int_var < (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Pre increment less than costant comparisons comparison. Value = %d.\n", value);

  value = --int_var < 10;
  printf("OK. Pre decrement less than costant positive integer comparison. Value = %d.\n", value);

  value = --int_var < -1;
  printf("OK. Pre decrement less than costant negative integer comparison. Value = %d.\n", value);

  value = --int_var < int_var;
  printf("OK. Pre decrement less than variable integer comparison. Value = %d.\n", value);

  value = --int_var < char_var;
  printf("OK. Pre decrement less than variable char comparison. Value = %d.\n", value);

  value = --int_var < int_array[1];
  printf("OK. Pre decrement less than int array element comparison. Value = %d.\n", value);

  value = --int_var < char_array[1];
  printf("OK. Pre decrement less than char array element comparison. Value = %d.\n", value);

  value = --int_var < 'a';
  printf("OK. Pre decrement less than costant char comparison. Value = %d.\n", value);

  value = --int_var < int_fun();
  printf("OK. Pre decrement less than int function call comparison. Value = %d.\n", value);

  value = --int_var < char_fun();
  printf("OK. Pre decrement less than char function call comparison. Value = %d.\n", value);

  value = --int_var < (1+1*10/10%10);
  printf("OK. Pre decrement less than costant operation comparison. Value = %d.\n", value);

  value = --int_var < ++int_var;
  printf("OK. Pre decrement less than pre increment comparison. Value = %d.\n", value);

  value = --int_var < --int_var;
  printf("OK. Pre decrement less than pre decrement comparison. Value = %d.\n", value);

  value = --int_var < int_var++;
  printf("OK. Pre decrement less than post increment comparison. Value = %d.\n", value);

  value = --int_var < int_var--;
  printf("OK. Pre decrement less than post decrement comparison. Value = %d.\n", value);

  value = --int_var < (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Pre decrement less than costant comparisons comparison. Value = %d.\n", value);

  value = int_var++ < 10;
  printf("OK. Post increment less than costant positive integer comparison. Value = %d.\n", value);

  value = int_var++ < -1;
  printf("OK. Post increment less than costant negative integer comparison. Value = %d.\n", value);

  value = int_var++ < int_var;
  printf("OK. Post increment less than variable integer comparison. Value = %d.\n", value);

  value = int_var++ < char_var;
  printf("OK. Post increment less than variable char comparison. Value = %d.\n", value);

  value = int_var++ < int_array[1];
  printf("OK. Post increment less than int array element comparison. Value = %d.\n", value);

  value = int_var++ < char_array[1];
  printf("OK. Post increment less than char array element comparison. Value = %d.\n", value);

  value = int_var++ < 'a';
  printf("OK. Post increment less than costant char comparison. Value = %d.\n", value);

  value = int_var++ < int_fun();
  printf("OK. Post increment less than int function call comparison. Value = %d.\n", value);

  value = int_var++ < char_fun();
  printf("OK. Post increment less than char function call comparison. Value = %d.\n", value);

  value = int_var++ < (1+1*10/10%10);
  printf("OK. Post increment less than costant operation comparison. Value = %d.\n", value);

  value = int_var++ < ++int_var;
  printf("OK. Post increment less than pre increment comparison. Value = %d.\n", value);

  value = int_var++ < --int_var;
  printf("OK. Post increment less than pre decrement comparison. Value = %d.\n", value);

  value = int_var++ < int_var++;
  printf("OK. Post increment less than post increment comparison. Value = %d.\n", value);

  value = int_var++ < int_var--;
  printf("OK. Post increment less than post decrement comparison. Value = %d.\n", value);

  value = int_var++ < (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Post increment less than costant comparisons comparison. Value = %d.\n", value);

  value = int_var-- < 10;
  printf("OK. Post decrement less than costant positive integer comparison. Value = %d.\n", value);

  value = int_var-- < -1;
  printf("OK. Post decrement less than costant negative integer comparison. Value = %d.\n", value);

  value = int_var-- < int_var;
  printf("OK. Post decrement less than variable integer comparison. Value = %d.\n", value);

  value = int_var-- < char_var;
  printf("OK. Post decrement less than variable char comparison. Value = %d.\n", value);

  value = int_var-- < int_array[1];
  printf("OK. Post decrement less than int array element comparison. Value = %d.\n", value);

  value = int_var-- < char_array[1];
  printf("OK. Post decrement less than char array element comparison. Value = %d.\n", value);

  value = int_var-- < 'a';
  printf("OK. Post decrement less than costant char comparison. Value = %d.\n", value);

  value = int_var-- < int_fun();
  printf("OK. Post decrement less than int function call comparison. Value = %d.\n", value);

  value = int_var-- < char_fun();
  printf("OK. Post decrement less than char function call comparison. Value = %d.\n", value);

  value = int_var-- < (1+1*10/10%10);
  printf("OK. Post decrement less than costant operation comparison. Value = %d.\n", value);

  value = int_var-- < ++int_var;
  printf("OK. Post decrement less than pre increment comparison. Value = %d.\n", value);

  value = int_var-- < --int_var;
  printf("OK. Post decrement less than pre decrement comparison. Value = %d.\n", value);

  value = int_var-- < int_var++;
  printf("OK. Post decrement less than post increment comparison. Value = %d.\n", value);

  value = int_var-- < int_var--;
  printf("OK. Post decrement less than post decrement comparison. Value = %d.\n", value);

  value = int_var-- < (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Post decrement less than costant comparisons comparison. Value = %d.\n", value);


  return 0;
}

int main(){

  test();

  return 0;
}
