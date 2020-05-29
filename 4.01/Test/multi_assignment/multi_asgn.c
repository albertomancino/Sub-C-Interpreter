int test(){

  int a, b[10], c, d, e;
  char f, g[10], h, i, j;

  // int multi assignement
  a = b[5] = c = d = e = 10;
  printf("OK. Int multi assignment %d\n", a);
  printf("OK. Int multi assignment %d\n", b[5]);
  printf("OK. Int multi assignment %d\n", c);
  printf("OK. Int multi assignment %d\n", d);
  printf("OK. Int multi assignment %d\n", e);

  // int multi assignement
  f = g[5] = h = i = j = 'a';
  printf("OK. Char multi assignment %c\n", f);
  printf("OK. Char multi assignment %c\n", g[5]);
  printf("OK. Char multi assignment %c\n", h);
  printf("OK. Char multi assignment %c\n", i);
  printf("OK. Char multi assignment %c\n", j);

  return 0;
}


int main(){

  test();

  return 0;
}
