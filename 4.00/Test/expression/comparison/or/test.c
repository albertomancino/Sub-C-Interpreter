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


  //// string || ////
  // string || 0
  x = "hello world" || 0;

  // string || 1
  x = "hello world" || 1;

  // string || costant positive integer
  x = "hello world" || 10;

  // string || costant negative integer
  x = "hello world" || -1;

  // string || int identifier (1)
  x = "hello world" || pos;

  // string || int identifier (0)
  x = "hello world" || neg;

  // string || int identifier
  x = "hello world" || int_var;

  // string || char identifier
  x = "hello world" || char_var;

  // string || int array element
  x = "hello world" || int_vec[1];

  // string || char array element
  x = "hello world" || char_vec[1];

  // string || int array identifier
  x = "hello world" || int_vec;

  // string || char array identifier
  x = "hello world" || char_vec;

  // string || string
  x = "hello world" || "hello world";

  // string || char
  x = "hello world" || 's';

  // string || function call
  x = "hello world" || fun0();

  // string || function call
  x = "hello world" || fun1();

  // string || sum
  x = "hello world" || 1 + 1;

  // string || dif
  x = "hello world" || 1 - 1;

  // string || prod
  x = "hello world" || 1 * 1;

  // string || div
  x = "hello world" || 1 / 1;

  // string || mod
  x = "hello world" || 1 % 1;

  // string || round parenthesis
  x = "hello world" || (1-1);

  // string || comparison
  x = "hello world" || 1 || 1;

  // string || increment
  x = "hello world" || int_var++;
  
  // string || decrement
  x = "hello world" || int_var--;



  return 0;
}
