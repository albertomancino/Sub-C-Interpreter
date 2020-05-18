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


  //// string && ////
  // string && 0
  x = "hello world" && 0;
  --ST
  // string && 1
  x = "hello world" && 1;
  --ST
  // string && costant positive integer
  x = "hello world" && 10;
  --ST
  // string && costant negative integer
  x = "hello world" && -1;
  --ST
  // string && int identifier (1)
  x = "hello world" && pos;
  --ST
  // string && int identifier (0)
  x = "hello world" && neg;
  --ST
  // string && int identifier
  x = "hello world" && int_var;
  --ST
  // string && char identifier
  x = "hello world" && char_var;
  --ST
  // string && int array element
  x = "hello world" && int_vec[1];
  --ST
  // string && char array element
  x = "hello world" && char_vec[1];
  --ST
  // string && int array identifier
  x = "hello world" && int_vec;
  --ST
  // string && char array identifier
  x = "hello world" && char_vec;
  --ST
  // string && string
  x = "hello world" && "hello world";
  --ST
  // string && char
  x = "hello world" && 's';
  --ST
  // string && function call
  x = "hello world" && fun0();
  --ST
  // string && function call
  x = "hello world" && fun1();
  --ST
  // string && sum
  x = "hello world" && 1 + 1;
  --ST
  // string && dif
  x = "hello world" && 1 - 1;
  --ST
  // string && prod
  x = "hello world" && 1 * 1;
  --ST
  // string && div
  x = "hello world" && 1 / 1;
  --ST
  // string && mod
  x = "hello world" && 1 % 1;
  --ST
  // string && round parenthesis
  x = "hello world" && (1-1);
  --ST
  // string && comparison
  x = "hello world" && 1 && 1;
  --ST
  // string && increment
  x = "hello world" && int_var++;
  --ST
  // string && decrement
  x = "hello world" && int_var--;
  --ST


  return 0;
}
