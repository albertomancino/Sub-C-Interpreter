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


  //// array identifier || ////
  // array identifier || 0
  x = int_vec || 0;
  --ST
  // array identifier || 1
  x = int_vec || 1;
  --ST
  // array identifier || costant positive integer
  x = int_vec || 10;
  --ST
  // array identifier || costant negative integer
  x = int_vec || -1;
  --ST
  // array identifier || int identifier (1)
  x = int_vec || pos;
  --ST
  // array identifier || int identifier (0)
  x = int_vec || neg;
  --ST
  // array identifier || int identifier
  x = int_vec || int_var;
  --ST
  // array identifier || char identifier
  x = int_vec || char_var;
  --ST
  // array identifier || int array element
  x = int_vec || int_vec[1];
  --ST
  // array identifier || char array element
  x = int_vec || char_vec[1];
  --ST
  // array identifier || int array identifier
  x = int_vec || int_vec;
  --ST
  // array identifier || char array identifier
  x = int_vec || char_vec;
  --ST
  // array identifier || string
  x = int_vec || "hello world";
  --ST
  // array identifier || char
  x = int_vec || 's';
  --ST
  // array identifier || function call
  x = int_vec || fun0();
  --ST
  // array identifier || function call
  x = int_vec || fun1();
  --ST
  // array identifier || sum
  x = int_vec || 1 + 1;
  --ST
  // array identifier || dif
  x = int_vec || 1 - 1;
  --ST
  // array identifier || prod
  x = int_vec || 1 * 1;
  --ST
  // array identifier || div
  x = int_vec || 1 / 1;
  --ST
  // array identifier || mod
  x = int_vec || 1 % 1;
  --ST
  // array identifier || round parenthesis
  x = int_vec || (1-1);
  --ST
  // array identifier || comparison
  x = int_vec || 1 || 1;
  --ST
  // array identifier || increment
  x = int_vec || int_var++;
  --ST
  // array identifier || decrement
  x = int_vec || int_var--;
  --ST


  return 0;
}
