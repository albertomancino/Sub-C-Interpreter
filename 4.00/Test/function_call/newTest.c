#include <stdlib.h>
#include <stdio.h>

int main(){

  int * array = (int*)malloc(sizeof(int)*10);

  if (array == NULL) printf("STANN PROBLEM\n");
  int i = 0;
  while (i++ < 10) array[i] = i;

  printf("%d\n", array[0]);

  int * copia;

  copia = array;

  printf("%d\n", copia[0]);


  return 0;
}
