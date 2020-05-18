int main(){

  int a;
  int b;
  int c;
  int d;

  int sol;

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  sol = 0;


  sol = a++ && 0;
  printf("sol: %d a:%d\n", sol, a); // ha incrementato dopo aver eseguito l'and
  a = 0;
  sol = a++ && 1;
  printf("sol: %d a:%d\n", sol, a); // ha incrementato dopo aver eseguito l'and
  a = 0;
  sol = a++ && 10;
  printf("sol: %d a:%d\n", sol, a); // ha incrementato dopo aver eseguito l'and
  a = 0;
  sol = a++ && -10;
  printf("sol: %d a:%d\n", sol, a); // ha incrementato dopo aver eseguito l'and
  a = 0;
  sol = 0 && a++;
  printf("sol: %d a:%d\n", sol, a); // NON ha incrementato
  a = 0;
  sol = 1 && a++;
  printf("sol: %d a:%d\n", sol, a); // ha incrementato dopo aver eseguito l'and
  a = 0;
  sol = 10 && a++;
  printf("sol: %d a:%d\n", sol, a); // ha incrementato dopo aver eseguito l'and
  a = 0;
  sol = -10 && a++;
  printf("sol: %d a:%d\n", sol, a); // ha incrementato dopo aver eseguito l'and
  a = 0;
  b = 0;
  sol = a++ && b++;
  printf("sol: %d a:%d b:%d\n", sol, a, b);  //  dopo aver eseguito l'and ha incrementato a NON ha incrementato b
  a = 0;
  b = 0;
  sol = b++ && a++;
  printf("sol: %d a:%d b:%d\n", sol, a, b);  // dopo aver eseguito l'and ha incrementato b NON ha incrementato a
  a = 0;
  b = 0;
  c = 0;
  sol = a++ && b++ && c++;
  printf("sol: %d a:%d b:%d c:%d\n", sol, a, b, c); // dopo aver eseguito l'and ha incrementato a NON ha incrementato b e c
  a = 0;
  b = 0;
  c = 0;
  sol = a++ && b++ && c++ && d++;
  printf("sol: %d a:%d b:%d c:%d d:%d\n", sol, a, b, c, d); // dopo aver eseguito l'and ha incrementato a NON ha incrementato b, c e d



  return 0;
}
