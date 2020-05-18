int fun(int a){
  return a;
}

int main(){

  int x;

  x = x++;

  x = 1 + ++x;

  x = (10 * 3 + ( x-- * 10));

  x = ((1&&0) + (x || 0) * --x);

  int y;

  x = y++ + y++;

  x = fun(x++);


  return 0;
}
