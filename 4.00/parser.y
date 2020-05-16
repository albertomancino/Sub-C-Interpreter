%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "lexer.h"
#include "Tree.h"
#include "parser.h"
#include "exec.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

enum exprType;

int L_DEBUGGING = 0;
int P_DEBUGGING = 0;
int TREE_DEBUGGING = 0;
int TREE_BUILDING = 1;
int ST_DEBUGGING = 0;
int EXEC = 1;
int ERR = 1;

int yylineno;
ProgramNode * MainNode;
struct ErrorList * Errors;
struct TreeNode * NullTreeNode;
FILE *yyin;

%}


%union
{
    long intValue;
    char * string;
    char charValue;
    struct TreeNode *node;
}


%token INT
%token CHAR
%token <string> IDENTIFIER
%token <intValue> NUMBER
%token EQUAL
%token END_COMMA
%token OPEN_ROUND CLOSED_ROUND
%token OPEN_SQUARED CLOSED_SQUARED
%token OPEN_BRACKET CLOSED_BRACKET
%token MAIN
%token RETURN
%token <string> STRING
%token <charValue> CH
%token IF
%token ELSE
%token WHILE
%token INC
%token DEC
%token AMP
%left COMMA
%left GT LT ET DF
%left AND OR
%left PLUS MINUS
%left STAR DIVIDE MODULO



%type <node> arguments_declaration
%type <node> expr_list
%type <node> start_scope
%type <node> arguments_declaration_list
%type <node> declaration
%type <node> function_call
%type <node> multi_dec
%type <node> multi_asgn
%type <node> declaration_and_assignment
%type <node> assignment
%type <node> array_inizializer
%type <node> return_statement
%type <node> expr
%type <node> pre_incdec
%type <node> post_incdec
%type <node> operation
%type <node> comparison
%type <node> if_else_statement
%type <node> if_statement
%type <node> if_declaration
%type <node> else_statement
%type <node> else_declaration
%type <node> while_statement
%type <node> condition
%type <node> while_declaration
%type <intValue> type
%type <node> variable

%expect 1 // https://www.math.utah.edu/docs/info/bison_8.html


%%

program
:
| global_scope function_list main_function
| global_scope main_function
| function_list main_function
| main_function
;

global_scope
: global_scope_body                                                             {if(P_DEBUGGING==1) printf("BISON: Global_scope found\n");}
;

global_scope_body
: global_statements                                                             {if(P_DEBUGGING==1) printf("BISON: Global_scope_body found\n");}
| global_scope global_statements                                                {if(P_DEBUGGING==1) printf("BISON: Global_scope_body found\n");}
;

global_statements
: declaration END_COMMA                                                         {if(P_DEBUGGING==1) printf("BISON: Global declaration statement found\n");                if(TREE_BUILDING) Add_Node_Tree(MainNode, $1);  if(EXEC) exec_DclN(MainNode, $1)}
| declaration_and_assignment END_COMMA                                          {if(P_DEBUGGING==1) printf("BISON: Global declaration and assignment statement found\n"); if(TREE_BUILDING) Add_Node_Tree(MainNode, $1);}
| multi_dec END_COMMA
;

function_list
: function                                                                      {if(P_DEBUGGING==1) printf("BISON: Function list found1\n");}
| function_list function                                                        {if(P_DEBUGGING==1) printf("BISON: Function list found2\n");}
;

main_function
: main_function_declaration statement_list CLOSED_BRACKET                       {if(P_DEBUGGING==1) printf("BISON: MAIN function found\n"); /* Resetting global scope as acutal scope*/ MainNode -> actual_stack = MainNode -> global_scope_stack;}
| main_function_declaration CLOSED_BRACKET                                      {if(P_DEBUGGING==1) printf("BISON: MAIN function found\n"); /* Resetting global scope as acutal scope*/ MainNode -> actual_stack = MainNode -> global_scope_stack;}
;

main_function_declaration
: INT MAIN arguments_declaration OPEN_BRACKET                                   {if(P_DEBUGGING==1) printf("BISON: MAIN function declaration found\n");    if(TREE_BUILDING) create_MainFunction(MainNode, $3);}
;

function
: function_declaration statement_list CLOSED_BRACKET                            {if(P_DEBUGGING==1) printf("BISON: Function found\n"); /* Resetting global scope as acutal scope*/ MainNode -> actual_stack = MainNode -> global_scope_stack;}
| function_declaration CLOSED_BRACKET                                           {if(P_DEBUGGING==1) printf("BISON: Function found\n"); /* Resetting global scope as acutal scope*/ MainNode -> actual_stack = MainNode -> global_scope_stack;}
;

function_declaration
: declaration arguments_declaration OPEN_BRACKET                                {if(P_DEBUGGING==1) printf("BISON: Function declaration found\n");         if(TREE_BUILDING) create_FunctionNode($1,$2);}
;


arguments_declaration
: OPEN_ROUND arguments_declaration_list CLOSED_ROUND                            {if(P_DEBUGGING==1) printf("BISON: arguments_declaration1 found\n");       if(TREE_BUILDING) $$ = $2}
| OPEN_ROUND CLOSED_ROUND                                                       {if(P_DEBUGGING==1) printf("BISON: arguments_declaration2 found\n");       if(TREE_BUILDING) $$ = create_Arg_ListNode(NULL, NULL);}
;

arguments_declaration_list
: declaration                                                                   {if(P_DEBUGGING==1) printf("BISON: arguments_declaration_list1 found\n");  if(TREE_BUILDING) $$ = create_Arg_ListNode(NULL, $1);}
| arguments_declaration_list COMMA declaration                                  {if(P_DEBUGGING==1) printf("BISON: arguments_declaration_list2 found\n");  if(TREE_BUILDING) $$ = create_Arg_ListNode($1, $3);}
;

scope
: start_scope statement_list CLOSED_BRACKET                                     {if(P_DEBUGGING==1) printf("BISON: End of the scope found\n");             if(TREE_BUILDING) ScopeStack_Pop(MainNode -> actual_stack);/*SymbolTable_Print(MainNode->ActualScope->last -> ThisScope.Tree -> node.ST); ScopeStack_Rem(MainNode->ActualScope);*/}
| start_scope CLOSED_BRACKET                                                    {if(P_DEBUGGING==1) printf("BISON: New empty scope found\n");              if(TREE_BUILDING) ScopeStack_Pop(MainNode -> actual_stack);/*ScopeStack_Rem(MainNode->ActualScope);*/}
;

start_scope
: OPEN_BRACKET                                                                  {if(P_DEBUGGING==1) printf("BISON: Start of the scope found\n");           if(TREE_BUILDING) { $$ = create_ScopeNode(); Add_Node_Tree(MainNode, $$); SetAs_ActualScope(MainNode, $$, Check_activation());}}
;

statement_list
: statement_scope
| statement_list statement_scope
;

statement_scope
: statement
| scope
;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

statement
: expr END_COMMA                                                                {if(P_DEBUGGING==1) printf("BISON: Expr statement found\n");                                       if(TREE_BUILDING) Add_Node_Tree(MainNode, $1); if(Check_activation()) exec_Expression($1);}
| return_statement                                                              {if(P_DEBUGGING==1) printf("BISON: Return statement found\n");                                     if(TREE_BUILDING) Add_Node_Tree(MainNode, $1);}
| declaration END_COMMA                                                         {if(P_DEBUGGING==1) printf("BISON: Declaration statement found\n");                                if(TREE_BUILDING) Add_Node_Tree(MainNode, $1); exec_DclN(MainNode,$1);}
| assignment END_COMMA                                                          {if(P_DEBUGGING==1) printf("BISON: Assignment statement found\n");                                 if(TREE_BUILDING) Add_Node_Tree(MainNode, $1); if(Check_activation()) exec_Asgn(MainNode,$1);}
| multi_dec END_COMMA                                                           {if(P_DEBUGGING==1) printf("BISON: Multi declaration statement found\n");                          if(TREE_BUILDING) Add_Node_Tree(MainNode, $1); if(Check_activation()) exec_Multi_DclN($1);}
| multi_asgn END_COMMA                                                          {if(P_DEBUGGING==1) printf("BISON: Multi assignment statement found\n");                           if(TREE_BUILDING) Add_Node_Tree(MainNode, $1); if(Check_activation()) exec_Multi_Asgn($1);}
| declaration_and_assignment END_COMMA                                          {if(P_DEBUGGING==1) printf("BISON: Declaration and assignment statement found\n");                 if(TREE_BUILDING) Add_Node_Tree(MainNode, $1); if(Check_activation()) exec_DclN_Asgn($1)}
| if_else_statement                                                             {if(P_DEBUGGING==1) printf("BISON: IF statement statement found\n");                               if(TREE_BUILDING) Add_Node_Tree(MainNode, $1); if(Check_activation()) exec_ifElse($1)}
| while_statement                                                               {if(P_DEBUGGING==1) printf("BISON: WHILE statement statement found\n");                            if(TREE_BUILDING) Add_Node_Tree(MainNode, $1); if(Check_activation()) exec_while($1)}
| END_COMMA                                                                     {if(P_DEBUGGING==1) printf("BISON: Empty statement found\n");}
;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
function_call
: IDENTIFIER OPEN_ROUND expr_list CLOSED_ROUND                                  {if(P_DEBUGGING==1) printf("BISON: Function call1 found\n");               if(TREE_BUILDING) $$ = create_Function_CallNode(MainNode, $1, $3);         if(TREE_DEBUGGING) printf("TREE: Function call statement node created\n");}
| IDENTIFIER OPEN_ROUND CLOSED_ROUND                                            {if(P_DEBUGGING==1) printf("BISON: Function call2 found\n");               if(TREE_BUILDING) $$ = create_Function_CallNode(MainNode, $1, NULL);       if(TREE_DEBUGGING) printf("TREE: Function call statement node created\n");}
;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



if_else_statement
: if_statement                                                                  {if(P_DEBUGGING==1) printf("BISON: If-else statement1 found\n");           if(TREE_BUILDING) $$ = create_IfElseNode($1, NULL);                        if(TREE_DEBUGGING) printf("TREE: If-else statement node created\n");}
| if_statement else_statement                                                   {if(P_DEBUGGING==1) printf("BISON: If-else statement1 found\n");           if(TREE_BUILDING) $$ = create_IfElseNode($1, $2);                          if(TREE_DEBUGGING) printf("TREE: If-else statement node created\n");}
;

else_statement
: else_declaration OPEN_BRACKET statement_list CLOSED_BRACKET                   {if(P_DEBUGGING==1) printf("BISON: Else statement1 found\n");              if(TREE_BUILDING) $$ = create_ElseNode($1);                                if(TREE_DEBUGGING) printf("TREE: Else statement node created\n");}
| else_declaration statement                                                    {if(P_DEBUGGING==1) printf("BISON: Else statement2 found\n");              if(TREE_BUILDING) $$ = create_ElseNode($1);                                if(TREE_DEBUGGING) printf("TREE: Else statement node created\n");}
;

if_statement
: if_declaration condition OPEN_BRACKET statement_list CLOSED_BRACKET           {if(P_DEBUGGING==1) printf("BISON: If statement1 found\n");                if(TREE_BUILDING) $$ = create_IfNode($1,$2);                               if(TREE_DEBUGGING) printf("TREE: If statement node created\n");}
| if_declaration condition OPEN_BRACKET CLOSED_BRACKET                          {if(P_DEBUGGING==1) printf("BISON: If statement2 found\n");                if(TREE_BUILDING) $$ = create_IfNode($1,$2);                               if(TREE_DEBUGGING) printf("TREE: If statement node created\n");}
| if_declaration condition statement                                            {if(P_DEBUGGING==1) printf("BISON: If statement3 found\n");                if(TREE_BUILDING) $$ = create_IfNode($1,$2);                               if(TREE_DEBUGGING) printf("TREE: If statement node created\n");}
;

else_declaration
: ELSE                                                                          {if(P_DEBUGGING==1) printf("BISON: Else declaration found\n");             if(TREE_BUILDING) $$ = create_ElseDeclaration();                           if(TREE_DEBUGGING) printf("TREE: Else node created\n");}
;

if_declaration
: IF                                                                            {if(P_DEBUGGING==1) printf("BISON: If declaration found\n");               if(TREE_BUILDING) $$ = create_IfDeclaration();                             if(TREE_DEBUGGING) printf("TREE: If node created\n");}
;

while_statement
: while_declaration condition OPEN_BRACKET statement_list CLOSED_BRACKET        {if(P_DEBUGGING==1) printf("BISON: While statement1 found\n");             if(TREE_BUILDING) $$ = create_WhileNode($1,$2);                            if(TREE_DEBUGGING) printf("TREE: While statement node created\n");}
| while_declaration condition OPEN_BRACKET CLOSED_BRACKET                       {if(P_DEBUGGING==1) printf("BISON: While statement2 found\n");             if(TREE_BUILDING) $$ = create_WhileNode($1,$2);                            if(TREE_DEBUGGING) printf("TREE: While statement node created\n");}
| while_declaration condition statement                                         {if(P_DEBUGGING==1) printf("BISON: While statement3 found\n");             if(TREE_BUILDING) $$ = create_WhileNode($1,$2);                            if(TREE_DEBUGGING) printf("TREE: While statement node created\n");}
;

condition
: OPEN_ROUND expr CLOSED_ROUND                                                  {if(P_DEBUGGING==1) printf("BISON: While condition1 found\n");             if(TREE_BUILDING)  $$ = create_Condition($2);                              if(TREE_DEBUGGING) printf("TREE: Condition node created\n");}
| OPEN_ROUND assignment CLOSED_ROUND                                            {if(P_DEBUGGING==1) printf("BISON: While condition2 found\n");             if(TREE_BUILDING)  $$ = create_Condition($2);                              if(TREE_DEBUGGING) printf("TREE: Condition node created\n");}
;

while_declaration
: WHILE                                                                         {if(P_DEBUGGING==1) printf("BISON: While declaration found\n");            if(TREE_BUILDING) $$ = create_WhileDeclaration();                          if(TREE_DEBUGGING) printf("TREE: While node created\n");}
;

multi_asgn
: assignment COMMA assignment                                                   {if(P_DEBUGGING==1) printf("BISON: Multi assignment1 found\n");            if(TREE_BUILDING) $$ = create_MultiAssignment($1, $3);                     if(TREE_DEBUGGING) printf("TREE: Multi assignment node created\n");}
| multi_asgn COMMA assignment                                                   {if(P_DEBUGGING==1) printf("BISON: Multi assignment2 found\n");            if(TREE_BUILDING) $$ = create_MultiAssignment($1, $3);                     if(TREE_DEBUGGING) printf("TREE: Multi assignment node created\n");}
;

multi_dec
: declaration COMMA variable                                                    {if(P_DEBUGGING==1) printf("BISON: Multi declaration1 found\n");           if(TREE_BUILDING) $$ = create_MultiDeclaration($1, $3, 1);                 if(TREE_DEBUGGING) printf("TREE: Multi declaration node created\n");}
| declaration_and_assignment COMMA variable                                     {if(P_DEBUGGING==1) printf("BISON: Multi declaration2 found\n");           if(TREE_BUILDING) $$ = create_MultiDeclaration($1, $3, 1);                 if(TREE_DEBUGGING) printf("TREE: Multi declaration node created\n");}
| multi_dec EQUAL expr                                                          {if(P_DEBUGGING==1) printf("BISON: Multi declaration3 found\n");           if(TREE_BUILDING) $$ = create_MultiDeclaration($1, $3, 0);                 if(TREE_DEBUGGING) printf("TREE: Multi declaration node created\n");}
| multi_dec EQUAL array_inizializer                                             {if(P_DEBUGGING==1) printf("BISON: Multi declaration4 found\n");           if(TREE_BUILDING) $$ = create_MultiDeclaration($1, $3, 0);                 if(TREE_DEBUGGING) printf("TREE: Multi declaration node created\n");}
| multi_dec COMMA variable                                                      {if(P_DEBUGGING==1) printf("BISON: Multi declaration5 found\n");           if(TREE_BUILDING) $$ = create_MultiDeclaration($1, $3, 1);                  if(TREE_DEBUGGING) printf("TREE: Multi declaration node created\n");}
;

declaration_and_assignment
: declaration EQUAL expr                                                        {if(P_DEBUGGING==1) printf("BISON: declaration and assignment 1 found\n"); if(TREE_BUILDING) $$ = create_Declaration_AssignmentNode ($1, $3);         if(TREE_DEBUGGING) printf("TREE: Declaration and Assignment node created\n");}
| declaration EQUAL array_inizializer                                           {if(P_DEBUGGING==1) printf("BISON: declaration and assignment 2 found\n"); if(TREE_BUILDING) $$ = create_Declaration_AssignmentNode ($1, $3);         if(TREE_DEBUGGING) printf("TREE: Declaration and Assignment node created\n");}
| declaration_and_assignment EQUAL expr                                         {if(P_DEBUGGING==1) printf("BISON: declaration and assignment 3 found\n"); if(TREE_BUILDING) $$ = create_Declaration_AssignmentNode ($1, $3);         if(TREE_DEBUGGING) printf("TREE: Declaration and Assignment node created\n");}
;

declaration
: type variable                                                                 {if(P_DEBUGGING==1) printf("BISON: declaration found\n");                  if(TREE_BUILDING) $$ = create_DeclarationNode($1, $2);                     if(TREE_DEBUGGING) printf("TREE: Declaration node created\n");}
;

assignment
: expr EQUAL expr                                                               {if(P_DEBUGGING==1) printf("BISON: assignment1 found\n");                  if(TREE_BUILDING) $$ = create_AssignmentNode(MainNode, $1, $3);            if(TREE_DEBUGGING) printf("TREE: Assignment node created\n")}
| assignment EQUAL expr                                                         {if(P_DEBUGGING==1) printf("BISON: assignment2 found\n");                  if(TREE_BUILDING) $$ = create_AssignmentNode(MainNode, $1, $3);            if(TREE_DEBUGGING) printf("TREE: Assignment node created\n")}
;

array_inizializer
: OPEN_BRACKET expr_list CLOSED_BRACKET                                         {if(P_DEBUGGING==1) printf("BISON: array initializer found\n");            if(TREE_BUILDING) $$=$2;}
;

expr_list
: expr                                                                          {if(P_DEBUGGING==1) printf("BISON: expression1 list found\n");             if(TREE_BUILDING) $$ = create_Expr_ListNode(NULL, $1);                     if(TREE_DEBUGGING) printf("TREE: Expression list node created\n");}
| expr_list COMMA expr                                                          {if(P_DEBUGGING==1) printf("BISON: expression2 list found\n");             if(TREE_BUILDING) $$ = create_Expr_ListNode($1, $3);                       if(TREE_DEBUGGING) printf("TREE: Expression list node created\n");}
;

return_statement
: RETURN expr END_COMMA                                                         {if(P_DEBUGGING==1) printf("BISON: return statement1 found\n");            if(TREE_BUILDING) $$ = create_ReturnNode($2);                              if(TREE_DEBUGGING) printf("TREE: Return node created\n");}
| RETURN END_COMMA                                                              {if(P_DEBUGGING==1) printf("BISON: return statement2 found\n");            if(TREE_BUILDING) $$ = create_ReturnNode(NULL);                            if(TREE_DEBUGGING) printf("TREE: Return node created\n");}
;

expr
: comparison                                                                    {if(P_DEBUGGING==1) printf("BISON: comparison -> expr\n");                 if(TREE_BUILDING) $$ = $1;                                                 if(TREE_DEBUGGING) printf("TREE: Expr node compare type created\n");}
| NUMBER                                                                        {if(P_DEBUGGING==1) printf("BISON: integer -> expr\n");                    if(TREE_BUILDING) $$ = create_ExprNode(NUM, $1, NULL, NULL, NULL, 0);      if(TREE_DEBUGGING) printf("TREE: Expr node integer type created\n");}
| PLUS NUMBER                                                                   {if(P_DEBUGGING==1) printf("BISON: positive integer -> expr\n");           if(TREE_BUILDING) $$ = create_ExprNode(NUM, $2, NULL, NULL, NULL, 0);      if(TREE_DEBUGGING) printf("TREE: Expr node integer type created\n");}
| MINUS NUMBER                                                                  {if(P_DEBUGGING==1) printf("BISON: negative integer -> expr\n");           if(TREE_BUILDING) $$ = create_ExprNode(NUM, -$2, NULL, NULL, NULL, 0);     if(TREE_DEBUGGING) printf("TREE: Expr node integer type created\n");}
| variable                                                                      {if(P_DEBUGGING==1) printf("BISON: variable -> expr\n");                   if(TREE_BUILDING) if(Check_ArrayDimension($1)) $$ = $1;                    if(TREE_DEBUGGING) printf("TREE: Expr node variable type created\n");}
| STRING                                                                        {if(P_DEBUGGING==1) printf("BISON: expr STRING -> expr\n");                if(TREE_BUILDING) $$ = create_ExprNode(STR, 0, $1, NULL, NULL, 0);         if(TREE_DEBUGGING) printf("TREE: Expr node string type created\n");}
| CH                                                                            {if(P_DEBUGGING==1) printf("BISON: expr character -> expr\n");             if(TREE_BUILDING) $$ = create_ExprNode(C, 0, &$1, NULL, NULL, 0);          if(TREE_DEBUGGING) printf("TREE: Expr node char type created\n");}
| function_call                                                                 {if(P_DEBUGGING==1) printf("BISON: expr function_call -> expr\n");         if(TREE_BUILDING) $$ = $1;                                                 if(TREE_DEBUGGING) printf("TREE: Expr node function call type created\n");}
| operation                                                                     {if(P_DEBUGGING==1) printf("BISON: expr PLUS expr -> expr\n");             if(TREE_BUILDING) $$ = $1;                                                 if(TREE_DEBUGGING) printf("TREE: Expr node operation type created\n");}
| pre_incdec                                                                    {if(P_DEBUGGING==1) printf("BISON: pre increment_decrement -> expr\n");    if(TREE_BUILDING) $$ = $1;                                                 if(TREE_DEBUGGING) printf("TREE: Expr node pre-increment/decrement type created\n");}
| post_incdec                                                                   {if(P_DEBUGGING==1) printf("BISON: post increment_decrement -> expr\n");   if(TREE_BUILDING) $$ = $1;                                                 if(TREE_DEBUGGING) printf("TREE: Expr node post-increment/decrement type created\n");}
| OPEN_ROUND assignment CLOSED_ROUND                                            {if(P_DEBUGGING==1) printf("BISON: parentheses assignment -> expr\n");     if(TREE_BUILDING) $$ = create_ExprNode(PA, 0, NULL, $2, NULL, 0);          if(TREE_DEBUGGING) printf("TREE: Expr node parentheses assignment type created\n");}
| AMP variable                                                                  {if(P_DEBUGGING==1) printf("BISON: variable address -> expr\n");           if(TREE_BUILDING) $$ = create_ExprNode(ADD, 0, NULL, $2, NULL, 0);         if(TREE_DEBUGGING) printf("TREE: Expr node variable address type created\n");}
;

pre_incdec
: INC variable                                                                  {if(P_DEBUGGING==1) printf("BISON: pre increment ++ found\n");             if(TREE_BUILDING) $$ = create_IncDecNode(PI, $2);                          if(TREE_DEBUGGING) printf("TREE: Expr node post increment type created\n");}
| DEC variable                                                                  {if(P_DEBUGGING==1) printf("BISON: pre decrement -- found\n");             if(TREE_BUILDING) $$ = create_IncDecNode(PD, $2);                          if(TREE_DEBUGGING) printf("TREE: Expr node post decrement type created\n");}
;

post_incdec
: variable INC                                                                  {if(P_DEBUGGING==1) printf("BISON: post increment ++ found\n");            if(TREE_BUILDING) $$ = create_IncDecNode(IP, $1);                          if(TREE_DEBUGGING) printf("TREE: Expr node post increment type created\n");}
| variable DEC                                                                  {if(P_DEBUGGING==1) printf("BISON: post decrement -- found\n");            if(TREE_BUILDING) $$ = create_IncDecNode(DP, $1);                          if(TREE_DEBUGGING) printf("TREE: Expr node post decrement type created\n");}
;

operation
: expr PLUS expr                                                                {if(P_DEBUGGING==1) printf("BISON: expr PLUS expr -> operation\n");        if(TREE_BUILDING) $$ = create_OperationNode(MainNode, $1, $3, SUM);        if(TREE_DEBUGGING) printf("TREE: Expr node plus type created\n");}
| expr MINUS expr                                                               {if(P_DEBUGGING==1) printf("BISON: expr MINUS expr -> operation\n");       if(TREE_BUILDING) $$ = create_OperationNode(MainNode, $1, $3, DIF);        if(TREE_DEBUGGING) printf("TREE: Expr node difference type created\n");}
| expr STAR expr                                                                {if(P_DEBUGGING==1) printf("BISON: expr STAR expr -> operation\n");        if(TREE_BUILDING) $$ = create_OperationNode(MainNode, $1, $3, TIM);        if(TREE_DEBUGGING) printf("TREE: Expr node times type created\n");}
| expr DIVIDE expr                                                              {if(P_DEBUGGING==1) printf("BISON: expr DIVIDE expr -> operation\n");      if(TREE_BUILDING) $$ = create_OperationNode(MainNode, $1, $3, DIV);        if(TREE_DEBUGGING) printf("TREE: Expr node divide type created\n");}
| expr MODULO expr                                                              {if(P_DEBUGGING==1) printf("BISON: expr MODULO expr -> operation\n");      if(TREE_BUILDING) $$ = create_OperationNode(MainNode, $1, $3, MOD);        if(TREE_DEBUGGING) printf("TREE: Expr node modulo type created\n");}
| OPEN_ROUND expr CLOSED_ROUND                                                  {if(P_DEBUGGING==1) printf("BISON: ( expr ) -> operation\n");              if(TREE_BUILDING) $$ = create_OperationNode(MainNode, $2, $2, RND);        if(TREE_DEBUGGING) printf("TREE: Expr node round brackets type created\n");}
;

comparison
: expr AND expr                                                                 {if(P_DEBUGGING==1) printf("BISON: AND -> comparison\n");                  if(TREE_BUILDING) $$ = create_ComparisonNode(MainNode, $1, $3, AND_);      if(TREE_DEBUGGING) printf("TREE: Expr node and type created\n");}
| expr OR expr                                                                  {if(P_DEBUGGING==1) printf("BISON: OR -> comparison\n");                   if(TREE_BUILDING) $$ = create_ComparisonNode(MainNode, $1, $3, OR_);       if(TREE_DEBUGGING) printf("TREE: Expr node or type created\n");}
| expr GT expr                                                                  {if(P_DEBUGGING==1) printf("BISON: GT -> comparison\n");                   if(TREE_BUILDING) $$ = create_ComparisonNode(MainNode, $1, $3, GREAT_);    if(TREE_DEBUGGING) printf("TREE: Expr node greater than type created\n");}
| expr LT expr                                                                  {if(P_DEBUGGING==1) printf("BISON: LT -> comparison\n");                   if(TREE_BUILDING) $$ = create_ComparisonNode(MainNode, $1, $3, LESS_);     if(TREE_DEBUGGING) printf("TREE: Expr node less then type created\n");}
| expr ET expr                                                                  {if(P_DEBUGGING==1) printf("BISON: ET -> comparison\n");                   if(TREE_BUILDING) $$ = create_ComparisonNode(MainNode, $1, $3, EQUAL_);    if(TREE_DEBUGGING) printf("TREE: Expr node equal to type created\n");}
| expr DF expr                                                                  {if(P_DEBUGGING==1) printf("BISON: DF -> comparison\n");                   if(TREE_BUILDING) $$ = create_ComparisonNode(MainNode, $1, $3, DIFF_);     if(TREE_DEBUGGING) printf("TREE: Expr node different from type created\n");}
;

type
: INT                                                                           {if(P_DEBUGGING==1) printf("BISON: INT -> type\n");                        if(TREE_BUILDING) $$ = INT_ }
| CHAR                                                                          {if(P_DEBUGGING==1) printf("BISON: CHAR -> type\n");                       if(TREE_BUILDING) $$ = CHAR_}
;

variable
: IDENTIFIER                                                                    {if(P_DEBUGGING==1) printf("BISON: identifier -> variable\n");             if(TREE_BUILDING) $$ = create_ExprNode(ID, 0, $1, NULL, NULL, 0);          if(TREE_DEBUGGING) printf("TREE: Variable node identifier type created\n");}
| IDENTIFIER OPEN_SQUARED expr CLOSED_SQUARED                                   {if(P_DEBUGGING==1) printf("BISON: array -> variable\n");                  if(TREE_BUILDING) $$ = create_ExprNode(VEC, 0, $1, $3, NULL, 0);           if(TREE_DEBUGGING) printf("TREE: Variable node vector type created\n");}
| IDENTIFIER OPEN_SQUARED CLOSED_SQUARED                                        {if(P_DEBUGGING==1) printf("BISON: array [] -> variable\n");               if(TREE_BUILDING) $$ = create_ExprNode(VEC, 0, $1, NULL, NULL, 0);         if(TREE_DEBUGGING) printf("TREE: Variable node vector type created\n");}
;

%%

/* EPILOGO */



  int yyerror (const char *error) {
    printf ("%s unexpected expression.\n", ErrorMsg());
    exit(EXIT_FAILURE);
    return 0;
  }


////////////////////  arguments_declaration_list PRODUCTION  ///////////////////
struct TreeNode * create_Arg_ListNode(struct TreeNode *arg_list, struct TreeNode *arg){

  // first element of the list
  if (arg_list == NULL){

    struct TreeNode * newTreeNode = TreeNodeInitialization (); // generic Tree Node memory space allocation
    // Linking specific node to generic Tree Node
    newTreeNode -> nodeType = ArgLst;

    if (arg != NULL){
      TreeNodeList_Add(newTreeNode -> child_list, arg);
      return newTreeNode;
    }
    // in case of 0 arguments
    else return newTreeNode;
  }
  else{
    TreeNodeList_Add(arg_list->child_list, arg);
    return arg_list;
  }
}

////////////////////  SCOPE PRODUCTION /////////////////////////////////////////

struct TreeNode * create_ScopeNode(){

  struct TreeNode * newTreeNode = TreeNodeInitialization (); // generic Tree Node memory space allocation

  // Linking specific node to generic Tree Node
  newTreeNode -> nodeType = Scope;
  newTreeNode -> node.ST = SymbolTable_Set();

  return newTreeNode;
}

////////////////////  expr_list PRODUCTION  ////////////////////////////////////

struct TreeNode * create_Expr_ListNode(struct TreeNode * expr_list, struct TreeNode * expr){

  if (expr -> nodeType == Expr){
    // first expression of the list
    if (expr_list == NULL){ // first element of the list

      struct TreeNode * newTreeNode = TreeNodeInitialization (); // generic Tree Node memory space allocation
      // Linking specific node to generic Tree Node
      newTreeNode -> nodeType = ExprLst;
      TreeNodeList_Add(newTreeNode -> child_list, expr);
      return newTreeNode;
    }
    // subsequent expression of the list
    else{
      if( expr_list -> nodeType == ExprLst){
        TreeNodeList_Add(expr_list -> child_list, expr);
        return expr_list;
      }
      else{
        printf("%s create_Expr_ListNode - unexpected Tree Node type. Expected ExprLst, found %s.\n", ErrorMsg(), NodeTypeString(expr_list));
        exit(EXIT_FAILURE);
      }
    }
  }
  else{
    printf("%s create_Expr_ListNode - unexpected Tree Node type. Expected Expr, found %s.\n", ErrorMsg(), NodeTypeString(expr));
    exit(EXIT_FAILURE);
  }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


////////////////////  function_call PRODUCTION  ////////////////////////////////

struct TreeNode * create_Function_CallNode(ProgramNode * prog, char * function_id, struct TreeNode * expr_list){

  if (expr_list != NULL) Check_NodeType(ExprLst, expr_list, "create_Function_CallNode");

  if (!strcmp(function_id, "printf")){
    struct TreeNode * node = create_ExprNode(FC, 0, "printf", expr_list, NULL, 0);
    Check_PrintfCallConcistency(node);
    return node;
  }
  else if(!strcmp(function_id, "scanf")){
    struct TreeNode * node = create_ExprNode(FC, 0, "scanf", expr_list, NULL, 0);
    Check_ScanfCallConcistency(node);
    return node;
  }
  else{

    struct TreeNode * node = create_ExprNode(FC, 0, function_id, expr_list, NULL, 0);
    Check_FunctionCallConcistency(prog, node);
    return node;
  }
}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


////////////////////  comparison PRODUCTION  ///////////////////////////////////

struct TreeNode * create_ComparisonNode(ProgramNode * prog, struct TreeNode * first, struct TreeNode * second, enum cmpType cmptype){

  if (first == NULL || second == NULL) {
      printf("%s create_ComparisonNode - comparison missing one or two expressions\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
    else{

      struct TreeNode * node = create_ExprNode(CMP, 0, NULL, first, second, cmptype);
      Check_ComparisonConcistency(prog, node);

      return node;
    }
}

////////////////////  main function PRODUCTION  ////////////////////////////////

void create_MainFunction(ProgramNode * prog, struct TreeNode * arguments){

  // arguments must be a ArgLst TreeNode
  if (arguments -> nodeType != ArgLst){
    printf("%s mainFunction - incorrect call. ArgLst TreeNode expected\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  else{
    // main function must not have arguments. argc and argv arguments are not supported.
    if(arguments -> child_list -> elements != 0){
        printf("%s this interpreter does not support main function arguments.\n",ErrorMsg());
        exit(EXIT_FAILURE);
    }
    else{

      struct TreeNode * identifier = create_ExprNode(ID, 0, "main", NULL, NULL, 0);
      FunNodeList_Add (prog, create_DeclarationNode(INT_, identifier));
      // main scope is always an active scope
      Scope_Activation();
    }
  }
}

////////////////////  function node PRODUCTION  ////////////////////////////////

void create_FunctionNode(struct TreeNode * declaration, struct TreeNode * parameters){

  // check parameters
  Check_NodeType(DclN, declaration, "create_functionNode");
  Check_NodeType(ArgLst, parameters, "create_functionNode");

  FunNodeList_Add (MainNode, declaration);
  Add_Node_Tree(MainNode, parameters);

  // declaration of parameters
  for (int i = 0; i < parameters -> child_list -> elements; i++){

    struct TreeNode * parameter;

    if (i == 0) parameter = parameters -> child_list -> first;
    else parameter = parameter -> next;

    if (parameter -> node.DclN -> arrayDim != NULL){ if (!IsCostant(parameter -> node.DclN -> arrayDim)) parameter -> node.DclN -> ignore = 1;}
    else if (parameter -> node.DclN -> arrayDim == NULL && (parameter -> node.DclN -> type == INT_V_ || parameter -> node.DclN -> type == CHAR_V_)){
      parameter -> node.DclN -> arrayDim = create_ExprNode(NUM, 0, NULL, NULL, NULL, 0);
      parameter -> node.DclN -> ignore = 1;
    }

    exec_DclN(MainNode, parameter);
  }
}

////////////////////  if PRODUCTION  ///////////////////////////////////////////

struct TreeNode * create_IfElseNode(struct TreeNode * if_node, struct TreeNode * else_node){


  Check_NodeType(If, if_node, "create_IfElseNode");

  // creating a generic Tree Node with memory allocation
  struct TreeNode * newIfElseNode = TreeNodeInitialization();
  // Tree Node Type
  newIfElseNode -> nodeType = IfElse;

  TreeNodeList_Add(newIfElseNode -> child_list, if_node);

  // exec if statement if the scope is active
   if(Check_activation()) {exec_if(if_node);}

  // if there's an else condition
  if (else_node != NULL){
    if (else_node -> nodeType == Else)  TreeNodeList_Add(newIfElseNode -> child_list, else_node);
    else{
      printf("%s create_IfElseNode - unexpected Tree Node type. Expected Else, found %s.\n", ErrorMsg(), NodeTypeString(else_node));
      exit(EXIT_FAILURE);
    }
  }

  return newIfElseNode;
}

struct TreeNode * create_ElseNode (struct TreeNode * else_node){

  Check_NodeType(Else, else_node, "create_ElseNode");

  // else scope is ended
  ScopeStack_Pop(MainNode -> actual_stack);

  return else_node;
}

struct TreeNode * create_ElseDeclaration(){

  // creating a generic Tree Node with memory allocation
  struct TreeNode * newElseNode = TreeNodeInitialization();
  // Tree Node Type
  newElseNode -> nodeType = Else;

  // creating else scope
  struct TreeNode * ElseScope = create_ScopeNode();
  // linking else scope to the while node
  TreeNodeList_Add(newElseNode -> child_list, ElseScope);
  // setting else scope as new actual scope
  // else scope is inactive by default
  SetAs_ActualScope(MainNode, ElseScope, 0);

  return newElseNode;
}

struct TreeNode * create_IfNode (struct TreeNode * if_node, struct TreeNode * condition){


  Check_NodeType(If, if_node, "create_IfNode");
  Check_NodeType(Expr, condition, "create_IfNode");

  // linking condition to the if node
  TreeNodeList_Add(if_node -> child_list, condition);
  // if scope is ended
  ScopeStack_Pop(MainNode -> actual_stack);

  return if_node;
}

struct TreeNode * create_IfDeclaration(){

  // creating a generic Tree Node with memory allocation
  struct TreeNode * newIfNode = TreeNodeInitialization();
  // Tree Node Type
  newIfNode -> nodeType = If;

  // creating if scope
  struct TreeNode * ifScope = create_ScopeNode();
  // linking if scope to the if node
  TreeNodeList_Add(newIfNode -> child_list, ifScope);
  // setting if scope as new actual scope
  // if scope is inactive by default
  SetAs_ActualScope(MainNode, ifScope, 0);
  // by default if condition is not satisfied
  newIfNode -> node.flag = 0;

  return newIfNode;
}

////////////////////  while PRODUCTION  ////////////////////////////////////////

struct TreeNode * create_WhileNode(struct TreeNode * while_node, struct TreeNode * condition){

  if (while_node -> nodeType == While){
    if (condition -> nodeType == Expr){

      TreeNodeList_Add(while_node -> child_list, condition);
      ScopeStack_Pop(MainNode -> actual_stack);

      return while_node;
    }
    else{
      printf("%s create_WhileNode - unexpected Tree Node type. Expected Expr, found %s.\n", ErrorMsg(), NodeTypeString(condition));
      exit(EXIT_FAILURE);
    }
  }
  else{
    printf("%s create_WhileNode - unexpected Tree Node type. Expected While, found %s.\n", ErrorMsg(), NodeTypeString(while_node));
    exit(EXIT_FAILURE);
  }
}

struct TreeNode * create_Condition(struct TreeNode * expr){

  struct TreeNode * condition;

  if ( expr -> nodeType == Expr){

    if (expr -> node.Expr -> exprType == STR){
      printf("%s this interpreter does not support pointer to integer conversion.\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
    if(IsCostant(expr)){
      char value = CMP_node_logicValue(MainNode, expr);
      if (value == 1){
        printf("%s condition is always true.\n", WarnMsg());
      }
      else if(value == 0){
        printf("%s condition is always false.\n", WarnMsg());
      }
    }

    condition = expr;
  }
  else if (expr -> nodeType == Asgn){

    // transforming assignment in a parathesis assignment node
    struct TreeNode * newExpr = create_ExprNode(PA, 0, NULL, expr, NULL, 0);
    condition = create_Condition(newExpr);
    // print warning
    printf("%s using the result of an assignment as a condition without parentheses\n", WarnMsg());
    printf("note: use '==' to turn this assignment into an equality comparison\n");
  }
  else{
    printf("%s create_Condition - unexpected Tree Node type. Expected Expr, found %s.\n", ErrorMsg(), NodeTypeString(expr));
    exit(EXIT_FAILURE);
  }

  return condition;
}

struct TreeNode * create_WhileDeclaration(){

  // creating a generic Tree Node with memory allocation
  struct TreeNode * newWhileNode = TreeNodeInitialization();
  // Tree Node Type
  newWhileNode -> nodeType = While;

  // creating while scope
  struct TreeNode * whileScope = create_ScopeNode();
  // linking while scope to the while node
  TreeNodeList_Add(newWhileNode -> child_list, whileScope);
  // setting while scope as new actual scope
  // while scope is inactive by default
  SetAs_ActualScope(MainNode, whileScope, 0);

  return newWhileNode;
}

////////////////////  multi assignment PRODUCTION  /////////////////////////////

struct TreeNode * create_MultiAssignment(struct TreeNode * first, struct TreeNode * second){

  struct TreeNode * multiAssignment;

  if (first -> nodeType == Asgn){
    if (second -> nodeType == Asgn){
      // creating multi assignment node
      multiAssignment = TreeNodeInitialization();
      // setting node type
      multiAssignment -> nodeType = MultiAs;
      // linking first and second assignment to the multi assgniment node
      TreeNodeList_Add(multiAssignment -> child_list, first);
      TreeNodeList_Add(multiAssignment -> child_list, second);
    }
    else{
      printf("%s create_MultiAssignment - unexpected Tree node type. Expected Asgn, found %s.\n", ErrorMsg(), NodeTypeString(second));
      exit(EXIT_FAILURE);
    }
  }
  else if (first -> nodeType == MultiAs){
    if (second -> nodeType == Asgn){
      // adding the new assignement to the existing multi assignment node
      TreeNodeList_Add(multiAssignment -> child_list, second);
      multiAssignment = first;
    }
    else{
      printf("%s create_MultiAssignment - unexpected Tree node type. Expected Asgn, found %s.\n", ErrorMsg(), NodeTypeString(second));
      exit(EXIT_FAILURE);
    }
  }
  else{
    printf("%s create_MultiAssignment - unexpected Tree node type. Expected Asgn / MultiAs found %s.\n", ErrorMsg(), NodeTypeString(first));
    exit(EXIT_FAILURE);
  }

  return multiAssignment;
}

////////////////////  multi declaration PRODUCTION  ////////////////////////////

struct TreeNode * create_MultiDeclaration(struct TreeNode * declaration, struct TreeNode * expr, char flag){

  if (declaration -> nodeType == DclN){

    // Multi declaration node
    struct TreeNode * newTreeNode = TreeNodeInitialization();
    // setting node type
    newTreeNode -> nodeType = MultiDc;
    /*
    * linking the declaration node to the multi declaration node as first node
    * of the child list.
    */
    TreeNodeList_Add(newTreeNode -> child_list, declaration);

    // declaration must be executed in order to add the declared variable to the Symbol Table
    exec_DclN(MainNode, declaration);

    enum Type declarationType = declaration -> node.DclN -> type;
    if (declarationType == INT_V_) declarationType = INT_;
    else if (declarationType == CHAR_V_) declarationType = CHAR_;

    if (expr -> node.Expr -> exprType == ID || expr -> node.Expr -> exprType == VEC){
      struct TreeNode * newDeclaration = create_DeclarationNode(declarationType, expr);
      TreeNodeList_Add(newTreeNode -> child_list, newDeclaration);
    }
    else{
      printf("%s create_MultiDeclaration - unexpected variable. Type found %u.\n", ErrorMsg(), expr -> node.Expr -> exprType);
      exit(EXIT_FAILURE);
    }

    return newTreeNode;
  }
  else if(declaration -> nodeType == DclAsgn){

    // Multi declaration node
    struct TreeNode * newTreeNode = TreeNodeInitialization();
    // setting node type
    newTreeNode -> nodeType = MultiDc;
    /*
    * linking the declaration node to the multi declaration node as first node
    * of the child list.
    */
    TreeNodeList_Add(newTreeNode -> child_list, declaration);

    enum Type declarationType = declaration -> child_list -> first -> node.DclN -> type;
    if (declarationType == INT_V_) declarationType = INT_;
    else if (declarationType == CHAR_V_) declarationType = CHAR_;

    if (expr -> node.Expr -> exprType == ID || expr -> node.Expr -> exprType == VEC){
      struct TreeNode * newDeclaration = create_DeclarationNode(declarationType, expr);
      TreeNodeList_Add(newTreeNode -> child_list, newDeclaration);
    }
    else{
      printf("%s create_MultiDeclaration - unexpected variable. Type found %u.\n", ErrorMsg(), expr -> node.Expr -> exprType);
      exit(EXIT_FAILURE);
    }

    return newTreeNode;
  }
  else if(declaration -> nodeType == MultiDc){
    /*
    *   flag value its used to recognize a new declaration (flag = 1)
    */
    if (flag == 1){
      // a new declaration node

      // if the previous element was a simple declaration I have to execute it
      if (declaration -> child_list  -> last -> nodeType == DclN){
        exec_DclN(MainNode, declaration -> child_list  -> last);
      }

      // declaration type derives from the first declaration
      enum Type declarationType;
      struct TreeNode * firstDeclaration = declaration -> child_list -> first;
      if (firstDeclaration -> nodeType == DclN){
        declarationType = firstDeclaration -> node.DclN -> type;
      }
      else if (firstDeclaration -> nodeType == DclAsgn){
        declarationType = firstDeclaration -> child_list -> first -> node.DclN -> type;
      }

      if (declarationType == INT_V_) declarationType = INT_;
      else if (declarationType == CHAR_V_) declarationType = CHAR_;

      if (expr -> node.Expr -> exprType == ID || expr -> node.Expr -> exprType == VEC){
        struct TreeNode * newDeclaration = create_DeclarationNode(declarationType, expr);
        TreeNodeList_Add(declaration -> child_list, newDeclaration);
      }
      else{
        printf("%s create_MultiDeclaration - unexpected variable. Type found %u.\n", ErrorMsg(), expr -> node.Expr -> exprType);
        exit(EXIT_FAILURE);
      }
    }
    /*
    *   a new assignemnt linked to the previous declaration
    */
    else{
      if(expr -> nodeType == Expr){
        if (expr -> node.Expr -> exprType == ID){
        }
      }
      struct TreeNode * lastDeclaration = declaration -> child_list -> last;
      struct TreeNode * newDeclarationAssignment = create_Declaration_AssignmentNode(lastDeclaration, expr);
      TreeNodeList_Rem(declaration -> child_list);
      TreeNodeList_Add(declaration -> child_list, newDeclarationAssignment);
    }
    return declaration;
  }
  else{
    printf("%s create_MultiDeclaration - incorrect call. Unexpected %s type node.\n", ErrorMsg(), NodeTypeString(declaration));
    exit(EXIT_FAILURE);
  }
}

////////////////////  declaration_and_assignment PRODUCTION  ///////////////////

struct TreeNode * create_Declaration_AssignmentNode(struct TreeNode * declaration, struct TreeNode * expr){

  if (declaration -> nodeType == DclN){
    // Declaration and Assignment node
    struct TreeNode * newTreeNode;

    // one expression to assign
    if (expr -> nodeType == Expr){

      // declaring variable identifier
      char * identifier = TreeNode_Identifier(declaration);
      struct TreeNode * identifierNode;

      enum Type decl_type = declaration -> node.DclN -> type;

      if (decl_type == INT_ || decl_type == CHAR_){

        identifierNode = create_ExprNode(ID, 0, identifier, NULL, NULL, 0);

        // declaration must be always executed, in order to add variables to the symbol table
        exec_DclN(MainNode, declaration);

        // creating the assignment node
        struct TreeNode * assignmentNode = create_AssignmentNode(MainNode, identifierNode, expr);

        // Declaration and Assignment node memory allocation
        newTreeNode = TreeNodeInitialization (); // generic Tree Node memory space allocation
        // setting node type
        newTreeNode -> nodeType = DclAsgn;
        // linking declaration node
        TreeNodeList_Add(newTreeNode -> child_list, declaration);
        // linking assignment node
        TreeNodeList_Add(newTreeNode -> child_list, assignmentNode);
      }
      else if (decl_type == INT_V_ || decl_type == CHAR_V_){

        if (expr -> node.Expr -> exprType == STR){
          if (decl_type == CHAR_V_){

            char * string = expr -> node.Expr -> exprVal.stringExpr;

            struct TreeNode * character;
            // converting the string in a char expr list
            struct TreeNode * expr_list = NULL;
            for (int i = 0; i < strlen(string); i++){
              character = create_ExprNode(C, 0, &string[i], NULL, NULL, 0);
              expr_list = create_Expr_ListNode(expr_list, character);
            }
            char end_string = '\0';
            // adding end string character
            character = create_ExprNode(C, 0, &end_string, NULL, NULL, 0);
            expr_list = create_Expr_ListNode(expr_list, character);
            newTreeNode = create_Declaration_AssignmentNode(declaration, expr_list);
          }
          // error: int string
          else if(decl_type == INT_V_){
            printf("%s initializing int array \'%s\' with a string.\n", ErrorMsg(), identifier);
            exit(EXIT_FAILURE);
          }
        }
        // error: missing initializer
        else{
          printf("%s array initializer of \'%s\' must be an initializer list or wide string literal.\n", ErrorMsg(), identifier);
          exit(EXIT_FAILURE);
        }
      }
    }
    // array initializer to assign
    else if (expr -> nodeType == ExprLst){

      int var_dimension;
      int init_dimension;
      enum Type decl_type = declaration -> node.DclN -> type;

      // dimension of the initializer
      init_dimension = expr -> child_list -> elements;

      // an expr list with a single string is managed as a simple string
      if (init_dimension == 1 && expr -> child_list -> first -> node.Expr -> exprType == STR){
        newTreeNode = create_Declaration_AssignmentNode(declaration, expr -> child_list -> first);
      }
      else{

        if (decl_type == INT_ || decl_type == CHAR_){
          var_dimension = 1;
        }
        // array with unspecified dimension
        else if(declaration -> node.DclN -> arrayDim == NULL && (decl_type == INT_V_ || decl_type == CHAR_V_)){
          var_dimension = init_dimension;
          struct TreeNode * dimension = create_ExprNode(NUM, var_dimension, NULL, NULL, NULL, 0);
          declaration -> node.DclN -> arrayDim = dimension;
        }
        // array with specified dimension
        else{
          var_dimension = Expr_toInt(MainNode, declaration -> node.DclN -> arrayDim);
        }

        // warning: excess elements in array initializer
        if(init_dimension > var_dimension){
          printf("%s excess elements in array initializer.\n", WarnMsg());
        }

        // single variable
        if (decl_type == INT_ || decl_type == CHAR_){
          // considers only the first expression in the expression list
          newTreeNode = create_Declaration_AssignmentNode(declaration, expr -> child_list -> first);
        }
        // array
        else if (decl_type == INT_V_ || decl_type == CHAR_V_){

          // declaration must be always executed, in order to add variables to the symbol table
          exec_DclN(MainNode, declaration);

          // declaring variable identifier
          char * identifier = TreeNode_Identifier(declaration);

          // Declaration and Assignment node memory allocation
          newTreeNode = TreeNodeInitialization (); // generic Tree Node memory space allocation
          // setting node type
          newTreeNode -> nodeType = DclAsgn;
          // linking declaration node
          TreeNodeList_Add(newTreeNode -> child_list, declaration);

          // value to assign
          struct TreeNode * value = expr -> child_list -> first;

          int assignments;
          if (var_dimension < init_dimension) assignments = var_dimension;
          else assignments = init_dimension;

          // loop for craating the assignment statemets
          for (int i = 0; i < assignments; i++){

            // skipping to the next expression in the expression list
            if (i != 0) value = value -> next;

            // array index expr node
            struct TreeNode * index = create_ExprNode(NUM, i, NULL, NULL, NULL, 0);
            // array element expr node
            struct TreeNode * variable = create_ExprNode(VEC, 0, identifier, index, NULL, 0);

            // creating the assignment node
            struct TreeNode * assignmentNode = create_AssignmentNode(MainNode, variable, value);
            // linking assignment node
            TreeNodeList_Add(newTreeNode -> child_list, assignmentNode);
          }

        }
        else{
          printf("%s create_Declaration_AssignmentNode - unexpected dimension: %d\n", ErrorMsg(), var_dimension);
          exit(EXIT_FAILURE);
        }
      }
    }
    else{
          printf("%s create_Declaration_AssignmentNode - incorrect call. Expr TreeNode type expected. Type found: %u.\n", ErrorMsg(), expr -> nodeType);
          exit(EXIT_FAILURE);
        }

    return newTreeNode;
  }
  // subsequent assignment
  else if (declaration -> nodeType == DclAsgn){

    // previous assignment
    struct TreeNode * prev_assignment = declaration -> child_list -> first -> next;

    prev_assignment = create_AssignmentNode(MainNode, prev_assignment, expr);

    return declaration;
  }
  else{
    printf("%s create_Declaration_AssignmentNode - incorrect call. Declaration TreeNode type expected. Type found: %s.\n", ErrorMsg(), NodeTypeString(declaration));
    exit(EXIT_FAILURE);
  }
}

////////////////////  assignment PRODUCTION  ///////////////////////////////////

struct TreeNode * create_AssignmentNode(struct ProgramNode * prog, struct TreeNode * leftOp, struct TreeNode * rightOp){

  if (leftOp -> nodeType == Expr && rightOp -> nodeType == Expr){

    // generic Tree Node memory space allocation
    struct TreeNode * newTreeNode = TreeNodeInitialization ();
    // setting node type
    newTreeNode -> nodeType = Asgn;
    // Checking if the assignment is consistent
    Check_AsgnConcistency(prog, leftOp, rightOp);
    // Storing left operator
    TreeNodeList_Add(newTreeNode -> child_list, leftOp);
    // Storing right operator
    TreeNodeList_Add(newTreeNode -> child_list, rightOp);

    return newTreeNode;
  }
  // multiple assignment
  else if (leftOp -> nodeType == Asgn && rightOp -> nodeType == Expr){

    struct TreeNode * leftOp_node = leftOp -> child_list -> last;

    // Checking if the assignment is consistent
    Check_AsgnConcistency(prog, leftOp_node, rightOp);

    // Storing right operator
    TreeNodeList_Add(leftOp -> child_list, rightOp);

    return leftOp;
  }
  // incorrect call
  else{
    printf("%s - create_AssignmentNode: incorrect call.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }

  exit(EXIT_FAILURE);
}

////////////////////  declaration PRODUCTION  //////////////////////////////////
/*
*   flag parameter: 1 for declaration, 0 for declaration and assignment
*/
struct TreeNode * create_DeclarationNode(enum Type type, struct TreeNode * var){

  Check_NodeType(Expr, var, "create_DeclarationNode");

  // generic Tree Node memory space allocation
  struct TreeNode * newTreeNode = TreeNodeInitialization ();
  // setting node type
  newTreeNode -> nodeType = DclN;
  // checking if the declaration is consistent
  Check_DeclConcistency(var);
  // memory space allocation for specific Declaration node
  struct DeclarationNode * newDeclaration;
  newDeclaration = (struct DeclarationNode *)malloc(sizeof(struct DeclarationNode));
  // variable identifier
  newDeclaration -> identifier = TreeNode_Identifier(var);
  // setting var type and array dimension
  if (var -> node.Expr -> exprType == ID){
    // variable type
    newDeclaration -> type = type;
    // array dimension
    newDeclaration -> arrayDim = NULL;
  }
  else if (var -> node.Expr -> exprType == VEC){
    if(type == INT_){
      // variable type
      newDeclaration -> type = INT_V_;
      // array dimension
      newDeclaration -> arrayDim = var -> child_list -> first;
    }
    else if(type == CHAR_){
      // variable type
      newDeclaration -> type = CHAR_V_;
      // array dimension
      newDeclaration -> arrayDim = var -> child_list -> first;
    }
    else{
      printf("%s create_DeclarationNode - unexpected variable type.\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
  }
  // setting ignore flag, 0 by default
  newDeclaration -> ignore = 0;

  // linking declaration struct to tree node
  newTreeNode -> node.DclN = newDeclaration;
  // freeing memory
  free(var -> node.Expr);
  free(var);

  return newTreeNode;

}

////////////////////  return PRODUCTION  ///////////////////////////////////////

struct TreeNode * create_ReturnNode(struct TreeNode *expr){

  struct TreeNode * newTreeNode = TreeNodeInitialization (); // generic Tree Node memory space allocation

  // Linking specific node to generic Tree Node
  newTreeNode -> nodeType = Return;

  if(expr != NULL){
    TreeNodeList_Add(newTreeNode -> child_list, expr);}

  return newTreeNode;
}

////////////////////  pre_incdec_statement PRODUCTION  //////////////////////////

struct TreeNode * create_IncDecNode(enum exprType type, struct TreeNode * var){
  if (var -> nodeType == Expr){
    if (isAssignable(var)){
      return create_ExprNode(type, 0, NULL, var, NULL, 0);
    }
    else{
      printf("%s expression is not assignable.\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
  }
  else{
    printf("%s create_IncDecNode - incorrect call. Expr TreeNode expected.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
}

////////////////////  operation PRODUCTION  ////////////////////////////////////

struct TreeNode * create_OperationNode(ProgramNode * prog, struct TreeNode * first, struct TreeNode * second, enum exprType type){

  if (first == NULL || second == NULL) {
      printf("%s create_OperationNode - comparison missing one or two expressions\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
  else{
    struct TreeNode * node = create_ExprNode(type, 0, NULL, first, second, 0);
    Check_OperationConcistency(prog, node);

    return node;
  }

}

////////////////////  expr PRODUCTION  /////////////////////////////////////////

struct TreeNode * create_ExprNode(enum exprType type, long intExpr, char * charExpr, struct TreeNode * first, struct TreeNode * second, enum cmpType cmptype){

    struct TreeNode * newTreeNode = TreeNodeInitialization (); // generic Tree Node memory space allocation


    struct exprNode * NewExprNode;
    NewExprNode = (struct exprNode *)malloc(sizeof(struct exprNode)); // memory space allocation for specific Expr node

    NewExprNode -> exprType = type;

    switch (type) {
      case NUM: NewExprNode -> exprVal.intExpr = (int)intExpr;
                break;
      case ID:  NewExprNode -> exprVal.stringExpr = charExpr;
                break;
      case VEC: NewExprNode -> exprVal.stringExpr = charExpr;
                // check if vec has a dimension
                if(first != NULL){
                  // check if array dimension index is not a string
                  if (first -> node.Expr -> exprType != STR ){
                    Check_ExprConcistency(MainNode, first);
                    // adding the array dimension index as tree node child
                    TreeNodeList_Add(newTreeNode -> child_list, first);
                  }
                  // display error message if the dimension index is a string
                  else{
                    printf("%s array index must not be a string.\n", ErrorMsg());
                    exit(EXIT_FAILURE);
                  }
                  // check if dimension is a variable
                }
                break;
      case STR: NewExprNode -> exprVal.stringExpr = (char *)malloc (sizeof(char) *strlen(charExpr)-2); // sottraggo due alla dimensione per rimuovere gli apici
                for (int i =1; i<strlen(charExpr)-1; i++){
                NewExprNode -> exprVal.stringExpr[i-1]=charExpr[i];
                }
                break;
      case C:   NewExprNode -> exprVal.charExpr = *charExpr;
                break;
      case FC:  NewExprNode -> exprVal.stringExpr = charExpr;
                // function parameters
                if (first != NULL) TreeNodeList_Add(newTreeNode -> child_list, first);
                break;
      case SUM: TreeNodeList_Add(newTreeNode -> child_list, first);
                TreeNodeList_Add(newTreeNode -> child_list, second);
                break;
      case DIF: TreeNodeList_Add(newTreeNode -> child_list, first);
                TreeNodeList_Add(newTreeNode -> child_list, second);
                break;
      case TIM: TreeNodeList_Add(newTreeNode -> child_list, first);
                TreeNodeList_Add(newTreeNode -> child_list, second);
                break;
      case DIV: TreeNodeList_Add(newTreeNode -> child_list, first);
                TreeNodeList_Add(newTreeNode -> child_list, second);
                break;
      case MOD: TreeNodeList_Add(newTreeNode -> child_list, first);
                TreeNodeList_Add(newTreeNode -> child_list, second);
                break;
      case RND: TreeNodeList_Add(newTreeNode -> child_list, first);
                break;
      case CMP: TreeNodeList_Add(newTreeNode -> child_list, first);
                TreeNodeList_Add(newTreeNode -> child_list, second);
                NewExprNode -> exprVal.cmpExpr = cmptype;
                break;
      case PI:  TreeNodeList_Add(newTreeNode -> child_list, first);
                break;
      case PD:  TreeNodeList_Add(newTreeNode -> child_list, first);
                break;
      case IP:  TreeNodeList_Add(newTreeNode -> child_list, first);
                break;
      case DP:  TreeNodeList_Add(newTreeNode -> child_list, first);
                break;
      case PA:  TreeNodeList_Add(newTreeNode -> child_list, first);
                break;
      case ADD: Check_VariableAddress(first);
                TreeNodeList_Add(newTreeNode -> child_list, first);
                break;
      }

    // Linking specific node to generic Tree Node
    newTreeNode -> nodeType = Expr;
    newTreeNode -> node.Expr = NewExprNode;

    return newTreeNode;
  }

////////////////////////////////////////////////////////////////////////////////

struct TreeNode * TreeNodeInitialization (){

    struct TreeNode * newTreeNode;
    newTreeNode = (struct TreeNode *)malloc(sizeof(struct TreeNode)); // memory space allocation for generic tree node
    newTreeNode -> child_list = TreeNodeList_Set();  // memory space allocation for tree node child list
    newTreeNode -> next = NULL;
    return newTreeNode;
  }

/* todo rimuovere sta schifezza
////////////////////  global scope declaration PRODUCTION  /////////////////////

void create_GlobalDeclarationNode(ProgramNode * prog, struct TreeNode * declaration){

  if (declaration -> nodeType == DclN){

    // check array lenght declaration, must not be an identifier
    if (declaration -> node.DclN -> arrayDim != NULL){
      if (declaration -> node.DclN -> arrayDim -> nodeType == Expr){
        if (!IsCostant(declaration -> node.DclN -> arrayDim)){
          printf("%s variable lenght array not allowed in at global scope.\n", ErrorMsg());
          exit(EXIT_FAILURE);
        }
      }
      else{
        printf("%s create_GlobalDeclarationNode - array lenght Expr node expected. Type found %u.\n", ErrorMsg(), declaration -> node.DclN -> arrayDim -> nodeType);
        exit(EXIT_FAILURE);
      }
    }

    // adding node to the AST
    Add_Node_Tree(prog, declaration);
  }
  else{
    printf("%s create_GlobalDeclarationNode - incorrect call. DclN node expected. Type found %u.\n", ErrorMsg(), declaration -> nodeType);
    exit(EXIT_FAILURE);
  }
}*/

//////////////////  concistency FUNCTIONS  /////////////////////////////////////

void Check_CharConcistency(int value){
  if (value < -128 || value > 127){
    printf("%s implicit conversion from 'int' to 'char' changes value from %d to %d\n", WarnMsg(), value, (char)value);
  }
}

void Check_ExprConcistency(ProgramNode * prog, struct TreeNode * expr_node){

  enum exprType type = expr_node -> node.Expr -> exprType;
  // an Expr Tree Node is expected
  if ( expr_node -> nodeType == Expr){
    // todo da rivedere
    switch (type) {
      case NUM: break;
      case ID:  Check_IdentifierConcistency (prog, expr_node); break;
      case VEC: Check_ArrayConcistency (prog, expr_node); break;
      case STR: break;
      case C:   break;
      case FC:  Check_FunctionCallConcistency (prog, expr_node); break;
      case SUM: break;
      case DIF: break;
      case TIM: break;
      case DIV: break;
      case MOD: break;
      case RND: break;
      case CMP: Check_ComparisonConcistency (prog, expr_node); break;
      case PI:  break;
      case PD:  break;
      case IP:  break;
      case DP:  break;
      case PA:  break;
    }
  }
  // Error: unexpected TreeNode type
  else{
    printf("%s Check_ExprConcistency - incorrect call. Expr TreeNode expected.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }

}

void Check_IdentifierConcistency(ProgramNode * prog, struct TreeNode * identifier_node){

  Check_NodeType(Expr, identifier_node, "Check_IdentifierConcistency");
  Check_ExprType(ID, identifier_node, "Check_IdentifierConcistency");

  char * identifier = identifier_node -> node.Expr -> exprVal.stringExpr;
  // check declaration
  if (!Check_VarWasDeclared(prog, identifier, 1)){
    printf("%s use of undeclared identifier \'%s\'.\n", ErrorMsg(), identifier);
    exit(EXIT_FAILURE);
  }
}

void Check_ArrayConcistency(ProgramNode * prog, struct TreeNode * array){

  Check_NodeType(Expr, array, "Check_ArrayConcistency");
  Check_ExprType(VEC, array, "Check_ArrayConcistency");

  char * array_id = array -> node.Expr -> exprVal.stringExpr;
  // check declaration
  if (!Check_VarWasDeclared(prog, array_id, 1)){

    printf("%s use of undeclared identifier \'%s\'.\n", ErrorMsg(), array_id);
    exit(EXIT_FAILURE);
  }
  else{
    // check array index
    int index = Retrieve_ArrayIndex(prog, array);
    int array_dim = Retrieve_ArrayDim(prog, array_id);

    // out of bounds array error
    if (index > array_dim - 1 && !IgnoreFlag(array_id)){
      printf("%s array index %d is past the end of the array. Array contains %d elements.\n",ErrorMsg(),index, array_dim);
      exit(EXIT_FAILURE);
    }
    else if (index < 0){
      printf("%s array index %d is before the beginning of the array. Array contains %d elements.\n", ErrorMsg(),index, array_dim);
      exit(EXIT_FAILURE);
    }
  }
}

void Check_OperationConcistency (ProgramNode * prog, struct TreeNode * operation_node){

  if (operation_node -> nodeType == Expr){
    if(isOperation(operation_node)){

      struct TreeNode * leftOp = operation_node -> child_list -> first;
      struct TreeNode * rightOp;
      if (operation_node -> node.Expr -> exprType != RND) rightOp = operation_node -> child_list -> first -> next;

      enum exprType leftOp_type = leftOp -> node.Expr -> exprType;
      enum exprType rightOp_type;
      if (operation_node -> node.Expr -> exprType != RND) rightOp_type = rightOp -> node.Expr -> exprType;

      // Raise an error if one operand is an undeclared identifier
      if (leftOp_type == ID || leftOp_type == VEC){

        char * left_identifier = TreeNode_Identifier(leftOp);
        if (!Check_VarWasDeclared(prog, left_identifier, 1)){

          printf("%s use of undeclared identifier \'%s\'.\n",ErrorMsg(),left_identifier);
          exit(EXIT_FAILURE);
        }
      }
      if (rightOp_type == ID || rightOp_type == VEC){

        char * right_identifier = TreeNode_Identifier(rightOp);
        if (!Check_VarWasDeclared(prog, right_identifier, 1)){

          printf("%s use of undeclared identifier \'%s\'.\n",ErrorMsg(),right_identifier);
          exit(EXIT_FAILURE);
        }
      }

      // Raise a warning if one or two operands are array identifiers
      if (leftOp_type == ID){
        char * identifier = TreeNode_Identifier(leftOp);
        enum Type varType = Retrieve_VarType(prog, identifier);
        if (varType == INT_V_ || varType == CHAR_V_){

          printf("%s this interpreter does not support pointer to integer conversion.\n", ErrorMsg());
          exit(EXIT_FAILURE);
        }
      }
      if (rightOp_type == ID){
        char * identifier = TreeNode_Identifier(rightOp);
        enum Type varType = Retrieve_VarType(prog, identifier);
        if (varType == INT_V_ || varType == CHAR_V_){

          printf("%s this interpreter does not support pointer to integer conversion.\n", ErrorMsg());
          exit(EXIT_FAILURE);
        }
      }

      // Raise an error if one or two operands are strings
      if (leftOp_type == STR || rightOp_type == STR){
        printf("%s this interpreter does not support pointer to integer conversion.\n", ErrorMsg());
        exit(EXIT_FAILURE);
      }

      // Raise a warning if there's a division by 0
      if(operation_node -> node.Expr -> exprType == DIV){
        // If the second operand is costant
        if(IsCostant(operation_node -> child_list -> first -> next)){
          // If the second operand value is 0
          if(Expr_toInt(prog, operation_node -> child_list -> first -> next) == 0){
            printf("%s division by zero is undefined.\n", WarnMsg());
          }
        }
      }
      // Node value pre-calculus if it is not a division by 0
      else if(IsCostant(operation_node)){

          int value = Expr_toInt(prog, operation_node);
          operation_node -> node.Expr -> exprVal.intExpr = value;
          operation_node -> node.Expr -> known = 1;
      }
    }
    else{
      printf("%s Check_OperationConcistency - incorrect call. SUM/DIF/TIM/DIV/MOD/RND Expr TreeNode expected.\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
  }
  else{
    printf("%s Check_OperationConcistency - incorrect call. Expr TreeNode expected.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
}

void Check_ComparisonConcistency (ProgramNode * prog, struct TreeNode * comparison_node){

  if (comparison_node -> nodeType == Expr){
    if(comparison_node -> node.Expr -> exprType == CMP){

      enum cmpType type = comparison_node -> node.Expr -> exprVal.cmpExpr;
      // comparison is a binary logic operation with two operands: leftOp and rightOp
      struct TreeNode * leftOp = comparison_node -> child_list -> first;
      struct TreeNode * rightOp = comparison_node -> child_list -> first -> next;

      // comparison is a binary logic operation with two operands: leftOp and rightOp
      enum exprType leftOp_type = leftOp -> node.Expr -> exprType;
      enum exprType rightOp_type = rightOp -> node.Expr -> exprType;


      // Raise an error if one or two operands are strings
      if (leftOp_type == STR || rightOp_type == STR){
        printf("%s this interpreter does not support pointer to integer conversion.\n", ErrorMsg());
        exit(EXIT_FAILURE);
      }

      // Raise an error if one operand is an undeclared identifier
      if (leftOp_type == ID || leftOp_type == VEC){

        char * left_identifier = TreeNode_Identifier(leftOp);
        if (!Check_VarWasDeclared(prog, left_identifier, 1)){

          printf("%s use of undeclared identifier \'%s\'.\n",ErrorMsg(),left_identifier);
          exit(EXIT_FAILURE);
        }
      }
      if (rightOp_type == ID || rightOp_type == VEC){

        char * right_identifier = TreeNode_Identifier(rightOp);

        if (!Check_VarWasDeclared(prog, right_identifier, 1)){

          printf("%s use of undeclared identifier \'%s\'.\n",ErrorMsg(),right_identifier);
          exit(EXIT_FAILURE);
        }
      }

      // todo gestire ++ e --
      if (type == AND_ || type == OR_){

        // Raise a warning if the operand is a costant and is different from 0 or 1
        if (IsCostant(leftOp)){
          int value = Expr_toInt(prog, leftOp);
          if (value != 0 && value != 1){
            printf("%s logical operation with costant first operand.\n", WarnMsg());
          }

        }
        if (IsCostant(rightOp)){
          int value = Expr_toInt(prog, rightOp);
          if (value != 0 && value != 1){
            printf("%s logical operation with costant first operand.\n", WarnMsg());
          }

        }

        // Raise a warning if the operand is an array identifier
        if (leftOp_type == ID){
          char * identifier = TreeNode_Identifier(leftOp);
          enum Type varType = Retrieve_VarType(prog, identifier);
          if (varType == INT_V_ || varType == CHAR_V_){

          printf("%s array identifier will always evaluate to 'true'.\n", WarnMsg());
          }
        }
        if (rightOp_type == ID){
          char * identifier = TreeNode_Identifier(rightOp);
          enum Type varType = Retrieve_VarType(prog, identifier);
          if (varType == INT_V_ || varType == CHAR_V_){

          printf("%s array identifier will always evaluate to 'true'.\n", WarnMsg());
          }
        }

        // Raise a warning if the operand is a string
        if (leftOp_type == STR || rightOp_type == STR){
          printf("%s string identifier will always evaluate to 'true'.\n", WarnMsg());
        }

      }
      else if(type == GREAT_ || type == LESS_ || type == EQUAL_ || type == DIFF_ ){

        // Print an error if the operand is a string
        if (leftOp_type == STR || rightOp_type == STR){

          printf("%s this interpreter does not support comparison against pointers.\n", ErrorMsg());
          exit(EXIT_FAILURE);
        }

        // Print an error if the operand is an array identifier
        if (leftOp_type == ID){
          char * identifier = TreeNode_Identifier(leftOp);
          enum Type varType = Retrieve_VarType(prog, identifier);
          if (varType == INT_V_ || varType == CHAR_V_){

          printf("%s this interpreter does not support comparison against pointers.\n", ErrorMsg());
          exit(EXIT_FAILURE);
          }
        }
        if (rightOp_type == ID){
          char * identifier = TreeNode_Identifier(rightOp);
          enum Type varType = Retrieve_VarType(prog, identifier);
          if (varType == INT_V_ || varType == CHAR_V_){

          printf("%s this interpreter does not support comparison against pointers.\n", ErrorMsg());
          exit(EXIT_FAILURE);
          }
        }

        // Print a warning if the comparison with a char is always true or always false
        if (IsCostant(leftOp)){
          if (rightOp_type == ID || rightOp_type == VEC){
            char * identifier = TreeNode_Identifier(rightOp);
            enum Type varType = Retrieve_VarType(prog, identifier);

            if (varType == CHAR_ || varType == CHAR_V_){
              if (type == GREAT_){
                if (Expr_toInt(prog, leftOp) > 127){
                  printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), Expr_toInt(prog, leftOp));
                }
                else if (Expr_toInt(prog, leftOp) < -128){
                  printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(prog, leftOp));
                }
              }
              if (type == LESS_){
                if (Expr_toInt(prog, leftOp) > 127){
                  printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(prog, leftOp));
                }
                else if (Expr_toInt(prog, leftOp) < -128){
                  printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), Expr_toInt(prog, leftOp));
                }
              }
              if (type == EQUAL_){
                if (Expr_toInt(prog, leftOp) > 127){
                  printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(prog, leftOp));
                }
                else if (Expr_toInt(prog, leftOp) < -128){
                  printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(prog, leftOp));
                }
              }
              if (type == DIFF_){
                if (Expr_toInt(prog, leftOp) > 127){
                  printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), Expr_toInt(prog, leftOp));
                }
                else if (Expr_toInt(prog, leftOp) < -128){
                  printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), Expr_toInt(prog, leftOp));
                }
              }
            }
          }
        }
        if (IsCostant(rightOp)){
          if (leftOp_type == ID || leftOp_type == VEC){
            char * identifier = TreeNode_Identifier(leftOp);
            enum Type varType = Retrieve_VarType(prog, identifier);

            if (varType == CHAR_ || varType == CHAR_V_){
              if (type == GREAT_){
                if (Expr_toInt(prog, rightOp) > 127){
                  printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(prog, rightOp));
                }
                else if (Expr_toInt(prog, rightOp) < -128){
                  printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), Expr_toInt(prog, rightOp));
                }
              }
              if (type == LESS_){
                if (Expr_toInt(prog, rightOp) > 127){
                  printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), rightOp -> node.Expr -> exprVal.intExpr);
                }
                else if (Expr_toInt(prog, rightOp) < -128){
                  printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), rightOp -> node.Expr -> exprVal.intExpr);
                }
              }
              if (type == EQUAL_){
                if (Expr_toInt(prog, rightOp) > 127){
                  printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(prog, rightOp));
                }
                else if (Expr_toInt(prog, rightOp) < -128){
                  printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(prog, rightOp));
                }
              }
              if (type == DIFF_){
                if (Expr_toInt(prog, rightOp) > 127){
                  printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), rightOp -> node.Expr -> exprVal.intExpr);
                }
                else if (Expr_toInt(prog, rightOp) < -128){
                  printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), rightOp -> node.Expr -> exprVal.intExpr);
                }
              }
            }
          }
        }

        // Print a warning if the comparison with an other comparison is always true or always false
        if (leftOp_type == CMP && IsCostant(rightOp)){
          if (type == GREAT_){
            if (Expr_toInt(prog, rightOp) < 0){
                printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(prog, rightOp));
            }
            if (Expr_toInt(prog, rightOp) > 0){
                printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(prog, rightOp));
            }
          }
          if (type == LESS_){
            if (Expr_toInt(prog, rightOp) > 1){
                printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(prog, rightOp));
            }
            if (Expr_toInt(prog, rightOp) < 1){
                printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(prog, rightOp));
            }
          }
          if (type == EQUAL_){
            if (Expr_toInt(prog, rightOp) != 0 &&  Expr_toInt(prog, rightOp) != 1){
                  printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(prog, rightOp));
              }
          }
          if (type == DIFF_){
            if (Expr_toInt(prog, rightOp) != 0 &&  rightOp -> node.Expr -> exprVal.intExpr != 1){
                printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(prog, rightOp));
            }
          }
        }
        if (IsCostant(leftOp) && rightOp_type == CMP){
          if (type == GREAT_){
            if (Expr_toInt(prog, leftOp) > 1){
                printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(prog, leftOp));
            }
            if (Expr_toInt(prog, leftOp) < 1){
                printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(prog, leftOp));
            }
          }
          if (type == LESS_){
            if (Expr_toInt(prog, leftOp) < 0){
                printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(prog, leftOp));
            }
            if (Expr_toInt(prog, leftOp) > 0){
                printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(prog, leftOp));
            }
          }
          if (type == EQUAL_){
            if (Expr_toInt(prog, leftOp) != 0 &&  Expr_toInt(prog, leftOp) != 1){
                  printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(prog, leftOp));
              }
          }
          if (type == DIFF_){
            if (Expr_toInt(prog, leftOp) != 0 &&  Expr_toInt(prog, leftOp) != 1){
                printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(prog, leftOp));
            }
          }
        }

        // Print a warning if the comparison is between a variable and itself
        if (((leftOp_type == ID) && (rightOp_type == ID)) || ((leftOp_type == VEC) && (rightOp_type == VEC))){

          char * left_identifier = TreeNode_Identifier(leftOp);
          char * right_identifier = TreeNode_Identifier(rightOp);

          if (!strcmp(left_identifier, right_identifier)){
            if (type == GREAT_ || type == LESS_ || type == DIFF_){
              printf("%s self-comparison always evaluates to false.\n", WarnMsg());
            }
            else if (type == EQUAL_){
              printf("%s self-comparison always evaluates to true.\n", WarnMsg());
            }
          }
        }

      }
    }
    else{
      printf("%s Check_ComparisonConcistency - incorrect call. CMP Expr TreeNode expected.\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
  }
  else{
    printf("%s Check_ComparisonConcistency - incorrect call. Expr TreeNode expected.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
}

void Check_AsgnConcistency(ProgramNode * prog, struct TreeNode * leftOp, struct TreeNode * rightOp){

  enum exprType leftOp_type = leftOp -> node.Expr -> exprType;
  enum exprType rightOp_type = rightOp -> node.Expr -> exprType;

  // Only valid variables and vectors elements are assignable
  if (isAssignable(leftOp)){

    char * leftOp_identifier = TreeNode_Identifier(leftOp);

    if (rightOp_type == STR){
      printf("%s a string is not assignable\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
    else if (rightOp_type == ID){

      char * rightOp_identifier = rightOp -> node.Expr -> exprVal.stringExpr;
      enum Type rightOp_varType = Retrieve_VarType(prog, rightOp_identifier);

      // check if rigth operator is not a vector identifier
      if (rightOp_varType == INT_V_ || rightOp_varType == CHAR_V_){
        int array_dim = Retrieve_ArrayDim(prog, rightOp_identifier);
        if (rightOp_varType == INT_V_) printf("%s array type \'int[%d]\' is not assignable\n", ErrorMsg(), array_dim);
        if (rightOp_varType == CHAR_V_) printf("%s array type \'char[%d]\' is not assignable\n", ErrorMsg(), array_dim);
        exit(EXIT_FAILURE);
      }
    }
    else if (rightOp_type == VEC){

    char * rightOp_identifier = rightOp -> node.Expr -> exprVal.stringExpr;
    int index = Retrieve_ArrayIndex(prog, rightOp);
    int array_dim = Retrieve_ArrayDim(prog, rightOp_identifier);

    if (!IgnoreFlag(rightOp_identifier)){
      // out of bounds array error
      if (index > array_dim-1){
        printf("%s array index %d is past the end of the array. Array contains %d elements.\n", ErrorMsg(), index, array_dim);
        exit(EXIT_FAILURE);
      }
      else if (index < 0){
        printf("%s array index %d is before the beginning of the array. Array contains %d elements.\n", ErrorMsg(), index, array_dim);
        exit(EXIT_FAILURE);
      }
    }
  }

    // Char assignment concistency
    if (IsCostant(rightOp)){

      enum Type varType = Retrieve_VarType(prog, leftOp_identifier);
      if (varType == CHAR_ || varType == CHAR_V_){

        int value = Expr_toInt(MainNode, rightOp);
        Check_CharConcistency(value);
      }
    }

    // todo: gestire il caso in cui il valore deriva dal contenuto di una espressione per esempio con parentesi
    // dovrebbe essere già gestito perchè con le stringhe non si possono fare operazioni, ma è da verificare

    if(Multiple_Modifications(rightOp, leftOp_identifier)){
      printf("%s multiple unsequenced modifications to '%s'\n", WarnMsg(), leftOp_identifier);
    }
  }
  else{

    printf("%s: expression is not assignable\n",ErrorMsg());
    exit(EXIT_FAILURE);
  }
}
/*
*   flag parameter: 1 for declaration, 0 for declaration and assignment
*/
void Check_DeclConcistency(struct TreeNode * variable){

    if (variable -> nodeType == Expr){

      if (variable -> node.Expr -> exprType == ID || variable -> node.Expr -> exprType == VEC){

        char * identifier = TreeNode_Identifier(variable);
        // check if variable was previously declared
        if(Check_VarWasDeclared(MainNode, identifier, 0)){
          printf("%s redefinition of %s.\n", ErrorMsg(), identifier);
          exit(EXIT_FAILURE);
        }

      }
      else{
        printf("%s Check_DeclConcistency - unexpected Expr type. Type found: %u.\n", ErrorMsg(), variable -> node.Expr -> exprType);
        exit(EXIT_FAILURE);
      }
    }
    else{
      printf("%s Check_DeclConcistency - incorrect call. Expr Tree Node expected. Type found %u.\n", ErrorMsg(), variable -> nodeType == Expr);
      exit(EXIT_FAILURE);
    }
}

int Check_ArrayDimension(struct TreeNode * node){

  if (node -> nodeType == Expr){
    if (node -> node.Expr -> exprType == VEC && node -> child_list -> elements == 0){
      printf("%s array '%s' dimension expression missing.\n", ErrorMsg(), TreeNode_Identifier(node));
      exit(EXIT_FAILURE);
      return 0;
    }
    else return 1;
  }
  else if (node -> nodeType == DclN){
    // array with no dimension specified
    if (node -> node.DclN -> arrayDim == NULL && (node -> node.DclN -> type == INT_V_ || node -> node.DclN -> type == CHAR_V_)){
      if (IgnoreFlag(node -> node.DclN -> identifier)) return 1;
      else{
        printf("%s definition of '%s' variable with array type needs an explicit size or an initializer.\n", ErrorMsg(), TreeNode_Identifier(node));
        exit(EXIT_FAILURE);
      }
    }
    else return 1;
  }
  else{
    printf("%s Check_ArrayDimension - unexpected tree node type. Expected 'expression' or 'declaration' found %s.\n", ErrorMsg(), NodeTypeString(node));
    exit(EXIT_FAILURE);
  }
}

void Check_NodeType(enum nodeType type, struct TreeNode * node, char * function_id){
  if( node -> nodeType != type){
    printf("%s %s - unexpected tree node type. Expected \'%s\', found \'%s\'.\n", ErrorMsg(), function_id, PrintNodeType(type), NodeTypeString(node));
    exit(EXIT_FAILURE);
  }
}

void Check_ExprType (enum exprType type, struct TreeNode * node, char * function_id){

  Check_NodeType(Expr, node, "Check_ExprType");

  if( node -> node.Expr -> exprType != type){
    printf("%s %s - unexpected expression tree node type. Expected \'%s\', found \'%s\'.\n", ErrorMsg(), function_id, PrintExpressionType(type), ExprTypeString(node));
    exit(EXIT_FAILURE);
  }
}

void Check_FunctionCallConcistency (ProgramNode * prog, struct TreeNode * function_call){

  Check_NodeType(Expr, function_call, "Check_FunctionCallConcistency");
  Check_ExprType(FC, function_call, "Check_FunctionCallConcistency");

  char * function_id = function_call -> node.Expr -> exprVal.stringExpr;

  // check if function was declared
  if(CheckFunAlreadyExist(prog, function_id)){

    if (function_call -> child_list -> elements > 0){

      struct TreeNode * arguments = function_call -> child_list -> first;
      struct TreeNode * argument = arguments -> child_list -> first;
      // check arguments
      for (int i = 0; i < arguments -> child_list -> elements; i++){

        if (i != 0) argument = argument -> next;
        // pensaci un attimo: se è stato creato il nodo expr, non è di per se già controllato in fase di creazione?
        Check_ExprConcistency(prog, argument);
      }
    }

    Check_FunctionParameters(function_call);
  }
  // undeclared function error
  else{
    printf("%s call of undeclared function \'%s\'\n", ErrorMsg(), function_id);
    exit(EXIT_FAILURE);
  }

}
/*
*   comparing function call node with the function declaration
*/
void Check_FunctionParameters(struct TreeNode * function_call){

  char * identifier = function_call -> node.Expr -> exprVal.stringExpr;
  int index = FunNodeList_Search(MainNode, identifier);
  struct FunNode * functionNode = FunNodeList_Get(MainNode, index);

  struct TreeNode * call_parameters;
  struct TreeNode * decl_parameters = functionNode -> function_scope -> child_list -> first;

  int call_parameters_No;
  int decl_parameters_No = decl_parameters -> child_list -> elements;

  if (function_call -> child_list -> elements > 0){

    call_parameters = function_call -> child_list -> first;
    call_parameters_No = call_parameters -> child_list -> elements;
  }
  else call_parameters_No = 0;

  // error: too many arguments
  if (call_parameters_No > decl_parameters_No){
    printf("%s too many arguments to function call '%s', expected %d, have %d.\n", ErrorMsg(), identifier, decl_parameters_No, call_parameters_No);
    exit(EXIT_FAILURE);
  }
  // error: too few arguments
  else if(call_parameters_No < decl_parameters_No){
    printf("%s too few arguments to function call '%s', expected %d, have %d.\n", ErrorMsg(), identifier, decl_parameters_No, call_parameters_No);
    exit(EXIT_FAILURE);
  }
  else{
    struct TreeNode * declaration;
    struct TreeNode * argument;
    for (int i = 0; i < decl_parameters_No; i++){

      if (i == 0) declaration = decl_parameters -> child_list -> first;
      else declaration = declaration -> next;

      if (i == 0) argument = call_parameters -> child_list -> first;
      else argument = argument -> next;

      printf("---------------- %d ----------------\n", i);
      printf("NODO DI TIPO %s\n", NodeTypeString(declaration));
      printf("Dichiarazione di tipo: %s\n", VarTypeString(declaration -> node.DclN -> type));
      printf("PASSO UN TIPO %s\n",  NodeTypeString(argument));
      printf("Argomento di tipo: %s\n", ExprTypeString(argument));

      CheckParameterAssignment(declaration, argument);
    }
  }

}

void CheckParameterAssignment(struct TreeNode * declaration, struct TreeNode * expression){

  Check_NodeType(DclN, declaration, "CheckParameterAssignment");
  Check_NodeType(Expr, expression, "CheckParameterAssignment");

  enum Type declaration_type = declaration -> node.DclN -> type;
  enum Type expression_type = expressionType(expression);

  if ((declaration_type == INT_V_ || declaration_type == CHAR_V_) && (expression_type == INT_ || expression_type == CHAR_)){
    printf("%s incompatible integer to pointer conversion passing \'%s\' to parameter of type \'%s\'.\n", ErrorMsg(), IdentifierTypeString(expression_type), IdentifierTypeString(declaration_type));
    exit(EXIT_FAILURE);
  }
  if ((declaration_type == INT_ || declaration_type == CHAR_) && (expression_type == INT_V_ || expression_type == CHAR_V_)){
    printf("%s incompatible pointer to integer conversion passing \'%s\' to parameter of type \'%s\'.\n", ErrorMsg(), IdentifierTypeString(expression_type), IdentifierTypeString(declaration_type));
    exit(EXIT_FAILURE);
  }

  if (declaration_type == CHAR_){
    if( expression -> node.Expr -> known){
      if (expression -> node.Expr -> exprVal.intExpr < -128 || expression -> node.Expr -> exprVal.intExpr > 127 ){
        printf("%s  implicit conversion from 'int' to 'char' changes value from %d to %d.\n", ErrorMsg(), expression -> node.Expr -> exprVal.intExpr, (char)expression -> node.Expr -> exprVal.intExpr);
      }
    }
  }

  if (declaration_type == INT_V_ || declaration_type == CHAR_V_){
    // pointer error
    if (declaration_type != expression_type){
      printf("%s incompatible pointer types passing \'%s\' to parameter of type \'%s\'.\n", ErrorMsg(),IdentifierTypeString(expression_type),IdentifierTypeString(declaration_type));
      exit(EXIT_FAILURE);
    }
  }
}

void Check_PrintfCallConcistency(struct TreeNode * function_call){

  Check_NodeType(Expr, function_call, "Check_PrintfCallConcistency");
  Check_ExprType(FC, function_call, "Check_PrintfCallConcistency");

  // check number of parameters
  if (function_call -> child_list -> elements == 0){
    printf("%s too few arguments to function call, expected at least 1, have 0.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  else{

    // first argument must be a string
    struct TreeNode * arguments = function_call -> child_list -> first;
    struct TreeNode * firstArgument = arguments -> child_list -> first;

    if (firstArgument -> node.Expr -> exprType != STR){

      enum Type expression_type = expressionType(firstArgument);

      if (expression_type == INT_ || expression_type == CHAR_){
        printf("%s incompatible integer to pointer conversion passing \'%s\' to parameter of type \'char pointer\'.\n", ErrorMsg(), IdentifierTypeString(expression_type));
        exit(EXIT_FAILURE);
      }
      else if (expression_type == INT_V_){
        printf("%s incompatible pointer types passing \'%s\' to parameter of type \'char pointer\'.\n", ErrorMsg(), IdentifierTypeString(expression_type));
        exit(EXIT_FAILURE);
      }
      else if (expression_type == CHAR_V_)  printf("%s format string is not a string literal (potentially insecure).\n", WarnMsg());
    }
    // if is a string, check format strings
    else{
        char * string = firstArgument -> node.Expr -> exprVal.stringExpr;
        Check_Printf_String(string, arguments);
    }
  }
}

void Check_Printf_String(char * string, struct TreeNode * arguments){

  Check_NodeType(ExprLst, arguments, "Check_Printf_String");

  int string_lenght = strlen(string);

  // check format strings
   int string_format_no = 0;
   enum Type string_format_type;

  for (int i = 0; i < string_lenght; i++){
    // string format check
    if (string[i] == '%'){
      char string_format = string[i+1];
      if (isStringFormat(string_format)){

        if (string_format != '%') string_format_no++;

        if ( string_format_no + 1 > arguments -> child_list -> elements) printf("%s: more \'%%\' conversions than data arguments.\n", WarnMsg());
        else Check_Printf_FormatString_argument(string_format, ExprList_Expression (arguments, string_format_no+1));

        i++;
      }
      else printf("%s invalid conversion specifier '%c'.\n", WarnMsg(), string_format);
    }
  }

  // warning data argument not used
  if (string_format_no + 1 < arguments -> child_list -> elements)
    printf("%s data argument not used by format string.\n", WarnMsg());
}

void Check_ScanfCallConcistency(struct TreeNode * function_call){

  Check_NodeType(Expr, function_call, "Check_ScanfCallConcistency");
  Check_ExprType(FC, function_call, "Check_ScanfCallConcistency");

  // check number of parameters
  if (function_call -> child_list -> elements == 0){
    printf("%s too few arguments to function call, expected at least 1, have 0.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  else{

    // first argument must be a string
    struct TreeNode * arguments = function_call -> child_list -> first;
    struct TreeNode * firstArgument = arguments -> child_list -> first;

    if (firstArgument -> node.Expr -> exprType != STR){

      enum Type expression_type = expressionType(firstArgument);
      // todo qui si potrebbe tollerare anche un CHAR_P_
      if (expression_type != CHAR_V_){
        printf("%s incompatible integer to pointer conversion passing \'%s\' to parameter of type \'char pointer\'.\n", ErrorMsg(), IdentifierTypeString(expression_type));
        exit(EXIT_FAILURE);
      }
    }
    // if is a string, check format strings
    else{
        char * string = firstArgument -> node.Expr -> exprVal.stringExpr;
        Check_Scanf_String(string, arguments);
    }
  }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Check_Scanf_String (char * string, struct TreeNode * arguments){

  Check_NodeType(ExprLst, arguments, "Check_Scanf_String");

  int string_lenght = strlen(string);

  // check format strings
   int string_format_no = 0;
   enum Type string_format_type;

   for (int i = 0; i < string_lenght; i++){
     // string format check
     if (string[i] == '%'){

       char string_format = string[i+1];
       if (isStringFormat(string_format) && string_format != '%'){

         string_format_no++;

         if ( string_format_no + 1 > arguments -> child_list -> elements) printf("%s: more \'%%\' conversions than data arguments.\n", WarnMsg());
         else Check_Scanf_FormatString_argument(string_format, ExprList_Expression (arguments, string_format_no+1));

         i++;
       }
       else printf("%s invalid conversion specifier '%c'.\n", WarnMsg(), string_format);
     }
     else if (string[i] != ' ') printf("%s invalid conversion specifier '%c'.\n", WarnMsg(), string[i]);
   }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Check_Printf_FormatString_argument(char string_form, struct TreeNode * expression){

  enum Type expr_type = expressionType(expression);

  if (string_form == 'd' || string_form == 'i'){
    if (expr_type != INT_ && expr_type != CHAR_){
      printf("%s format specifies type 'int' but the argument has type '%s'.\n", WarnMsg(), IdentifierTypeString(expr_type));
    }
  }
  else if (string_form == 'c'){
    if (expr_type != INT_ && expr_type != CHAR_){
      printf("%s format specifies type 'char' but the argument has type '%s'.\n", WarnMsg(), IdentifierTypeString(expr_type));
    }
  }
  else if (string_form == 'o' || string_form == 'u'){
    if (expr_type != INT_ && expr_type != CHAR_){
      printf("%s format specifies type 'unsigned int' but the argument has type '%s'.\n", WarnMsg(), IdentifierTypeString(expr_type));
    }
  }
  else if (string_form == 's'){
    if (expr_type != CHAR_V_){
      if (expr_type == INT_V_ || expr_type == INT_P_ || expr_type == CHAR_P_) printf("%s format specifies type 'char pointer' but the argument has type '%s'.\n", WarnMsg(), IdentifierTypeString(expr_type));
      else{
        printf("%s format specifies type 'char pointer' but the argument has type '%s'.\n", ErrorMsg(), IdentifierTypeString(expr_type));
        exit(EXIT_FAILURE);
      }
    }
  }
  if (string_form == 'x' || string_form == 'X'){
    if (expr_type != INT_ && expr_type != CHAR_){
      printf("%s format specifies type 'unsigned int' but the argument has type '%s'.\n", WarnMsg(), IdentifierTypeString(expr_type));
    }
  }
}


void Check_Scanf_FormatString_argument (char string_form, struct TreeNode * expression){

  enum Type expr_type = expressionType(expression);

  if (expression -> node.Expr -> exprType == STR){
    printf("%s a 'costant string' is not assignable.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  if (string_form == 'd' || string_form == 'i'){
    if (expr_type == INT_ || expr_type == CHAR_){
      printf("%s format specifies type 'int pointer' but the argument has type '%s'.\n", ErrorMsg(), IdentifierTypeString(expr_type));
      exit(EXIT_FAILURE);
    }
    else if (expr_type == INT_V_ || expr_type == CHAR_V_ || expr_type == CHAR_P_)
      printf("%s format specifies type 'int pointer' but the argument has type '%s'.\n", WarnMsg(), IdentifierTypeString(expr_type));
  }
  else if (string_form == 'c'){
    if (expr_type == INT_ || expr_type == CHAR_){
      printf("%s format specifies type 'char pointer' but the argument has type '%s'.\n", ErrorMsg(), IdentifierTypeString(expr_type));
      exit(EXIT_FAILURE);
    }
    else if (expr_type == INT_V_ || expr_type == CHAR_V_ || expr_type == INT_P_)
      printf("%s format specifies type 'char pointer' but the argument has type '%s'.\n", WarnMsg(), IdentifierTypeString(expr_type));
  }
  else if (string_form == 'o' || string_form == 'u'){
    if (expr_type == INT_ || expr_type == CHAR_){
      printf("%s format specifies type 'unsigned int' but the argument has type '%s'.\n", ErrorMsg(), IdentifierTypeString(expr_type));
      exit(EXIT_FAILURE);
    }
    else if (expr_type == INT_V_ || expr_type == CHAR_V_ || expr_type == CHAR_P_)
      printf("%s format specifies type 'unsigned int' but the argument has type '%s'.\n", WarnMsg(), IdentifierTypeString(expr_type));
  }
  else if (string_form == 's'){
    if (expr_type == INT_ || expr_type == CHAR_){
      printf("%s format specifies type 'char pointer' but the argument has type '%s'.\n", ErrorMsg(), IdentifierTypeString(expr_type));
      exit(EXIT_FAILURE);
    }
    else if (expr_type == INT_V_ || expr_type == CHAR_V_ || expr_type == INT_P_)
      printf("%s format specifies type 'char pointer' but the argument has type '%s'.\n", WarnMsg(), IdentifierTypeString(expr_type));
  }
  if (string_form == 'x' || string_form == 'X'){
    if (expr_type == INT_ || expr_type == CHAR_){
      printf("%s format specifies type 'unsigned int' but the argument has type '%s'.\n", ErrorMsg(), IdentifierTypeString(expr_type));
      exit(EXIT_FAILURE);
    }
    else if (expr_type == INT_V_ || expr_type == CHAR_V_ || expr_type == CHAR_P_)
      printf("%s format specifies type 'unsigned int' but the argument has type '%s'.\n", WarnMsg(), IdentifierTypeString(expr_type));
  }

}

struct TreeNode * ExprList_Expression(struct TreeNode * exprList, int index){

  Check_NodeType(ExprLst, exprList, "ExprList_Expression");

  if (index > exprList -> child_list -> elements){
    printf("%s ExprList_Expression - index after expression list end.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  else if (index < 1){
    printf("%s ExprList_Expression - index before expression list beginning.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  else{
    struct TreeNode * expression;

    for (int i = 0; i < index; i++){

      if (i == 0) expression = exprList -> child_list -> first;
      else expression = expression -> next;
    }
    return expression;
  }
}

void Check_VariableAddress(struct TreeNode * variable){

  if (variable != NULL){

    // check if the variable is an array without expressed dimension
    if (variable -> node.Expr -> exprType == VEC && variable -> child_list -> elements == 0){
      printf("%s expected expression.\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
    // check if the variable was declared
    if (variable -> node.Expr -> exprType == ID) Check_IdentifierConcistency(MainNode, variable);
    if (variable -> node.Expr -> exprType == VEC) Check_ArrayConcistency(MainNode, variable);

  }
  else{
    printf("%s variable not found.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
}

//////////////////  execution CONTROL  /////////////////////////////////////////

int Check_Main(){

  struct FunNode * actualFunction =  MainNode -> function_list -> last;
  if (!strcmp("main", actualFunction -> funName)){
    return 1;
  }
  else{
    return 0;
  }
}

char Check_activation(){
  struct Scope * actualScope = MainNode -> actual_stack -> top;
  // activation value is by default inherited by previous scope
  return actualScope -> active;
}

void Scope_Activation(){
  struct Scope * actualScope = MainNode -> actual_stack -> top;
  // check if previous scope is active
  if (actualScope -> prevScope -> active){
    actualScope -> active = 1;
  }
}