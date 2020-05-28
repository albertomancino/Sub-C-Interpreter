int int_fun(){

  return 10;
}

char char_fun(){

  return 'a';
}

int test(){

  int dim = 10;
  char dim2 = 10;
  int dim3[3] = {1,2,3};
  char dim4[3] = {1,2,3};

  char a[10];
  printf("OK. 'a' char array variable with costant integer dimension declared.\n");
  char b[dim];
  printf("OK. 'b' char array variable with int variable dimension declared.\n");
  char c[dim2];
  printf("OK. 'c' char array variable with char variable dimension declared.\n");
  char d[dim3[2]];
  printf("OK. 'd' char array variable with int array element dimension declared.\n");
  char e[dim4[2]];
  printf("OK. 'e' char array variable with char array element dimension declared.\n");
  char f['a'];
  printf("OK. 'f' char array variable with costant char dimension declared.\n");
  char g[int_fun()];
  printf("OK. 'g' char array variable with int function call dimension declared.\n");
  char h[char_fun()];
  printf("OK. 'h' char array variable with char function call dimension declared.\n");
  char i[(1+1*2/2%10)];
  printf("OK. 'i' char array variable with operation dimension declared.\n");
  char j[++dim];
  printf("OK. 'j' char array variable with variable pre increment dimension declared.\n");
  char k[--dim];
  printf("OK. 'k' char array variable with variable pre decrement dimension declared.\n");
  char l[dim++];
  printf("OK. 'l' char array variable with variable post increment dimension declared.\n");
  char m[dim--];
  printf("OK. 'm' char array variable with variable post decrement dimension declared.\n");
  char n[(1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20)];
  printf("OK. 'n' char array variable with comparions dimension declared.\n");



  return 0;
}

int main(){

  test();

  return 0;
}
