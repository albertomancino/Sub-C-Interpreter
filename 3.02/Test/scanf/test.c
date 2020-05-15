#include <stdio.h>

int main(){



  int x;
  char y;

  void * pointer;
  pointer = &x;
  //scanf("%d", (int*)pointer);
  scanf("%d", &x);
  printf("Il puntatore vale: %d\n", pointer);
  pointer = &y;
  //scanf("%d", (int*)pointer);
  scanf("%d", &y);
  printf("Il puntatore vale: %d\n", pointer);

  printf("x vale: %d\n", x);
  printf("y vale: %d\n", y);

  return 0;
}
