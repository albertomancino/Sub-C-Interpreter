%option yylineno
%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
#include "lexer.h"
#include "Tree.h"
int L_DEBUGGING;
int ERR;
struct TreeNode * NullTreeNode;
struct ErrorList * Errors;
struct ProgramNode * MainNode;
char * line = "";
int cursor;

%}
%x comment

space       [ \t]
ws          {space}+
digit       [0-9]
number      {digit}+
letter      [A-Za-z_]
id          {letter}({letter}|{digit})*
string      \"(\\.|[^"\\])*\"
escape      \'\\([\'\"\\\?abefnrtv]|({digit}{digit}?{digit}?))\'
character   \'(\\.|[^'\\])*\'
ILcomment   \/\/(.)*\n

%%
"/*"                  {BEGIN (comment); copyLine();}
<comment>[^*\n]*      copyLine();
<comment>"*"+[^*\/n]* copyLine();
<comment>\n           copyLine();
<comment>"*"+"/"      {BEGIN(INITIAL); copyLine();}

"return"    {                                                                                                    copyLine(); return RETURN;}
"if"        {if(L_DEBUGGING==1) printf("%d FLEX: IF found\n",yylineno);                                          copyLine(); return IF;}
"else"      {if(L_DEBUGGING==1) printf("%d FLEX: ELSE found\n",yylineno);                                        copyLine(); return ELSE;}
"while"     {if(L_DEBUGGING==1) printf("%d FLEX: WHILE found\n",yylineno);                                       copyLine(); return WHILE;}
"*"         {if(L_DEBUGGING==1) printf("%d FLEX: STAR found\n",yylineno);                                        copyLine(); return STAR;}
{ws}        {copyLine();}
"\n"        {resetLine();}
int         {if(L_DEBUGGING==1) printf("%d FLEX: INT found\n",yylineno);                                         copyLine(); return INT;}
char        {if(L_DEBUGGING==1) printf("%d FLEX: CHAR TYPE found\n",yylineno);                                   copyLine(); return CHAR;}
{number}    {if(L_DEBUGGING==1) printf("%d FLEX: NUMBER found with value: %s\n",yylineno,yytext); copyNUM();     copyLine(); return NUMBER;}
{id}        {if(L_DEBUGGING==1) printf("%d FLEX: ID found with name: %s\n",yylineno,yytext);  copyID();          copyLine(); return IDENTIFIER;}
";"         {if(L_DEBUGGING==1) printf("%d FLEX: END_COMMA found\n",yylineno);                                   copyLine(); return END_COMMA;}
","         {if(L_DEBUGGING==1) printf("%d FLEX: COMMA found\n",yylineno);                                       copyLine(); return COMMA;}
"("         {if(L_DEBUGGING==1) printf("%d FLEX: OPEN_ROUND found\n",yylineno);                                  copyLine(); return OPEN_ROUND;}
")"         {if(L_DEBUGGING==1) printf("%d FLEX: CLOSED_ROUND found\n",yylineno);                                copyLine(); return CLOSED_ROUND;}
"["         {if(L_DEBUGGING==1) printf("%d FLEX: OPEN_SQUARED found\n",yylineno);                                copyLine(); return OPEN_SQUARED;}
"]"         {if(L_DEBUGGING==1) printf("%d FLEX: CLOSED_SQUARED found\n",yylineno);                              copyLine(); return CLOSED_SQUARED;}
"{"         {if(L_DEBUGGING==1) printf("%d FLEX: OPEN_BRACKET found\n",yylineno);                                copyLine(); return OPEN_BRACKET;  }
"}"         {if(L_DEBUGGING==1) printf("%d FLEX: CLOSED_BRACKET found\n",yylineno);                              copyLine(); return CLOSED_BRACKET;}
"="         {if(L_DEBUGGING==1) printf("%d FLEX: EQUAL found\n",yylineno);                                       copyLine(); return EQUAL;}
"+"         {if(L_DEBUGGING==1) printf("%d FLEX: PLUS found\n",yylineno);                                        copyLine(); return PLUS;}
"-"         {if(L_DEBUGGING==1) printf("%d FLEX: MINUS found\n",yylineno);                                       copyLine(); return MINUS;}
"/"         {if(L_DEBUGGING==1) printf("%d FLEX: DIVIDE found\n",yylineno);                                      copyLine(); return DIVIDE;}
"%"         {if(L_DEBUGGING==1) printf("%d FLEX: MODULO found\n",yylineno);                                      copyLine(); return MODULO;}
">"         {if(L_DEBUGGING==1) printf("%d FLEX: GREATER THEN found\n",yylineno);                                copyLine(); return GT;}
"<"         {if(L_DEBUGGING==1) printf("%d FLEX: LESS THEN found\n",yylineno);                                   copyLine(); return LT;}
"=="        {if(L_DEBUGGING==1) printf("%d FLEX: EQUAL TO found\n",yylineno);                                    copyLine(); return ET;}
"!="        {if(L_DEBUGGING==1) printf("%d FLEX: DIFFERENT FROM found\n",yylineno);                              copyLine(); return DF;}
"&&"        {if(L_DEBUGGING==1) printf("%d FLEX: LOGIC AND found\n",yylineno);                                   copyLine(); return AND;}
"||"        {if(L_DEBUGGING==1) printf("%d FLEX: LOGIC OR found\n",yylineno);                                    copyLine(); return OR;}
"++"        {if(L_DEBUGGING==1) printf("%d FLEX: INCREMENT found\n",yylineno);                                   copyLine(); return INC;}
"--"        {if(L_DEBUGGING==1) printf("%d FLEX: DECREMENT OR found\n",yylineno);                                copyLine(); return DEC;}
"&"         {if(L_DEBUGGING==1) printf("%d FLEX: AMPERSAND found\n",yylineno);                                   copyLine(); return AMP;}
{string}    {if(L_DEBUGGING==1) printf("%d FLEX: STRING found with value %s\n",yylineno,yytext);  copyString();  copyLine(); return STRING;}
{escape}    {if(L_DEBUGGING==1) printf("%d FLEX: ESCAPE found with value %s\n",yylineno, yytext); copyEscape();  copyLine(); return CH;}
{character} {if(L_DEBUGGING==1) printf("%d FLEX: CHAR found with value %s\n",yylineno, yytext);   copyChar();     copyLine(); return CH;}
{ILcomment} {/*InLine Comment*/}
"!ST"       {if(L_DEBUGGING==1) printf("%d FLEX: SYMBOL TABLE print request found\n",yylineno); PrintActualST();}
"!LINE"     {if(L_DEBUGGING==1) printf("%d FLEX: LINE print request found\n",yylineno); printf("line: %d\n", yylineno);}
"!TREE"     {if(L_DEBUGGING==1) printf("%d FLEX: TREE print request found\n",yylineno); PrintTree(MainNode);}
"!SEP"      {printf("--------------------------------------------------------------------------------\n");}
"!STOP"     {return '\0';}
.           {printf("%s unknown symbol found: \'%s\'.\n", WarnMsg(), yytext); copyLine();}

%%

void copyID(){

  if (strlen(yytext) < 32){

    int firstAllocation = 0;
    if (firstAllocation != 0){
      free(yylval.string);
    }
    else{
      firstAllocation ++;
    }

    yylval.string = (char*)malloc(sizeof(char)*strlen(yytext));
    if ( yylval.string == NULL ){
      exit(EXIT_FAILURE);
    }
    strcpy(yylval.string, yytext);
  }
  else{
    printf("%s identifier max lenght exceeded. (max lenght = 31 characters)\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
}

void copyString(){

  int firstAllocation = 0;
  if (firstAllocation != 0){
    free(yylval.string);
  }
  else{
    firstAllocation ++;
  }
  /*yylval.string = (char*)malloc(sizeof(char)*strlen(yytext));
  if ( yylval.string == NULL ){
    printf("%s copyString - out of memory.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  strcpy(yylval.string, yytext);*/
  yylval.string = yytext;
}

void copyChar(){

  int len = (int)strlen(yytext);
  if (len == 2){
    printf("%s expected expression: %s.\n", ErrorMsg(), yytext);
    exit(EXIT_FAILURE);
  }
  if (len > 3){
    printf("%s not allowed multi-character character: %s\n", ErrorMsg(), yytext);
    exit(EXIT_FAILURE);
  }
  yylval.charValue = yytext[1]; // yytext[1], the index 1 is the char value, index 0 is the apex symbol

}

void copyNUM(){

  long value;
  if(strlen(yytext)<12){
    value = atof(yytext);

    if (value <  2147483649){
      yylval.intValue = value;
    }
    else{
      printf("%s out of integer range. This interpreter works with integer numbers only.\n",ErrorMsg());
      exit(EXIT_FAILURE);
    }
    }
  else{
    printf("%s out of integer range. This interpreter works with integer numbers only.\n",ErrorMsg());
    exit(EXIT_FAILURE);
  }
}

void copyEscape(){
  int len = (int)strlen(yytext);
  if(len == 4){
    char symbol = yytext[2];
    if (symbol < 48 || symbol > 57){
      switch (symbol) {
        case 'a': yylval.charValue = 7;
                break;
        case 'b': yylval.charValue = 8;
                break;
        case 'e': yylval.charValue = 27;
                break;
        case 'f': yylval.charValue = 12;
                break;
        case 'n': yylval.charValue = 10;
                break;
        case 'r': yylval.charValue = 15;
                break;
        case 't': yylval.charValue = 9;
                break;
        case 'v': yylval.charValue = 11;
                break;
        case '\\': yylval.charValue = 92;
                break;
        case '\'': yylval.charValue = 39;
                break;
        case '\"': yylval.charValue = 34;
                break;
        case '\?': yylval.charValue = 63;
                break;
        default:
              printf("%s unknown escape sequence: %s.\n", ErrorMsg(), yytext);
              exit(EXIT_FAILURE);
        }
    }
    else{
      int value;
      value = symbol - 48;
      if (value > -1 && value < 8){
        yylval.charValue = value;
      }
      else{
        printf("%s unknown escape sequence: %s.\n", ErrorMsg(), yytext);
        exit(EXIT_FAILURE);
      }
    }
  }
  else if(len == 5){

    int value, value0, value1;
    value0 = yytext[3] - 48;
    value1 = yytext[2] - 48;

    if (value0 < 0 || value0 > 7){
      printf("%s unknown escape sequence: %s.\n", ErrorMsg(), yytext);
      exit(EXIT_FAILURE);
    }
    if (value1 < 0 || value1 > 7){
      printf("%s unknown escape sequence: %s.\n", ErrorMsg(), yytext);
      exit(EXIT_FAILURE);
    }

    value = value1 * 8 + value0;
    yylval.charValue = value;
  }
  else{
    int value, value0, value1, value2;
    value0 = yytext[4] - 48;
    value1 = yytext[3] - 48;
    value2 = yytext[2] - 48;

    if (value0 < 0 || value0 > 7){
      printf("%s unknown escape sequence: %s.\n", ErrorMsg(), yytext);
      exit(EXIT_FAILURE);
    }
    if (value1 < 0 || value1 > 7){
      printf("%s unknown escape sequence: %s.\n", ErrorMsg(), yytext);
      exit(EXIT_FAILURE);
    }
    if (value2 < 0 || value2 > 7){
      printf("%s unknown escape sequence: %s.\n", ErrorMsg(), yytext);
      exit(EXIT_FAILURE);
    }

    value = value2 * 64 + value1 * 8 + value0;

    if (value > 255){
      printf("%s octal escape sequence out of range: %s.\n", ErrorMsg(), yytext);
      exit(EXIT_FAILURE);
    }
    else if(value > 127){
      value = value - 255;
    }

    yylval.charValue = value;
  }
}

void copyLine(){

  if (!strcmp(line, "")){
    line = (char*)malloc(sizeof(char) * (yyleng + 1));
    strcpy(line, yytext);
  }
  else{
    char* str = (char*)malloc(sizeof(char) * (yyleng + strlen(line) + 1));
    strcpy(str, line);
    strcat(str, yytext);
    free(line);
    line = str;
  }

  cursor += yyleng;
}

void resetLine(){

  if (strcmp(line, "")){

    free(line);
    line = (char *)malloc(sizeof(char)*(strlen("") + 1));
    strcpy(line, "");
  }

  cursor = 0;
}
