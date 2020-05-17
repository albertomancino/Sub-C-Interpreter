int main(){

  // mancano le chiamate a funzioni
  int a;
  a = 0;
  a = -2147483648;
  a = 2147483647;

  char b;
  b = 's';
  b = -128;
  b = 127;

  int c[10];
  c[0] = 10;
  c[9] = 10;
  c[0] = a;
  c[0] = b;

  char d[10];
  d[0] = 's';
  d[9] = 's';
  d[0] = a;
  d[0] = b;

  int e;
  e = 123;
  a = e;
  b = e;
  c[2] = e;
  d[2] = e;

  char f;
  f = 's';
  a = f;
  b = f;
  c[2] = f;
  d[2] = f;
  f = a;
  f = b;

  // multiple assigments
  a = b = c[9] = d[9] = e = f;

  return 0;
}
