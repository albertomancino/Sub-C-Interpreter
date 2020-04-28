int fun1(int a, int b){
  int c;
  c = a+b;
  return c;
}

char fun2(char a, char b){
  return a+b;
}

int main(){

  int a;
  char b;
  int c[10];
  char d[10];

  // INT ID = INT
  a = 1;
  // INT ID = ID
  a = a;
  a = b;
  // INT ID = VEC
  a = c[1];
  a = d[9];
  // INT ID = C
  a = 'c';
  // INT ID = INT FC
  a = fun1(1,2);
  // INT ID = CHAR FC
  a = fun2(1,2);
  // INT ID = SUM
  a = 1+2;
  // INT ID = DIF
  a = 1-2;
  // INT ID = TIM
  a = 1*2;
  // INT ID = DIV
  a = 1/2;
  // INT ID = MOD
  a = 1%2;
  // INT ID = RND
  a = (1);
  a = (a+b);
  // INT ID = CMP
  a = 1&&2;

  // CHAR ID = INT
  b = 1;
  // CHAR ID = ID
  b = a;
  b = b;
  // CHAR ID = VEC
  b = c[1];
  b = d[9];
  // CHAR ID = C
  b = 'c';
  // CHAR ID = INT FC
  b = fun1(1,2);
  // CHAR ID = CHAR FC
  b = fun2(1,2);
  // CHAR ID = SUM
  b = 1+2;
  // CHAR ID = DIF
  b = 1-2;
  // CHAR ID = TIM
  b = 1*2;
  // CHAR ID = DIV
  b = 1/2;
  // CHAR ID = MOD
  b = 1%2;
  // CHAR ID = RND
  b = (1);
  b = (a+b);
  // CHAR ID = CMP
  b = 1&&2;

  // INT VEC = INT
  c[2] = 1;
  // INT VEC = ID
  c[2] = a;
  c[2] = b;
  // INT VEC = VEC
  c[2] = c[1];
  c[2] = d[9];
  // INT VEC = C
  c[2] = 'c';
  // INT VEC = INT FC
  c[2] = fun1(1,2);
  // INT VEC = CHAR FC
  c[2] = fun2(1,2);
  // INT VEC = SUM
  c[2] = 1+2;
  // INT VEC = DIF
  c[2] = 1-2;
  // INT VEC = TIM
  c[2] = 1*2;
  // INT VEC = DIV
  c[2] = 1/2;
  // INT VEC = MOD
  c[2] = 1%2;
  // INT VEC = RND
  c[2] = (1);
  c[2] = (a+b);
  // INT VEC = CMP
  c[2] = 1&&2;

  // CHAR VEC = INT
  d[2] = 1;
  // CHAR VEC = ID
  d[2] = a;
  d[2] = b;
  // CHAR VEC = VEC
  d[2] = c[1];
  d[2] = d[9];
  // CHAR VEC = C
  d[2] = 'c';
  // CHAR VEC = INT FC
  d[2] = fun1(1,2);
  // CHAR VEC = CHAR FC
  d[2] = fun2(1,2);
  // CHAR VEC = SUM
  d[2] = 1+2;
  // CHAR VEC = DIF
  d[2] = 1-2;
  // CHAR VEC = TIM
  d[2] = 1*2;
  // CHAR VEC = DIV
  d[2] = 1/2;
  // CHAR VEC = MOD
  d[2] = 1%2;
  // CHAR VEC = RND
  d[2] = (1);
  d[2] = (a+b);
  // CHAR VEC = CMP
  d[2] = 1&&2;

  return 0;
}
