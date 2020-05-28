int main(){


  int x = 0;
  int y;

  x = ((x=y=2)+(x=3));
  --ST
  y = (x=1)&&(x=0);
  --ST
  y = (x=1)||(x=0);
  --ST
  y = (x=1)>(x=0);
  --ST
  y = (x=1)<(x=0);
  --ST
  y = (x=1)==(x=0);
  --ST
  y = (x=1)!=(x=0);
  --ST
  y = (x=1)+(x=0);
  --ST
  y = (x=1)-(x=0);
  --ST
  y = (x=1)*(x=0);
  --ST
  y = (x=1)/(x=10);
  --ST
  y = (x=1)%(x=10);
  --ST
  y = ((x=0));
  --ST

  --ST
  int v[5] = {(x=0),(x=1),(x=2),(x=3),(x=4)};
  --ST


  return 1;
}
