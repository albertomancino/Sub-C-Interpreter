//#include <stdio.h>

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

  printf("%c\n", 1);
  printf("%c\n", -1);
  printf("%c\n", a);
  //printf("%c\n", b);  // error
  printf("%c\n", b[1]);
  //printf("%c\n", "Hello world");  //error
  printf("%c\n", c);
  //printf("%c\n", d);  // error
  printf("%c\n", infFun());
  printf("%c\n", charFun());
  printf("%c\n", 1+1);
  printf("%c\n", 1-1);
  printf("%c\n", 1*1);
  printf("%c\n", 1/1);
  printf("%c\n", 1%1);
  printf("%c\n", (1%1));
  printf("%c\n",  ++a);
  printf("%c\n", --a);
  printf("%c\n", a++);
  printf("%c\n", a--);
  //printf("%c\n", a=1);

  return 0;
}


int main(){

  test();

  return 0;
}
