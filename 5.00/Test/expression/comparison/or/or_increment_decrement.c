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

  value = ++int_var || 0;
  printf("OK. Pre increment or 0 comparison. Value = %d.\n", value);

  value = ++int_var || 1;
  printf("OK. Pre increment or 1 comparison. Value = %d.\n", value);

  value = ++int_var || 10;
  printf("OK. Pre increment or costant positive integer comparison. Value = %d.\n", value);

  value = ++int_var || -1;
  printf("OK. Pre increment or costant negative integer comparison. Value = %d.\n", value);

  value = ++int_var || int_var;
  printf("OK. Pre increment or variable integer comparison. Value = %d.\n", value);

  value = ++int_var || char_var;
  printf("OK. Pre increment or variable char comparison. Value = %d.\n", value);

  value = ++int_var || int_array[1];
  printf("OK. Pre increment or int array element comparison. Value = %d.\n", value);

  value = ++int_var || char_array[1];
  printf("OK. Pre increment or char array element comparison. Value = %d.\n", value);

  value = ++int_var || 'a';
  printf("OK. Pre increment or costant char comparison. Value = %d.\n", value);

  value = ++int_var || int_fun();
  printf("OK. Pre increment or int function call comparison. Value = %d.\n", value);

  value = ++int_var || char_fun();
  printf("OK. Pre increment or char function call comparison. Value = %d.\n", value);

  value = ++int_var || (1+1*10/10%10);
  printf("OK. Pre increment or costant operation comparison. Value = %d.\n", value);

  value = ++int_var || ++int_var;
  printf("OK. Pre increment or pre increment comparison. Value = %d.\n", value);

  value = ++int_var || --int_var;
  printf("OK. Pre increment or pre decrement comparison. Value = %d.\n", value);

  value = ++int_var || int_var++;
  printf("OK. Pre increment or post increment comparison. Value = %d.\n", value);

  value = ++int_var || int_var--;
  printf("OK. Pre increment or post decrement comparison. Value = %d.\n", value);

  value = ++int_var || (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Pre increment or costant comparisons comparison. Value = %d.\n", value);

  value = --int_var || 0;
  printf("OK. Pre decrement or 0 comparison. Value = %d.\n", value);

  value = --int_var || 1;
  printf("OK. Pre decrement or 1 comparison. Value = %d.\n", value);

  value = --int_var || 10;
  printf("OK. Pre decrement or costant positive integer comparison. Value = %d.\n", value);

  value = --int_var || -1;
  printf("OK. Pre decrement or costant negative integer comparison. Value = %d.\n", value);

  value = --int_var || int_var;
  printf("OK. Pre decrement or variable integer comparison. Value = %d.\n", value);

  value = --int_var || char_var;
  printf("OK. Pre decrement or variable char comparison. Value = %d.\n", value);

  value = --int_var || int_array[1];
  printf("OK. Pre decrement or int array element comparison. Value = %d.\n", value);

  value = --int_var || char_array[1];
  printf("OK. Pre decrement or char array element comparison. Value = %d.\n", value);

  value = --int_var || 'a';
  printf("OK. Pre decrement or costant char comparison. Value = %d.\n", value);

  value = --int_var || int_fun();
  printf("OK. Pre decrement or int function call comparison. Value = %d.\n", value);

  value = --int_var || char_fun();
  printf("OK. Pre decrement or char function call comparison. Value = %d.\n", value);

  value = --int_var || (1+1*10/10%10);
  printf("OK. Pre decrement or costant operation comparison. Value = %d.\n", value);

  value = --int_var || ++int_var;
  printf("OK. Pre decrement or pre increment comparison. Value = %d.\n", value);

  value = --int_var || --int_var;
  printf("OK. Pre decrement or pre decrement comparison. Value = %d.\n", value);

  value = --int_var || int_var++;
  printf("OK. Pre decrement or post increment comparison. Value = %d.\n", value);

  value = --int_var || int_var--;
  printf("OK. Pre decrement or post decrement comparison. Value = %d.\n", value);

  value = --int_var || (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Pre decrement or costant comparisons comparison. Value = %d.\n", value);

  value = int_var++ || 0;
  printf("OK. Post increment or 0 comparison. Value = %d.\n", value);

  value = int_var++ || 1;
  printf("OK. Post increment or 1 comparison. Value = %d.\n", value);

  value = int_var++ || 10;
  printf("OK. Post increment or costant positive integer comparison. Value = %d.\n", value);

  value = int_var++ || -1;
  printf("OK. Post increment or costant negative integer comparison. Value = %d.\n", value);

  value = int_var++ || int_var;
  printf("OK. Post increment or variable integer comparison. Value = %d.\n", value);

  value = int_var++ || char_var;
  printf("OK. Post increment or variable char comparison. Value = %d.\n", value);

  value = int_var++ || int_array[1];
  printf("OK. Post increment or int array element comparison. Value = %d.\n", value);

  value = int_var++ || char_array[1];
  printf("OK. Post increment or char array element comparison. Value = %d.\n", value);

  value = int_var++ || 'a';
  printf("OK. Post increment or costant char comparison. Value = %d.\n", value);

  value = int_var++ || int_fun();
  printf("OK. Post increment or int function call comparison. Value = %d.\n", value);

  value = int_var++ || char_fun();
  printf("OK. Post increment or char function call comparison. Value = %d.\n", value);

  value = int_var++ || (1+1*10/10%10);
  printf("OK. Post increment or costant operation comparison. Value = %d.\n", value);

  value = int_var++ || ++int_var;
  printf("OK. Post increment or pre increment comparison. Value = %d.\n", value);

  value = int_var++ || --int_var;
  printf("OK. Post increment or pre decrement comparison. Value = %d.\n", value);

  value = int_var++ || int_var++;
  printf("OK. Post increment or post increment comparison. Value = %d.\n", value);

  value = int_var++ || int_var--;
  printf("OK. Post increment or post decrement comparison. Value = %d.\n", value);

  value = int_var++ || (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Post increment or costant comparisons comparison. Value = %d.\n", value);

  value = int_var-- || 0;
  printf("OK. Post decrement or 0 comparison. Value = %d.\n", value);

  value = int_var-- || 1;
  printf("OK. Post decrement or 1 comparison. Value = %d.\n", value);

  value = int_var-- || 10;
  printf("OK. Post decrement or costant positive integer comparison. Value = %d.\n", value);

  value = int_var-- || -1;
  printf("OK. Post decrement or costant negative integer comparison. Value = %d.\n", value);

  value = int_var-- || int_var;
  printf("OK. Post decrement or variable integer comparison. Value = %d.\n", value);

  value = int_var-- || char_var;
  printf("OK. Post decrement or variable char comparison. Value = %d.\n", value);

  value = int_var-- || int_array[1];
  printf("OK. Post decrement or int array element comparison. Value = %d.\n", value);

  value = int_var-- || char_array[1];
  printf("OK. Post decrement or char array element comparison. Value = %d.\n", value);

  value = int_var-- || 'a';
  printf("OK. Post decrement or costant char comparison. Value = %d.\n", value);

  value = int_var-- || int_fun();
  printf("OK. Post decrement or int function call comparison. Value = %d.\n", value);

  value = int_var-- || char_fun();
  printf("OK. Post decrement or char function call comparison. Value = %d.\n", value);

  value = int_var-- || (1+1*10/10%10);
  printf("OK. Post decrement or costant operation comparison. Value = %d.\n", value);

  value = int_var-- || ++int_var;
  printf("OK. Post decrement or pre increment comparison. Value = %d.\n", value);

  value = int_var-- || --int_var;
  printf("OK. Post decrement or pre decrement comparison. Value = %d.\n", value);

  value = int_var-- || int_var++;
  printf("OK. Post decrement or post increment comparison. Value = %d.\n", value);

  value = int_var-- || int_var--;
  printf("OK. Post decrement or post decrement comparison. Value = %d.\n", value);

  value = int_var-- || (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Post decrement or costant comparisons comparison. Value = %d.\n", value);


  return 0;
}

int main(){

  test();

  return 0;
}
