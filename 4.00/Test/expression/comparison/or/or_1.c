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


  //// 1 || ////
  // 1 || 0
  x = 1 || 0;
  --ST
  // 1 || 1
  x = 1 || 1;
  --ST
  // 1 || costant positive integer
  x = 1 || 10;
  --ST
  // 1 || costant negative integer
  x = 1 || -1;
  --ST
  // 1 || int identifier (1)
  x = 1 || pos;
  --ST
  // 1 || int identifier (0)
  x = 1 || neg;
  --ST
  // 1 || int identifier
  x = 1 || int_var;
  --ST
  // 1 || char identifier
  x = 1 || char_var;
  --ST
  // 1 || int array element
  x = 1 || int_vec[1];
  --ST
  // 1 || char array element
  x = 1 || char_vec[1];
  --ST
  // 1 || int array identifier
  x = 1 || int_vec;
  --ST
  // 1 || char array identifier
  x = 1 || char_vec;
  --ST
  // 1 || string
  x = 1 || "hello world";
  --ST
  // 1 || char
  x = 1 || 's';
  --ST
  // 1 || function call
  x = 1 || fun0();
  --ST
  // 1 || function call
  x = 1 || fun1();
  --ST
  // 1 || sum
  x = 1 || 1 + 1;
  --ST
  // 1 || dif
  x = 1 || 1 - 1;
  --ST
  // 1 || prod
  x = 1 || 1 * 1;
  --ST
  // 1 || div
  x = 1 || 1 / 1;
  --ST
  // 1 || mod
  x = 1 || 1 % 1;
  --ST
  // 1 || round parenthesis
  x = 1 || (1-1);
  --ST
  // 1 || comparison
  x = 1 || 1 || 1;
  --ST
  // 1 || increment
  x = 1 || int_var++;
  --ST
  // 1 || decrement
  x = 1 || int_var--;
  --ST


  return 0;
}
