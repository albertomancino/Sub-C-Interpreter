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

  1 || int_array;       // error
  1 || char_array;      // error
  1 || &int_var;        // error
  1 || &char_var;       // error
  1 || &int_array;      // error
  1 || &char_array;     // error
  1 || &int_array[0];   // error
  1 || &char_array[0];  // error
  1 || "hello world";   // error

  int_var == int_array;       // error
  int_var == char_array;      // error
  int_var == &int_var;        // error
  int_var == &char_var;       // error
  int_var == &int_array;      // error
  int_var == &char_array;     // error
  int_var == &int_array[0];   // error
  int_var == &char_array[0];  // error
  int_var == "hello world";   // error

  char_var != int_array;       // error
  char_var != char_array;      // error
  char_var != &int_var;        // error
  char_var != &char_var;       // error
  char_var != &int_array;      // error
  char_var != &char_array;     // error
  char_var != &int_array[0];   // error
  char_var != &char_array[0];  // error
  char_var != "hello world";   // error

  int_array[0] < int_array;       // error
  int_array[0] < char_array;      // error
  int_array[0] < &int_var;        // error
  int_array[0] < &char_var;       // error
  int_array[0] < &int_array;      // error
  int_array[0] < &char_array;     // error
  int_array[0] < &int_array[0];   // error
  int_array[0] < &char_array[0];  // error
  int_array[0] < "hello world";   // error

  char_array[0] > int_array;       // error
  char_array[0] > char_array;      // error
  char_array[0] > &int_var;        // error
  char_array[0] > &char_var;       // error
  char_array[0] > &int_array;      // error
  char_array[0] > &char_array;     // error
  char_array[0] > &int_array[0];   // error
  char_array[0] > &char_array[0];  // error
  char_array[0] > "hello world";   // error

  'a' && int_array;       // error
  'a' && char_array;      // error
  'a' && &int_var;        // error
  'a' && &char_var;       // error
  'a' && &int_array;      // error
  'a' && &char_array;     // error
  'a' && &int_array[0];   // error
  'a' && &char_array[0];  // error
  'a' && "hello world";   // error

  int_fun() && int_array;       // error
  int_fun() && char_array;      // error
  int_fun() && &int_var;        // error
  int_fun() && &char_var;       // error
  int_fun() && &int_array;      // error
  int_fun() && &char_array;     // error
  int_fun() && &int_array[0];   // error
  int_fun() && &char_array[0];  // error
  int_fun() && "hello world";   // error

  char_fun() || int_array;       // error
  char_fun() || char_array;      // error
  char_fun() || &int_var;        // error
  char_fun() || &char_var;       // error
  char_fun() || &int_array;      // error
  char_fun() || &char_array;     // error
  char_fun() || &int_array[0];   // error
  char_fun() || &char_array[0];  // error
  char_fun() || "hello world";   // error

  (1+1*10/10%10) == int_array;       // error
  (1+1*10/10%10) == char_array;      // error
  (1+1*10/10%10) == &int_var;        // error
  (1+1*10/10%10) == &char_var;       // error
  (1+1*10/10%10) == &int_array;      // error
  (1+1*10/10%10) == &char_array;     // error
  (1+1*10/10%10) == &int_array[0];   // error
  (1+1*10/10%10) == &char_array[0];  // error
  (1+1*10/10%10) == "hello world";   // error

  ++int_var != int_array;       // error
  ++int_var != char_array;      // error
  ++int_var != &int_var;        // error
  ++int_var != &char_var;       // error
  ++int_var != &int_array;      // error
  ++int_var != &char_array;     // error
  ++int_var != &int_array[0];   // error
  ++int_var != &char_array[0];  // error
  ++int_var != "hello world";   // error

  --int_var < int_array;       // error
  --int_var < char_array;      // error
  --int_var < &int_var;        // error
  --int_var < &char_var;       // error
  --int_var < &int_array;      // error
  --int_var < &char_array;     // error
  --int_var < &int_array[0];   // error
  --int_var < &char_array[0];  // error
  --int_var < "hello world";   // error

  int_var++ > int_array;       // error
  int_var++ > char_array;      // error
  int_var++ > &int_var;        // error
  int_var++ > &char_var;       // error
  int_var++ > &int_array;      // error
  int_var++ > &char_array;     // error
  int_var++ > &int_array[0];   // error
  int_var++ > &char_array[0];  // error
  int_var++ > "hello world";   /(1+1*10/10%10)

  int_var-- && int_array;       // error
  int_var-- && char_array;      // error
  int_var-- && &int_var;        // error
  int_var-- && &char_var;       // error
  int_var-- && &int_array;      // error
  int_var-- && &char_array;     // error
  int_var-- && &int_array[0];   // error
  int_var-- && &char_array[0];  // error
  int_var-- && "hello world";   // error

  (1 && 1)||(10 > 5)||(10 < 5)||('a' == 10)||(10 != 20) || int_array;       // error
  (1 && 1)||(10 > 5)||(10 < 5)||('a' == 10)||(10 != 20) || char_array;      // error
  (1 && 1)||(10 > 5)||(10 < 5)||('a' == 10)||(10 != 20) || &int_var;        // error
  (1 && 1)||(10 > 5)||(10 < 5)||('a' == 10)||(10 != 20) || &char_var;       // error
  (1 && 1)||(10 > 5)||(10 < 5)||('a' == 10)||(10 != 20) || &int_array;      // error
  (1 && 1)||(10 > 5)||(10 < 5)||('a' == 10)||(10 != 20) || &char_array;     // error
  (1 && 1)||(10 > 5)||(10 < 5)||('a' == 10)||(10 != 20) || &int_array[0];   // error
  (1 && 1)||(10 > 5)||(10 < 5)||('a' == 10)||(10 != 20) || &char_array[0];  // error
  (1 && 1)||(10 > 5)||(10 < 5)||('a' == 10)||(10 != 20) || "hello world";   // error


  return 0;
}

int main(){

  test();

}
