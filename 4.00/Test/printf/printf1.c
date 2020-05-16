#include <stdio.h>
#include <string.h>

/* questo test dimostra che passare un char pointer ad una printf è un rishio perchè
potrebbe non avere un carattere di fine stringa e questo porterebbe ad altre aree di memoria */

int test(){

  char s[] = {'1','2'};
  printf(s);
  printf("\n");
  char * point = &s[0];
  char character = *point;

  printf("LUNGHEZZA: %lu\n", strlen(s));
  for (int i = 0; i < 10; i++){
    printf("CARATTERE: %c\n", character);
    printf("VALORE: %d\n", character);
    point ++;
    character = *point;
  }

  return 0;
}


int main(){

  test();

  return 0;
}
