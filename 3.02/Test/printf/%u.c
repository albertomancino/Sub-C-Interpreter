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

  printf("%u\n", 1);
  printf("%u\n", -1);
  printf("%u\n", a);
  //printf("%u\n", b);  // error
  printf("%u\n", b[1]);
  //printf("%u\n", "Hello world");  //error
  printf("%u\n", c);
  //printf("%u\n", d);  // error
  printf("%u\n", infFun());
  printf("%u\n", charFun());
  printf("%u\n", 1+1);
  printf("%u\n", 1-1);
  printf("%u\n", 1*1);
  printf("%u\n", 1/1);
  printf("%u\n", 1%1);
  printf("%u\n", (1%1));
  printf("%u\n",  ++a);
  printf("%u\n", --a);
  printf("%u\n", a++);
  printf("%u\n", a--);
  //printf("%u\n", a=1);


  return 0;
}


int main(){

  test();

  return 0;
}
