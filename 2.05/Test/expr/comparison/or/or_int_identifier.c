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


  //// int identifier (1) || ////
  // int identifier || 0
  x = int_var || 0;
  --ST
  // int identifier || 1
  x = int_var || 1;
  --ST
  // int identifier || costant positive integer
  x = int_var || 10;
  --ST
  // int identifier || costant negative integer
  x = int_var || -1;
  --ST
  // int identifier || int identifier (1)
  x = int_var || pos;
  --ST
  // int identifier || int identifier (0)
  x = int_var || neg;
  --ST
  // int identifier || int identifier
  x = int_var || int_var;
  --ST
  // int identifier || char identifier
  x = int_var || char_var;
  --ST
  // int identifier || int array element
  x = int_var || int_vec[1];
  --ST
  // int identifier || char array element
  x = int_var || char_vec[1];
  --ST
  // int identifier || int array identifier
  x = int_var || int_vec;
  --ST
  // int identifier || char array identifier
  x = int_var || char_vec;
  --ST
  // int identifier || string
  x = int_var || "hello world";
  --ST
  // int identifier || char
  x = int_var || 's';
  --ST
  // int identifier || function call
  x = int_var || fun0();
  --ST
  // int identifier || function call
  x = int_var || fun1();
  --ST
  // int identifier || sum
  x = int_var || 1 + 1;
  --ST
  // int identifier || dif
  x = int_var || 1 - 1;
  --ST
  // int identifier || prod
  x = int_var || 1 * 1;
  --ST
  // int identifier || div
  x = int_var || 1 / 1;
  --ST
  // int identifier || mod
  x = int_var || 1 % 1;
  --ST
  // int identifier || round parenthesis
  x = int_var || (1-1);
  --ST
  // int identifier || comparison
  x = int_var || 1 || 1;
  --ST
  // int identifier || increment
  x = int_var || int_var++;
  --ST
  // int identifier || decrement
  x = int_var || int_var--;
  --ST


  return 0;
}
