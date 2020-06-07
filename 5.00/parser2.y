%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "lexer.h"
#include "Tree.h"
#include "parser.h"
#include "exec.h"

#define RED     "\x1b[31m"
#define RESET   "\x1b[0m"

enum exprType;

int L_DEBUGGING = 0;
int P_DEBUGGING = 0;
int TREE_DEBUGGING = 0;

int ERROR_STATUS = 0;

int yylineno;
ProgramNode * MainNode;
struct ErrorList * Errors;
struct TreeNode * NullTreeNode;
struct TreeNode * return_node;
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
%type <node> function_declaration
%type <node> function_call
%type <node> multi_dec
%type <node> multi_dec_statement
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
| global_scope function_list
| function_list
;

global_scope
: global_scope_body                                                             {if(P_DEBUGGING==1) printf("BISON: Global_scope found\n");}
;

global_scope_body
: global_statements                                                             {if(P_DEBUGGING==1) printf("BISON: Global_scope_body found\n");}
| global_scope global_statements                                                {if(P_DEBUGGING==1) printf("BISON: Global_scope_body found\n");}
;

global_statements
: declaration END_COMMA                                                         {if(P_DEBUGGING==1) printf("BISON: Global declaration statement found\n");                 Add_Node_Tree($1);  exec_DclN($1)}
| declaration_and_assignment END_COMMA                                          {if(P_DEBUGGING==1) printf("BISON: Global declaration and assignment statement found\n");  Add_Node_Tree($1);  exec_DclN_Asgn($1);}
| multi_dec END_COMMA                                                           {if(P_DEBUGGING==1) printf("BISON: Global multi declaration statement found\n");           Add_Node_Tree($1);  exec_Multi_DclN($1);}
| error END_COMMA {printf("%s global stmt error %s\n", RED, RESET); yyerrok;}
;

function_list
: function                                                                      {if(P_DEBUGGING==1) printf("BISON: Function list1 found\n");}
| function_list function                                                        {if(P_DEBUGGING==1) printf("BISON: Function list2 found\n");}
;

function
: function_parameters_declaration statement_list CLOSED_BRACKET                 {if(P_DEBUGGING==1) printf("BISON: Function found\n"); if(Function_End())YYACCEPT;}
| function_parameters_declaration CLOSED_BRACKET                                {if(P_DEBUGGING==1) printf("BISON: Function found\n"); if(Function_End())YYACCEPT;}
;

function_parameters_declaration
: function_declaration arguments_declaration OPEN_BRACKET                       {if(P_DEBUGGING==1) printf("BISON: Function parameters declaration found\n");  create_FunctionNode($1,$2);    if(TREE_DEBUGGING) printf("TREE: Function node created\n");}
;

function_declaration
: declaration                                                                   {if(P_DEBUGGING==1) printf("BISON: Function declaration found\n");  FunNodeList_Add ($1); $$ = $1; }
;

arguments_declaration
: OPEN_ROUND arguments_declaration_list CLOSED_ROUND                            {if(P_DEBUGGING==1) printf("BISON: arguments_declaration1 found\n");        $$ = $2}
| OPEN_ROUND CLOSED_ROUND                                                       {if(P_DEBUGGING==1) printf("BISON: arguments_declaration2 found\n");        $$ = create_Arg_ListNode(NULL, NULL);}
;

arguments_declaration_list
: declaration                                                                   {if(P_DEBUGGING==1) printf("BISON: arguments_declaration_list1 found\n");   $$ = create_Arg_ListNode(NULL, $1);}
| arguments_declaration_list COMMA declaration                                  {if(P_DEBUGGING==1) printf("BISON: arguments_declaration_list2 found\n");   $$ = create_Arg_ListNode($1, $3);}
;

scope
: start_scope statement_list CLOSED_BRACKET                                     {if(P_DEBUGGING==1) printf("BISON: End of the scope found\n");              Propagate_return_flag(); ScopeStack_Pop(MainNode -> actual_stack);}
| start_scope CLOSED_BRACKET                                                    {if(P_DEBUGGING==1) printf("BISON: New empty scope found\n");               Propagate_return_flag(); ScopeStack_Pop(MainNode -> actual_stack);}
;

start_scope
: OPEN_BRACKET                                                                  {if(P_DEBUGGING==1) printf("BISON: Start of the scope found\n");            {$$ = create_ScopeNode(); Add_Node_Tree($$); SetAs_ActualScope($$, Check_activation());} if(TREE_DEBUGGING) printf("TREE: Scope node created\n");}
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
: expr END_COMMA                                                                {if(P_DEBUGGING==1) printf("BISON: Expr statement found\n");                                        Add_Node_Tree($1); Warning_Unused($1); if(Check_activation()) exec_Expression($1);}
| return_statement                                                              {if(P_DEBUGGING==1) printf("BISON: Return statement found\n");                                      Add_Node_Tree($1); Update_return_flag(); if(Check_activation()) {return_node = exec_return($1); Return_main(return_node); YYACCEPT;}}
| declaration END_COMMA                                                         {if(P_DEBUGGING==1) printf("BISON: Declaration statement found\n");                                 Add_Node_Tree($1); exec_DclN($1);}
| assignment END_COMMA                                                          {if(P_DEBUGGING==1) printf("BISON: Assignment statement found\n");                                  Add_Node_Tree($1); if(Check_activation()) exec_Asgn($1);}
| multi_dec_statement                                                           {if(P_DEBUGGING==1) printf("BISON: Multi declaration statement found\n");                           Add_Node_Tree($1); if(Check_activation()) exec_Multi_DclN($1);}
| multi_asgn END_COMMA                                                          {if(P_DEBUGGING==1) printf("BISON: Multi assignment statement found\n");                            Add_Node_Tree($1); if(Check_activation()) exec_Multi_Asgn($1);}
| declaration_and_assignment END_COMMA                                          {if(P_DEBUGGING==1) printf("BISON: Declaration and assignment statement found\n");                  Add_Node_Tree($1); if(Check_activation()) exec_DclN_Asgn($1);}
| if_else_statement                                                             {if(P_DEBUGGING==1) printf("BISON: IF statement statement found\n");                                Add_Node_Tree($1); if(Check_activation()) {return_node = exec_ifElse($1, 0); if(Return_main(return_node)) YYACCEPT;}}
| while_statement                                                               {if(P_DEBUGGING==1) printf("BISON: WHILE statement statement found\n");                             Add_Node_Tree($1); if(Check_activation()) {return_node = exec_while($1, 0);  if(Return_main(return_node)) YYACCEPT;}}
| END_COMMA                                                                     {if(P_DEBUGGING==1) printf("BISON: Empty statement found\n");}
;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

function_call
: IDENTIFIER OPEN_ROUND expr_list CLOSED_ROUND                                  {if(P_DEBUGGING==1) printf("BISON: Function call1 found\n");                $$ = create_Function_CallNode($1, $3);                   if(TREE_DEBUGGING) printf("TREE: Function call statement node created\n");}
| IDENTIFIER OPEN_ROUND CLOSED_ROUND                                            {if(P_DEBUGGING==1) printf("BISON: Function call2 found\n");                $$ = create_Function_CallNode($1, NULL);                 if(TREE_DEBUGGING) printf("TREE: Function call statement node created\n");}
;

if_else_statement
: if_statement                                                                  {if(P_DEBUGGING==1) printf("BISON: If-else statement1 found\n");            $$ = create_IfElseNode($1, NULL);                        if(TREE_DEBUGGING) printf("TREE: If-else statement node created\n");}
| if_statement else_statement                                                   {if(P_DEBUGGING==1) printf("BISON: If-else statement1 found\n");            $$ = create_IfElseNode($1, $2);                          if(TREE_DEBUGGING) printf("TREE: If-else statement node created\n");}
;

else_statement
: else_declaration OPEN_BRACKET statement_list CLOSED_BRACKET                   {if(P_DEBUGGING==1) printf("BISON: Else statement1 found\n");               $$ = create_ElseNode($1);                                if(TREE_DEBUGGING) printf("TREE: Else statement node created\n");}
| else_declaration OPEN_BRACKET CLOSED_BRACKET                                  {if(P_DEBUGGING==1) printf("BISON: Else statement1 found\n");               $$ = create_ElseNode($1);                                if(TREE_DEBUGGING) printf("TREE: Else statement node created\n");}
| else_declaration statement                                                    {if(P_DEBUGGING==1) printf("BISON: Else statement2 found\n");               $$ = create_ElseNode($1);                                if(TREE_DEBUGGING) printf("TREE: Else statement node created\n");}
;

if_statement
: if_declaration condition OPEN_BRACKET statement_list CLOSED_BRACKET           {if(P_DEBUGGING==1) printf("BISON: If statement1 found\n");                 $$ = create_IfNode($1,$2);                               if(TREE_DEBUGGING) printf("TREE: If statement node created\n");}
| if_declaration condition OPEN_BRACKET CLOSED_BRACKET                          {if(P_DEBUGGING==1) printf("BISON: If statement2 found\n");                 $$ = create_IfNode($1,$2);                               if(TREE_DEBUGGING) printf("TREE: If statement node created\n");}
| if_declaration condition statement                                            {if(P_DEBUGGING==1) printf("BISON: If statement3 found\n");                 $$ = create_IfNode($1,$2);                               if(TREE_DEBUGGING) printf("TREE: If statement node created\n");}
;

else_declaration
: ELSE                                                                          {if(P_DEBUGGING==1) printf("BISON: Else declaration found\n");              $$ = create_ElseDeclaration();                           if(TREE_DEBUGGING) printf("TREE: Else node created\n");}
;

if_declaration
: IF                                                                            {if(P_DEBUGGING==1) printf("BISON: If declaration found\n");                $$ = create_IfDeclaration();                             if(TREE_DEBUGGING) printf("TREE: If node created\n");}
;

while_statement
: while_declaration condition OPEN_BRACKET statement_list CLOSED_BRACKET        {if(P_DEBUGGING==1) printf("BISON: While statement1 found\n");              $$ = create_WhileNode($1,$2);                            if(TREE_DEBUGGING) printf("TREE: While statement node created\n");}
| while_declaration condition OPEN_BRACKET CLOSED_BRACKET                       {if(P_DEBUGGING==1) printf("BISON: While statement2 found\n");              $$ = create_WhileNode($1,$2);                            if(TREE_DEBUGGING) printf("TREE: While statement node created\n");}
| while_declaration condition statement                                         {if(P_DEBUGGING==1) printf("BISON: While statement3 found\n");              $$ = create_WhileNode($1,$2);                            if(TREE_DEBUGGING) printf("TREE: While statement node created\n");}
;

condition
: OPEN_ROUND expr CLOSED_ROUND                                                  {if(P_DEBUGGING==1) printf("BISON: While condition1 found\n");               $$ = create_Condition($2);                              if(TREE_DEBUGGING) printf("TREE: Condition node created\n");}
| OPEN_ROUND assignment CLOSED_ROUND                                            {if(P_DEBUGGING==1) printf("BISON: While condition2 found\n");               $$ = create_Condition($2);                              if(TREE_DEBUGGING) printf("TREE: Condition node created\n");}
;

while_declaration
: WHILE                                                                         {if(P_DEBUGGING==1) printf("BISON: While declaration found\n");             $$ = create_WhileDeclaration();                          if(TREE_DEBUGGING) printf("TREE: While node created\n");}
;

multi_asgn
: assignment COMMA assignment                                                   {if(P_DEBUGGING==1) printf("BISON: Multi assignment1 found\n");             $$ = create_MultiAssignment($1, $3);                     if(TREE_DEBUGGING) printf("TREE: Multi assignment node created\n");}
| multi_asgn COMMA assignment                                                   {if(P_DEBUGGING==1) printf("BISON: Multi assignment2 found\n");             $$ = create_MultiAssignment($1, $3);                     if(TREE_DEBUGGING) printf("TREE: Multi assignment node created\n");}
;

multi_dec_statement
: multi_dec END_COMMA                                                           {if(P_DEBUGGING==1) printf("BISON: Multi declaration statement found\n");   $$ = create_MultiDeclarationStatement($1);               if(TREE_DEBUGGING) printf("TREE: Multi declaration node created\n");}
;

multi_dec
: declaration COMMA variable                                                    {if(P_DEBUGGING==1) printf("BISON: Multi declaration1 found\n");            $$ = create_MultiDeclaration($1, $3, 1);                 if(TREE_DEBUGGING) printf("TREE: Multi declaration node created\n");}
| declaration_and_assignment COMMA variable                                     {if(P_DEBUGGING==1) printf("BISON: Multi declaration2 found\n");            $$ = create_MultiDeclaration($1, $3, 1);                 if(TREE_DEBUGGING) printf("TREE: Multi declaration node created\n");}
| multi_dec COMMA variable                                                      {if(P_DEBUGGING==1) printf("BISON: Multi declaration3 found\n");            $$ = create_MultiDeclaration($1, $3, 1);                 if(TREE_DEBUGGING) printf("TREE: Multi declaration node created\n");}
| multi_dec EQUAL expr                                                          {if(P_DEBUGGING==1) printf("BISON: Multi declaration4 found\n");            $$ = create_MultiDeclaration($1, $3, 0);                 if(TREE_DEBUGGING) printf("TREE: Multi declaration node created\n");}
| multi_dec EQUAL array_inizializer                                             {if(P_DEBUGGING==1) printf("BISON: Multi declaration5 found\n");            $$ = create_MultiDeclaration($1, $3, 0);                 if(TREE_DEBUGGING) printf("TREE: Multi declaration node created\n");}
;

declaration_and_assignment
: declaration EQUAL expr                                                        {if(P_DEBUGGING==1) printf("BISON: declaration and assignment 1 found\n");  $$ = create_Declaration_AssignmentNode ($1, $3);         if(TREE_DEBUGGING) printf("TREE: Declaration and Assignment node created\n");}
| declaration EQUAL array_inizializer                                           {if(P_DEBUGGING==1) printf("BISON: declaration and assignment 2 found\n");  $$ = create_Declaration_AssignmentNode ($1, $3);         if(TREE_DEBUGGING) printf("TREE: Declaration and Assignment node created\n");}
| declaration_and_assignment EQUAL expr                                         {if(P_DEBUGGING==1) printf("BISON: declaration and assignment 3 found\n");  $$ = create_Declaration_AssignmentNode ($1, $3);         if(TREE_DEBUGGING) printf("TREE: Declaration and Assignment node created\n");}
;

declaration
: type variable                                                                 {if(P_DEBUGGING==1) printf("BISON: declaration found\n");                   $$ = create_DeclarationNode($1, $2);                     if(TREE_DEBUGGING) printf("TREE: Declaration node created\n");}
;

assignment
: expr EQUAL expr                                                               {if(P_DEBUGGING==1) printf("BISON: assignment1 found\n");                   $$ = create_AssignmentNode(MainNode, $1, $3);            if(TREE_DEBUGGING) printf("TREE: Assignment node created\n");}
| assignment EQUAL expr                                                         {if(P_DEBUGGING==1) printf("BISON: assignment2 found\n");                   $$ = create_AssignmentNode(MainNode, $1, $3);            if(TREE_DEBUGGING) printf("TREE: Assignment node created\n");}
;

array_inizializer
: OPEN_BRACKET expr_list CLOSED_BRACKET                                         {if(P_DEBUGGING==1) printf("BISON: array initializer found\n");             $$=$2;}
;

expr_list
: expr                                                                          {if(P_DEBUGGING==1) printf("BISON: expression1 list found\n");              $$ = create_Expr_ListNode(NULL, $1);                     if(TREE_DEBUGGING) printf("TREE: Expression list node created\n");}
| expr_list COMMA expr                                                          {if(P_DEBUGGING==1) printf("BISON: expression2 list found\n");              $$ = create_Expr_ListNode($1, $3);                       if(TREE_DEBUGGING) printf("TREE: Expression list node created\n");}
;

return_statement
: RETURN expr END_COMMA                                                         {if(P_DEBUGGING==1) printf("BISON: return statement1 found\n");             $$ = create_ReturnNode($2);                              if(TREE_DEBUGGING) printf("TREE: Return node created\n");}
;

expr
: comparison                                                                    {if(P_DEBUGGING==1) printf("BISON: comparison -> expr\n");                  $$ = $1;                                                 if(TREE_DEBUGGING) printf("TREE: Expr node compare type created\n");}
| NUMBER                                                                        {if(P_DEBUGGING==1) printf("BISON: integer -> expr\n");                     $$ = create_ExprNode(NUM, $1, NULL, NULL, NULL, 0);      if(TREE_DEBUGGING) printf("TREE: Expr node integer type created\n");}
| PLUS NUMBER                                                                   {if(P_DEBUGGING==1) printf("BISON: positive integer -> expr\n");            $$ = create_ExprNode(NUM, $2, NULL, NULL, NULL, 0);      if(TREE_DEBUGGING) printf("TREE: Expr node integer type created\n");}
| MINUS NUMBER                                                                  {if(P_DEBUGGING==1) printf("BISON: negative integer -> expr\n");            $$ = create_ExprNode(NUM, -$2, NULL, NULL, NULL, 0);     if(TREE_DEBUGGING) printf("TREE: Expr node integer type created\n");}
| variable                                                                      {if(P_DEBUGGING==1) printf("BISON: variable -> expr\n");                    Check_VariableConcistency($1); $$ = $1;                  if(TREE_DEBUGGING) printf("TREE: Expr node variable type created\n");}
| STRING                                                                        {if(P_DEBUGGING==1) printf("BISON: expr STRING -> expr\n");                 $$ = create_ExprNode(STR, 0, $1, NULL, NULL, 0);         if(TREE_DEBUGGING) printf("TREE: Expr node string type created\n");}
| CH                                                                            {if(P_DEBUGGING==1) printf("BISON: expr character -> expr\n");              $$ = create_ExprNode(C, 0, &$1, NULL, NULL, 0);          if(TREE_DEBUGGING) printf("TREE: Expr node char type created\n");}
| function_call                                                                 {if(P_DEBUGGING==1) printf("BISON: expr function_call -> expr\n");          $$ = $1;                                                 if(TREE_DEBUGGING) printf("TREE: Expr node function call type created\n");}
| operation                                                                     {if(P_DEBUGGING==1) printf("BISON: expr PLUS expr -> expr\n");              $$ = $1;                                                 if(TREE_DEBUGGING) printf("TREE: Expr node operation type created\n");}
| pre_incdec                                                                    {if(P_DEBUGGING==1) printf("BISON: pre increment_decrement -> expr\n");     $$ = $1;                                                 if(TREE_DEBUGGING) printf("TREE: Expr node pre-increment/decrement type created\n");}
| post_incdec                                                                   {if(P_DEBUGGING==1) printf("BISON: post increment_decrement -> expr\n");    $$ = $1;                                                 if(TREE_DEBUGGING) printf("TREE: Expr node post-increment/decrement type created\n");}
| AMP variable                                                                  {if(P_DEBUGGING==1) printf("BISON: variable address -> expr\n");            $$ = create_ExprNode(ADD, 0, NULL, $2, NULL, 0);         if(TREE_DEBUGGING) printf("TREE: Expr node variable address type created\n");}
;

pre_incdec
: INC variable                                                                  {if(P_DEBUGGING==1) printf("BISON: pre increment ++ found\n");              $$ = create_IncDecNode(PI, $2);                          if(TREE_DEBUGGING) printf("TREE: Expr node post increment type created\n");}
| DEC variable                                                                  {if(P_DEBUGGING==1) printf("BISON: pre decrement -- found\n");              $$ = create_IncDecNode(PD, $2);                          if(TREE_DEBUGGING) printf("TREE: Expr node post decrement type created\n");}
;

post_incdec
: variable INC                                                                  {if(P_DEBUGGING==1) printf("BISON: post increment ++ found\n");             $$ = create_IncDecNode(IP, $1);                          if(TREE_DEBUGGING) printf("TREE: Expr node post increment type created\n");}
| variable DEC                                                                  {if(P_DEBUGGING==1) printf("BISON: post decrement -- found\n");             $$ = create_IncDecNode(DP, $1);                          if(TREE_DEBUGGING) printf("TREE: Expr node post decrement type created\n");}
;

operation
: expr PLUS expr                                                                {if(P_DEBUGGING==1) printf("BISON: expr PLUS expr -> operation\n");         $$ = create_OperationNode($1, $3, SUM);                if(TREE_DEBUGGING) printf("TREE: Expr node plus type created\n");}
| expr MINUS expr                                                               {if(P_DEBUGGING==1) printf("BISON: expr MINUS expr -> operation\n");        $$ = create_OperationNode($1, $3, DIF);                if(TREE_DEBUGGING) printf("TREE: Expr node difference type created\n");}
| expr STAR expr                                                                {if(P_DEBUGGING==1) printf("BISON: expr STAR expr -> operation\n");         $$ = create_OperationNode($1, $3, TIM);                if(TREE_DEBUGGING) printf("TREE: Expr node times type created\n");}
| expr DIVIDE expr                                                              {if(P_DEBUGGING==1) printf("BISON: expr DIVIDE expr -> operation\n");       $$ = create_OperationNode($1, $3, DIV);                if(TREE_DEBUGGING) printf("TREE: Expr node divide type created\n");}
| expr MODULO expr                                                              {if(P_DEBUGGING==1) printf("BISON: expr MODULO expr -> operation\n");       $$ = create_OperationNode($1, $3, MOD);                if(TREE_DEBUGGING) printf("TREE: Expr node modulo type created\n");}
| OPEN_ROUND expr CLOSED_ROUND                                                  {if(P_DEBUGGING==1) printf("BISON: ( expr ) -> operation\n");               $$ = create_OperationNode($2, $2, RND);                if(TREE_DEBUGGING) printf("TREE: Expr node round brackets type created\n");}
;

comparison
: expr AND expr                                                                 {if(P_DEBUGGING==1) printf("BISON: AND -> comparison\n");                   $$ = create_ComparisonNode($1, $3, AND_);              if(TREE_DEBUGGING) printf("TREE: Expr node and type created\n");}
| expr OR expr                                                                  {if(P_DEBUGGING==1) printf("BISON: OR -> comparison\n");                    $$ = create_ComparisonNode($1, $3, OR_);               if(TREE_DEBUGGING) printf("TREE: Expr node or type created\n");}
| expr GT expr                                                                  {if(P_DEBUGGING==1) printf("BISON: GT -> comparison\n");                    $$ = create_ComparisonNode($1, $3, GREAT_);            if(TREE_DEBUGGING) printf("TREE: Expr node greater than type created\n");}
| expr LT expr                                                                  {if(P_DEBUGGING==1) printf("BISON: LT -> comparison\n");                    $$ = create_ComparisonNode($1, $3, LESS_);             if(TREE_DEBUGGING) printf("TREE: Expr node less then type created\n");}
| expr ET expr                                                                  {if(P_DEBUGGING==1) printf("BISON: ET -> comparison\n");                    $$ = create_ComparisonNode($1, $3, EQUAL_);            if(TREE_DEBUGGING) printf("TREE: Expr node equal to type created\n");}
| expr DF expr                                                                  {if(P_DEBUGGING==1) printf("BISON: DF -> comparison\n");                    $$ = create_ComparisonNode($1, $3, DIFF_);             if(TREE_DEBUGGING) printf("TREE: Expr node different from type created\n");}
;

type
: INT                                                                           {if(P_DEBUGGING==1) printf("BISON: INT -> type\n");                         $$ = INT_;    ERROR_STATUS = 1;}
| CHAR                                                                          {if(P_DEBUGGING==1) printf("BISON: CHAR -> type\n");                        $$ = CHAR_;   ERROR_STATUS = 1;}
| error INT                                                                     {if(P_DEBUGGING==1) printf("BISON: %sERROR%s INT -> type\n",RED,RESET);     $$ = INT_;    ERROR_STATUS = 1; yyerrok;}
| error CHAR                                                                    {if(P_DEBUGGING==1) printf("BISON: %sERROR%s CHAR -> type\n",RED,RESET);    $$ = CHAR_;   ERROR_STATUS = 1; yyerrok;}
;

variable
: IDENTIFIER                                                                    {if(P_DEBUGGING==1) printf("BISON: identifier -> variable\n");              $$ = create_ExprNode(ID, 0, $1, NULL, NULL, 0);        if(TREE_DEBUGGING) printf("TREE: Variable node identifier type created\n");}
| IDENTIFIER OPEN_SQUARED expr CLOSED_SQUARED                                   {if(P_DEBUGGING==1) printf("BISON: array -> variable\n");                   $$ = create_ExprNode(VEC, 0, $1, $3, NULL, 0);         if(TREE_DEBUGGING) printf("TREE: Variable node array type created\n");}
| IDENTIFIER OPEN_SQUARED CLOSED_SQUARED                                        {if(P_DEBUGGING==1) printf("BISON: array [] -> variable\n");                $$ = create_ExprNode(VEC, 0, $1, NULL, NULL, 0);       if(TREE_DEBUGGING) printf("TREE: Variable node array type created\n");}
| error IDENTIFIER                                                              {if(P_DEBUGGING==1) printf("BISON: %sERROR%s identifier -> variable\n", RED,RESET);              $$ = create_ExprNode(ID, 0, $2, NULL, NULL, 0);        if(TREE_DEBUGGING) printf("TREE: Variable node identifier type created\n");}
| error IDENTIFIER OPEN_SQUARED expr CLOSED_SQUARED {$$ = create_ExprNode(VEC, 0, $2, $4, NULL, 0);         if(TREE_DEBUGGING) printf("TREE: Variable node array type created\n");}
| IDENTIFIER error OPEN_SQUARED expr CLOSED_SQUARED {$$ = create_ExprNode(VEC, 0, $1, $4, NULL, 0);         if(TREE_DEBUGGING) printf("TREE: Variable node array type created\n");}
;

%%

/* EPILOGO */



  int yyerror (const char *error) {
    printf ("%s %s. Found: \'%s\'.\n", ErrorMsg(), error_msg(), yytext);
  }


////////////////////  arguments_declaration_list PRODUCTION  ///////////////////
struct TreeNode * create_Arg_ListNode(struct TreeNode * arg_list, struct TreeNode * arg){

  // first element of the list
  if (arg_list == NULL){

    struct TreeNode * newTreeNode = TreeNodeInitialization (); // generic Tree Node memory space allocation
    // Linking specific node to generic Tree Node
    newTreeNode -> nodeType = ArgLst;

    if (arg != NULL){

      if (arg -> node.DclN -> arrayDim != NULL){ if (!IsCostant(arg -> node.DclN -> arrayDim)) arg -> node.DclN -> ignore = 1;}
      else if (arg -> node.DclN -> arrayDim == NULL && (arg -> node.DclN -> type == INT_V_ || arg -> node.DclN -> type == CHAR_V_)){
        arg -> node.DclN -> arrayDim = create_ExprNode(NUM, 0, NULL, NULL, NULL, 0);
        arg -> node.DclN -> ignore = 1;
      }

      exec_DclN(arg);

      TreeNodeList_Add(newTreeNode -> child_list, arg);
      return newTreeNode;
    }
    // in case of 0 arguments
    else return newTreeNode;
  }
  else{

    if (arg -> node.DclN -> arrayDim != NULL){ if (!IsCostant(arg -> node.DclN -> arrayDim)) arg -> node.DclN -> ignore = 1;}
    else if (arg -> node.DclN -> arrayDim == NULL && (arg -> node.DclN -> type == INT_V_ || arg -> node.DclN -> type == CHAR_V_)){
      arg -> node.DclN -> arrayDim = create_ExprNode(NUM, 0, NULL, NULL, NULL, 0);
      arg -> node.DclN -> ignore = 1;
    }

    exec_DclN(arg);

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

////////////////////  function_call PRODUCTION  ////////////////////////////////

struct TreeNode * create_Function_CallNode(char * function_id, struct TreeNode * expr_list){

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
    Check_FunctionCallConcistency(node);
    return node;
  }
}

////////////////////  comparison PRODUCTION  ///////////////////////////////////

struct TreeNode * create_ComparisonNode(struct TreeNode * first, struct TreeNode * second, enum cmpType cmptype){

  if (first == NULL || second == NULL) {
      printf("%s create_ComparisonNode - comparison missing one or two expressions\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
    else{

      struct TreeNode * node = create_ExprNode(CMP, 0, NULL, first, second, cmptype);
      Check_ComparisonConcistency(node);

      return node;
    }
}

////////////////////  function node PRODUCTION  ////////////////////////////////

void create_FunctionNode(struct TreeNode * declaration, struct TreeNode * parameters){

  // check parameters
  Check_NodeType(DclN, declaration, "create_functionNode");
  Check_NodeType(ArgLst, parameters, "create_functionNode");

  Add_Node_Tree(parameters);

  char * fun_identifier = TreeNode_Identifier(declaration);

  if (!strcmp("main", fun_identifier)){
    // main arguments warning
    if (parameters -> child_list -> elements != 0) printf("%s this interpreter does not support main function arguments. \nArguments will be ignored.\n", WarnMsg());
    // main function scope must be active
    Scope_Activation();
    // there's a main function in the file
    MainNode -> main_flag = 1;
  }
}

////////////////////  if PRODUCTION  ///////////////////////////////////////////

struct TreeNode * create_IfElseNode(struct TreeNode * if_node, struct TreeNode * else_node){

  Check_NodeType(If, if_node, "create_IfElseNode");

  // creating a generic Tree Node with memory allocation
  struct TreeNode * newIfElseNode = TreeNodeInitialization();
  // Tree Node Type
  newIfElseNode -> nodeType = IfElse;
  // linking if node to if-else node
  TreeNodeList_Add(newIfElseNode -> child_list, if_node);

  // if there's an else condition
  if (else_node != NULL){
    // else_node must be an Else node
    Check_NodeType(Else, else_node, "create_IfElseNode");
    // linking else node to the if-else node
    TreeNodeList_Add(newIfElseNode -> child_list, else_node);
  }

  // return flag check
  char if_return_flag = Check_return_statement(if_node -> child_list -> first);
  char else_return_flag;
  if (else_node != NULL) else_return_flag = Check_return_statement(else_node -> child_list -> first);


  if (if_return_flag == 1 && else_return_flag == 1)
    MainNode -> actual_stack -> top -> return_flag = 1;

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
  SetAs_ActualScope(ElseScope, 0);

  return newElseNode;
}

struct TreeNode * create_IfNode (struct TreeNode * if_node, struct TreeNode * condition){

  Check_NodeType(If, if_node, "create_IfNode");
  Check_NodeType(Expr, condition, "create_IfNode");

  // linking condition to the if node
  TreeNodeList_Add(if_node -> child_list, condition);
  // if-scope is ended
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
  SetAs_ActualScope(ifScope, 0);
  // by default if condition is not satisfied
  newIfNode -> node.flag = 0;

  return newIfNode;
}

////////////////////  while PRODUCTION  ////////////////////////////////////////

struct TreeNode * create_WhileNode(struct TreeNode * while_node, struct TreeNode * condition){

  Check_NodeType(While, while_node, "create_WhileNode");
  Check_NodeType(Expr, condition, "create_WhileNode");

  TreeNodeList_Add(while_node -> child_list, condition);
  ScopeStack_Pop(MainNode -> actual_stack);

  return while_node;
}

struct TreeNode * create_Condition(struct TreeNode * expr){

  struct TreeNode * condition;

  if ( expr -> nodeType == Expr){

    enum exprType type = expr -> node.Expr -> exprType;

    if (type == STR) printf("%s address of string will always evaluate to \'true\'.\n", WarnMsg());
    else if (type == ADD){

      if (expr -> child_list -> first -> node.Expr -> exprType == ID)
        printf("%s address of \'%s\' will always evaluate to \'true\'.\n", WarnMsg(), TreeNode_Identifier(expr));
      else if (expr -> child_list -> first -> node.Expr -> exprType == VEC)
        printf("%s address of \'%s[%d]\' will always evaluate to \'true\'.\n", WarnMsg(), TreeNode_Identifier(expr), Retrieve_ArrayIndex(expr -> child_list -> first));

    }
    else if (isArrayPointer(expr))
      printf("%s address of array \'%s\' will always evaluate to \'true\'.\n", WarnMsg(), TreeNode_Identifier(expr));
    else if(IsCostant(expr)){

      char value = CMP_node_logicValue(expr);
      if (value == 1){
        printf("%s condition is always true.\n", WarnMsg());
      }
      else if(value == 0){
        printf("%s condition is always false.\n", WarnMsg());
      }
    }

    condition = expr;
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
  SetAs_ActualScope(whileScope, 0);

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
    exec_DclN(declaration);

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
        exec_DclN(declaration -> child_list  -> last);
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

struct TreeNode * create_MultiDeclarationStatement(struct TreeNode * multi_dec){

  Check_NodeType(MultiDc, multi_dec, "create_MultiDeclarationStatement");

  struct TreeNode * last_declaration = multi_dec -> child_list -> last;
  if ( last_declaration -> nodeType == DclN ){
    exec_DclN(last_declaration);
  }
  else if ( !last_declaration -> nodeType == DclAsgn ){
    printf("%s unexpected expression.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  return multi_dec;
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
        exec_DclN(declaration);

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
          var_dimension = Expr_toInt(declaration -> node.DclN -> arrayDim);
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
          exec_DclN(declaration);

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
    Check_AsgnConcistency(leftOp, rightOp);
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
    Check_AsgnConcistency(leftOp_node, rightOp);

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

struct TreeNode * create_ReturnNode(struct TreeNode * expr){

  struct TreeNode * newTreeNode = TreeNodeInitialization (); // generic Tree Node memory space allocation

  // Linking specific node to generic Tree Node
  newTreeNode -> nodeType = Return;
  // Linking returned expression to the return node
  TreeNodeList_Add(newTreeNode -> child_list, expr);

  int value;
  if (IsCostant(expr)){
    value = Expr_toInt(expr);

    FunNode * function_node = MainNode -> function_list -> last;
    enum Type function_type = function_node -> funType;

    if (function_type == CHAR_) Check_CharConcistency(value);
  }

  return newTreeNode;
}

////////////////////  pre_incdec_statement PRODUCTION  //////////////////////////

struct TreeNode * create_IncDecNode(enum exprType type, struct TreeNode * var){

  Check_NodeType(Expr, var, "create_IncDecNode");

  if (isAssignable(var)){
    Check_VariableConcistency(var);
    return create_ExprNode(type, 0, NULL, var, NULL, 0);
  }
  else{
    printf("%s expression is not assignable.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
}

////////////////////  operation PRODUCTION  ////////////////////////////////////

struct TreeNode * create_OperationNode(struct TreeNode * first, struct TreeNode * second, enum exprType type){

  Check_NodeType(Expr, first, "create_OperationNode");
  Check_NodeType(Expr, second, "create_OperationNode");

  if (first == NULL || second == NULL) {
      printf("%s create_OperationNode - comparison missing one or two expressions\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
  else{
    struct TreeNode * node = create_ExprNode(type, 0, NULL, first, second, 0);
    Check_OperationConcistency(node);

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
      case NUM: if(intExpr > -2147483649 && intExpr < 2147483648){
                  NewExprNode -> exprVal.intExpr = (int)intExpr;
                }
                else{
                 printf("%s out of integer range. This interpreter works with integer numbers only.\n",ErrorMsg());
                 exit(EXIT_FAILURE);
               }
                break;
      case ID:  NewExprNode -> exprVal.stringExpr = charExpr;
                break;
      case VEC: NewExprNode -> exprVal.stringExpr = charExpr;
                // check if vec has a dimension
                if(first != NULL){
                  enum Type dimension_type = expressionType(first);

                  // check if array dimension index is not a pointer
                  if (dimension_type == INT_ || dimension_type == CHAR_){

                    // adding the array dimension index as tree node child
                    TreeNodeList_Add(newTreeNode -> child_list, first);
                  }
                  // display error message if the dimension index is a string
                  else{
                    printf("%s size of array has non-integer type. Type found \'%s\'.\n", ErrorMsg(), IdentifierTypeString(dimension_type));
                    exit(EXIT_FAILURE);
                  }
                  // check if dimension is a variable
                }
                break;
      case STR: NewExprNode -> exprVal.stringExpr = (char *)malloc (sizeof(char) *strlen(charExpr)-1);
                // skipping the first and last apex
                for (int i =1; i<strlen(charExpr)-1; i++){
                  NewExprNode -> exprVal.stringExpr[i-1]=charExpr[i];
                }
                // adding end string symbol
                NewExprNode -> exprVal.stringExpr[strlen(charExpr)] = '\0';
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

//////////////////  concistency FUNCTIONS  /////////////////////////////////////

void Check_CharConcistency(int value){
  if (value < -128 || value > 127){
    printf("%s implicit conversion from 'int' to 'char' changes value from %d to %d\n", WarnMsg(), value, (char)value);
  }
}

void Check_IdentifierConcistency(struct TreeNode * identifier_node){

  Check_NodeType(Expr, identifier_node, "Check_IdentifierConcistency");
  Check_ExprType(ID, identifier_node, "Check_IdentifierConcistency");

  char * identifier = identifier_node -> node.Expr -> exprVal.stringExpr;
  // check declaration
  if (!Check_VarWasDeclared(identifier, 1)){
    printf("%s use of undeclared identifier \'%s\'.\n", ErrorMsg(), identifier);
    exit(EXIT_FAILURE);
  }
}

void Check_ArrayConcistency(struct TreeNode * array){

  Check_NodeType(Expr, array, "Check_ArrayConcistency");
  Check_ExprType(VEC, array, "Check_ArrayConcistency");

  char * array_id = array -> node.Expr -> exprVal.stringExpr;
  // check declaration
  if (!Check_VarWasDeclared(array_id, 1)){

    printf("%s use of undeclared identifier \'%s\'.\n", ErrorMsg(), array_id);
    exit(EXIT_FAILURE);
  }
  else{
    // array dimension index missing
    if (array -> child_list -> elements == 0){
      printf("%s expexted expression.\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
    // check array index
    int index = Retrieve_ArrayIndex(array);
    int array_dim = Retrieve_ArrayDim(array_id);

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

void Check_VariableConcistency(struct TreeNode * node){

  Check_NodeType(Expr, node, "Check_VariableConcistency");
  char * identifier = TreeNode_Identifier(node);

  if (node -> node.Expr -> exprType == ID) Check_IdentifierConcistency(node);
  else if (node -> node.Expr -> exprType == VEC) Check_ArrayConcistency(node);
  else {
    printf("%s Check_VariableConcistency unexpected expression type. Type found %s.\n", ErrorMsg(), ExprTypeString(node));
    exit(EXIT_FAILURE);
  }
}

void Check_OperationConcistency (struct TreeNode * operation_node){

  Check_NodeType(Expr, operation_node, "Check_OperationConcistency");
  if (operation_node -> nodeType == Expr){
    if(isOperation(operation_node)){

      if (operation_node -> node.Expr -> exprType != RND){
        // left operand type check
        struct TreeNode * leftOp = operation_node -> child_list -> first;
        enum Type leftOp_type = expressionType(leftOp);

        // right operand type check
        struct TreeNode * rightOp = operation_node -> child_list -> first -> next;
        enum Type rightOp_type = expressionType(rightOp);

        // left operand must not be a pointer
        if (leftOp_type != INT_ && leftOp_type != CHAR_){
          printf("%s Invalid operands. Operations with pointers are not allowed.\n", ErrorMsg());
          exit(EXIT_FAILURE);
        }
        // right operand must not be a pointer
        if (rightOp_type != INT_ && rightOp_type != CHAR_){
          printf("%s Invalid operands. Operations with pointers are not allowed.\n", ErrorMsg());
          exit(EXIT_FAILURE);
        }

        // Raise a warning if there's a division by 0
        if(operation_node -> node.Expr -> exprType == DIV || operation_node -> node.Expr -> exprType == MOD){
          // If the second operand is costant
          if(IsCostant(operation_node -> child_list -> first -> next)){
            // If the second operand value is 0
            if(Expr_toInt(operation_node -> child_list -> first -> next) == 0){
              printf("%s division by zero is undefined.\n", WarnMsg());
            }
          }
        }
        // Node value pre-calculus if it is not a division by 0
        else if(IsCostant(operation_node)){

            int value = Expr_toInt(operation_node);
            operation_node -> node.Expr -> exprVal.intExpr = value;
            operation_node -> node.Expr -> known = 1;
        }
      }
    }
    else{
      printf("%s Check_OperationConcistency - incorrect call. SUM/DIF/TIM/DIV/MOD/RND Expr TreeNode expected.\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
  }
}

void Check_ComparisonConcistency (struct TreeNode * comparison_node){

  Check_NodeType(Expr, comparison_node, "Check_ComparisonConcistency");
  Check_ExprType(CMP, comparison_node, "Check_ComparisonConcistency");

  enum cmpType type = comparison_node -> node.Expr -> exprVal.cmpExpr;

  // comparison is a binary logic operation with two operands: leftOp and rightOp
  struct TreeNode * leftOp = comparison_node -> child_list -> first;
  struct TreeNode * rightOp = comparison_node -> child_list -> first -> next;

  // comparison is a binary logic operation with two operands: leftOp and rightOp
  enum exprType leftOp_type = leftOp -> node.Expr -> exprType;
  enum exprType rightOp_type = rightOp -> node.Expr -> exprType;

  enum Type left_type = expressionType(leftOp);
  enum Type right_type = expressionType(rightOp);

  // operands must not be
  if ((left_type != INT_ && left_type != CHAR_) || ((right_type != INT_ && right_type != CHAR_))){
    printf("%s Invalid operands. Operations with pointers are not allowed.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }

  if (type == AND_ || type == OR_){

    // Raise a warning if the operand is a costant and is different from 0 or 1
    if (IsCostant(leftOp)){
      int value = Expr_toInt(leftOp);
      if (value != 0 && value != 1){
        printf("%s logical operation with costant first operand.\n", WarnMsg());
      }

    }
    if (IsCostant(rightOp)){
      int value = Expr_toInt(rightOp);
      if (value != 0 && value != 1){
        printf("%s logical operation with costant second operand.\n", WarnMsg());
      }
    }

  }
  else if(type == GREAT_ || type == LESS_ || type == EQUAL_ || type == DIFF_ ){

    // Print a warning if the comparison with a char is always true or always false
    if (IsCostant(leftOp)){
      if (rightOp_type == ID || rightOp_type == VEC){
        char * identifier = TreeNode_Identifier(rightOp);
        enum Type varType = Retrieve_VarType(identifier);

        if (varType == CHAR_ || varType == CHAR_V_){
          if (type == GREAT_){
            if (Expr_toInt(leftOp) > 127){
              printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), Expr_toInt(leftOp));
            }
            else if (Expr_toInt(leftOp) < -128){
              printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(leftOp));
            }
          }
          if (type == LESS_){
            if (Expr_toInt(leftOp) > 127){
              printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(leftOp));
            }
            else if (Expr_toInt(leftOp) < -128){
              printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), Expr_toInt(leftOp));
            }
          }
          if (type == EQUAL_){
            if (Expr_toInt(leftOp) > 127){
              printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(leftOp));
            }
            else if (Expr_toInt(leftOp) < -128){
              printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(leftOp));
            }
          }
          if (type == DIFF_){
            if (Expr_toInt(leftOp) > 127){
              printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), Expr_toInt(leftOp));
            }
            else if (Expr_toInt(leftOp) < -128){
              printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), Expr_toInt(leftOp));
            }
          }
        }
      }
    }
    if (IsCostant(rightOp)){
      if (leftOp_type == ID || leftOp_type == VEC){
        char * identifier = TreeNode_Identifier(leftOp);
        enum Type varType = Retrieve_VarType(identifier);

        if (varType == CHAR_ || varType == CHAR_V_){
          if (type == GREAT_){
            if (Expr_toInt(rightOp) > 127){
              printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(rightOp));
            }
            else if (Expr_toInt(rightOp) < -128){
              printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), Expr_toInt(rightOp));
            }
          }
          if (type == LESS_){
            if (Expr_toInt(rightOp) > 127){
              printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), rightOp -> node.Expr -> exprVal.intExpr);
            }
            else if (Expr_toInt(rightOp) < -128){
              printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), rightOp -> node.Expr -> exprVal.intExpr);
            }
          }
          if (type == EQUAL_){
            if (Expr_toInt(rightOp) > 127){
              printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(rightOp));
            }
            else if (Expr_toInt(rightOp) < -128){
              printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(rightOp));
            }
          }
          if (type == DIFF_){
            if (Expr_toInt(rightOp) > 127){
              printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), rightOp -> node.Expr -> exprVal.intExpr);
            }
            else if (Expr_toInt(rightOp) < -128){
              printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), rightOp -> node.Expr -> exprVal.intExpr);
            }
          }
        }
      }
    }

    // Print a warning if the comparison with an other comparison is always true or always false
    if (leftOp_type == CMP && IsCostant(rightOp)){
      if (type == GREAT_){
        if (Expr_toInt(rightOp) < 0){
            printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(rightOp));
        }
        if (Expr_toInt(rightOp) > 0){
            printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(rightOp));
        }
      }
      if (type == LESS_){
        if (Expr_toInt(rightOp) > 1){
            printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(rightOp));
        }
        if (Expr_toInt(rightOp) < 1){
            printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(rightOp));
        }
      }
      if (type == EQUAL_){
        if (Expr_toInt(rightOp) != 0 &&  Expr_toInt(rightOp) != 1){
              printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(rightOp));
          }
      }
      if (type == DIFF_){
        if (Expr_toInt(rightOp) != 0 &&  rightOp -> node.Expr -> exprVal.intExpr != 1){
            printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(rightOp));
        }
      }
    }
    if (IsCostant(leftOp) && rightOp_type == CMP){
      if (type == GREAT_){
        if (Expr_toInt(leftOp) > 1){
            printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(leftOp));
        }
        if (Expr_toInt(leftOp) < 1){
            printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(leftOp));
        }
      }
      if (type == LESS_){
        if (Expr_toInt(leftOp) < 0){
            printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(leftOp));
        }
        if (Expr_toInt(leftOp) > 0){
            printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(leftOp));
        }
      }
      if (type == EQUAL_){
        if (Expr_toInt(leftOp) != 0 &&  Expr_toInt(leftOp) != 1){
              printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(leftOp));
          }
      }
      if (type == DIFF_){
        if (Expr_toInt(leftOp) != 0 &&  Expr_toInt(leftOp) != 1){
            printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(leftOp));
        }
      }
    }

    // Print a warning if the comparison is between a variable and itself
    if ((leftOp_type == ID) && (rightOp_type == ID)){

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
    if ((leftOp_type == VEC) && (rightOp_type == VEC)){

      char * left_identifier = TreeNode_Identifier(leftOp);
      char * right_identifier = TreeNode_Identifier(rightOp);
      // arrays must have the same index
      if ((IsCostant(leftOp -> child_list -> first))&&(IsCostant(rightOp -> child_list -> first))){
        if (Retrieve_ArrayIndex(leftOp) == Retrieve_ArrayIndex(leftOp)){

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
  }
}

void Check_AsgnConcistency(struct TreeNode * leftOp, struct TreeNode * rightOp){

  Check_NodeType(Expr, leftOp,  "Check_AsgnConcistency");
  Check_NodeType(Expr, rightOp, "Check_AsgnConcistency");


  enum exprType leftOp_type = leftOp -> node.Expr -> exprType;
  enum exprType rightOp_type = rightOp -> node.Expr -> exprType;

  // Only valid variables and array elements are assignable
  if (isAssignable(leftOp)){

    enum Type variable_type = expressionType(leftOp);
    enum Type value_type = expressionType(rightOp);

    // check if the value is an integer
    if (value_type != INT_ && value_type != CHAR_)
      printf("%s incompatible pointer to integer conversion assigning to '%s' from '%s'.\n", WarnMsg(), IdentifierTypeString(variable_type), IdentifierTypeString(value_type));

    char * leftOp_identifier = TreeNode_Identifier(leftOp);

    // Char assignment concistency
    if (IsCostant(rightOp)){

      enum Type varType = Retrieve_VarType(leftOp_identifier);
      if (varType == CHAR_ || varType == CHAR_V_){

        int value = Expr_toInt(rightOp);
        Check_CharConcistency(value);
      }
    }

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

  Check_NodeType(Expr, variable, "Check_DeclConcistency");

  if (variable -> node.Expr -> exprType == ID || variable -> node.Expr -> exprType == VEC){

    char * identifier = TreeNode_Identifier(variable);
    // check if variable was previously declared
    if(Check_VarWasDeclared(identifier, 0)){
      printf("%s redefinition of %s.\n", ErrorMsg(), identifier);
      exit(EXIT_FAILURE);
    }

  }
  else{
    printf("%s Check_DeclConcistency - unexpected Expr type. Type found: %u.\n", ErrorMsg(), variable -> node.Expr -> exprType);
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
    if ((node -> node.DclN -> arrayDim == NULL) && (node -> node.DclN -> type == INT_V_ || node -> node.DclN -> type == CHAR_V_)){
      if (node -> node.DclN -> ignore) return 1;
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

void Check_FunctionCallConcistency (struct TreeNode * function_call){

  Check_NodeType(Expr, function_call, "Check_FunctionCallConcistency");
  Check_ExprType(FC, function_call, "Check_FunctionCallConcistency");

  char * function_id = function_call -> node.Expr -> exprVal.stringExpr;

  // check if function was declared
  if(CheckFunAlreadyExist(function_id)) Check_FunctionParameters(function_call);
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
  int index = FunNodeList_Search(identifier);
  struct FunNode * functionNode = FunNodeList_Get(index);

  struct TreeNode * call_parameters;
  struct TreeNode * decl_parameters = functionNode -> function_scope -> child_list -> first;

  int call_parameters_No;
  int decl_parameters_No = decl_parameters -> child_list -> elements;

  // if function call has parameters
  if (function_call -> child_list -> elements > 0){

    call_parameters = function_call -> child_list -> first;
    call_parameters_No = call_parameters -> child_list -> elements;
  }
  // if function call has not parameters
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
  // no error: right number of parameters
  else{
    struct TreeNode * declaration;
    struct TreeNode * argument;
    for (int i = 0; i < decl_parameters_No; i++){

      if (i == 0) declaration = decl_parameters -> child_list -> first;
      else declaration = declaration -> next;

      if (i == 0) argument = call_parameters -> child_list -> first;
      else argument = argument -> next;

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
  if ((declaration_type == INT_ || declaration_type == CHAR_) && (expression_type == INT_V_ || expression_type == CHAR_V_ || expression_type == INT_P_ || expression_type == CHAR_P_)){
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
  else if (string_form == 'x' || string_form == 'X'){
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
    if (variable -> node.Expr -> exprType == ID) Check_IdentifierConcistency(variable);
    if (variable -> node.Expr -> exprType == VEC) Check_ArrayConcistency(variable);

  }
  else{
    printf("%s variable not found.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
}

void Warning_Unused(struct TreeNode * node){

  Check_NodeType(Expr, node, "Warning_Unused");

  enum exprType type = node -> node.Expr -> exprType;

  switch (type) {

    case NUM: printf("%s expression result unused.\n", WarnMsg());
              break;
    case ID:  printf("%s expression result unused.\n", WarnMsg());
              break;
    case VEC: printf("%s expression result unused.\n", WarnMsg());
              break;
    case STR: printf("%s expression result unused.\n", WarnMsg());
              break;
    case C:   printf("%s expression result unused.\n", WarnMsg());
              break;
    case FC:  break;
    case SUM: printf("%s expression result unused.\n", WarnMsg());
              break;
    case DIF: printf("%s expression result unused.\n", WarnMsg());
              break;
    case TIM: printf("%s expression result unused.\n", WarnMsg());
              break;
    case DIV: printf("%s expression result unused.\n", WarnMsg());
              break;
    case MOD: printf("%s expression result unused.\n", WarnMsg());
              break;
    case RND: printf("%s expression result unused.\n", WarnMsg());
              break;
    case CMP: printf("%s expression result unused.\n", WarnMsg());
              break;
    case PI:  break;
    case PD:  break;
    case IP:  break;
    case DP:  break;
    case ADD: printf("%s expression result unused.\n", WarnMsg());
              break;
    default:  break;

  }
}

//////////////////  execution CONTROL  /////////////////////////////////////////

int Check_Main(){

  struct FunNode * actualFunction =  MainNode -> function_list -> last;
  if (!strcmp("main", actualFunction -> funName)) return 1;
  else return 0;
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

int Function_End(){

  // Return warning
  if (MainNode -> actual_stack -> top -> return_flag == 0)
    printf("%s control may reach end of non-void function.\n", WarnMsg());

  // Resetting global scope as actual scope
  MainNode -> actual_stack = MainNode -> global_scope_stack;

  if (!strcmp("main", MainNode -> function_list -> last -> funName)) return 1;
  else return 0;
}

void Update_return_flag(){

  MainNode -> actual_stack -> top -> return_flag = 1;
}

void Propagate_return_flag(){

  if (MainNode -> actual_stack -> top -> return_flag == 1)
    MainNode -> actual_stack -> top -> prevScope -> return_flag = 1;
}

int Check_return_statement(struct TreeNode * scope){

  Check_NodeType(Scope, scope, "Check_return_statement");
  struct TreeNode * statement;

  for (int i = 0; i < scope -> child_list -> elements; i++){
    if (i == 0) statement = scope -> child_list -> first;
    else statement = statement -> next;

    if (statement -> nodeType == Return) return 1;
  }

  return 0;
}

int Return_main (struct TreeNode * node){

  if (node != NULL) {

    Check_NodeType(Expr, node, "Return");

    MainNode -> return_value = Expr_toInt(node);
    return 1;
  }
  else return 0;
}

//////////////////  error messages  ////////////////////////////////////////////

char * error_msg(){

  if      (ERROR_STATUS == 0) return "expected variable or function declaration";
  else if (ERROR_STATUS == 1) return "expexted identifier";
  else "";
}
