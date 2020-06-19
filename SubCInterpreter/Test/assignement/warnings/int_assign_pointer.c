int test(){

  int x;
  int a;
  char b;
  int int_array[3] = {1,2,3};
  char char_array[3] = {1,2,3};

  x = int_array;
  x = char_array;
  x = &a;
  x = &b;
  x = &int_array;
  x = &char_array;
  x = "Hello World";

  return 0;
}

int main(){

  test();


  return 0;
}
