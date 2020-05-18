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

  0 && int_array;       // error
  0 && char_array;      // error
  0 && &int_var;        // error
  0 && &char_var;       // error
  0 && &int_array;      // error
  0 && &char_array;     // error
  0 && &int_array[0];   // error
  0 && &char_array[0];  // error
  0 && "hello world";   // error

  1 && int_array;       // error
  1 && char_array;      // error
  1 && &int_var;        // error
  1 && &char_var;       // error
  1 && &int_array;      // error
  1 && &char_array;     // error
  1 && &int_array[0];   // error
  1 && &char_array[0];  // error
  1 && "hello world";   // error

  int_var && int_array;       // error
  int_var && char_array;      // error
  int_var && &int_var;        // error
  int_var && &char_var;       // error
  int_var && &int_array;      // error
  int_var && &char_array;     // error
  int_var && &int_array[0];   // error
  int_var && &char_array[0];  // error
  int_var && "hello world";   // error

  char_var && int_array;       // error
  char_var && char_array;      // error
  char_var && &int_var;        // error
  char_var && &char_var;       // error
  char_var && &int_array;      // error
  char_var && &char_array;     // error
  char_var && &int_array[0];   // error
  char_var && &char_array[0];  // error
  char_var && "hello world";   // error

  int_array[0] && int_array;       // error
  int_array[0] && char_array;      // error
  int_array[0] && &int_var;        // error
  int_array[0] && &char_var;       // error
  int_array[0] && &int_array;      // error
  int_array[0] && &char_array;     // error
  int_array[0] && &int_array[0];   // error
  int_array[0] && &char_array[0];  // error
  int_array[0] && "hello world";   // error

  char_array[0] && int_array;       // error
  char_array[0] && char_array;      // error
  char_array[0] && &int_var;        // error
  char_array[0] && &char_var;       // error
  char_array[0] && &int_array;      // error
  char_array[0] && &char_array;     // error
  char_array[0] && &int_array[0];   // error
  char_array[0] && &char_array[0];  // error
  char_array[0] && "hello world";   // error

  return 0;
}

int main(){

  test();

  return 0;
}
