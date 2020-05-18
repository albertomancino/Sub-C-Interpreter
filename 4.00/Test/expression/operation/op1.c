int main(){

  int x;
  char y;
  int z;
  char t;

  int a;
  a = 3;
  int b[10];
  b[0] = 5;
  int c;
  c = 10;
  int d;
  d = 2;
  int e;
  e = 20;
  int f;
  f = 7;

  char ac;
  ac = '\3';
  char bc[10];
  bc[0] = '\5';
  char cc;
  cc = '\12';
  char dc;
  dc = '\2';
  char ec;
  ec = '\24';
  char fc;
  fc = '\7';
  
  // aritmetic operation with costant integers
  x = (7 + (20 - (2 * (10 / (5 % 3)))));

  // aritmetic operation with costant characters
  y = ('\7' + ('\24' - ('\2' * ('\12' / ('\5' % '\3')))));

  // aritmetic operation with variable integers
  z = (f + (e - (d * (c / (b[0] % a)))));

  // aritmetic operation with variable characters
  t = (fc + (ec - (dc * (cc / (bc[0] % ac)))));

  --ST
}
