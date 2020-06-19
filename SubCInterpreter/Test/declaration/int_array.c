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

  int a[10];
  printf("OK. 'a' int array variable with costant integer dimension declared.\n");
  int b[dim];
  printf("OK. 'b' int array variable with int variable dimension declared.\n");
  int c[dim2];
  printf("OK. 'c' int array variable with char variable dimension declared.\n");
  int d[dim3[2]];
  printf("OK. 'd' int array variable with int array element dimension declared.\n");
  int e[dim4[2]];
  printf("OK. 'e' int array variable with char array element dimension declared.\n");
  int f['a'];
  printf("OK. 'f' int array variable with costant char dimension declared.\n");
  int g[int_fun()];
  printf("OK. 'g' int array variable with int function call dimension declared.\n");
  int h[char_fun()];
  printf("OK. 'h' int array variable with char function call dimension declared.\n");
  int i[(1+1*2/2%10)];
  printf("OK. 'i' int array variable with operation dimension declared.\n");
  int j[++dim];
  printf("OK. 'j' int array variable with variable pre increment dimension declared.\n");
  int k[--dim];
  printf("OK. 'k' int array variable with variable pre decrement dimension declared.\n");
  int l[dim++];
  printf("OK. 'l' int array variable with variable post increment dimension declared.\n");
  int m[dim--];
  printf("OK. 'm' int array variable with variable post decrement dimension declared.\n");
  int n[(1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20)];
  printf("OK. 'n' int array variable with comparions dimension declared.\n");



  return 0;
}

int main(){

  test();

  return 0;
}
