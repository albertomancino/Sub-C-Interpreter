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


  //// int identifier (1) == ////
  // int identifier == 0
  x = int_var == 0;

  // int identifier == 1
  x = int_var == 1;

  // int identifier == costant positive integer
  x = int_var == 10;

  // int identifier == costant negative integer
  x = int_var == -1;

  // int identifier == int identifier (1)
  x = int_var == pos;

  // int identifier == int identifier (0)
  x = int_var == neg;

  // int identifier == int identifier
  x = int_var == int_var;

  // int identifier == char identifier
  x = int_var == char_var;

  // int identifier == int array element
  x = int_var == int_vec[1];

  // int identifier == char array element
  x = int_var == char_vec[1];

  // int identifier == char
  x = int_var == 's';

  // int identifier == function call
  x = int_var == fun0();

  // int identifier == function call
  x = int_var == fun1();

  // int identifier == sum
  x = int_var == 1 + 1;

  // int identifier == dif
  x = int_var == 1 - 1;

  // int identifier == prod
  x = int_var == 1 * 1;

  // int identifier == div
  x = int_var == 1 / 1;

  // int identifier == mod
  x = int_var == 1 % 1;

  // int identifier == round parenthesis
  x = int_var == (1-1);

  // int identifier == comparison
  x = int_var == 1 == 1;

  // int identifier == increment
  x = int_var == int_var++;

  // int identifier == decrement
  x = int_var == int_var--;
  


  return 0;
}
