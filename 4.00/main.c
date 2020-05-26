#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Tree.h"
#include "Tree.c"
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define GREEN   "\033[32m"                 /* Green */
#define RED     "\x1b[31m"      /* Red */
#define BOLD_YELLOW   "\033[1m\033[33m"
#define RESET   "\033[0m"
FILE *yyin;


// avoiding compiler warning
int yyparse();
ProgramNode * MainNode;

void title();

int main (int argc, char *argv[]){

  if (argc != 2){
    if (argc > 2){
      printf("\nExceed number of arguments. 1 argument expexted.\nExample: sub-C-Int.out \"[C-FILE-PATH]\"\n");
      exit(EXIT_FAILURE);
    }
    else{
      printf("1 parameter expexted, found %d.\nExample: sub-C-Int.out \"[C-FILE-PATH]\"\n", argc);
      exit(EXIT_FAILURE);
    }
  }
  else{

    if( access( argv[1], R_OK ) == -1 ) {

      printf("%serror%s: C file not found.\n",RED,RESET);
      exit(EXIT_FAILURE);
    }
    yyin = fopen(argv[1], "r");
    if (yyin == NULL){
      printf("%serror%s: C file reading fails.\n",RED,RESET);
      exit(EXIT_FAILURE);
    }

    title();

    MainNode = ProgramNode_Set();
    int parsing = 0;
    parsing = yyparse();

    fclose(yyin);

    if (!parsing){
      printf("\n\n%sSuccessul parsing%s\n\n\n", GREEN, RESET);
      printf("Main function return value: %d\n", MainNode -> return_value);
    }

    //PrintTree(MainNode);

    // warnings counter printer
    if(MainNode -> warnings > 0){
      printf("%s%d warnings%s detected.\n", BOLDWHITE, MainNode -> warnings, RESET);
    }
  }

  printf("\n ------------------------------------------------------------------------------------------------------------- \n");
  printf(" -----------------------------------------------SUB-C INTERPRETER--------------------------------------------- \n\n\n");

  return 0;
}

void title(){

  printf("\n\n\n");
  printf("%s   _____         _              _____     _____         _                                 _\n  / ____|       | |            / ____|   |_   _|       | |                               | |\n | (___   _   _ | |__  ______ | |   ______ | |   _ __  | |_  ___  _ __  _ __   _ __  ___ | |_  ___  _ __\n  \\___ \\ | | | || '_ \\|______|| |  |______|| |  | '_ \\ | __|/ _ \\| '__|| '_ \\ | '__|/ _ \\| __|/ _ \\| '__|\n  ____) || |_| || |_) |       | |____     _| |_ | | | || |_|  __/| |   | |_) || |  |  __/| |_|  __/| |\n |_____/  \\__,_||_.__/         \\_____|   |_____||_| |_| \\__|\\___||_|   | .__/ |_|   \\___| \\__|\\___||_|\n                                                                       | |\n                                                                       |_|                               %s\n", BOLDWHITE, RESET);

  printf("\n\n %sDesigned and made by%s: Alberto Carlo Maria Mancino\n", BOLD_YELLOW, RESET);
  printf(" %sSupervised by%s: Prof. Ing. Floriano Scioscia\n", BOLD_YELLOW, RESET);
  printf("\n %sVersion No%s: 4.00\n",BOLDWHITE, RESET);
  printf("\n -----------------------------------------------SUB-C INTERPRETER--------------------------------------------- \n");
  printf(" ------------------------------------------------------------------------------------------------------------- \n\n\n");
}
