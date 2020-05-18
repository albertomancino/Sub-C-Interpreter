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
  printf("OK. Pre increment equal to 0 comparison. Value = %d.\n", value);

  value = ++int_var || 1;
  printf("OK. Pre increment equal to 1 comparison. Value = %d.\n", value);

  value = ++int_var || 10;
  printf("OK. Pre increment equal to costant positive integer comparison. Value = %d.\n", value);

  value = ++int_var || -1;
  printf("OK. Pre increment equal to costant negative integer comparison. Value = %d.\n", value);

  value = ++int_var || int_var;
  printf("OK. Pre increment equal to variable integer comparison. Value = %d.\n", value);

  value = ++int_var || char_var;
  printf("OK. Pre increment equal to variable char comparison. Value = %d.\n", value);

  value = ++int_var || int_array[1];
  printf("OK. Pre increment equal to int array element comparison. Value = %d.\n", value);

  value = ++int_var || char_array[1];
  printf("OK. Pre increment equal to char array element comparison. Value = %d.\n", value);

  value = ++int_var || 'a';
  printf("OK. Pre increment equal to costant char comparison. Value = %d.\n", value);

  value = ++int_var || int_fun();
  printf("OK. Pre increment equal to int function call comparison. Value = %d.\n", value);

  value = ++int_var || char_fun();
  printf("OK. Pre increment equal to char function call comparison. Value = %d.\n", value);

  value = ++int_var || (1+1*10/10%10);
  printf("OK. Pre increment equal to costant operation comparison. Value = %d.\n", value);

  value = ++int_var || ++int_var;
  printf("OK. Pre increment equal to pre increment comparison. Value = %d.\n", value);

  value = ++int_var || --int_var;
  printf("OK. Pre increment equal to pre decrement comparison. Value = %d.\n", value);

  value = ++int_var || int_var++;
  printf("OK. Pre increment equal to post increment comparison. Value = %d.\n", value);

  value = ++int_var || int_var--;
  printf("OK. Pre increment equal to post decrement comparison. Value = %d.\n", value);

  value = ++int_var || (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Pre increment equal to costant comparisons comparison. Value = %d.\n", value);

  value = --int_var || 0;
  printf("OK. Pre decrement equal to 0 comparison. Value = %d.\n", value);

  value = --int_var || 1;
  printf("OK. Pre decrement equal to 1 comparison. Value = %d.\n", value);

  value = --int_var || 10;
  printf("OK. Pre decrement equal to costant positive integer comparison. Value = %d.\n", value);

  value = --int_var || -1;
  printf("OK. Pre decrement equal to costant negative integer comparison. Value = %d.\n", value);

  value = --int_var || int_var;
  printf("OK. Pre decrement equal to variable integer comparison. Value = %d.\n", value);

  value = --int_var || char_var;
  printf("OK. Pre decrement equal to variable char comparison. Value = %d.\n", value);

  value = --int_var || int_array[1];
  printf("OK. Pre decrement equal to int array element comparison. Value = %d.\n", value);

  value = --int_var || char_array[1];
  printf("OK. Pre decrement equal to char array element comparison. Value = %d.\n", value);

  value = --int_var || 'a';
  printf("OK. Pre decrement equal to costant char comparison. Value = %d.\n", value);

  value = --int_var || int_fun();
  printf("OK. Pre decrement equal to int function call comparison. Value = %d.\n", value);

  value = --int_var || char_fun();
  printf("OK. Pre decrement equal to char function call comparison. Value = %d.\n", value);

  value = --int_var || (1+1*10/10%10);
  printf("OK. Pre decrement equal to costant operation comparison. Value = %d.\n", value);

  value = --int_var || ++int_var;
  printf("OK. Pre decrement equal to pre increment comparison. Value = %d.\n", value);

  value = --int_var || --int_var;
  printf("OK. Pre decrement equal to pre decrement comparison. Value = %d.\n", value);

  value = --int_var || int_var++;
  printf("OK. Pre decrement equal to post increment comparison. Value = %d.\n", value);

  value = --int_var || int_var--;
  printf("OK. Pre decrement equal to post decrement comparison. Value = %d.\n", value);

  value = --int_var || (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Pre decrement equal to costant comparisons comparison. Value = %d.\n", value);

  value = int_var++ || 0;
  printf("OK. Post increment equal to 0 comparison. Value = %d.\n", value);

  value = int_var++ || 1;
  printf("OK. Post increment equal to 1 comparison. Value = %d.\n", value);

  value = int_var++ || 10;
  printf("OK. Post increment equal to costant positive integer comparison. Value = %d.\n", value);

  value = int_var++ || -1;
  printf("OK. Post increment equal to costant negative integer comparison. Value = %d.\n", value);

  value = int_var++ || int_var;
  printf("OK. Post increment equal to variable integer comparison. Value = %d.\n", value);

  value = int_var++ || char_var;
  printf("OK. Post increment equal to variable char comparison. Value = %d.\n", value);

  value = int_var++ || int_array[1];
  printf("OK. Post increment equal to int array element comparison. Value = %d.\n", value);

  value = int_var++ || char_array[1];
  printf("OK. Post increment equal to char array element comparison. Value = %d.\n", value);

  value = int_var++ || 'a';
  printf("OK. Post increment equal to costant char comparison. Value = %d.\n", value);

  value = int_var++ || int_fun();
  printf("OK. Post increment equal to int function call comparison. Value = %d.\n", value);

  value = int_var++ || char_fun();
  printf("OK. Post increment equal to char function call comparison. Value = %d.\n", value);

  value = int_var++ || (1+1*10/10%10);
  printf("OK. Post increment equal to costant operation comparison. Value = %d.\n", value);

  value = int_var++ || ++int_var;
  printf("OK. Post increment equal to pre increment comparison. Value = %d.\n", value);

  value = int_var++ || --int_var;
  printf("OK. Post increment equal to pre decrement comparison. Value = %d.\n", value);

  value = int_var++ || int_var++;
  printf("OK. Post increment equal to post increment comparison. Value = %d.\n", value);

  value = int_var++ || int_var--;
  printf("OK. Post increment equal to post decrement comparison. Value = %d.\n", value);

  value = int_var++ || (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Post increment equal to costant comparisons comparison. Value = %d.\n", value);

  value = int_var-- || 0;
  printf("OK. Post decrement equal to 0 comparison. Value = %d.\n", value);

  value = int_var-- || 1;
  printf("OK. Post decrement equal to 1 comparison. Value = %d.\n", value);

  value = int_var-- || 10;
  printf("OK. Post decrement equal to costant positive integer comparison. Value = %d.\n", value);

  value = int_var-- || -1;
  printf("OK. Post decrement equal to costant negative integer comparison. Value = %d.\n", value);

  value = int_var-- || int_var;
  printf("OK. Post decrement equal to variable integer comparison. Value = %d.\n", value);

  value = int_var-- || char_var;
  printf("OK. Post decrement equal to variable char comparison. Value = %d.\n", value);

  value = int_var-- || int_array[1];
  printf("OK. Post decrement equal to int array element comparison. Value = %d.\n", value);

  value = int_var-- || char_array[1];
  printf("OK. Post decrement equal to char array element comparison. Value = %d.\n", value);

  value = int_var-- || 'a';
  printf("OK. Post decrement equal to costant char comparison. Value = %d.\n", value);

  value = int_var-- || int_fun();
  printf("OK. Post decrement equal to int function call comparison. Value = %d.\n", value);

  value = int_var-- || char_fun();
  printf("OK. Post decrement equal to char function call comparison. Value = %d.\n", value);

  value = int_var-- || (1+1*10/10%10);
  printf("OK. Post decrement equal to costant operation comparison. Value = %d.\n", value);

  value = int_var-- || ++int_var;
  printf("OK. Post decrement equal to pre increment comparison. Value = %d.\n", value);

  value = int_var-- || --int_var;
  printf("OK. Post decrement equal to pre decrement comparison. Value = %d.\n", value);

  value = int_var-- || int_var++;
  printf("OK. Post decrement equal to post increment comparison. Value = %d.\n", value);

  value = int_var-- || int_var--;
  printf("OK. Post decrement equal to post decrement comparison. Value = %d.\n", value);

  value = int_var-- || (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Post decrement equal to costant comparisons comparison. Value = %d.\n", value);


  return 0;
}

int main(){

  test();

  return 0;
}
