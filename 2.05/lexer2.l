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

%}
%x comment

space       [ \t\n]
ws          {space}+
digit       [0-9]
number      [\+\-]?{digit}+
letter      [A-Za-z_]
id          {letter}({letter}|{digit})*
string      \"(\\.|[^"\\])*\"
character   \'.+\'
ILcomment   \/\/(.)*\n

%%
"/*"              BEGIN (comment);
<comment>[^*\n]*
<comment>"*"+[^*\/n]*
<comment>\n
<comment>"*"+"/"  BEGIN(INITIAL);
"main"      {                                                                                 return MAIN;}
"return"    {                                                                                 return RETURN;}
"if"        {if(L_DEBUGGING==1) printf("%d FLEX: IF found\n",yylineno);                       return IF;}
"else"        {if(L_DEBUGGING==1) printf("%d FLEX: ELSE found\n",yylineno);                     return ELSE;}
"while"     {if(L_DEBUGGING==1) printf("%d FLEX: WHILE found\n",yylineno);                    return WHILE;}
"*"         {if(L_DEBUGGING==1) printf("%d FLEX: STAR found\n",yylineno);                     return STAR;}
{ws}        {/*DO NOTHING*/}
int         {if(L_DEBUGGING==1) printf("%d FLEX: INT found\n",yylineno);                      return INT;}
char        {if(L_DEBUGGING==1) printf("%d FLEX: CHAR TYPE found\n",yylineno);                return CHAR;}
{number}    {if(L_DEBUGGING==1) printf("%d FLEX: NUMBER found\n",yylineno);                   copyNUM();  return NUMBER;}
{id}        {if(L_DEBUGGING==1) printf("%d FLEX: ID found with name: %s\n",yylineno,yytext);  copyID();   return IDENTIFIER;}
";"         {if(L_DEBUGGING==1) printf("%d FLEX: END_COMMA found\n",yylineno);                return END_COMMA;}
","         {if(L_DEBUGGING==1) printf("%d FLEX: COMMA found\n",yylineno);                    return COMMA;}
"("         {if(L_DEBUGGING==1) printf("%d FLEX: OPEN_ROUND found\n",yylineno);               return OPEN_ROUND;}
")"         {if(L_DEBUGGING==1) printf("%d FLEX: CLOSED_ROUND found\n",yylineno);             return CLOSED_ROUND;}
"["         {if(L_DEBUGGING==1) printf("%d FLEX: OPEN_SQUARED found\n",yylineno);             return OPEN_SQUARED;}
"]"         {if(L_DEBUGGING==1) printf("%d FLEX: CLOSED_SQUARED found\n",yylineno);           return CLOSED_SQUARED;}
"{"         {if(L_DEBUGGING==1) printf("%d FLEX: OPEN_BRACKET found\n",yylineno);             return OPEN_BRACKET;}
"}"         {if(L_DEBUGGING==1) printf("%d FLEX: CLOSED_BRACKET found\n",yylineno);           return CLOSED_BRACKET;}
"="         {if(L_DEBUGGING==1) printf("%d FLEX: EQUAL found\n",yylineno);                    return EQUAL;}
"+"         {if(L_DEBUGGING==1) printf("%d FLEX: PLUS found\n",yylineno);                     return PLUS;}
"-"         {if(L_DEBUGGING==1) printf("%d FLEX: MINUS found\n",yylineno);                    return MINUS;}
"/"         {if(L_DEBUGGING==1) printf("%d FLEX: DIVIDE found\n",yylineno);                   return DIVIDE;}
"%"         {if(L_DEBUGGING==1) printf("%d FLEX: MODULO found\n",yylineno);                   return MODULO;}
">"         {if(L_DEBUGGING==1) printf("%d FLEX: GREATER THEN found\n",yylineno);             return GT;}
"<"         {if(L_DEBUGGING==1) printf("%d FLEX: LESS THEN found\n",yylineno);                return LT;}
"=="        {if(L_DEBUGGING==1) printf("%d FLEX: EQUAL TO found\n",yylineno);                 return ET;}
"!="        {if(L_DEBUGGING==1) printf("%d FLEX: DIFFERENT FROM found\n",yylineno);           return DF;}
"&&"        {if(L_DEBUGGING==1) printf("%d FLEX: LOGIC AND found\n",yylineno);                return AND;}
"||"        {if(L_DEBUGGING==1) printf("%d FLEX: LOGIC OR found\n",yylineno);                 return OR;}
"++"        {if(L_DEBUGGING==1) printf("%d FLEX: INCREMENT found\n",yylineno);                return INC;}
"--"        {if(L_DEBUGGING==1) printf("%d FLEX: DECREMENT OR found\n",yylineno);             return DEC;}
{string}    {if(L_DEBUGGING==1) printf("%d FLEX: STRING found with value %s\n",yylineno,yytext);      copyString(); return STRING;}
{character} {if(L_DEBUGGING==1) printf("%d FLEX: CHAR found with value %s\n",yylineno, yytext);  copyChar();   return CH;}
{ILcomment} {/*InLine Comment*/}
{escape}    {if(L_DEBUGGING==1) printf("%d FLEX: ESCAPE SEQUENCE found with value %s\n",yylineno, yytext);  copyEscape(); return CH;}
"--ST"      {if(L_DEBUGGING==1) printf("%d FLEX: SYMBOL TABLE print request found\n",yylineno); PrintActualST(MainNode);}
"--LINE"    {if(L_DEBUGGING==1) printf("%d FLEX: LINE print request found\n",yylineno); printf("line: %d\n", yylineno);}
%%
//{escape}    {copyChar()}

void copyID(){
  if (strlen(yytext)<1023){
    strcpy(yylval.stringValue, yytext);

    }
  else{
    char line[11];
    sprintf(line,"%d",yylineno); // from int value yylineno a string value

    char * message = (char *) malloc (sizeof(char)*(strlen(line)+strlen("line : WARNING: identifier named :  is too long. Max length: 1023")+strlen(yytext)));
    strcpy (message, "line ");
    strcat (message, line);
    strcat (message, " WARNING: identifier named : ");
    strcat (message, yytext);
    strcat (message, " is too long. Max length: 1023");

    Error_Add(Errors, message);

  }
}

void copyString(){
  yylval.string = (char*)malloc(sizeof(char)*strlen(yytext));
  strcpy(yylval.string,yytext);

}

void copyChar(){
  int len = (int)strlen(yytext);
  if (len != 3){
    printf("%s not allowed multi-character character: %s\n", ErrorMsg(), yytext);
    exit(EXIT_FAILURE);
  }
  yylval.charValue = yytext[1]; // yytext[1], the index 1 is the char value, index 0 is the apex symbol

}

void copyNUM(){
  long support;
  if(strlen(yytext)<12){
    support = atof (yytext);
    yylval.intValue = support;

    }
  else{
    printf("Error: out of range number. This interpreter works with integer numbers only.\n");
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
      if (value > 0 && value < 8){
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
