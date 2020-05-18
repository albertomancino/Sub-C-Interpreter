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
  printf("OK. Pre increment and 0 comparison. Value = %d.\n", value);

  value = ++int_var || 1;
  printf("OK. Pre increment and 1 comparison. Value = %d.\n", value);

  value = ++int_var || 10;
  printf("OK. Pre increment and costant positive integer comparison. Value = %d.\n", value);

  value = ++int_var || -1;
  printf("OK. Pre increment and costant negative integer comparison. Value = %d.\n", value);

  value = ++int_var || int_var;
  printf("OK. Pre increment and variable integer comparison. Value = %d.\n", value);

  value = ++int_var || char_var;
  printf("OK. Pre increment and variable char comparison. Value = %d.\n", value);

  value = ++int_var || int_array[1];
  printf("OK. Pre increment and int array element comparison. Value = %d.\n", value);

  value = ++int_var || char_array[1];
  printf("OK. Pre increment and char array element comparison. Value = %d.\n", value);

  value = ++int_var || 'a';
  printf("OK. Pre increment and costant char comparison. Value = %d.\n", value);

  value = ++int_var || int_fun();
  printf("OK. Pre increment and int function call comparison. Value = %d.\n", value);

  value = ++int_var || char_fun();
  printf("OK. Pre increment and char function call comparison. Value = %d.\n", value);

  value = ++int_var || (1+1*10/10%10);
  printf("OK. Pre increment and costant operation comparison. Value = %d.\n", value);

  value = ++int_var || ++int_var;
  printf("OK. Pre increment and pre increment comparison. Value = %d.\n", value);

  value = ++int_var || --int_var;
  printf("OK. Pre increment and pre decrement comparison. Value = %d.\n", value);

  value = ++int_var || int_var++;
  printf("OK. Pre increment and post increment comparison. Value = %d.\n", value);

  value = ++int_var || int_var--;
  printf("OK. Pre increment and post decrement comparison. Value = %d.\n", value);

  value = ++int_var || (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Pre increment and costant comparisons comparison. Value = %d.\n", value);

  value = --int_var || 0;
  printf("OK. Pre decrement and 0 comparison. Value = %d.\n", value);

  value = --int_var || 1;
  printf("OK. Pre decrement and 1 comparison. Value = %d.\n", value);

  value = --int_var || 10;
  printf("OK. Pre decrement and costant positive integer comparison. Value = %d.\n", value);

  value = --int_var || -1;
  printf("OK. Pre decrement and costant negative integer comparison. Value = %d.\n", value);

  value = --int_var || int_var;
  printf("OK. Pre decrement and variable integer comparison. Value = %d.\n", value);

  value = --int_var || char_var;
  printf("OK. Pre decrement and variable char comparison. Value = %d.\n", value);

  value = --int_var || int_array[1];
  printf("OK. Pre decrement and int array element comparison. Value = %d.\n", value);

  value = --int_var || char_array[1];
  printf("OK. Pre decrement and char array element comparison. Value = %d.\n", value);

  value = --int_var || 'a';
  printf("OK. Pre decrement and costant char comparison. Value = %d.\n", value);

  value = --int_var || int_fun();
  printf("OK. Pre decrement and int function call comparison. Value = %d.\n", value);

  value = --int_var || char_fun();
  printf("OK. Pre decrement and char function call comparison. Value = %d.\n", value);

  value = --int_var || (1+1*10/10%10);
  printf("OK. Pre decrement and costant operation comparison. Value = %d.\n", value);

  value = --int_var || ++int_var;
  printf("OK. Pre decrement and pre increment comparison. Value = %d.\n", value);

  value = --int_var || --int_var;
  printf("OK. Pre decrement and pre decrement comparison. Value = %d.\n", value);

  value = --int_var || int_var++;
  printf("OK. Pre decrement and post increment comparison. Value = %d.\n", value);

  value = --int_var || int_var--;
  printf("OK. Pre decrement and post decrement comparison. Value = %d.\n", value);

  value = --int_var || (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Pre decrement and costant comparisons comparison. Value = %d.\n", value);

  value = int_var++ || 0;
  printf("OK. Post increment and 0 comparison. Value = %d.\n", value);

  value = int_var++ || 1;
  printf("OK. Post increment and 1 comparison. Value = %d.\n", value);

  value = int_var++ || 10;
  printf("OK. Post increment and costant positive integer comparison. Value = %d.\n", value);

  value = int_var++ || -1;
  printf("OK. Post increment and costant negative integer comparison. Value = %d.\n", value);

  value = int_var++ || int_var;
  printf("OK. Post increment and variable integer comparison. Value = %d.\n", value);

  value = int_var++ || char_var;
  printf("OK. Post increment and variable char comparison. Value = %d.\n", value);

  value = int_var++ || int_array[1];
  printf("OK. Post increment and int array element comparison. Value = %d.\n", value);

  value = int_var++ || char_array[1];
  printf("OK. Post increment and char array element comparison. Value = %d.\n", value);

  value = int_var++ || 'a';
  printf("OK. Post increment and costant char comparison. Value = %d.\n", value);

  value = int_var++ || int_fun();
  printf("OK. Post increment and int function call comparison. Value = %d.\n", value);

  value = int_var++ || char_fun();
  printf("OK. Post increment and char function call comparison. Value = %d.\n", value);

  value = int_var++ || (1+1*10/10%10);
  printf("OK. Post increment and costant operation comparison. Value = %d.\n", value);

  value = int_var++ || ++int_var;
  printf("OK. Post increment and pre increment comparison. Value = %d.\n", value);

  value = int_var++ || --int_var;
  printf("OK. Post increment and pre decrement comparison. Value = %d.\n", value);

  value = int_var++ || int_var++;
  printf("OK. Post increment and post increment comparison. Value = %d.\n", value);

  value = int_var++ || int_var--;
  printf("OK. Post increment and post decrement comparison. Value = %d.\n", value);

  value = int_var++ || (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Post increment and costant comparisons comparison. Value = %d.\n", value);

  value = int_var-- || 0;
  printf("OK. Post decrement and 0 comparison. Value = %d.\n", value);

  value = int_var-- || 1;
  printf("OK. Post decrement and 1 comparison. Value = %d.\n", value);

  value = int_var-- || 10;
  printf("OK. Post decrement and costant positive integer comparison. Value = %d.\n", value);

  value = int_var-- || -1;
  printf("OK. Post decrement and costant negative integer comparison. Value = %d.\n", value);

  value = int_var-- || int_var;
  printf("OK. Post decrement and variable integer comparison. Value = %d.\n", value);

  value = int_var-- || char_var;
  printf("OK. Post decrement and variable char comparison. Value = %d.\n", value);

  value = int_var-- || int_array[1];
  printf("OK. Post decrement and int array element comparison. Value = %d.\n", value);

  value = int_var-- || char_array[1];
  printf("OK. Post decrement and char array element comparison. Value = %d.\n", value);

  value = int_var-- || 'a';
  printf("OK. Post decrement and costant char comparison. Value = %d.\n", value);

  value = int_var-- || int_fun();
  printf("OK. Post decrement and int function call comparison. Value = %d.\n", value);

  value = int_var-- || char_fun();
  printf("OK. Post decrement and char function call comparison. Value = %d.\n", value);

  value = int_var-- || (1+1*10/10%10);
  printf("OK. Post decrement and costant operation comparison. Value = %d.\n", value);

  value = int_var-- || ++int_var;
  printf("OK. Post decrement and pre increment comparison. Value = %d.\n", value);

  value = int_var-- || --int_var;
  printf("OK. Post decrement and pre decrement comparison. Value = %d.\n", value);

  value = int_var-- || int_var++;
  printf("OK. Post decrement and post increment comparison. Value = %d.\n", value);

  value = int_var-- || int_var--;
  printf("OK. Post decrement and post decrement comparison. Value = %d.\n", value);

  value = int_var-- || (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Post decrement and costant comparisons comparison. Value = %d.\n", value);


  return 0;
}

int main(){

  test();

  return 0;
}
