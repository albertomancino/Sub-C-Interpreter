int test(){

  int x;

  {
    int y;
    {
      x = 10;
      y = 11;
    }

    x = 0;
    printf("%d\n", x);
  }

  if (1){
    int x;
    {
      x = 110;
    }
    x = 111;
  }
}

int main(){


  int x;

  {
    int y;
    {
      x = 10;
      y = 11;
    }

    x = 0;
  }

  test();

  return 0;
}
