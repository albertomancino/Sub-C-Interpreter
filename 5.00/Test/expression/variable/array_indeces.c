int int_fun(){

  return 0;
}

int char_fun(){

  return 0;
}

int test(){

  int int_var = 0;
  char char_var = 0;
  int int_array[3] = {1,2,3};
  char char_array[3] = {1,2,3};

  int_array[0];
  char_array[0];
  printf("OK. Costant integer index.\n");

  int_array[+1];
  char_array[+1];
  printf("OK. Costant positive integer index.\n");

  int_array[int_var];
  printf("OK. Integer variable index.\n");
  char_array[char_var];
  printf("OK. Char variable index.\n");

  int_array[int_array[0]];
  printf("OK. Integer array element index.\n");
  char_array[char_array[0]];
  printf("OK. Char array element index.\n");

  int_array['\1'];
  printf("OK. Costant char index.\n");
  char_array['\1'];
  printf("OK. Costant char index.\n");

  int_array[int_fun()];
  printf("OK. Integer function call index.\n");
  char_array[int_fun()];
  printf("OK. Integer function call index.\n");

  int_array[char_fun()];
  printf("OK. Char function call index.\n");
  char_array[char_fun()];
  printf("OK. Char function call index.\n");

  int_array[(1+1*10/10%10)];
  printf("OK. Operation index.\n");
  char_array[(1+1*10/10%10)];
  printf("OK. Operation index.\n");

  int_array[++int_var];
  printf("OK. Pre increment index.\n");
  char_array[++int_var];
  printf("OK. Pre increment index.\n");

  int_array[--int_var];
  printf("OK. Pre decrement index.\n");
  char_array[--int_var];
  printf("OK. Pre decrement index.\n");

  int_array[int_var++];
  printf("OK. Post increment index.\n");
  char_array[int_var++];
  printf("OK. Post increment  index.\n");

  int_array[int_var--];
  printf("OK. Post decrement index.\n");
  char_array[int_var--];
  printf("OK. Post decrement index.\n");

  int_array[(1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20)];
  printf("OK. Comparison index.\n");
  char_array[(1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20)];
  printf("OK. Comparison index.\n");

  return 0;
}

int main(){

  test();

  return 0;
}
