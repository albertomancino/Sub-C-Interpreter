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
  char array[] = {'H','e','l','l','o',' ','N','u','m',':','%','d'};

  printf(array, 1);
  printf(array, 1);
  printf(array, -1);
  printf(array, a);
  printf(array, b[1]);
  printf(array, c);
  printf(array, infFun());
  printf(array, charFun());
  printf(array, 1+1);
  printf(array, 1-1);
  printf(array, 1*1);
  printf(array, 1/1);
  printf(array, 1%1);
  printf(array, (1%1));
  printf(array,  ++a);
  printf(array, --a);
  printf(array, a++);
  printf(array, a--);

  return 0;
}


int main(){

  test();

  return 0;
}
