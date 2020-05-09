#include <stdio.h>

int infFun(){

  return 0;
}

char charFun(){

  return 'a';
}

int test(){

  int a = 10;
  int b[] = {1,2,3,4,5,6,7,8,9,0};
  char c = 'a';
  char d[] = {'H','e','l','l','o'};

  printf("%e\n", 1);
  printf("%e\n", -1);
  printf("%e\n", a);
  //printf("%e\n", b);  // error
  printf("%e\n", b[1]);
  //printf("%e\n", "Hello world");  //error
  printf("%e\n", c);
  //printf("%e\n", d);  // error
  printf("%e\n", infFun());
  printf("%e\n", charFun());
  printf("%e\n", 1+1);
  printf("%e\n", 1-1);
  printf("%e\n", 1*1);
  printf("%e\n", 1/1);
  printf("%e\n", 1%1);
  printf("%e\n", (1%1));
  printf("%e\n",  ++a);
  printf("%e\n", --a);
  printf("%e\n", a++);
  printf("%e\n", a--);
  //printf("%e\n", a=1);

  return 0;
}


int main(){

  test();

  return 0;
}
