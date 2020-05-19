int fun_costant(char a, char b, char c){

  printf("\n");
  printf("OK. Costant positive integer: %d.\n", a);
  printf("OK. Costant negative integer: %d.\n", b);
  printf("OK. Costant char: %d.\n", c);

  return 0;
}

int fun_variable(char a, char b, char c, char d){

  printf("\n");
  printf("OK. Integer variable: %d.\n", a);
  printf("OK. Char variable: %d.\n", b);
  printf("OK. Integer array element: %d.\n", c);
  printf("OK. Char array element: %d.\n", d);

  return 0;
}

int fun_array_pointer(char a, char b){

  printf("\n");
  printf("OK. Int array pointer : %d.\n", a);
  printf("OK. Char array pointer: %d.\n", b);

  return 0;
}

int fun_string(char a){

  printf("\n");
  printf("OK. String pointer : %d.\n", a);

  return 0;
}

int fun_function_call(char a, char b){

  printf("\n");
  printf("OK. Int function call : %d.\n", a);
  printf("OK. Char function call : %d.\n", b);

  return 0;
}

int fun_operation(char a){

    printf("\n");
    printf("OK. Costant operation : %d.\n", a);

    return 0;
}

int fun_increment_decrement(char a, char b, char c, char d){

    printf("\n");
    printf("OK. Pre increment : %d.\n", a);
    printf("OK. Pre decrement : %d.\n", b);
    printf("OK. Post increment : %d.\n", c);
    printf("OK. Post decrement : %d.\n", d);

    return 0;
}

int fun_variable_pointers(char a, char b, char c, char d, char e, char f){

    printf("\n");
    printf("OK. Int variable pointer : %d.\n", a);
    printf("OK. Char variable pointer : %d.\n", b);
    printf("OK. Int array pointer : %d.\n", c);
    printf("OK. Char array pointer : %d.\n", d);
    printf("OK. Int array element pointer : %d.\n", e);
    printf("OK. Char array element pointer : %d.\n", f);

    return 0;
}

int intFun (){

  return 0;
}

char charFun (){

  return 'a';
}

int test(){

  int int_var = 1;
  char char_var = 1;
  int int_array[3] = {1,2,3};
  char char_array[3] = {1,2,3};

  fun_costant(30, -30, 'a');
  fun_variable(int_var, char_var, int_array[0], char_array[1]);
  //fun_array_pointer(int_array, char_array);  // error
  //fun_string("Hello World");  // error
  fun_function_call(intFun(), charFun());
  fun_operation(1+1*10/10%10);
  fun_increment_decrement(++int_var, --int_var, int_var++, int_var--);
  //fun_variable_pointers(&int_var, &char_var, &int_array, &char_array, &int_array[1], &char_array[1]);  // error

  return 0;
}

int main(){

  test();

  return 0;
}
