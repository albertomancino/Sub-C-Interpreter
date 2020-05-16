int fun0(){

  return 0;
}

int fun1(){

  return 1;
}

int main(){

  int x;
  int pos;
  pos = 1;
  int neg;
  neg = 0;
  int int_var;
  int_var = 23;
  char char_var;
  char_var = 's';
  int int_vec[3];
  int_vec[1] = 10;
  char char_vec[3];
  char_vec[1] = 's';


  //// char identifier ('s') == ////
  // char identifier == 0
  x = char_var == 0;
  --ST
  // char identifier == 1
  x = char_var == 1;
  --ST
  // char identifier == costant positive integer
  x = char_var == 10;
  --ST
  // char identifier == costant negative integer
  x = char_var == -1;
  --ST
  // char identifier == int identifier (1)
  x = char_var == pos;
  --ST
  // char identifier == int identifier (0)
  x = char_var == neg;
  --ST
  // char identifier == int identifier
  x = char_var == int_var;
  --ST
  // char identifier == char identifier
  x = char_var == char_var;
  --ST
  // char identifier == int array element
  x = char_var == int_vec[1];
  --ST
  // char identifier == char array element
  x = char_var == char_vec[1];
  --ST
  // char identifier == char
  x = char_var == 's';
  --ST
  // char identifier == function call
  x = char_var == fun0();
  --ST
  // char identifier == function call
  x = char_var == fun1();
  --ST
  // char identifier == sum
  x = char_var == 1 + 1;
  --ST
  // char identifier == dif
  x = char_var == 1 - 1;
  --ST
  // char identifier == prod
  x = char_var == 1 * 1;
  --ST
  // char identifier == div
  x = char_var == 1 / 1;
  --ST
  // char identifier == mod
  x = char_var == 1 % 1;
  --ST
  // char identifier == round parenthesis
  x = char_var == (1-1);
  --ST
  // char identifier == comparison
  x = char_var == 1 == 1;
  --ST
  // char identifier == increment
  x = char_var == int_var++;
  --ST
  // char identifier == decrement
  x = char_var == int_var--;
  --ST

  return 0;
}
