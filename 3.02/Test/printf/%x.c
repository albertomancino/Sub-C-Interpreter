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

  printf("%x\n", 1);
  printf("%x\n", -1);
  printf("%x\n", a);
  //printf("%x\n", b);  // error
  printf("%x\n", b[1]);
  //printf("%x\n", "Hello world");  //error
  printf("%x\n", c);
  //printf("%x\n", d);  // error
  printf("%x\n", infFun());
  printf("%x\n", charFun());
  printf("%x\n", 1+1);
  printf("%x\n", 1-1);
  printf("%x\n", 1*1);
  printf("%x\n", 1/1);
  printf("%x\n", 1%1);
  printf("%x\n", (1%1));
  printf("%x\n",  ++a);
  printf("%x\n", --a);
  printf("%x\n", a++);
  printf("%x\n", a--);
  //printf("%x\n", a=1);


  return 0;
}


int main(){

  test();

  return 0;
}
