int main(){

  int x;
  x = 0;
  int y;
  y = 0;
  int z;
  z = 0;

  y = x++ && x++ && x++ && x++;
  printf("%d %d\n", x, y);
  y = x++ || x++ || x++ || x++ || x++ || x++ || x++;
  printf("%d %d\n", x, y);
  y = x++ > x++;
  printf("%d %d\n", x, y);
  y = x++ < x++;
  printf("%d %d\n", x, y);
  y = x++ == x++;
  printf("%d %d\n", x, y);
  y = x++ != x++;
  printf("%d %d\n", x, y);

  printf("----------\n");
  x = 0;

  printf("x: %d z:%d y:%d\n", x, z, y);
  y = z++ && x++;
  printf("x: %d z:%d y:%d\n", x, z, y);
  y = ++x && ++x && ++x && ++x && ++x && ++x && ++x;
  printf("%d %d\n", x, y);
  y = ++x || ++x || ++x || ++x || ++x || ++x || ++x || ++x;
  printf("%d %d\n", x, y);
  y = ++x > ++x;
  printf("%d %d\n", x, y);
  y = ++x < ++x;
  printf("%d %d\n", x, y);
  y = ++x == ++x;
  printf("%d %d\n", x, y);
  y = ++x != ++x;
  printf("%d %d\n", x, y);











  return 0;
}
