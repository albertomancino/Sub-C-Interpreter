int main(){
  int f;
  f = 12345678;
  int x;
  char y;
  int a[4];
  int b[4];
  x = y = a[0] = a[1] = a[2] = a[3] = b[0] = b[1] = b[2] = b[3] = 1;
  	--ST
  x ++;
  y ++;
  a[0] ++;
  b[0] ++;
  	--ST
  x --;
  y --;
  a[0] --;
  b[0] --;
  	--ST
  y = ++x;
  b[0] = ++a[0];
  	--ST
  y = x++ + x++;
  b[0] = a[0]++;
  	--ST
}
