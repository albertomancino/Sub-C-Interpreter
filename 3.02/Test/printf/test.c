#include <stdio.h>

int fun(){

    return 1;
}

int main(){


  int x;
  int a[10];

  printf("%p\n", &x);
  printf("%p\n", &a);
  printf("%p\n", &a[1]);
  printf("%p\n", &x[]);

  return 0;
}
