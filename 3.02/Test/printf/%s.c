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

  //printf("%s\n", 1);  // error
  //printf("%s\n", -1); // error
  //printf("%s\n", a);  // error
  //printf("%s\n", b);  // error
  //printf("%s\n", b[1]);
  printf("%s\n", "Hello world");
  //printf("%s\n", c);  // error
  printf("%s\n", d);
  //printf("%s\n", infFun());  // error
  //printf("%s\n", charFun()); // error
  //printf("%s\n", 1+1);       // error
  //printf("%s\n", 1-1);       // error
  //printf("%s\n", 1*1);       // error
  //printf("%s\n", 1/1);       // error
  //printf("%s\n", 1%1);       // error
  //printf("%s\n", (1%1));     // error
  //printf("%s\n",  ++a);     // error
  //printf("%s\n", --a);      // error
  //printf("%s\n", a++);      // error
  //printf("%s\n", a--);      // error
  //printf("%s\n", a=1);      // error

  return 0;
}


int main(){

  test();

  return 0;
}
