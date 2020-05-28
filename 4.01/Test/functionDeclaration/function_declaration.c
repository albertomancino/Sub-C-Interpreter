int fun1(){

  return 1;
}

int fun2(int a, char b[10], char c[a], char d[1], char e[b[1]]){

  --ST
  return 1;
}

char fun3(){

  return 1;
}

char fun4(int a, int b, char c, char d){

  return 1;
}

int main(){

  char c[3] = {10, 11, 12};
  fun2(10,c, c, c, c);
  return 1;
}
