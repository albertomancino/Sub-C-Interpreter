int main(){

  int x;
  char y;
  int a[4];
  int b[4];
  x = y = a[0] = a[1] = a[2] = a[3] = b[0] = b[1] = b[2] = b[3] = 1;
  printf("%d %d %d %d %d %d %d %d %d %d\n", x,y,a[0],a[1],a[2],a[3],b[0],b[1],b[2],b[3]);
  x ++;
  y ++;
  a[0] ++;
  b[0] ++;
  printf("%d %d %d %d\n", x,y,a[0],b[0]);
  x --;
  y --;
  a[0] --;
  b[0] --;
  printf("%d %d %d %d\n", x,y,a[0],b[0]);
  y = ++x;
  b[0] = ++a[0];
  printf("%d %d %d %d\n", x,y,a[0],b[0]);
  y = x++ + x++;
  b[0] = a[0]++;
  printf("%d %d %d %d\n", x,y,a[0],b[0]);
}
