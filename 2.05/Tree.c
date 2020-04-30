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

  char * error = (char*)malloc(sizeof("\aline:10000000000\x1b[31merror:\x1b[0m ") + sizeof(char)*100);
  sprintf (error, "%cline %d: %serror:%s",7,yylineno,ANSI_COLOR_RED,ANSI_COLOR_RESET);
  return error;
}
char * WarnMsg (){

  char * error = (char*)malloc(sizeof("line:10000000000\x1b[31merror:\x1b[0m ") + sizeof(char)*100);
  sprintf (error, "line %d: %swarning:%s",yylineno,ANSI_COLOR_RED,ANSI_COLOR_RESET);
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

  if (node -> nodeType == DclN){
    return node -> node.DclN -> identifier;
  }
  else if (node -> nodeType == Expr){

    struct exprNode * exprNode = node -> node.Expr;

    /* only identifiers nodes and vector nodes have an identifier stored within */
    if (exprNode -> exprType == ID || exprNode -> exprType == VEC){
      return exprNode -> exprVal.stringExpr;
    }
    else{
      printf("%s TreeNode_Identifier - this Expr TreeNode has not an identifier\n", ErrorMsg());
      return NULL;
    }
  }
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

  if (node -> nodeType != Expr){
    printf("%s Expr_toInt - incorrect call. Expr TreeNode was expected. Node type %u \n", ErrorMsg(), node -> nodeType);
    exit(EXIT_FAILURE);
  }
  else{
     int value;
     int index;
    enum exprType type = node -> node.Expr -> exprType;

    // if value is already known
    if(node -> node.Expr -> known == 1){
      value = node -> node.Expr -> exprVal.intExpr;
    }
    else{
      switch (type) {
        case NUM: value = node -> node.Expr -> exprVal.intExpr;
                  break;
        case ID:  value = Retrieve_VarValue(prog, node -> node.Expr -> exprVal.stringExpr, 0);
                  break;
        case VEC: index = Retrieve_ArrayIndex(prog, node);
                  value = Retrieve_VarValue(prog, node -> node.Expr -> exprVal.stringExpr, index);
                  break;
        case STR: printf("%s Expr_toInt - incorrect call. A string can't be converted into an integer.\n", ErrorMsg());
                  exit(EXIT_FAILURE);
                  break;
        case C:   value = node -> node.Expr -> exprVal.charExpr;
                  break;
        case FC:  value = 101;
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
        default:  printf("%s Expr_toInt - incorrect call. Unexpected Expr.\n", ErrorMsg());
                  exit(EXIT_FAILURE);
                  break;
      }
    }
    return value;
  }
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

        printf("%s use of undeclared identifier %s\n", ErrorMsg(), identifier);
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
        else{

          int index = Retrieve_ArrayIndex(MainNode, node);
          int array_dim = Retrieve_ArrayDim(MainNode, identifier);

          // out of bounds array error
          if (index > array_dim-1){
            printf("%s array index %d is past the end of the array. Array contains %d elements.\n", ErrorMsg(), index, array_dim);
            exit(EXIT_FAILURE);
            return 0;
          }
          else if (index < 0){
            printf("%s array index %d is before the beginning of the array. Array contains %d elements.\n", ErrorMsg(), index, array_dim);
            exit(EXIT_FAILURE);
            return 0;
          }
          else{
            return 1;
          }
        }
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
int SymbolTable_Add(struct SymbolTable * table, char * identifier, enum Type type, int arrayDim){

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
      printf("\tdimension: %d\n", newSTN -> arrayDim);

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
  if (ST_Node -> arrayDim == -1){
    printf("Retrieve_ArrayDim - An error occurred retrieving array dimension. The variable is not an array.\n");
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

  printf("TREE: ");
  printf(" ERROR! LIST IS EMPTY.\n");
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
void ScopeStack_Push(struct ScopeStack * stack, struct TreeNode * scope){

  if (stack -> elements == 0){
    /* no need to memory allocation cause the first element was already allocated
     during the scope stack initialization
     */
    stack -> top -> thisScope = scope;
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
  }
  stack -> elements += 1;
  // debug si potrebbe tenere con un if di controllo
  printf("New scope in the scope stack. Scope in the stacks: %d\n", stack -> elements);
}
void ScopeStack_Pop(struct ScopeStack * stack){

  struct Scope * previous_scope = stack -> top -> prevScope;
  stack -> top = previous_scope;
  stack -> elements -= 1;
  printf("A scope has been removed from the scope stack. Scope in the stacks: %d\n", stack -> elements);

}
struct TreeNode * ScopeStack_Peek(struct ScopeStack * stack){

  return stack -> top -> thisScope;
}
void SetAs_ActualScope(struct ProgramNode * prog, struct TreeNode * scope){
  ScopeStack_Push(prog -> actual_stack, scope);
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
  printf("- FunNodeList_Add: Creating a new function Node\n"); // debug

  if (declaration -> nodeType != DclN){
    printf("%s FunNodeList_Add - incorrect call. DclN node expected. Node type: %u\n", ErrorMsg(), declaration -> nodeType);
    exit(EXIT_FAILURE);
  }

  char * identifier = declaration -> node.DclN -> identifier;
  // check if a function with the same identifier was already declared
  if (CheckFunAlreadyExist(prog,identifier)){
    printf("%s redefinition of \'%s\'\n", ErrorMsg(),identifier);
    exit(EXIT_FAILURE);
  }

  // Function Node space allocation
  FunNode* newFunction;
  newFunction = (FunNode*)malloc(sizeof(FunNode)); // memory space allocation
  if ( newFunction == NULL ){
    printf("%s FunNodeList_Add - out of memory.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }

  // Linking function identifier to the created function node
  newFunction -> funName = (char*)malloc(strlen(identifier));
  if ( newFunction -> funName == NULL ){
    printf("%s FunNodeList_Add - out of memory.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  strcpy(newFunction -> funName, identifier);

  // Linking function type to the created function node
  newFunction -> funType = declaration -> node.DclN -> type;

  // Function node child list space allocation
  newFunction -> child_list = TreeNodeList_Set();

  // Function scope stack memory space allocation
  newFunction -> scope_stack = ScopeStack_Set();
  // Scope node space allocation
  newFunction -> function_scope = create_ScopeNode(); // global scope setting

  // Setting global scope at the bottom of the function scope stack
  ScopeStack_Push(newFunction -> scope_stack, MainNode -> global_scope_stack -> top -> thisScope);
  // Adding function scope to the stack as first scope
  ScopeStack_Push(newFunction -> scope_stack, newFunction -> function_scope);

  // Setting the function scope stack as actual scope stack
  prog -> actual_stack = newFunction -> scope_stack;
  printf("New actual scope stack set.\n");

  /*
  // Setting function scope as new actual scope
  prog -> actual_scope = newFunction -> function_scope;
  printf("SCOPE - FunNodeList_Add: nuovo actual_scope settato. È lo scope della nuova funzione %s\n",identifier);
  */
  // todo: rimuovere questa parte commentata dal momento in cui le funzioni non vanno più nello scope stack
  // Adding function to scope stack
  //ScopeStack_Add(prog -> ActualScope, NULL, newElem);   //  adding scope as new actual scope

  // Adding function to ProgramNode function list
  if (prog -> function_list -> elements == 0){
    if (TREE_DEBUGGING){
    printf("TREE: %s first function insert in FunNodeList\n",identifier);
  }
    prog -> function_list -> first = newFunction;
    prog -> function_list -> last = newFunction;
  }
  else{
    if (TREE_DEBUGGING){
    printf("TREE: \"%s\" function insert in FunNodeList\n",identifier);
    }
    prog -> function_list -> last -> next = newFunction;
    prog -> function_list -> last = newFunction;

  }
  prog -> function_list -> elements ++;
  printf("- FunNodeList_Add: A new function Node was created\n");
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
  ScopeStack_Push(prog -> global_scope_stack, prog -> global_scope);
  // setting global scope stack as actual scope stack
  prog -> actual_stack = prog -> global_scope_stack;
  // setting initial state
  prog -> exec_state = 0;
  // setting warnings counter
  prog -> warnings = 0;
  return prog;
}

// returns 1 if a function with the same identifier was already declared, otherwise 0
int CheckFunAlreadyExist (ProgramNode* prog, char* identifier){

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

  printf("TREE: Program with %d functions\n",prog -> function_list -> elements);
  if(prog -> function_list -> elements == 0) printf("WARNING: no function found in this C program\n");

    for (int i=0; i<prog -> function_list -> elements; i++){
      if (i==0){
        support = prog -> function_list -> first;
      }
      else{
        support = support -> next;
      }
      printf("TREE: Function Node - function number %d identifier %s with type %s\n",i+1,support->funName,PrintVarType(support->funType));
      PrintTreeNode (support -> function_scope -> child_list);
    }
}
void PrintTreeNode (struct TreeNodeList* main_list){

  if(main_list -> elements == 0) {
    PrintDepth ();
    printf("END Node\n");
    }

  struct TreeNode* support;

  for (int i=0; i<main_list -> elements; i++){
    if (i==0){
      treeDepth ++;
      support = main_list -> first;
    }
    else{
      support = support -> next;
    }

    PrintDepth ();
    printf("TREE: Tree Node - ");
    PrintTreeNodeType(support->nodeType, support);
    printf(".\n");

    PrintTreeNode(support->child_list);
    if (i+1 == main_list -> elements){
      treeDepth --;
      printf("\n");
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
    case DclAsgn: printf("declaration and assignment of %s",Tnode->child_list->first->node.DclN->identifier);
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
    case ArgLst:printf("Arguments list");
            break;
    case Scope:printf("SCOPE");
            break;
    case If:printf("If");
            break;
    case Else:printf("Else");
            break;
    case While:printf("While");
            break;
  }
}
void PrintExprType (unsigned int type, struct TreeNode* Tnode){

  switch (type) {
    case 0: printf("num expr with value: %d",Tnode->node.Expr->exprVal.intExpr);
            break;
    case 1: printf("identifier expr with value %s",Tnode->node.Expr->exprVal.stringExpr);
            break;
    case 2: printf("vector expr with value \"%s\"",Tnode->node.Expr->exprVal.stringExpr);
            break;
    case 3: printf("string expr with value \"%s\"",Tnode->node.Expr->exprVal.stringExpr);
            break;
    case 4: printf("char expr with value '%c'(%d)",Tnode->node.Expr->exprVal.charExpr,Tnode->node.Expr->exprVal.charExpr);
            break;
    case 5: printf("function call expr");
            break;
    case 6: printf("sum expr \"+\"");
            break;
    case 7: printf("difference expr \"-\"");
            break;
    case 8: printf("times expr \"*\"");
            break;
    case 9: printf("divide expr \"/\"");
            break;
    case 10: printf("modulo expr \"%%\"");
            break;
    case 11:printf("round brackets (expr)");
            break;
    case 12:printf("comparison ");
            PrintCmpType(Tnode->node.Expr->exprVal.cmpExpr, NULL);
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
    case Expr:    return ExprTypeString(node);
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
    case While:   return "while";
            break;
    case Multi:   return "multi expressions";
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
    }

  }
  else{
    printf("%s ExprTypeString - incorrect call. Expr TrenNode type expected. Type found: %u.\n", ErrorMsg(), node -> nodeType);
    exit(EXIT_FAILURE);
  }
}
