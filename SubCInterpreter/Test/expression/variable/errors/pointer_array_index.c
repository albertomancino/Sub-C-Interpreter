int test(){

  int int_var = 0;
  char char_var = 0;
  int int_array[3] = {1,2,3};
  char char_array[3] = {1,2,3};

  int_array[int_array];
  printf("Integer array pointer index.\n");
  char_array[int_array];
  printf("Integer array pointer index.\n");

  int_array[char_array];
  printf("Char array pointer index.\n");
  char_array[char_array];
  printf("Char array pointer index.\n");

  int_array[&int_var];
  printf("Integer variable pointer index.\n");
  char_array[&int_var];
  printf("Integer variable pointer index.\n");

  int_array[&char_var];
  printf("Char variable pointer index.\n");
  char_array[&char_var];
  printf("Char variable pointer index.\n");

  int_array[&int_array];
  printf("Integer array pointer index.\n");
  char_array[&int_array];
  printf("Integer array pointer index.\n");

  int_array[&char_array];
  printf("Char array pointer index.\n");
  char_array[&char_array];
  printf("Char array pointer index.\n");

  int_array[&int_array[1]];
  printf("Integer array element pointer index.\n");
  char_array[&int_array[1]];
  printf("Integer array element pointer index.\n");

  int_array[&char_array[1]];
  printf("Char array element pointer index.\n");
  char_array[&char_array[1]];
  printf("Char array element pointer index.\n");

  int_array["Hello World"];
  printf("Char array element pointer index.\n");
  char_array["Hello World"];
  printf("Char array element pointer index.\n");

  return 0;
}

int main(){

  test();

  return 0;
}
