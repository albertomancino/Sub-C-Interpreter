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

  printf("%i\n", 1);
  printf("%i\n", -1);
  printf("%i\n", a);
  //printf("%i\n", b);  // error
  printf("%i\n", b[1]);
  //printf("%i\n", "Hello world");  //error
  printf("%i\n", c);
  //printf("%i\n", d);  // error
  printf("%i\n", infFun());
  printf("%i\n", charFun());
  printf("%i\n", 1+1);
  printf("%i\n", 1-1);
  printf("%i\n", 1*1);
  printf("%i\n", 1/1);
  printf("%i\n", 1%1);
  printf("%i\n", (1%1));
  printf("%i\n",  ++a);
  printf("%i\n", --a);
  printf("%i\n", a++);
  printf("%i\n", a--);
  //printf("%i\n", a=1);

  return 0;
}


int main(){

  test();

  return 0;
}
