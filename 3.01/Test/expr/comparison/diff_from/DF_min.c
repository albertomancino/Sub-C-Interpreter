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

  //// -2147483648 != ////
  // -2147483648 != 0
  x = -2147483648 != 0;
  --ST
  // -2147483648 != 1
  x = -2147483648 != 1;
  --ST
  // -2147483648 != costant positive integer
  x = -2147483648 != 10;
  --ST
  // -2147483648 != costant negative integer
  x = -2147483648 != -1;
  --ST
  // -2147483648 != int identifier (1)
  x = -2147483648 != pos;
  --ST
  // -2147483648 != int identifier (0)
  x = -2147483648 != neg;
  --ST
  // -2147483648 != int identifier
  x = -2147483648 != int_var;
  --ST
  // -2147483648 != char identifier
  x = -2147483648 != char_var;
  --ST
  // -2147483648 != int array element
  x = -2147483648 != int_vec[1];
  --ST
  // -2147483648 != char array element
  x = -2147483648 != char_vec[1];
  --ST
  // -2147483648 != char
  x = -2147483648 != 's';
  --ST
  // -2147483648 != function call
  x = -2147483648 != fun0();
  --ST
  // -2147483648 != function call
  x = -2147483648 != fun1();
  --ST
  // -2147483648 != sum
  x = -2147483648 != 1 + 1;
  --ST
  // -2147483648 != dif
  x = -2147483648 != 1 - 1;
  --ST
  // -2147483648 != prod
  x = -2147483648 != 1 * 1;
  --ST
  // -2147483648 != div
  x = -2147483648 != 1 / 1;
  --ST
  // -2147483648 != mod
  x = -2147483648 != 1 % 1;
  --ST
  // -2147483648 != round parenthesis
  x = -2147483648 != (1-1);
  --ST
  // -2147483648 != comparison
  x = -2147483648 != 1 && 1;
  --ST
  // -2147483648 != increment
  x = -2147483648 != int_var++;
  --ST
  // -2147483648 != decrement
  x = -2147483648 != int_var--;
  --ST


  return 0;
}
