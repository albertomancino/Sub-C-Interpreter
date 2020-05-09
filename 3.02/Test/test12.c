int fun1(char x){

  //printf("%s\n", x);
  return 1;
}

int fun2(int x[]){

  //printf("%d - %d - %d\n", x[0],x[1],x[2]);
  return 1;
}

int main(){

  int var[4];
  char y, t, u = {'a'}, i[3] = {'3','5'};
  int a, b = 4, c, d, e = 5, f;
  int x[] = {1,2,3};

  fun1("ciao");
  printf("%c %c %c\n", y, t, u);
  printf("%d %d %d %d %d %d \n",a,b,c,d,e,f);

  return 0;
}
