//int x[-1]; /* error */
//int x[0];  /* error */

int fun0(){

  int a;
  a = -10;
  int b[a]; /* this error will raise only if the function is called */
  //int y[-10];  /* error */
  return 0;
}

int main(){

  int a;
  a = -10;
  int b[a];  /* error */

  return 0;
}
