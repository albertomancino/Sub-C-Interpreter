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


  //// char identifier ('s') > ////
  // char identifier > 0
  x = char_var > 0;

  // char identifier > 1
  x = char_var > 1;

  // char identifier > costant positive integer
  x = char_var > 10;

  // char identifier > costant negative integer
  x = char_var > -1;

  // char identifier > int identifier (1)
  x = char_var > pos;

  // char identifier > int identifier (0)
  x = char_var > neg;

  // char identifier > int identifier
  x = char_var > int_var;

  // char identifier > char identifier
  x = char_var > char_var;

  // char identifier > int array element
  x = char_var > int_vec[1];

  // char identifier > char array element
  x = char_var > char_vec[1];

  // char identifier > char
  x = char_var > 's';

  // char identifier > function call
  x = char_var > fun0();

  // char identifier > function call
  x = char_var > fun1();

  // char identifier > sum
  x = char_var > 1 + 1;

  // char identifier > dif
  x = char_var > 1 - 1;

  // char identifier > prod
  x = char_var > 1 * 1;

  // char identifier > div
  x = char_var > 1 / 1;

  // char identifier > mod
  x = char_var > 1 % 1;

  // char identifier > round parenthesis
  x = char_var > (1-1);

  // char identifier > comparison
  x = char_var > 1 > 1;

  // char identifier > increment
  x = char_var > int_var++;

  // char identifier > decrement
  x = char_var > int_var--;


  return 0;
}
