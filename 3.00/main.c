#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"
#include "Tree.c"
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define GREEN   "\033[32m"      /* Green */
#define RESET   "\033[0m"


// avoiding compiler warning
int yyparse();
ProgramNode * MainNode;

int main (int argc, char *argv[]){

  MainNode = ProgramNode_Set();

  int parsing = 0;
  parsing = yyparse();


  if (!parsing){
    printf("\n\n%sSuccessul parsing%s\n\n\n", GREEN, RESET);
  }

  PrintTree(MainNode);

  // warnings counter printer
  if(MainNode -> warnings > 0){
    printf("%s%d warnings%s detected.\n", BOLDWHITE, MainNode -> warnings, RESET);
  }

}
