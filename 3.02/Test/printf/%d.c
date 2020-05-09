//#include <stdio.h>

int infFun(){

  return 0;
}

char charFun(){

  return 'a';
}

int test(){

  int a = 10;
  int b[10] = {1,2,3,4,5,6,7,8,9,0};
  char c = 'a';
  char d[10] = {'H','e','l','l','o'};

  printf("%d\n", 1);
  printf("%d\n", -1);
  printf("%d\n", a);
  //printf("%d\n", b);  // error
  printf("%d\n", b[1]);
  //printf("%d\n", "Hello world");  //error
  printf("%d\n", c);
  //printf("%d\n", d);  // error
  printf("%d\n", infFun());
  printf("%d\n", charFun());
  printf("%d\n", 1+1);
  printf("%d\n", 1-1);
  printf("%d\n", 1*1);
  printf("%d\n", 1/1);
  printf("%d\n", 1%1);
  printf("%d\n", (1%1));
  printf("%d\n",  ++a);
  printf("%d\n", --a);
  printf("%d\n", a++);
  printf("%d\n", a--);
  //printf("%d\n", a=1);


  return 0;
}


int main(){

  test();

  return 0;
}
