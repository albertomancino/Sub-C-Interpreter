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


  //// function call ('s') == ////
  // function call == 0
  x = fun0() == 0;

  // function call == 1
  x = fun0() == 1;

  // function call == costant positive integer
  x = fun0() == 10;

  // function call == costant negative integer
  x = fun0() == -1;

  // function call == int identifier (1)
  x = fun0() == pos;

  // function call == int identifier (0)
  x = fun0() == neg;

  // function call == int identifier
  x = fun0() == int_var;

  // function call == char identifier
  x = fun0() == char_var;

  // function call == int array element
  x = fun0() == int_vec[1];

  // function call == char array element
  x = fun0() == char_vec[1];

  // function call == char
  x = fun0() == 's';

  // function call == function call
  x = fun0() == fun0();

  // function call == function call
  x = fun0() == fun1();

  // function call == sum
  x = fun0() == 1 + 1;

  // function call == dif
  x = fun0() == 1 - 1;

  // function call == prod
  x = fun0() == 1 * 1;

  // function call == div
  x = fun0() == 1 / 1;

  // function call == mod
  x = fun0() == 1 % 1;

  // function call == round parenthesis
  x = fun0() == (1-1);
  
  // function call == comparison
  x = fun0() == 1 == 1;

  // function call == increment
  x = fun0() == int_var++;

  // function call == decrement
  x = fun0() == int_var--;


  return 0;
}
