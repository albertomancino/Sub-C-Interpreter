int main(){


  int x = 0;
  int y;

  x = ((x=y=2)+(x=3));

  y = (x=1)&&(x=0);
  printf("%d\n", y);
  y = (x=1)||(x=0);
  printf("%d\n", y);
  y = (x=1)>(x=0);
  printf("%d\n", y);
  y = (x=1)<(x=0);
  printf("%d\n", y);
  y = (x=1)==(x=0);
  printf("%d\n", y);
  y = (x=1)!=(x=0);
  printf("%d\n", y);
  y = (x=1)+(x=0);
  printf("%d\n", y);
  y = (x=1)-(x=0);
  printf("%d\n", y);
  y = (x=1)*(x=0);
  printf("%d\n", y);
  y = (x=1)/(x=10);
  printf("%d\n", y);
  y = (x=1)%(x=10);
  printf("%d\n", y);
  y = ((x=0));
  printf("%d\n", y);

  printf("x vale: %d\n", x);
  int v[5] = {(x=0),(x=1),(x=2),(x=3),(x=4)};
  printf("%d %d %d %d %d\n", v[0], v[1], v[2], v[3], v[4]);

  /*
  while (x < 5) x++;

  while(10!=10){


    {



      {


      }
    }
    {

    }
  }

  int vec[4] = {1,2,3,4};

  while(1){
    //printf("ciao\n" );
  }
*/
  return 1;
}
