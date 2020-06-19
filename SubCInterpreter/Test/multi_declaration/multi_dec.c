int test(){

  // int multi declaration
  int a, b=10, c[5] = {1,2,3,4,5}, d[5], e[] = {1,2,3,4,5};
  printf("OK. Int multi declaration %d.\n", a);
  printf("OK. Int multi declaration %d.\n", b);
  printf("OK. Int multi declaration %d.\n", c[3]);
  printf("OK. Int multi declaration %d.\n", d[3]);
  printf("OK. Int multi declaration %d.\n", e[3]);

  // char multi declaration
  char f, g='a', h[5] = {'H','e','l','l','o'}, i[5], j[] = "Hello";
  printf("OK. Char multi declaration %c.\n", f);
  printf("OK. Char multi declaration %c.\n", g);
  printf("OK. Char multi declaration %s.\n", h);
  printf("OK. Char multi declaration %c.\n", i[3]);
  printf("OK. Char multi declaration %s.\n", j);

  return 0;
}


int main(){

  test();
  return 0;
}
