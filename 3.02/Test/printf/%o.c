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

  printf("%o\n", 1);
  printf("%o\n", -1);
  printf("%o\n", a);
  //printf("%o\n", b);  // error
  printf("%o\n", b[1]);
  //printf("%o\n", "Hello world");  //error
  printf("%o\n", c);
  //printf("%o\n", d);  // error
  printf("%o\n", infFun());
  printf("%o\n", charFun());
  printf("%o\n", 1+1);
  printf("%o\n", 1-1);
  printf("%o\n", 1*1);
  printf("%o\n", 1/1);
  printf("%o\n", 1%1);
  printf("%o\n", (1%1));
  printf("%o\n",  ++a);
  printf("%o\n", --a);
  printf("%o\n", a++);
  printf("%o\n", a--);
  //printf("%o\n", a=1);

  return 0;
}


int main(){

  test();

  return 0;
}
