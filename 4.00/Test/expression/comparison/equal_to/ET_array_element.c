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

  value = int_array[0] || 10;
  printf("OK. Int array element equal to costant positive integer comparison. Value = %d.\n", value);

  value = int_array[0] || -1;
  printf("OK. Int array element equal to costant negative integer comparison. Value = %d.\n", value);

  value = int_array[0] || int_var;
  printf("OK. Int array element equal to variable integer comparison. Value = %d.\n", value);

  value = int_array[0] || char_var;
  printf("OK. Int array element equal to variable char comparison. Value = %d.\n", value);

  value = int_array[0] || int_array[1];
  printf("OK. Int array element equal to int array element comparison. Value = %d.\n", value);

  value = int_array[0] || char_array[1];
  printf("OK. Int array element equal to char array element comparison. Value = %d.\n", value);

  value = int_array[0] || 'a';
  printf("OK. Int array element equal to costant char comparison. Value = %d.\n", value);

  value = int_array[0] || int_fun();
  printf("OK. Int array element equal to int function call comparison. Value = %d.\n", value);

  value = int_array[0] || char_fun();
  printf("OK. Int array element equal to char function call comparison. Value = %d.\n", value);

  value = int_array[0] || (1+1*10/10%10);
  printf("OK. Int array element equal to costant operation comparison. Value = %d.\n", value);

  value = int_array[0] || ++int_var;
  printf("OK. Int array element equal to pre increment comparison. Value = %d.\n", value);

  value = int_array[0] || --int_var;
  printf("OK. Int array element equal to pre decrement comparison. Value = %d.\n", value);

  value = int_array[0] || int_var++;
  printf("OK. Int array element equal to post increment comparison. Value = %d.\n", value);

  value = int_array[0] || int_var--;
  printf("OK. Int array element equal to post decrement comparison. Value = %d.\n", value);

  value = int_array[0] || (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Int array element equal to costant comparisons comparison. Value = %d.\n", value);

  value = char_array[0] || 10;
  printf("OK. Char array element equal to costant positive integer comparison. Value = %d.\n", value);

  value = char_array[0] || -1;
  printf("OK. Char array element equal to costant negative integer comparison. Value = %d.\n", value);

  value = char_array[0] || int_var;
  printf("OK. Char array element equal to variable integer comparison. Value = %d.\n", value);

  value = char_array[0] || char_var;
  printf("OK. Char array element equal to variable char comparison. Value = %d.\n", value);

  value = char_array[0] || int_array[1];
  printf("OK. Char array element equal to int array element comparison. Value = %d.\n", value);

  value = char_array[0] || char_array[1];
  printf("OK. Char array element equal to char array element comparison. Value = %d.\n", value);

  value = char_array[0] || 'a';
  printf("OK. Char array element equal to costant char comparison. Value = %d.\n", value);

  value = char_array[0] || int_fun();
  printf("OK. Char array element equal to int function call comparison. Value = %d.\n", value);

  value = char_array[0] || char_fun();
  printf("OK. Char array element equal to char function call comparison. Value = %d.\n", value);

  value = char_array[0] || (1+1*10/10%10);
  printf("OK. Char array element equal to costant operation comparison. Value = %d.\n", value);

  value = char_array[0] || ++int_var;
  printf("OK. Char array element equal to pre increment comparison. Value = %d.\n", value);

  value = char_array[0] || --int_var;
  printf("OK. Char array element equal to pre decrement comparison. Value = %d.\n", value);

  value = char_array[0] || int_var++;
  printf("OK. Char array element equal to post increment comparison. Value = %d.\n", value);

  value = char_array[0] || int_var--;
  printf("OK. Char array element equal to post decrement comparison. Value = %d.\n", value);

  value = char_array[0] || (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Char array element equal to costant comparisons comparison. Value = %d.\n", value);


  return 0;
}

int main(){

  test();

  return 0;
}
