int test(){

  int int_var = 1;
  char char_var = 1;
  int int_array[3] = {1,2,3};
  char char_array[3] = {1,2,3};

  int_array + char_array;           // error
  &int_var + &char_var;             // error
  &int_array + &char_array;         // error
  &int_array[0] + &char_array[0];   // error
  "Hello" + "World";                // error

  int_array - char_array;           // error
  &int_var - &char_var;             // error
  &int_array - &char_array;         // error
  &int_array[0] - &char_array[0];   // error
  "Hello" - "World";                // error

  int_array * char_array;           // error
  &int_var * &char_var;             // error
  &int_array * &char_array;         // error
  &int_array[0] * &char_array[0];   // error
  "Hello" * "World";                // error

  int_array / char_array;           // error
  &int_var / &char_var;             // error
  &int_array / &char_array;         // error
  &int_array[0] / &char_array[0];   // error
  "Hello" / "World";                // error

  int_array % char_array;           // error
  &int_var % &char_var;             // error
  &int_array % &char_array;         // error
  &int_array[0] % &char_array[0];   // error
  "Hello" % "World";                // error


  return 0;
}

int main(){

  test();

  return 0;
}
