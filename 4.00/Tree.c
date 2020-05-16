#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "exec.h"
#include "lexer.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int treeDepth = 0;
int P_DEBUGGING;
int ST_DEBUGGING;
int TREE_DEBUGGING;
int TREE_BUILDING;

ProgramNode * MainNode;

////////////////////////////////////////////////////////////////////////////////
////////////////// ERROR MESSAGES //////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

char * ErrorMsg (){

  char * error = (char*)malloc(sizeof("\n\aline:10000000000\x1b[31merror:\x1b[0m ") + sizeof(char)*100);
  sprintf (error, "\n%cline %d: %serror:%s",7,yylineno,ANSI_COLOR_RED,ANSI_COLOR_RESET);
  return error;
}
char * WarnMsg (){

  char * error = (char*)malloc(sizeof("\nline:10000000000\x1b[31merror:\x1b[0m ") + sizeof(char)*100);
  sprintf (error, "\nline %d: %swarning:%s",yylineno,ANSI_COLOR_RED,ANSI_COLOR_RESET);
  MainNode -> warnings++;
  return error;
}

struct ErrorList * Error_Set(){

  struct ErrorList * new = (struct ErrorList *) malloc (sizeof(struct ErrorList));
  new -> elements = 0;
  new -> first = NULL;
  new -> last = NULL;
  return new;
}
void Error_Add (struct ErrorList * list, char * newError){

  struct Error * error = (struct Error *) malloc (sizeof(struct Error));
  error -> errorMsg = (char *) malloc (sizeof(char)*strlen(newError));
  strcpy(error -> errorMsg, newError);
  error -> next = NULL;

  if (list -> elements == 0){

    list -> first = list -> last = error;
    list -> first -> next = error;
    list -> last -> next = NULL;
  }
  else{

    list -> last -> next = error;
    list -> last = error;
  }

  list -> elements ++;
}
void PrintErrors (struct ErrorList * list){

  struct Error * error;
  error = list -> first;
  while (error!=NULL){              // equivalente a while (error != NULL)
    printf("%s\n",error -> errorMsg);
    error = error -> next;
  }

}


////////////////////////////////////////////////////////////////////////////////
///////////////// TREE NODE USEFUL FUNCTIONS ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/*
* Returns variable identifier stored in the TreeNode
*/
char * TreeNode_Identifier(struct TreeNode * node){

  if (node -> nodeType == DclN) return node -> node.DclN -> identifier;

  else if (node -> nodeType == Expr){

    enum exprType expression_type = node -> node.Expr -> exprType;

    if (expression_type == ID || expression_type == VEC)
       return node -> node.Expr -> exprVal.stringExpr;
    else if (expression_type == PI || expression_type == PD || expression_type == IP || expression_type == DP)
       return TreeNode_Identifier(node -> child_list -> first);
    else if (expression_type == PA || expression_type == ADD) return TreeNode_Identifier(node -> child_list -> first);
    else{
      printf("%s TreeNode_Identifier - this expression tree node \'%s\' has not an identifier\n", ErrorMsg(), ExprTypeString(node));
      return NULL;
    }
  }

  else if (node -> nodeType == Asgn) return TreeNode_Identifier(node -> child_list -> first);

  else{
    printf("%s TreeNode_Identifier - incorrect call. Expr or DclN TreeNode expected. Type found: %u\n", ErrorMsg(), node -> nodeType);
    return NULL;
  }
}
/*
* Returns the index of an array from the VEC Tree Node
*/
int Retrieve_ArrayIndex(ProgramNode * prog, struct TreeNode * node){

  struct TreeNode * arrayDimNode;

  if (node -> nodeType == DclN) arrayDimNode = node -> node.DclN -> arrayDim;
  else if (node -> nodeType == Expr) {if (node -> node.Expr -> exprType == VEC) arrayDimNode = node -> child_list -> first;}
  else{
    printf("%s Retrieve_ArrayIndex - incorrect call. Expr TreeNode expected. Type found: %u\n", ErrorMsg(), node -> nodeType);
    exit(EXIT_FAILURE);
  }

  return Expr_toInt(prog, arrayDimNode);
}
/*
* Given an Expr TreeNode return its integer value.
*/
int Expr_toInt(ProgramNode * prog, struct TreeNode * node){

  Check_NodeType(Expr, node, "Expr_toInt");

  int value;
  int index;
  enum exprType type = node -> node.Expr -> exprType;
  enum Type var_type;
  // if value is already known
  if(node -> node.Expr -> known == 1){
  value = node -> node.Expr -> exprVal.intExpr;
  }
  else{
    switch (type) {
      case NUM: value = node -> node.Expr -> exprVal.intExpr;
                break;
      case ID:  var_type = Retrieve_VarType(MainNode, TreeNode_Identifier(node));
                if (var_type == INT_ || var_type == CHAR_) value = Retrieve_VarValue(prog, TreeNode_Identifier(node), 0);
                else if (var_type == INT_V_ || var_type == CHAR_V_) value = (int)Retrieve_VarPointer(TreeNode_Identifier(node), 0);
                break;
      case VEC: index = Retrieve_ArrayIndex(prog, node);
                value = Retrieve_VarValue(prog, node -> node.Expr -> exprVal.stringExpr, index);
                break;
      case STR: value = (int)node -> node.Expr -> exprVal.stringExpr;
                break;
      case C:   value = node -> node.Expr -> exprVal.charExpr;
                break;
      case FC:  value = exec_FunctionCall(node);
                break;
      case SUM: value = exec_Operation(node);
                break;
      case DIF: value = exec_Operation(node);
                break;
      case TIM: value = exec_Operation(node);
                break;
      case DIV: value = exec_Operation(node);
                break;
      case MOD: value = exec_Operation(node);
                break;
      case RND: value = exec_Operation(node);
                break;
      case CMP: value = exec_CMP(node);
                break;
      case PI:  value = exec_IncDec(node);
                break;
      case PD:  value = exec_IncDec(node);
                break;
      case IP:  value = exec_IncDec(node);
                break;
      case DP:  value = exec_IncDec(node);
                break;
      case PA:  exec_Asgn(MainNode, node -> child_list -> first);
                value = Expr_toInt(MainNode, node -> child_list -> first -> child_list -> first);
                break;
      case ADD: if (node -> child_list -> first -> node.Expr -> exprType == ID){
                  value = (int)Retrieve_VarPointer(TreeNode_Identifier(node -> child_list -> first), 0);
                }
                else if (node -> child_list -> first -> node.Expr -> exprType == VEC){
                  index = Retrieve_ArrayIndex(prog, node -> child_list -> first);
                  value = (int)Retrieve_VarPointer(TreeNode_Identifier(node -> child_list -> first), index);
                }
                else{
                  printf("%s Expr_toInt - unexpected expr type. Type found %s.\n", ErrorMsg(), ExprTypeString(node -> child_list -> first -> node.Expr -> exprType));
                  exit(EXIT_FAILURE);
                }
                break;
      default:  printf("%s Expr_toInt - incorrect call. Unexpected Expr. %d\n", ErrorMsg(),type);
                exit(EXIT_FAILURE);
                break;
    }
  }
  return value;
}
/*
* Given an expression returns 1 if its value is costant, 0 if is variable
*/
int IsCostant(struct TreeNode * node){

  if (node -> nodeType == Expr){

    enum exprType type = node -> node.Expr -> exprType;

    switch (type) {
      case NUM: return 1;
                break;
      case ID:  return 0;
                break;
      case VEC: return 0;
                break;
      case STR: return 0;
                break;
      case C:   return 1;
                break;
      case FC:  return 0;
                break;
      case SUM: return (IsCostant(node -> child_list -> first) && IsCostant(node -> child_list -> first -> next));
                break;
      case DIF: return (IsCostant(node -> child_list -> first) && IsCostant(node -> child_list -> first -> next));
                break;
      case TIM: return (IsCostant(node -> child_list -> first) && IsCostant(node -> child_list -> first -> next));
                break;
      case DIV:  return (IsCostant(node -> child_list -> first) && IsCostant(node -> child_list -> first -> next) && Expr_toInt(MainNode, node -> child_list -> first -> next) != 0);
                break;
      case MOD: return (IsCostant(node -> child_list -> first) && IsCostant(node -> child_list -> first -> next));
                break;
      case RND: return IsCostant(node -> child_list -> first);
                break;
      case CMP: return (IsCostant(node -> child_list -> first) && IsCostant(node -> child_list -> first -> next));
                break;
      case PI:  return 0;
                break;
      case PD:  return 0;
                break;
      case IP:  return 0;
                break;
      case DP:  return 0;
                break;
      case PA:  return (IsCostant(node -> child_list -> first -> child_list -> last));
                break;
      default:
                printf("%s IsCostant - unexpected exprType. Type found %u.\n", ErrorMsg(), type);
                exit(EXIT_FAILURE);
                break;
    }
  }
  else{
    printf("%s IsCostant - incorrect call. Expr node expected.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
}
/*
* Given an expression returns 1 if it is an operation, otherwise 0
*/
int isOperation(struct TreeNode * node){

  if(node -> nodeType == Expr){

    enum exprType type = node -> node.Expr -> exprType;
    if(type == SUM || type == DIF || type == TIM || type == DIV || type == MOD || type == RND ){
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    printf("%s isOperation - incorrect call. Expr node expected.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
}
/*
* Given an expression returns 1 if it is assignable (variable identifier or array element), otherwise it generates an error message
*/
int isAssignable(struct TreeNode * node){

  if(node -> nodeType == Expr){

    if(node -> node.Expr -> exprType == ID || node -> node.Expr -> exprType == VEC){

      char * identifier = TreeNode_Identifier(node);

      // check if the variable was previously declared before be assigned
      if (!Check_VarWasDeclared(MainNode, identifier, 1)){

        printf("%s use of undeclared identifier \'%s\'\n", ErrorMsg(), identifier);
        exit(EXIT_FAILURE);
      }

      enum Type varType = Retrieve_VarType(MainNode, identifier);

      // array identifier are not assignable
      if (node -> node.Expr -> exprType == ID){
        if(varType == INT_V_ || varType == CHAR_V_){

          printf("%s array pointer is not assignable.\n", ErrorMsg());
          exit(EXIT_FAILURE);
          return 0;
        }
        else{
        return 1;
      }
      }
      else if (node -> node.Expr -> exprType == VEC){

        // array without dimension
        if(node -> child_list -> elements == 0){
          printf("%s array '%s' dimension expression missing.\n", ErrorMsg(), identifier);
          exit(EXIT_FAILURE);
          return 0;
        }
        else if (!IgnoreFlag(identifier)){
          int index = Retrieve_ArrayIndex(MainNode, node);
          int array_dim = Retrieve_ArrayDim(MainNode, identifier);

          // out of bounds array error
          if (index > array_dim - 1){
            printf("%s array index %d is past the end of the array. Array contains %d elements.\n", ErrorMsg(), index, array_dim);
            exit(EXIT_FAILURE);
            return 0;
          }
          else if (index < 0){
            printf("%s array index %d is before the beginning of the array. Array contains %d elements.\n", ErrorMsg(), index, array_dim);
            exit(EXIT_FAILURE);
            return 0;
          }
          else return 1;
        }
        // ignore case
        else return 1;
      }
    }
    else{
      printf("%s %s expression is not assignable.\n", ErrorMsg(), ExprTypeString(node));
      exit(EXIT_FAILURE);
      return 0;
    }
  }
  else{
    printf("%s isAssignable - incorrect call. Expr node expected.\n", ErrorMsg());
    exit(EXIT_FAILURE);
    return 0;
  }

  return 0;
}
/*
* returns 1 if there are modifications to the variable with the same identifier of the argument
* otherwise 0
*/
int Multiple_Modifications(struct TreeNode * node, char* identifier){

  if (node -> nodeType == Expr){
    enum exprType type = node -> node.Expr -> exprType;
    if(type == PI || type == PD || type == IP || type == DP){
      if(!strcmp(TreeNode_Identifier(node -> child_list -> first), identifier)){
        return 1;
      }
      else{
        return 0;
      }
    }
    else{
      int flag = 0;
      if (node -> child_list -> elements > 0){
        struct TreeNode * tree_node = node -> child_list -> first;
        flag += Multiple_Modifications(tree_node, identifier);

        for (int i = 1; i < node -> child_list -> elements; i++){
          tree_node = tree_node -> next;
          flag += Multiple_Modifications(tree_node, identifier);
        }
        if (flag == 0){
          return 0;
        }
        else{
          return 1;
        }
      }
      else{
        return 0;
      }
    }
  }
  else{
    return 0;
  }
}

enum Type expressionType(struct TreeNode * expression){

  Check_NodeType(Expr, expression, "expressionType");
  enum exprType expression_type = expression -> node.Expr -> exprType;
  enum Type return_type;

  if (expression_type == NUM)                               return_type = INT_;
  else if (expression_type == ID)                           return_type = Retrieve_VarType(MainNode, TreeNode_Identifier(expression));
  else if (expression_type == VEC){
    return_type = Retrieve_VarType(MainNode, TreeNode_Identifier(expression));
    if (return_type == INT_V_) return_type = INT_;
    if (return_type == CHAR_V_) return_type = CHAR_;
  }
  else if (expression_type == STR)                          return_type = CHAR_V_;
  else if (expression_type == C)                            return_type = CHAR_;
  else if (expression_type == FC)                           return_type = Retrive_FunType(MainNode, expression -> node.Expr -> exprVal.stringExpr);
  else if (isOperation(expression))                         return_type = INT_;
  else if (expression_type == CMP)                          return_type = INT_;
  else if (expression_type == PI || expression_type == PD || expression_type == IP || expression_type == DP)
                                                            return_type = expressionType(expression -> child_list -> first);
  else if (expression_type == PA)                           return_type = expressionType(expression -> child_list -> first -> child_list -> first);
  else if (expression_type == ADD){

    return_type = expressionType(expression -> child_list -> first);
    if (return_type == INT_ || return_type == INT_V_) return_type = INT_P_;
    else if (return_type == CHAR_ || return_type == CHAR_V_) return_type = CHAR_P_;
  }
  return return_type;
}

int isStringFormat(char symbol){
  switch (symbol) {
    case 'd': return 1;
    break;
    case 'i': return 1;
    break;
    case 'c': return 1;
    break;
    case 'o': return 1;
    break;
    case 's': return 1;
    break;
    case 'x': return 1;
    break;
    case 'X': return 1;
    break;
    case 'u': return 1;
    break;
    case '%': return 1;
    break;
    default: return 0;
    break;
  }
}

void * TreeNode_Var_Pointer(struct TreeNode * expression){

  Check_NodeType(Expr, expression, "TreeNode_Var_Pointer");

  if (expression -> node.Expr -> exprType == ID) return Retrieve_VarPointer(TreeNode_Identifier(expression), 0);
  else if (expression -> node.Expr -> exprType == VEC){
    int index = Retrieve_ArrayIndex(MainNode, expression);
    return Retrieve_VarPointer(TreeNode_Identifier(expression), index);
  }
  else if (expression -> node.Expr -> exprType == ADD) return TreeNode_Var_Pointer(expression -> child_list -> first);

}

////////////////////////////////////////////////////////////////////////////////
//////////////////  SYMBOL TABLE FUNCTIONS  ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/*
*   Returns a new empty symbol table with memory space allocated
*/
struct SymbolTable * SymbolTable_Set(){

  struct SymbolTable * newST = (struct SymbolTable *)malloc(sizeof(struct SymbolTable));
  // memory allocation error
  if ( newST == NULL ){
    printf("%s SymbolTable_Set - out of memory.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }

  newST -> elements = 0;
  newST -> first = NULL;
  newST -> last = NULL;
  if (ST_DEBUGGING) printf("SYMBOL TABLE: new ST space allocated\n");
  return newST;
}
/*
*   Adds a variable in the last place of the symbol table creating a new SymbolTable_Node
*   Returns 1 if the adding is made with success
*   Returns 0 if it fails
*/
int SymbolTable_Add(struct SymbolTable * table, char * identifier, enum Type type, int arrayDim, char ignoreFlag){

  // check identifier lenght
  if (strlen(identifier) > 31){
    printf("%s identifier max lenght exceeded. (max lenght = 31 characters)\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }

  // check if the variable was previously declared
  if (SymbolTable_Search(table, identifier) < 0){
    // Symbol Table Node construction
    struct SymbolTable_Node * newSTN = (struct SymbolTable_Node *)malloc(sizeof(struct SymbolTable_Node));
    // memory allocation error
    if ( newSTN == NULL ){
      printf("%s SymbolTable_Add - out of memory.\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }

    newSTN -> type = type; // variable type
    strcpy(newSTN -> identifier, identifier); // variable identifier
    // todo toremove variable pointer
    //newSTN -> varPtr = varPtr; // variable pointer

    // todo ha senso impostare la dimensione ad 1?
    // declaration of a variable
    if (type == INT_) newSTN -> arrayDim = 1;
    if (type == CHAR_) newSTN -> arrayDim = 1;

    // setting ignore flag
    newSTN -> ignore = ignoreFlag;

    // declaration of an array variable
    if (type == INT_V_ ) {
      newSTN -> arrayDim = arrayDim;
      newSTN -> varPtr.intPtr = (int *)malloc(sizeof(int)*arrayDim);
      // memory allocation error
      if ( newSTN -> varPtr.intPtr == NULL ){
        printf("%s SymbolTable_Search - out of memory.\n", ErrorMsg());
        exit(EXIT_FAILURE);
      }
    }
    if (type == CHAR_V_ ) {
      newSTN -> arrayDim = arrayDim;
      newSTN -> varPtr.charPtr = (char *)malloc(sizeof(char)*arrayDim);
      if ( newSTN -> varPtr.charPtr == NULL ){
        printf("%s SymbolTable_Search - out of memory.\n", ErrorMsg());
        exit(EXIT_FAILURE);
      }
    }

    // Adding the Symbol Table Node to the table
    if (table -> elements == 0){
      table -> first = newSTN;
      table -> last = newSTN;
    }
    else{
      table -> last -> next = newSTN;
      table -> last = newSTN;
    }
    table -> elements ++;
    return 1;
  }
  // if a variable with the same identifier was already declared in the scope
  else {
    if (ST_DEBUGGING) printf("SYMBOL TABLE: FAILED ADDING VARIABLE TO SCOPE, variable %s already exist in this scope\n",identifier);
    return 0;
  }
}
/*
*   returns -1 if the table is empty
*   returns -2 if there isn't any variable with the identifier passed as argument
*   returns the position in the table of the first variable with the identifier passed as argument
*/
int SymbolTable_Search(struct SymbolTable * table, char * identifier){

  struct SymbolTable_Node * newSTN;
  int flag = -2;  // default flag value
  // todo toremove debug
  if (table -> elements != 0){
    newSTN = table -> first;
    for (int i = 0; i < table -> elements; i++){
      // matching the same identifier
      if (!strcmp(identifier, newSTN -> identifier)) {
        return i;
      }                        // outputting the index
      else newSTN = newSTN -> next;
    }

  return flag;
  }
  else {
    return -1;
  }
}
/*
*   returns the index-th symbol table node inside the given symbol table
*/
struct SymbolTable_Node * SymbolTable_Get(struct SymbolTable * table, int index){

  struct SymbolTable_Node * newSTN;

  if (table -> elements < index || index < 0){
    // todo valutare se tenerlo questo errore
    printf("%s SymbolTable_Get - FAILED INDEX SEARCH, index is not present\n", ErrorMsg());
    return NULL;
  }
  else {

    if (index == 0) return table -> first;
    else if (index == table -> elements-1) return table -> last;
    else{
      newSTN = table -> first -> next;
      for (int i=1; i < index; i++){
        newSTN = newSTN -> next;
      }

      return newSTN;
    }
  }

}


// todo probabilmente inutile
int SymbolTable_Put(struct SymbolTable * table, struct SymbolTable_Node * new ,int index){

  struct SymbolTable_Node * newSTN;

  if (table -> elements < index || index < 0){

    //printf("SYMBOL TABLE: FAILED INDEX SEARCH, index is not present\n");
    return 0;
  }

  else {

    if (index == 1) {
      table -> first = new;
      return 1;
    }

    else if (index == table -> elements) {
      table -> last = new;
      return 1;
    }

    else{

      newSTN = table -> first -> next;
      for (int i=1; i < index-1; i++){
        newSTN = newSTN -> next;
      }

      newSTN = new;
      return 1;
    }
  }

}
// todo valutare di rimuovere SymbolTable_AddInt
/*int SymbolTable_AddInt (struct SymbolTable * table, char * identifier, int value){

  struct SymbolTable_Node * support;

  if (SymbolTable_Search < 0) return 0;

  support = SymbolTable_Get(table, SymbolTable_Search(table, identifier));

  if (support -> type == INT_) {

    support -> varVal.intVal = value;
    return 1;

  }
  else {

    printf("SYMBOL TABLE: ERROR - TYPE NOT MATCHED. Expected int");
    return -1;

  }
}*/


/*
*   prints the symbol table elements with their types and values
*/
void SymbolTable_Print(struct SymbolTable * table){

  printf("\nSYMBOL TABLE: \n");
  struct SymbolTable_Node * newSTN;
  for (int i = 0; i < table -> elements; i++){

    if (i == 0) newSTN = table -> first;
    else newSTN = newSTN -> next;
    printf("Variable %d \n\tidentifier: %s\n\ttype: %s \n",i+1,newSTN -> identifier, VarTypeString(newSTN -> type));
    if (newSTN -> type == INT_V_ || newSTN -> type == CHAR_V_){
      printf("\tdimension: %d", newSTN -> arrayDim);
      if (newSTN -> ignore) printf(" (IGNORE)");
      printf("\n");
      if (newSTN -> type == INT_V_) printf("\tarray elements: [%d", newSTN -> varPtr.intPtr[0]);
      if (newSTN -> type == CHAR_V_) printf("\tarray elements: ['%c'(%d)", newSTN -> varPtr.charPtr[0], newSTN -> varPtr.charPtr[0]);

      for (int i = 1; i< newSTN -> arrayDim; i++){
        if (newSTN -> type == INT_V_) printf("|%d", newSTN -> varPtr.intPtr[i]);
        if (newSTN -> type == CHAR_V_) printf("|'%c'(%d)", newSTN -> varPtr.charPtr[i], newSTN -> varPtr.charPtr[i]);
      }
      printf("]\n");

    }
    if (newSTN -> type == INT_ || newSTN -> type == CHAR_){
      printf("\tvalue: ");
      if (newSTN -> type == INT_)   printf("%d\n",newSTN -> varVal.intVal);
      if (newSTN -> type == CHAR_)  printf("'%c'(%d)\n",newSTN -> varVal.charVal,newSTN -> varVal.charVal);
    }
  }
}
/*
*   given the variable identifier, retrieves the variable Symbol Table Node from the actual scope
*/
struct SymbolTable_Node * SymbolTable_RetrieveVar (struct ProgramNode * prog, char * identifier){

  // retrieve the actual scope
  struct TreeNode * actualScope = Get_ActualScope(prog);
  // retrieve symbol table from the scope
  struct SymbolTable * ST = actualScope -> node.ST;

  // retrieve variable symbol table node index in the symbol table
  int index = SymbolTable_Search(ST, identifier);
  // if variable was not found
  if (index < 0){
    return NULL;
  }
  // if variable was found
  else{
    return SymbolTable_Get(ST, index);
  }
}
struct SymbolTable_Node * SymbolTable_IterativeRetrieveVar (char * identifier){

  struct SymbolTable_Node * ST_Node = SymbolTable_RetrieveVar(MainNode, identifier);
  // if the search fails in the acutal_scope
  if (ST_Node == NULL){
    // retrieve the actual scope node
    struct Scope * ScopeNode = Get_ActualScopeNode();
    // search in the other scopes of the scope stack
    for (int i = 1; i < ScopeStack_Elements(); i++){
      // previous scope in the scope
      ScopeNode = ScopeNode -> prevScope;

      struct TreeNode * scope = ScopeNode -> thisScope;
      // symbol table from the scope
      struct SymbolTable * ST = scope -> node.ST;
      // retrieve variable symbol table node index in the symbol table
      int index = SymbolTable_Search(ST, identifier);

      // if the search ended successfully
      if (index > -1){
        return SymbolTable_Get(ST, index);
      }
    }

    // unsuccessful search
    return NULL;
  }
  // if the search in the acutal_scope ended successfully
  else{
    return ST_Node;
  }
}
/*
// debug verion of SymbolTable_IterativeRetrieveVar
struct SymbolTable_Node * SymbolTable_IterativeRetrieveVar (char * identifier){

  struct SymbolTable_Node * ST_Node = SymbolTable_RetrieveVar(MainNode, identifier);
  printf("\n///////RICERCA DI %s alla linea %d////////\n\n\n", identifier, yylineno);
  // if the search fails in the acutal_scope
  if (ST_Node == NULL){
    printf("NUMERO DI SCOPES: %d\n", ScopeStack_Elements());
    // retrieve the actual scope node
    struct Scope * ScopeNode = Get_ActualScopeNode();
    // search in the other scopes of the scope stack
    for (int i = 1; i < ScopeStack_Elements(); i++){
      // previous scope in the scope
      ScopeNode = ScopeNode -> prevScope;

      struct TreeNode * scope = ScopeNode -> thisScope;
      // symbol table from the scope
      struct SymbolTable * ST = scope -> node.ST;
      printf("\nSTO CERCANDO IN");
      SymbolTable_Print(ST);
      printf("è una tablle di %d elementi\n", ST -> elements);
      printf("-------------------------\n");
      // retrieve variable symbol table node index in the symbol table
      int index = SymbolTable_Search(ST, identifier);

      // if the search ended successfully
      if (index > -1){
        printf("RICERCA FORTUNATA! Ho trovato %s\n", identifier);
        printf("-------------------------\n");
        printf("-------------------------\n");
        return SymbolTable_Get(ST, index);
      }
    }

    // search in the global scope

    printf("RICERCA FALLITA!\n");
    printf("-------------------------\n");
    printf("-------------------------\n\n\n");
    // unsuccessful search
    return NULL;
  }
  // if the search in the acutal_scope ended successfully
  else{
    return ST_Node;
  }
}
*/

/*
*   given the variable identifier, returns the int value stored in symbol table
*   if the variable is a character returns the int value
*/
int Retrieve_VarValue (struct ProgramNode * prog, char * identifier, int index){

  // symbol table node with the given identifier
  struct SymbolTable_Node * ST_Node = SymbolTable_IterativeRetrieveVar(identifier);

  if (ST_Node == NULL){
    printf("%s Retrieve_VarValue - variable '%s' not found.\n", ErrorMsg(), identifier);
    exit(EXIT_FAILURE);
  }
  else if(ST_Node -> type == INT_){
    return ST_Node -> varVal.intVal;
  }
  else if(ST_Node -> type == CHAR_){
    int value = ST_Node -> varVal.charVal;
    return value;
  }
  else if(ST_Node -> type == INT_V_){

    int array_dim = Retrieve_ArrayDim(prog, identifier);

    // out of bounds array error
    if (index > array_dim - 1){
      printf("%s array index %d is past the end of the array. Array contains %d elements.\n", ErrorMsg(), index, array_dim);
      exit(EXIT_FAILURE);
    }
    else if (index < 0){
      printf("%s array index %d is before the beginning of the array. Array contains %d elements.\n", ErrorMsg(), index, array_dim);
      exit(EXIT_FAILURE);
    }

    int value = ST_Node -> varPtr.intPtr[index];
    return value;
  }
  else if(ST_Node -> type == CHAR_V_){

    int array_dim = Retrieve_ArrayDim(prog, identifier);

    // out of bounds array error
    if (index > array_dim - 1){
      printf("%s array index %d is past the end of the array. Array contains %d elements.\n", ErrorMsg(), index, array_dim);
      exit(EXIT_FAILURE);
    }
    else if (index < 0){
      printf("%s array index %d is before the beginning of the array. Array contains %d elements.\n", ErrorMsg(), index, array_dim);
      exit(EXIT_FAILURE);
    }

    int value = ST_Node -> varPtr.charPtr[index];
    return value;
  }
  else{
    printf("%s Retrieve_VarValue - unexpected variable type. Type found: %u\n", ErrorMsg(), ST_Node -> type);
    exit(EXIT_FAILURE);
  }
}
void * Retrieve_VarPointer (char * identifier, int index){
  // symbol table node with the given identifier
  struct SymbolTable_Node * ST_Node = SymbolTable_IterativeRetrieveVar(identifier);

  if (ST_Node == NULL){
    printf("%s Retrieve_VarValue - variable '%s' not found.\n", ErrorMsg(), identifier);
    exit(EXIT_FAILURE);
  }
  else if(ST_Node -> type == INT_)  return &(ST_Node -> varVal.intVal);
  else if(ST_Node -> type == CHAR_) return &(ST_Node -> varVal.charVal);
  else if(ST_Node -> type == INT_V_){

    int array_dim = Retrieve_ArrayDim(MainNode, identifier);
    // out of bounds array error
    if (index > array_dim - 1){
      printf("%s array index %d is past the end of the array. Array contains %d elements.\n", ErrorMsg(), index, array_dim);
      exit(EXIT_FAILURE);
    }
    else if (index < 0){
      printf("%s array index %d is before the beginning of the array. Array contains %d elements.\n", ErrorMsg(), index, array_dim);
      exit(EXIT_FAILURE);
    }

    return &(ST_Node -> varPtr.intPtr[index]);
  }
  else if(ST_Node -> type == CHAR_V_){

    int array_dim = Retrieve_ArrayDim(MainNode, identifier);

    // out of bounds array error
    if (index > array_dim - 1){
      printf("%s array index %d is past the end of the array. Array contains %d elements.\n", ErrorMsg(), index, array_dim);
      exit(EXIT_FAILURE);
    }
    else if (index < 0){
      printf("%s array index %d is before the beginning of the array. Array contains %d elements.\n", ErrorMsg(), index, array_dim);
      exit(EXIT_FAILURE);
    }

    return &(ST_Node -> varPtr.charPtr[index]);
  }
  else{
    printf("%s Retrieve_VarValue - unexpected variable type. Type found: %u\n", ErrorMsg(), ST_Node -> type);
    exit(EXIT_FAILURE);
  }
}
enum Type Retrieve_VarType(struct ProgramNode * prog, char * identifier){

  // symbol table node with the given identifier
  struct SymbolTable_Node * ST_Node = SymbolTable_IterativeRetrieveVar(identifier);
  if (ST_Node == NULL){
    printf("%s Retrieve_VarType - variable '%s' was not declared.\n", ErrorMsg(), identifier);
    exit(EXIT_FAILURE);
  }
  return ST_Node -> type;
}
int Retrieve_ArrayDim(struct ProgramNode * prog, char * identifier){

  struct SymbolTable_Node * ST_Node = SymbolTable_IterativeRetrieveVar (identifier);
  if (ST_Node -> type == INT_ || ST_Node -> type == CHAR_){
    printf("%s subscripted value is not an array.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  return ST_Node -> arrayDim;
}
int Check_VarWasDeclared (struct ProgramNode * prog, char * identifier, int flag){

  struct SymbolTable_Node * node;
  // search only in the actual scope
  if(flag == 0){
    node = SymbolTable_RetrieveVar (prog, identifier);
  }
  // search in the actual scope and in the other scopes in the stack
  else if(flag == 1){
    node = SymbolTable_IterativeRetrieveVar (identifier);
  }
  else{
    printf("%s Check_VarWasDeclared - incorrect call. Unexpected value of flag: %d\n", ErrorMsg(), flag);
    exit(EXIT_FAILURE);
  }
  // return
  if (node == NULL){
    return 0;
  }
  else{
    return 1;
  }
}
/*
* change the value of a symbol table node with the value stored in a TreeNode
*/
void SymbolTable_AssignValue (struct ProgramNode * prog, struct TreeNode * variable, int value){

  if (variable -> nodeType == Expr){

    if (variable -> node.Expr -> exprType == ID || variable -> node.Expr -> exprType == VEC){
      char * identifier = variable -> node.Expr -> exprVal.stringExpr;


      struct SymbolTable_Node * ST_Node = SymbolTable_IterativeRetrieveVar(identifier);

      enum Type varType = ST_Node -> type;
      if (varType == INT_){
        ST_Node -> varVal.intVal = value;
      }
      else if(varType == CHAR_){

        // todo valutare di rimuoverlo dato che è già presente in fase di dichiarazione, mancherebbe il warning in fase di assegnazione ma effettivamente non bisogna generarne
        /*
        if (value < -128 || value > 127){
          printf("%s implicit conversion from 'int' to 'char' changes value from %d to %d\n", WarnMsg(), value, (char)value);
        }
        */
        ST_Node -> varVal.charVal = (char)value;
      }
      else if(varType == INT_V_){
        int index = Retrieve_ArrayIndex(prog, variable);
        ST_Node -> varPtr.intPtr[index] = value;
      }
      else if(varType == CHAR_V_){
        int index = Retrieve_ArrayIndex(prog, variable);
        ST_Node -> varPtr.charPtr[index] = (char)value;
      }
    }
    else{
      printf("%s SymbolTable_AssignValue - incorrect call. Unexpected Expr type. Type found: %u\n", ErrorMsg(), variable -> node.Expr -> exprType);
      exit(EXIT_FAILURE);
    }
  }
  else{
    printf("%s SymbolTable_AssignValue - incorrect call. Expr TreeNode expected. Type found: %u\n", ErrorMsg(), variable -> nodeType);
    exit(EXIT_FAILURE);
  }
}
int IgnoreFlag(char * identifier){
  struct SymbolTable_Node * ST_Node = SymbolTable_IterativeRetrieveVar(identifier);
  return ST_Node -> ignore;
};
void SymbolTableCopy (struct SymbolTable * SymbolTab, struct SymbolTable * newSymbolTab){

  struct SymbolTable_Node * variable;

  for (int i = 0; i < SymbolTab -> elements; i++){

    if (i == 0) variable = SymbolTab -> first;
    else variable = variable -> next;

    if (variable -> type == INT_)       SymbolTable_Add(newSymbolTab, variable -> identifier, INT_, 0, 0);
    else if (variable -> type == CHAR_) SymbolTable_Add(newSymbolTab, variable -> identifier, CHAR_, 0, 0);
    else if (variable -> type == INT_V_ || variable -> type == CHAR_V_){
        // temporary array declaration
      if (variable -> ignore) SymbolTable_Add(newSymbolTab, variable -> identifier, variable -> type, 0 , 1);
        // defined array declaration
      else SymbolTable_Add(newSymbolTab, variable -> identifier, variable -> type, variable -> arrayDim , 0);
    }
  }
}

////////////////////////////////////////////////////////////////////////////////
//////////////////  TREE NODE LIST FUNCTIONS  //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

struct TreeNodeList* TreeNodeList_Set(){

  struct TreeNodeList* list;
  list  = (struct TreeNodeList*) malloc (sizeof(struct TreeNodeList)); // memory space allocation
  if ( list == NULL ){
    printf("%s TreeNodeList - out of memory.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  list  -> elements = 0;
  return list;

}
void TreeNodeList_Add (struct TreeNodeList * list, struct TreeNode * newElem){
  if (newElem != NULL){
    if (list -> elements==0){
      if (TREE_DEBUGGING){
      printf("TREE: ");
      PrintTreeNodeType(newElem -> nodeType, newElem);
      printf(" new element insert in list\n");
      }
      list -> first = newElem;
      list -> last = newElem;
    }

    else{
      if (TREE_DEBUGGING){
      printf("%d TREE: ", yylineno);
      printf("NODE TYPE: %u\n", newElem -> nodeType);
      PrintTreeNodeType(newElem -> nodeType, newElem);
      printf(" new element insert in list\n");
      }
      list -> last -> next = newElem;
      list -> last = newElem;
    }
    list -> elements ++;
  }
}
void TreeNodeList_Rem (struct TreeNodeList * list){

  if (list -> elements==0){
    printf("%s TreeNodeList_Rem - Tree Node list is empty!\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }

  else{

    struct TreeNode * support;
    support = list -> first;

    for (int i=0; i<list->elements-2; i++){ // scroll down the list up to the second-last element
      support = support -> next;
    }
    if (list->elements==1){    // if there's only one element I need to initialize the list
      list -> first = NULL;
      list -> last = NULL;
    }
    else{
      list -> last = support;
      list -> last -> next = NULL;
    }

    list -> elements --;

    if (TREE_DEBUGGING){
      printf("TREE: ");
      printf(" new element removed from list\n");
    }
  }
}
/*
* Return the index-th element of the list
*/
struct TreeNode * TreeNodeList_IndexSearch (struct TreeNodeList * list, int index){

  if ( index > -1 && index < list -> elements){

    struct TreeNode * node = list -> first;
    for (int i = 0; i<index; i++){
      node = node -> next;
    }
    return node;
  }
  else if ( index < 0){
    printf("line:%d %serror%s - TreeNodeList_IndexSearch: list index is before the beginning of the list. List contains %d elements.\n",yylineno,ANSI_COLOR_RED,ANSI_COLOR_RESET, list -> elements);
    exit(EXIT_FAILURE);
  }
  else if ( index >= list -> elements){
    printf("line:%d %serror%s - TreeNodeList_IndexSearch: list index is past the end of the list. List contains %d elements.\n",yylineno,ANSI_COLOR_RED,ANSI_COLOR_RESET, list -> elements);
    exit(EXIT_FAILURE);
  }
  else{
    printf("line:%d %serror%s - TreeNodeList_IndexSearch: unexpected index value.\n",yylineno,ANSI_COLOR_RED,ANSI_COLOR_RESET);
    exit(EXIT_FAILURE);
  }

}

////////////////////////////////////////////////////////////////////////////////
//////////////////  SCOPE STACK FUNCTIONS  /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// initialize a new scope stack
struct ScopeStack * ScopeStack_Set (){

  struct ScopeStack * stack = (struct ScopeStack *) malloc (sizeof(struct ScopeStack));
  if ( stack == NULL ){
    printf("%s TreeNodeList - out of memory.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  stack -> top = (struct Scope *) malloc (sizeof(struct Scope));
  if ( stack -> top == NULL ){
    printf("%s ScopeStack_Set - out of memory.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  stack -> elements = 0;
  return stack;
}
void ScopeStack_Push(struct ScopeStack * stack, struct TreeNode * scope, char active){

  if (stack -> elements == 0){
    /* no need to memory allocation cause the first element was already allocated
     during the scope stack initialization
     */
    stack -> top -> thisScope = scope;
    // flag that specifies if the scope is active or not
    stack -> top -> active = active;
  }
  else{
    struct Scope * newScope = (struct Scope *) malloc (sizeof(struct Scope));
    // memory allocation error
    if ( newScope == NULL ){
      printf("%s ScopeStack_Push - out of memory.\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }

    newScope -> thisScope = scope;
    newScope -> prevScope = stack -> top;
    stack -> top = newScope;
    // flag that specifies if the scope is active or not
    stack -> top -> active = active;
  }
  stack -> elements += 1;
  // todo valutare di rimuovere
  // debug si potrebbe tenere con un if di controllo
  if(ST_DEBUGGING) printf("New scope in the scope stack. Scope in the stacks: %d\n", stack -> elements);
}
void ScopeStack_Pop(struct ScopeStack * stack){

  struct Scope * previous_scope = stack -> top -> prevScope;
  stack -> top = previous_scope;
  stack -> elements -= 1;
  // todo valutare di rimuovere
  if(ST_DEBUGGING) printf("A scope has been removed from the scope stack. Scope in the stacks: %d\n", stack -> elements);

}
struct TreeNode * ScopeStack_Peek(struct ScopeStack * stack){

  return stack -> top -> thisScope;
}
void SetAs_ActualScope(struct ProgramNode * prog, struct TreeNode * scope, char active){
  ScopeStack_Push(prog -> actual_stack, scope, active);
}
void Remove_ActualScope(struct ProgramNode * prog){
  ScopeStack_Pop(prog -> actual_stack);
}
struct TreeNode * Get_ActualScope(struct ProgramNode * prog){

  return ScopeStack_Peek(prog -> actual_stack);
}
// restituisce il numero di scope presenti nello scope stack attuale
int ScopeStack_Elements(){

  if (MainNode -> actual_stack == NULL){
    printf("%s ScopeStack_Elements - program scope stack not found.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  else{
    return MainNode -> actual_stack -> elements;
  }
}
// restituisce lo scope stack node attuale
struct Scope * Get_ActualScopeNode(){

  if (MainNode -> actual_stack == NULL){
    printf("%s Get_ActualScopeNode - program scope stack not found.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  else{
    return MainNode -> actual_stack -> top;
  }
}

////////////////////////////////////////////////////////////////////////////////
//////////////////  TREE BUILDING FUNCTIONS  ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// links a TreeNode to the last scope
void Add_Node_Tree (ProgramNode * prog, struct TreeNode * newNode){

  struct TreeNode * acutal_scope = prog -> actual_stack -> top -> thisScope;
  TreeNodeList_Add(acutal_scope -> child_list, newNode);
}

////////////////////////////////////////////////////////////////////////////////
//////////////////  FUNCTION NODE AND LIST METHODS  ////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void FunNodeList_Set (ProgramNode* prog){

  prog -> function_list  = (FunNodeList*) malloc (sizeof(FunNodeList)); // memory space allocation
  if ( prog -> function_list == NULL ){
    printf("%s FunNodeList_Set - out of memory.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  prog -> function_list  -> elements = 0;

}
// create a new FunNode and add it to the FunctionList
void FunNodeList_Add (ProgramNode* prog, struct TreeNode * declaration){

  // check argument type
  Check_NodeType(DclN, declaration, "FunNodeList_Add");

  // fuction identifier
  char * identifier = TreeNode_Identifier(declaration);

  // check if a function with the same identifier was already declared
  if (CheckFunAlreadyExist(prog,identifier)){
    printf("%s redefinition of \'%s\'\n", ErrorMsg(),identifier);
    exit(EXIT_FAILURE);
  }

  // function Node space allocation
  FunNode* newFunction;
  // memory space allocation
  newFunction = (FunNode*)malloc(sizeof(FunNode));
  // memory allocation error
  if ( newFunction == NULL ){
    printf("%s FunNodeList_Add - out of memory.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }

  // Linking function identifier to the created function node
  newFunction -> funName = identifier;

  // Linking function type to the created function node
  newFunction -> funType = declaration -> node.DclN -> type;

  // Function node child list space allocation
  newFunction -> child_list = TreeNodeList_Set();

  // Function scope stack memory space allocation
  newFunction -> scope_stack = ScopeStack_Set();
  // Scope node space allocation
  newFunction -> function_scope = create_ScopeNode();

  // Setting global scope at the bottom of the function scope stack
  // Global scope is active by default
  ScopeStack_Push(newFunction -> scope_stack, MainNode -> global_scope_stack -> top -> thisScope, 1);
  // Adding function scope to the stack as first scope after the global one
  // Function scope is inactive by default
  ScopeStack_Push(newFunction -> scope_stack, newFunction -> function_scope, 0);

  // Setting the function scope stack as actual scope stack
  prog -> actual_stack = newFunction -> scope_stack;
  // todo valutare di rimuovere questo debugging
  if (ST_DEBUGGING) printf("New actual scope stack set.\n");

  /*
  // Setting function scope as new actual scope
  prog -> actual_scope = newFunction -> function_scope;
  printf("SCOPE - FunNodeList_Add: nuovo actual_scope settato. È lo scope della nuova funzione %s\n",identifier);
  */
  // todo: rimuovere questa parte commentata dal momento in cui le funzioni non vanno più nello scope stack
  // Adding function to scope stack
  //ScopeStack_Add(prog -> ActualScope, NULL, newElem);   //  adding scope as new actual scope

  // Adding function to ProgramNode function list
  // Fist function in the function list
  if (prog -> function_list -> elements == 0){

    if (TREE_DEBUGGING)  printf("TREE: %s first function insert in FunNodeList\n",identifier);
    prog -> function_list -> first = newFunction;
    prog -> function_list -> last = newFunction;
  }
  // Subsequent function in the function list
  else{

    if (TREE_DEBUGGING)  printf("TREE: \"%s\" function insert in FunNodeList\n",identifier);
    prog -> function_list -> last -> next = newFunction;
    prog -> function_list -> last = newFunction;

  }

  prog -> function_list -> elements ++;
  if (ST_DEBUGGING) printf("- FunNodeList_Add: A new function Node was created\n");
}
/*
* returns -1 if the list is empty
* returns -2 if there isn't any function with the identifier passed as argument
* returns the position in the function node with the identifier passed as argument
*/
int FunNodeList_Search (ProgramNode * prog, char * identifier){

  struct FunNode * newFunNode;
  struct FunNodeList * funList = prog -> function_list;
  int flag = -2;  // default flag value
  // todo toremove debug
  if (funList -> elements != 0){
    newFunNode = funList -> first;
    for (int i = 0; i < funList -> elements; i++){

      if (!strcmp(identifier, newFunNode -> funName)) {  // matching the same identifier
        return i;
      }                        // outputting the index
      else newFunNode = newFunNode -> next;
    }

  return flag;
  }
  else {
    return -1;
  }
}
/*
* Given an index return the index-th function node in the program node function list.
* The index can be retrieved with the 'FunNodeList_Search' function.
*/
struct FunNode * FunNodeList_Get (ProgramNode * prog, int index){

  // index must be inside list bounds
  if (index >= prog -> function_list -> elements){

    printf("%s FunNodeList_Get - list index is past the end of the list. List contains %d elements.\n", ErrorMsg(),prog -> function_list -> elements);
    exit(EXIT_FAILURE);
  }
  else if (index < 0){
    printf("%s FunNodeList_Get - list index is before the beginning of the list.\n", ErrorMsg());
    exit(EXIT_FAILURE);
    }

  struct FunNode * function = prog -> function_list -> first;
  for (int i = 0; i < prog -> function_list -> elements; i++){
    if (i == index){
      return function;
    }
    else{
      function = function -> next;
    }
  }

  return function;
}
/*
* Given the variable identifier return its type. (INT_, CHAR_)
*/
enum Type Retrive_FunType(ProgramNode * prog, char * identifier){

  int index = FunNodeList_Search(prog, identifier);
  struct FunNode * function = FunNodeList_Get(prog, index);
  return function -> funType;
}
// todo: rimuovere se useless
void ActiveFunStack_Set (ProgramNode* prog){

    prog -> active_function  = (FunNodeList*) malloc (sizeof(FunNodeList)); // memory space allocation
    if ( prog -> active_function == NULL ){
      printf("%s ActiveFunStack_Set - out of memory.\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
    prog -> active_function  -> elements = 0;

}
void ActiveFunStack_Add (ProgramNode* prog, FunNode* function){

  struct FunNodeList* function_stack = prog -> active_function;

  if (function_stack -> elements == 0) {   // empty stack

    function_stack -> first = function;
    function_stack -> last = function;

  }
  else { // not empty stack

    function_stack -> first = function;
    function_stack -> last = function;
    // last todo
  }

}

////////////////////////////////////////////////////////////////////////////////
//////////////////  PROGRAM NODE  //////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

ProgramNode* ProgramNode_Set (){
  ProgramNode* prog; // support var
  // program node memory space allocation
  prog = (ProgramNode*) malloc (sizeof(ProgramNode));
  if ( prog == NULL ){
    printf("%s ProgramNode_Set - out of memory.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  // initializing functions' list
  FunNodeList_Set(prog);
  // initializing functions' stack
  ActiveFunStack_Set(prog);
  // global scope setting
  prog -> global_scope = create_ScopeNode();
  // global scope stack setting
  prog -> global_scope_stack = ScopeStack_Set();
  // setting the global scope as first scope in the global scope stack
  // global scope is active by default
  ScopeStack_Push(prog -> global_scope_stack, prog -> global_scope, 1);
  // setting global scope stack as actual scope stack
  prog -> actual_stack = prog -> global_scope_stack;
  // setting warnings counter
  prog -> warnings = 0;
  return prog;
}

// returns 1 if a function with the same identifier was already declared, otherwise 0
int CheckFunAlreadyExist (ProgramNode* prog, char* identifier){

  // printf - scanf name check
  if (!strcmp(identifier, "printf") || !strcmp(identifier, "scanf")){
    printf("%s incompatible redeclaration of library function \'%s\'.\n", ErrorMsg(), identifier);
    exit(EXIT_FAILURE);
  }
  FunNodeList * list = prog -> function_list;

  if (list -> elements == 0) {
    //printf("CHECK IF FUNCTION EXIST: Nessuna funzione ancora dichiarata\n");
    return 0;}
  // scorro tutti i nodi funzione
  FunNode * function = list -> first;
  for (int i = 0; i < list -> elements; i++){
    if(!strcmp(function -> funName, identifier)){
      //printf("CHECK IF FUNCTION EXIST: a function with identifier %s already exist!!\n",identifier);
      return 1;
    }
    else{
      function = function -> next;
    }
  }
  //printf("CHECK IF FUNCTION EXIST: Nessuna funzione con lo stesso nome precedentemente dichiarata\n");
  return 0;
}

////////////////////////////////////////////////////////////////////////////////
//////////////////  PRINT TREE FUNCTIONS  //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void PrintTree (ProgramNode* prog){

  printf("\n\n\nGLOBAL SCOPE\n");
  PrintTreeNode(prog -> global_scope -> child_list);

  FunNode* support;

  // print all the functions
  printf("|TREE: Program with %d functions\n",prog -> function_list -> elements);
  if(prog -> function_list -> elements == 0) printf("WARNING: no function found in this C program\n");

    for (int i=0; i<prog -> function_list -> elements; i++){
      if (i==0){
        support = prog -> function_list -> first;
      }
      else{
        support = support -> next;
      }
      // print the single function
      printf("|TREE: Function Node - function number %d identifier %s with type %s\n",i+1,support->funName,PrintVarType(support->funType));
      PrintTreeNode (support -> function_scope -> child_list);
    }
}
void PrintTreeNode (struct TreeNodeList* main_list){

  if(main_list -> elements == 0) {
    PrintDepth ();
    printf("|END Node\n");
    /*PrintDepth ();
    printf("|");
    for(int i = 0; i < 50; i++) printf("-");
    printf("\n");
    //printf("------------------------------------------------------------------------\n");*/
    PrintDepth ();
    printf("|");
    printf("\n");
    }

  struct TreeNode* support;
  for (int i = 0; i < main_list -> elements; i++){
    if (i==0){
      treeDepth ++;
      support = main_list -> first;
    }
    else{
      support = support -> next;
    }
    PrintDepth ();
    printf("|TREE: Tree Node - ");
    PrintTreeNodeType(support -> nodeType, support);
    printf(".\n");

    PrintTreeNode(support->child_list);
    if (i+1 == main_list -> elements){
      treeDepth --;
      //printf("\n");
    }
  }

}
void PrintTreeNodeType (unsigned int type, struct TreeNode* Tnode){

  switch (type) {
    case Ukn: printf("uknown");
            break;
    case DclN: printf("declaration of %s",Tnode->node.DclN->identifier);
            break;
    case ArgD: printf("arguments declaration");
            break;
    case DclAsgn: printf("declaration and assignment of %s", Tnode->child_list->first->node.DclN->identifier);
            break;
    case Expr: PrintExprType (Tnode->node.Expr->exprType, Tnode);
            break;
    case Asgn: printf("assignment");
            break;
    case Return: printf("return");
            break;
    case ExprLst: printf("expr list");
            break;
    case FunCall: printf("function call");
            break;
    case ArgLst:printf("arguments list");
            break;
    case Scope:printf("scope");
            break;
    case If:printf("if");
            break;
    case Else:printf("else");
            break;
    case IfElse:printf("if else");
            break;
    case While:printf("while");
            break;
    case MultiDc:printf("multi declaration");
            break;
    case MultiAs:printf("multi assignment");
            break;
  }
}
void PrintExprType (unsigned int type, struct TreeNode* Tnode){

  switch (type) {
    case NUM: printf("num expr with value: %d",Tnode->node.Expr->exprVal.intExpr);
            break;
    case ID: printf("identifier expr with value \'%s\'",Tnode->node.Expr->exprVal.stringExpr);
            break;
    case VEC: printf("array expr with value \"%s\"",Tnode->node.Expr->exprVal.stringExpr);
            break;
    case STR: printf("string expr with value \"%s\"",Tnode->node.Expr->exprVal.stringExpr);
            break;
    case C: printf("char expr with value \'%c\'(%d)",Tnode->node.Expr->exprVal.charExpr,Tnode->node.Expr->exprVal.charExpr);
            break;
    case FC: printf("function call expr");
            break;
    case SUM: printf("sum expr \"+\"");
            break;
    case DIF: printf("difference expr \"-\"");
            break;
    case TIM: printf("times expr \"*\"");
            break;
    case DIV: printf("divide expr \"/\"");
            break;
    case MOD: printf("modulo expr \"%%\"");
            break;
    case RND:printf("round parathesis (expr)");
            break;
    case CMP:printf("comparison ");
            PrintCmpType(Tnode->node.Expr->exprVal.cmpExpr, NULL);
            break;
    case PI:printf("pre-increment");
            break;
    case PD:printf("pre-decrement");
            break;
    case IP:printf("post-increment");
            break;
    case DP:printf("post-decrement");
            break;
    case PA:printf("parentheses assignment");
            break;
  }
}
void PrintCmpType (unsigned int type, struct TreeNode* Tnode){

  switch (type) {
    case 0: printf("AND");
            break;
    case 1: printf("OR");
            break;
    case 2: printf("greater than \">\"");
            break;
    case 3: printf("less than \"<\"");
            break;
    case 4: printf("equal to \"==\"");
            break;
    case 5: printf("different from \"!=\"");
            break;
  }
}
char * PrintVarType(enum Type type){

  switch (type) {

    case INT_:    return "'int'";
                  break;
    case CHAR_:   return "'char'";
                  break;
    case INT_V_:  return "'int'";
                  break;
    case CHAR_V_: return "'char'";
                  break;

  }
}
void PrintDepth (){

  for (int i=0; i<treeDepth; i++){
    printf("\t");
    //printf("-----");
  }
}
void PrintTreeNodeList (struct TreeNodeList* list){
  struct TreeNode* support;

  support = list-> first;

  for (int i=0; i< list->elements; i++){
    printf("TYPE %u\n",support->nodeType);
    support = support->next;
  }
}
char * VarTypeString(enum Type type){

  if (type == 0){
    return "INT";
  }
  else if(type == 1){
    return "CHAR";
  }
  else if(type == 2){
    return "INT VECTOR";
  }
  else if(type == 3){
    return "CHAR VECTOR";
  }
  return NULL;
}
void PrintActualST(ProgramNode * prog){
  // retrieve the actual scope
  struct TreeNode * actualScope = Get_ActualScope(prog);
  // retrieve symbol table from the scope
  struct SymbolTable * ST = actualScope -> node.ST;
  // print ST
  SymbolTable_Print(ST);
}
char * NodeTypeString(struct TreeNode * node){

  switch (node -> nodeType){
    case Ukn:     return "uknown";
            break;
    case DclN:    return "declaration";
            break;
    case ArgD:    return "arguments declaration";
            break;
    case DclAsgn: return "declaration and assignment";
            break;
    case Expr:    return "expression";
            break;
    case Asgn:    return "assignment";
            break;
    case Return:  return "return";
            break;
    case ExprLst: return "expression list";
            break;
    case FunCall: return "function call";
            break;
    case ArgLst:  return "arguments list";
            break;
    case Scope:   return "scope";
            break;
    case If:      return "if";
            break;
    case Else:    return "else";
            break;
    case IfElse:  return "if else";
            break;
    case While:   return "while";
            break;
    case MultiDc:   return "multi declaration";
            break;
    case MultiAs:   return "multi assignment";
            break;
    default:      return "unexpected";
            break;
  }
}
char * ExprTypeString(struct TreeNode * node){

  if (node -> nodeType == Expr){

    switch (node -> node.Expr -> exprType){
      case NUM:     return "integer";
              break;
      case ID:    return "identifier";
              break;
      case VEC:    return "array element";
              break;
      case STR: return "string";
              break;
      case C:    return "character";
              break;
      case FC:    return "function call";
              break;
      case SUM:  return "sum";
              break;
      case DIF: return "difference";
              break;
      case TIM: return "multiplication";
              break;
      case DIV:  return "division";
              break;
      case MOD:  return "modulus";
              break;
      case RND:   return "parathesis";
              break;
      case CMP:      return "comparison";
              break;
      case PI:    return "pre increment";
              break;
      case PD:   return "pre decrement";
              break;
      case IP:   return "post increment";
              break;
      case DP:   return "post decrement";
              break;
      case PA:   return "parentheses assignment";
              break;
      case ADD:  return "address pointer";
              break;
      default:   return "uknown";
              break;
    }

  }
  else{
    printf("%s ExprTypeString - incorrect call. Expr TrenNode type expected. Type found: %s.\n", ErrorMsg(), NodeTypeString(node));
    exit(EXIT_FAILURE);
  }
}
char * PrintNodeType (enum nodeType type){
  switch (type) {
    case Ukn:     return "uknown";
            break;
    case DclN:    return "declaration";
            break;
    case ArgD:    return "arguments declaration";
            break;
    case DclAsgn: return "declaration and assignment";
            break;
    case Expr:    return "expression";
            break;
    case Asgn:    return "assignment";
            break;
    case Return:  return "return";
            break;
    case ExprLst: return "expression list";
            break;
    case FunCall: return "function call";
            break;
    case ArgLst:  return "arguments list";
            break;
    case Scope:   return "scope";
            break;
    case If:      return "if";
            break;
    case Else:    return "else";
            break;
    case IfElse:  return "if else";
            break;
    case While:   return "while";
            break;
    case MultiDc:   return "multi declaration";
            break;
    case MultiAs:   return "multi assignment";
            break;
    default:      return "unexpected";
            break;
  }
}
char * PrintExpressionType (enum exprType type){

  switch (type){
    case NUM:     return "integer";
            break;
    case ID:    return "identifier";
            break;
    case VEC:    return "array element";
            break;
    case STR: return "string";
            break;
    case C:    return "character";
            break;
    case FC:    return "function call";
            break;
    case SUM:  return "sum";
            break;
    case DIF: return "difference";
            break;
    case TIM: return "multiplication";
            break;
    case DIV:  return "division";
            break;
    case MOD:  return "modulus";
            break;
    case RND:   return "parathesis";
            break;
    case CMP:      return "comparison";
            break;
    case PI:    return "pre increment";
            break;
    case PD:   return "pre decrement";
            break;
    case IP:   return "post increment";
            break;
    case DP:   return "post decrement";
            break;
    case PA:   return "parentheses assignment";
            break;
  }
}
char * IdentifierTypeString (enum Type type){

  if      (type == INT_)      return "int";
  else if (type == CHAR_ )    return "char";
  else if (type == INT_V_ )   return "int array pointer";
  else if (type == CHAR_V_ )  return "char array pointer";
  else if (type == INT_P_ )   return "int pointer";
  else if (type == CHAR_P_ )  return "char pointer";
  else                        return "unknown";
}
void PrintScopeStackDimension(){
  printf("SCOPES IN THE STACK: %d\n", MainNode -> actual_stack -> elements);
}