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

  //// 0 && ////
  // 0 && 0
  x = 0 && 0;
  --ST
  // 0 && 1
  x = 0 && 1;
  --ST
  // 0 && costant positive integer
  x = 0 && 10;
  --ST
  // 0 && costant negative integer
  x = 0 && -1;
  --ST
  // 0 && int identifier (1)
  x = 0 && pos;
  --ST
  // 0 && int identifier (0)
  x = 0 && neg;
  --ST
  // 0 && int identifier
  x = 0 && int_var;
  --ST
  // 0 && char identifier
  x = 0 && char_var;
  --ST
  // 0 && int array element
  x = 0 && int_vec[1];
  --ST
  // 0 && char array element
  x = 0 && char_vec[1];
  --ST
  // 0 && int array identifier
  x = 0 && int_vec;
  --ST
  // 0 && char array identifier
  x = 0 && char_vec;
  --ST
  // 0 && string
  x = 0 && "hello world";
  --ST
  // 0 && char
  x = 0 && 's';
  --ST
  // 0 && function call
  x = 0 && fun0();
  --ST
  // 0 && function call
  x = 0 && fun1();
  --ST
  // 0 && sum
  x = 0 && 1 + 1;
  --ST
  // 0 && dif
  x = 0 && 1 - 1;
  --ST
  // 0 && prod
  x = 0 && 1 * 1;
  --ST
  // 0 && div
  x = 0 && 1 / 1;
  --ST
  // 0 && mod
  x = 0 && 1 % 1;
  --ST
  // 0 && round parenthesis
  x = 0 && (1-1);
  --ST
  // 0 && comparison
  x = 0 && 1 && 1;
  --ST
  // 0 && increment
  x = 0 && int_var++;
  --ST
  // 0 && decrement
  x = 0 && int_var--;
  --ST


  return 0;
}
