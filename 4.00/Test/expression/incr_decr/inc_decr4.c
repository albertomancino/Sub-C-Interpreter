int main(){

  int a;
  int b;
  int c;
  int d;

  int sol;

  a = 7;
  b = 8;
  c = 9;
  d = 4;

  sol = 0;


  sol = a++ && 0;
  printf("sol: %d a:%d\n", sol, a); // ha incrementato dopo aver eseguito l'and
  a = 7;
  sol = a++ && 1;
  printf("sol: %d a:%d\n", sol, a); // ha incrementato dopo aver eseguito l'and
  a = 7;
  sol = a++ && 10;
  printf("sol: %d a:%d\n", sol, a); // ha incrementato dopo aver eseguito l'and
  a = 7;
  sol = a++ && -10;
  printf("sol: %d a:%d\n", sol, a); // ha incrementato dopo aver eseguito l'and
  a = 7;
  sol = 0 && a++;
  printf("sol: %d a:%d\n", sol, a); // NON ha incrementato
  a = 7;
  sol = 1 && a++;
  printf("sol: %d a:%d\n", sol, a); // ha incrementato dopo aver eseguito l'and
  a = 7;
  sol = 10 && a++;
  printf("sol: %d a:%d\n", sol, a); // ha incrementato dopo aver eseguito l'and
  a = 7;
  sol = -10 && a++;
  printf("sol: %d a:%d\n", sol, a); // ha incrementato dopo aver eseguito l'and
  a = 7;
  b = 8;
  sol = a++ && b++;
  printf("sol: %d a:%d b:%d\n", sol, a, b);  //  dopo aver eseguito l'and ha incrementato a e b
  a = 7;
  b = 8;
  sol = b++ && a++;
  printf("sol: %d a:%d b:%d\n", sol, a, b);  // dopo aver eseguito l'and ha incrementato b ed a
  a = 7;
  b = 8;
  c = 9;
  sol = a++ && b++ && c++;
  printf("sol: %d a:%d b:%d c:%d\n", sol, a, b, c); // dopo aver eseguito l'and ha incrementato a, b e c
  a = 7;
  b = 8;
  c = 9;
  d = 4;
  sol = a++ && b++ && c++ && d++;
  printf("sol: %d a:%d b:%d c:%d d:%d\n", sol, a, b, c, d); // dopo aver eseguito l'and ha incrementato a, b, c e d



  return 0;
}
