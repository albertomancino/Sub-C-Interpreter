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

  //// 2147483647 == ////
  // 2147483647 == 0
  x = 2147483647 == 0;

  // 2147483647 == 1
  x = 2147483647 == 1;

  // 2147483647 == costant positive integer
  x = 2147483647 == 10;

  // 2147483647 == costant negative integer
  x = 2147483647 == -1;

  // 2147483647 == int identifier (1)
  x = 2147483647 == pos;

  // 2147483647 == int identifier (0)
  x = 2147483647 == neg;

  // 2147483647 == int identifier
  x = 2147483647 == int_var;

  // 2147483647 == char identifier
  x = 2147483647 == char_var;

  // 2147483647 == int array element
  x = 2147483647 == int_vec[1];

  // 2147483647 == char array element
  x = 2147483647 == char_vec[1];

  // 2147483647 == char
  x = 2147483647 == 's';

  // 2147483647 == function call
  x = 2147483647 == fun0();

  // 2147483647 == function call
  x = 2147483647 == fun1();

  // 2147483647 == sum
  x = 2147483647 == 1 + 1;

  //// 2147483647 == ////
  // 2147483647 == dif
  x = 2147483647 == 1 - 1;

  // 2147483647 == prod
  x = 2147483647 == 1 * 1;

  // 2147483647 == div
  x = 2147483647 == 1 / 1;

  // 2147483647 == mod
  x = 2147483647 == 1 % 1;

  // 2147483647 == round parenthesis
  x = 2147483647 == (1-1);

  // 2147483647 == comparison
  x = 2147483647 == 1 && 1;

  // 2147483647 == increment
  x = 2147483647 == int_var++;

  // 2147483647 == decrement
  x = 2147483647 == int_var--;



  return 0;
}
