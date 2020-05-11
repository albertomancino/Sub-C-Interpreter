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

  printf("%X\n", 1);
  printf("%X\n", -1);
  printf("%X\n", a);
  //printf("%X\n", b);  // error
  printf("%X\n", b[1]);
  //printf("%X\n", "Hello world");  //error
  printf("%X\n", c);
  //printf("%X\n", d);  // error
  printf("%X\n", infFun());
  printf("%X\n", charFun());
  printf("%X\n", 1+1);
  printf("%X\n", 1-1);
  printf("%X\n", 1*1);
  printf("%X\n", 1/1);
  printf("%X\n", 1%1);
  printf("%X\n", (1%1));
  printf("%X\n",  ++a);
  printf("%X\n", --a);
  printf("%X\n", a++);
  printf("%X\n", a--);
  //printf("%X\n", a=1);


  return 0;
}


int main(){

  test();

  return 0;
}
