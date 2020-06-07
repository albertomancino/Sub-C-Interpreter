int fun1(){

  printf("OK int function call.\n");

  return 1;
}

int fun2(int a, char b, int c[], char d[], int e[10], char f[10]){

  printf("OK int function int argument %d\n", a);
  printf("OK int function char argument %c\n", b);
  printf("OK int function int array with unspecified dimension argument %d\n", c[0]);
  printf("OK int function char array with unspecified dimension argument %c\n", d[0]);
  printf("OK int function int array with specified dimension argument %d\n", e[0]);
  printf("OK int function char array with specified dimension argument %c\n", f[0]);

  return 1;
}

char fun3(){

  printf("OK char function call.\n");

  return 1;
}

char fun4(int a, char b, int c[], char d[], int e[10], char f[10]){

  printf("OK char function int argument %d\n", a);
  printf("OK char function char argument %c\n", b);
  printf("OK char function int array with unspecified dimension argument %d\n", c[0]);
  printf("OK char function char array with unspecified dimension argument %c\n", d[0]);
  printf("OK char function int array with specified dimension argument %d\n", e[0]);
  printf("OK char function char array with specified dimension argument %c\n", f[0]);

  return 1;
}

int main(){

  int int_var = 10;
  char char_var = 'a';
  int int_array[5] = {1,2,3,4,5};
  char char_array[11] = {'H','e','l','l','o',' ','W','o','r','l','d'};

  fun1();
  fun2(int_var, char_var, int_array, "Hello World", int_array, char_array);
  fun3();
  fun4(int_var, char_var, int_array, "Hello World", int_array, char_array);

  return 0;
}
