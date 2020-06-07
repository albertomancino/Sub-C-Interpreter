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
int L_DEBUGGING;
int P_DEBUGGING;
int TREE_DEBUGGING;
int PRINT_TREE = 0;
int ONLINE = 0;

void banner();
void help();

int main (int argc, char *argv[]){

  if (argc > 1){
    if (!strcmp("-help", argv[1])) {
      help();
      return 0;
    }
    else if (!strcmp("-online", argv[1])) ONLINE = 1;
    else if( access( argv[1], R_OK ) == -1 ) {

      printf("%serror%s: C file not found.\n",RED,RESET);
      exit(EXIT_FAILURE);
    }

    // file opening
    if (ONLINE == 0){
      yyin = fopen(argv[1], "r");
      if (yyin == NULL){
        printf("%serror%s: C file reading fails.\n",RED,RESET);
        exit(EXIT_FAILURE);
      }
    }

    for (int i = 2; i < argc; i++){

      if      (!strcmp("-p", argv[i]))    P_DEBUGGING = 1;
      else if (!strcmp("-l", argv[i]))    L_DEBUGGING = 1;
      else if (!strcmp("-t", argv[i]))    TREE_DEBUGGING = 1;
      else if (!strcmp("-tree", argv[i])) PRINT_TREE = 1;
      else if (!strcmp("-help", argv[i])) {
        help();
        return 0;
      }
      else {
        printf("%s error:%s unknown argument %s. '-help' for more details.\n\n",RED, RESET, argv[i]);
        return 1;
      }
    }

    banner();

    MainNode = ProgramNode_Set();
    int parsing = 0;
    parsing = yyparse();

    fclose(yyin);

    if (!parsing){
      printf("\n\n%sSuccessul parsing%s\n", GREEN, RESET);
    }

    if ( MainNode -> main_flag) {
      printf("function 'main' return value: %d\n", MainNode -> return_value);
    }
    else printf("%s function 'main' missing!\n", WarnMsg());

    printf("\n\n\n");

    if (PRINT_TREE) PrintTree(MainNode);

    // warnings counter printer
    if(MainNode -> warnings > 0) printf("%s%d warnings%s detected.\n", BOLDWHITE, MainNode -> warnings, RESET);


    printf("\n ------------------------------------------------------------------------------------------------------------- \n");
    printf(" -----------------------------------------------SUB-C INTERPRETER--------------------------------------------- \n\n\n");

    return 0;
  }
  else{
    printf("%s error:%s at least 1 argument is required. '-help' for more details.\n",RED, RESET);
    return 1;
  }
}

void banner(){

  printf("\n\n\n");
  printf("%s   _____         _              _____     _____         _                                 _\n  / ____|       | |            / ____|   |_   _|       | |                               | |\n | (___   _   _ | |__   _____ | |          | |   _ __  | |_  ___  _ __  _ __   _ __  ___ | |_  ___  _ __\n  \\___ \\ | | | || '_ \\ |_____|| |          | |  | '_ \\ | __|/ _ \\| '__|| '_ \\ | '__|/ _ \\| __|/ _ \\| '__|\n  ____) || |_| || |_) |       | |____     _| |_ | | | || |_|  __/| |   | |_) || |  |  __/| |_|  __/| |\n |_____/  \\__,_||_.__/         \\_____|   |_____||_| |_| \\__|\\___||_|   | .__/ |_|   \\___| \\__|\\___||_|\n                                                                       | |\n                                                                       |_|                               %s\n", BOLDWHITE, RESET);

  printf("\n\n %sDesigned and made by%s: Alberto Carlo Maria Mancino\n", BOLD_YELLOW, RESET);
  printf(" %sSupervised by%s: Prof. Ing. Floriano Scioscia\n", BOLD_YELLOW, RESET);
  printf("\n %sVersion No%s: 4.00\n",BOLDWHITE, RESET);
  printf("\n -----------------------------------------------SUB-C INTERPRETER--------------------------------------------- \n");
  printf(" ------------------------------------------------------------------------------------------------------------- \n\n\n");
}

void help(){

  printf("OVERVIEW: Sub-C Interpreter.\n\n");
  printf("USAGE: sub-C-int [C FILE PATH | -online] [options]\n\n");
  printf("OPTIONS:\n\n");
  printf("-p\t\tPrints a message when the parser finds a production, specifying the name of the production found.\n");
  printf("-l\t\tPrints a message when the lexer finds a token, specifying the name of the token found.\n");
  printf("-t\t\tPrints a message when a new node of the AST is created, specifying the type of the node created.\n");
  printf("-tree\t\tAfter the interpretation phase, prints the AST.\n");
  printf("\n\n\n");
}
