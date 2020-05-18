int int_fun(){

  return 0;
}

int char_fun(){

  return 'a';
}

int test(){

  int int_var = 1;
  char char_var = 2;
  int int_array[3] = {1,2,3};
  char char_array[3] = {1,2,3};

  int value;

  value = 1 / 1;
  printf("OK. Costant integer division. Value %d.\n", value);

  value = 1 / +1;
  printf("OK. Costant positive integer division. Value %d.\n", value);

  value = 1 / -1;
  printf("OK. Costant negative integer division. Value %d.\n", value);

  value = int_var / int_var;
  printf("OK. Integer variable division. Value %d.\n", value);

  value = char_var / char_var;
  printf("OK. Char variable division. Value %d.\n", value);

  value = int_array[0] / int_array[0];
  printf("OK. Integer array element variable division. Value %d.\n", value);

  value = char_array[0] / char_array[0];
  printf("OK. Char array element division. Value %d.\n", value);

  value = 'a' / 'b';
  printf("OK. Costant Char division. Value %d.\n", value);

  value = int_fun() / char_fun();
  printf("OK. Function calls division. Value %d.\n", value);

  value = (1+10/10) / (1-10%10);
  printf("OK. Operations division. Value %d.\n", value);

  value = ++int_var / --char_var;
  printf("OK. Pre increment and decrement division. Value %d.\n", value);

  value = int_var++ / char_var--;
  printf("OK. Post increment and decrement division. Value %d.\n", value);

  value = (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20) / (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Comparison division. Value %d.\n", value);


  return 0;
}

int main(){

  test();

  return 0;
}
