#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"
#include "Tree.h"
#include "parser.h"
#include "exec.h"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_BOLD_YELLOW   "\033[1m\033[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

ProgramNode * MainNode;


///////////////////////////  USEFUL FUNCTIONS   ////////////////////////////////

/*
* Given an Expr TreeNode returns a Type var with the node value type (INT_, CHAR_, INT_V_. CHAR_V_)
*/
enum Type ExprNode_valueType (ProgramNode * prog, struct TreeNode * node){

  // value node expr type
  enum exprType valueExprType = node -> node.Expr -> exprType;
  // value type
  enum Type valueType;

  if (valueExprType == NUM){
    valueType = INT_;
  }
  else if (valueExprType == ID || valueExprType == VEC){
    valueType = Retrieve_VarType(prog, node -> node.Expr -> exprVal.stringExpr);
  }
  else if (valueExprType == C){
    valueType = CHAR_;
  }
  else if (valueExprType == FC){
    valueType = Retrive_FunType(prog, node -> node.Expr -> exprVal.stringExpr);
  }
  // remaining types are integers (SUM, DIF, TIM, DIV, MOD, RND, CMP)
  else{
    valueType = INT_;
  }

  return valueType;
}
/*  todo: dopo averla tolta dal calcolo del valore logico potrebbe essere inutile
* Given a variable's identifier, returns a - INT or CHAR - Expr Tree Node with
* the variable value stored in the symbol table
*/
struct TreeNode * IdentifierResolverTreeNode (struct ProgramNode * prog, char * identifier, int index){

    // Retrieving the variable symbol table node with the specific identifier
    struct SymbolTable_Node * var = SymbolTable_RetrieveVar(prog, identifier);

    struct TreeNode * newNode;

    //// Integer ////
    if (var -> type == INT_){
      // value of the int variable stored in the SymbolTable_Node
      int intValue = var -> varVal.intVal;
      // creating the INT Expr Tree Node
      newNode = create_ExprNode(NUM, intValue, NULL, NULL, NULL, 0);
    }
    //// Character ////
    else if(var -> type == CHAR_){
      // value of the char variable
      char charVal = var -> varVal.charVal;
      // creating the CHAR Expr Tree Node
      newNode = create_ExprNode(C, 0, &charVal, NULL, NULL, 0);
    }
    //// Interger stored in a vector ////
    else if(var -> type == INT_V_){
      // char vector pointer
      int * vectorPtr = var -> varPtr.intPtr;
      // value of the index-th element in the array
      int intValue = vectorPtr[index];
      // creating the INT Expr Tree Node
      newNode = create_ExprNode(NUM, intValue, NULL, NULL, NULL, 0);
    }
    //// Character stored in a vector ////
    else if(var -> type == CHAR_V_){
      // char vector pointer
      char * vectorPtr = var -> varPtr.charPtr;
      // value of the index-th element in the array
      char charValue = vectorPtr[index];
      // creating the CHAR Expr Tree Node
      newNode = create_ExprNode(C, 0, &charValue, NULL, NULL, 0);
    }
    // Unspected type
    else{
      printf("ERROR: IdentifierResolverTreeNode - unespected SymbolTable_Node type. Expected INT_, CHAR_, INT_V_ or CHAR_V_\n");
      if (var == NULL){
        printf("Variable with identifier %s was not found\n", identifier);
      }
      newNode = NULL;
    }

    return newNode;
}


////////////////////////////////////////////////////////////////////////////////
////////////////////////////// INTERPRETATION  /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/////////////////////////// RETURN   ///////////////////////////////////////////

int exec_return(struct TreeNode * node){

  Check_NodeType(Return, node, "exec_return");

  return Expr_toInt(MainNode, node -> child_list -> first);
}

/////////////////////////// FUNCTION CALL   ////////////////////////////////////

int exec_FunctionCall(struct TreeNode * function_call){
  //todo remove
  //printf("------------ EXEC FUNCTION ------------\n");

  Check_NodeType(Expr, function_call, "exec_FunctionCall");
  Check_ExprType(FC, function_call, "exec_FunctionCall");

  if (!strcmp(function_call -> node.Expr -> exprVal.stringExpr, "printf")){

    struct TreeNode * arguments = function_call -> child_list -> first;
    struct TreeNode * firstArgument = arguments -> child_list -> first;
    char * string;
    int remaining_arguments = arguments -> child_list -> elements - 1;

    if (firstArgument -> node.Expr -> exprType == ID){
      if (expressionType(firstArgument) == CHAR_V_){
        struct SymbolTable_Node * stringNode = SymbolTable_IterativeRetrieveVar(firstArgument -> node.Expr -> exprVal.stringExpr);
        string = stringNode -> varPtr.charPtr;
        Check_Printf_String(string, arguments);
      }
      else{
        printf("%s exec_FunctionCall - unexpected variable. Char pointer expected.\n", ErrorMsg());
        exit(EXIT_FAILURE);
      }
    }
    else if (firstArgument -> node.Expr -> exprType == STR)
      string = firstArgument -> node.Expr -> exprVal.stringExpr;

    struct TreeNode * argument;
    if (remaining_arguments > 0){
      argument = firstArgument -> next;
    }
    int printed = 0;

    for (int i = 0; i < strlen(string); i++){
      // string format
      if (string[i] == '%'){
        if (string[i+1] == 'd'){
          if (remaining_arguments > 0) printed += printf("%d", Expr_toInt(MainNode, argument));
          else printed = printf("%d");
          remaining_arguments --;
          if (remaining_arguments > 0)  argument = argument -> next;
        }
        else if (string[i+1] == 'i'){
          if (remaining_arguments > 0) printed += printf("%i", Expr_toInt(MainNode, argument));
          else printed = printf("%i");
          remaining_arguments --;
          if (remaining_arguments > 0)  argument = argument -> next;
        }
        else if (string[i+1] == 'c'){
          if (remaining_arguments > 0) printed += printf("%c", Expr_toInt(MainNode, argument));
          else printed = printf("%c");
          remaining_arguments --;
          if (remaining_arguments > 0)  argument = argument -> next;
        }
        else if (string[i+1] == 'o'){
          if (remaining_arguments > 0) printed += printf("%o", Expr_toInt(MainNode, argument));
          else printed = printf("%o");
          remaining_arguments --;
          if (remaining_arguments > 0)  argument = argument -> next;
        }
        else if (string[i+1] == 'u'){
          if (remaining_arguments > 0) printed += printf("%u", Expr_toInt(MainNode, argument));
          else printed = printf("%u");
          remaining_arguments --;
          if (remaining_arguments > 0)  argument = argument -> next;
        }
        else if (string[i+1] == 'x'){
          if (remaining_arguments > 0) printed += printf("%x", Expr_toInt(MainNode, argument));
          else printed = printf("%x");
          remaining_arguments --;
          if (remaining_arguments > 0)  argument = argument -> next;
        }
        else if (string[i+1] == 'X'){
          if (remaining_arguments > 0) printed += printf("%X", Expr_toInt(MainNode, argument));
          else printed = printf("%X");
          remaining_arguments --;
          if (remaining_arguments > 0)  argument = argument -> next;
        }
        else if (string[i+1] == 's'){
          if (remaining_arguments > 0) {

            if (argument -> node.Expr -> exprType == STR){
              printed += printf("%s", argument -> node.Expr -> exprVal.stringExpr);
              remaining_arguments --;
              if (remaining_arguments > 0)  argument = argument -> next;
            }
            else if (argument -> node.Expr -> exprType == ID){
              struct SymbolTable_Node * stringNode = SymbolTable_IterativeRetrieveVar(argument -> node.Expr -> exprVal.stringExpr);
              char * string;
              if (stringNode -> type == INT_V_) string = (char*)stringNode -> varPtr.intPtr;
              else if (stringNode -> type == CHAR_V_) string = stringNode -> varPtr.charPtr;

              printed += printf("%s", string);
              remaining_arguments --;
              if (remaining_arguments > 0)  argument = argument -> next;
            }
            else if (argument -> node.Expr -> exprType == ADD){

              struct SymbolTable_Node * stringNode = SymbolTable_IterativeRetrieveVar(TreeNode_Identifier(argument));

              char * string;

              if (argument -> child_list -> first -> node.Expr -> exprType == ID){
                if (stringNode -> type == INT_V_) string = (char*)stringNode -> varPtr.intPtr;
                else if (stringNode -> type == CHAR_V_) string = stringNode -> varPtr.charPtr;
                else if (stringNode -> type == INT_)    string = (char*)&(stringNode -> varVal.intVal);
                else if (stringNode -> type == CHAR_)   string = &(stringNode -> varVal.charVal);
              }
              else if (argument -> child_list -> first -> node.Expr -> exprType == VEC){

                int index = Retrieve_ArrayIndex(MainNode, argument -> child_list -> first);
                if (stringNode -> type == INT_V_) string = (char*)&(stringNode -> varPtr.intPtr)[index];
                else if (stringNode -> type == CHAR_V_) string = &(stringNode -> varPtr.charPtr)[index];
              }

              printed += printf("%s", string);
              remaining_arguments --;
              if (remaining_arguments > 0)  argument = argument -> next;
            }
          }
          else printed = printf("%s");
        }
        else if (string[i+1] == '%'){
          printed += printf("%%");
        }
        else printed += printf("%c", string[i+1]);
        i++;
      }
      // escape sequence
      else if (string[i] == '\\'){
        if (string[i+1] == 'a'){
          printed += printf("\a");
          i++;
        }
        else if (string[i+1] == 'b'){
          printed += printf("\b");
          i++;
        }
        else if (string[i+1] == 'e'){
          printed += printf("\e");
          i++;
        }
        else if (string[i+1] == 'f'){
          printed += printf("\f");
          i++;
        }
        else if (string[i+1] == 'n'){
          printed += printf("\n");
          i++;
        }
        else if (string[i+1] == 'r'){
          printed += printf("\r");
          i++;
        }
        else if (string[i+1] == 't'){
          printed += printf("\t");
          i++;
        }
        else if (string[i+1] == 'v'){
          printed += printf("\v");
          i++;
        }
        else if (string[i+1] == '\\'){
          printed += printf("\\");
          i++;
        }
        else if (string[i+1] == '\''){
          printed += printf("\'");
          i++;
        }
        else if (string[i+1] == '\"'){
          printed += printf("\"");
          i++;
        }
        else if (string[i+1] == '\?'){
          printed += printf("\?");
          i++;
        }
        else if (string[i+1] > 47 && string[i+1] < 56){
          int skip = 1;
          if (string[i+2] > 47 && string[i+2] < 56){
            if (string[i+3] > 47 && string[i+3] < 56){

              char octal = (((string[i+1] - 48)*64)+((string[i+2] - 48)*8)+(string[i+3] - 48));
              printed += printf("%c", octal);
              skip = 3;
            }
            else{
              char octal = (((string[i+1] - 48)*8)+(string[i+2] - 48));
              printed += printf("%c", octal);
              skip = 2;
            }
          }
          else{
            char octal = (string[i+1] - 48);
            printed += printf("%c", octal);
          }

          i = i + skip;
        }
        else printf("%s unknown escape sequence '\\%c'\n", WarnMsg(),string[i+1]);
      }
      // simple character
      else{
        printed += printf("%c", string[i]);
      }
    }

    return printed;
  }
  if (!strcmp(function_call -> node.Expr -> exprVal.stringExpr, "scanf")){

    struct TreeNode * arguments = function_call -> child_list -> first;
    struct TreeNode * firstArgument = arguments -> child_list -> first;
    char * string;
    int remaining_arguments = arguments -> child_list -> elements - 1;

    if (firstArgument -> node.Expr -> exprType == ID){
      if (expressionType(firstArgument) == CHAR_V_){
        struct SymbolTable_Node * stringNode = SymbolTable_IterativeRetrieveVar(firstArgument -> node.Expr -> exprVal.stringExpr);
        string = stringNode -> varPtr.charPtr;
        Check_Scanf_String(string, arguments);
      }
      else{
        printf("%s exec_FunctionCall - unexpected variable. Char pointer expected.\n", ErrorMsg());
        exit(EXIT_FAILURE);
      }
    }
    else if (firstArgument -> node.Expr -> exprType == STR)
      string = firstArgument -> node.Expr -> exprVal.stringExpr;

    struct TreeNode * argument;
    if (remaining_arguments > 0){
      argument = firstArgument -> next;
    }
    int scanned = 0;

    for (int i = 0; i < strlen(string); i++){

      if (string[i] == '%'){

        void * pointer = TreeNode_Var_Pointer(argument);

        if (string[i+1] == 'd'){

          if (remaining_arguments > 0) scanned += scanf("%d", (int*)pointer);
          else scanned = scanf("%d");
          remaining_arguments --;
          if (remaining_arguments > 0)  argument = argument -> next;
          i++;
        }
        if (string[i+1] == 'i'){

          if (remaining_arguments > 0) scanned += scanf("%i", (int*)pointer);
          else scanned = scanf("%i");
          remaining_arguments --;
          if (remaining_arguments > 0)  argument = argument -> next;
          i++;
        }
        if (string[i+1] == 'c'){

          if (remaining_arguments > 0) scanned += scanf("%c", (char*)pointer);
          else scanned = scanf("%c");
          remaining_arguments --;
          if (remaining_arguments > 0)  argument = argument -> next;
          i++;
        }
        if (string[i+1] == 'o'){

          if (remaining_arguments > 0) scanned += scanf("%o", (int*)pointer);
          else scanned = scanf("%o");
          remaining_arguments --;
          if (remaining_arguments > 0)  argument = argument -> next;
          i++;
        }
        if (string[i+1] == 'u'){

          if (remaining_arguments > 0) scanned += scanf("%u", (int*)pointer);
          else scanned = scanf("%u");
          remaining_arguments --;
          if (remaining_arguments > 0)  argument = argument -> next;
          i++;
        }
        if (string[i+1] == 's'){

          if (remaining_arguments > 0) scanned += scanf("%s", (char*)pointer);
          else scanned = scanf("%s");
          remaining_arguments --;
          if (remaining_arguments > 0)  argument = argument -> next;
          i++;
        }
        if (string[i+1] == 'x'){

          if (remaining_arguments > 0) scanned += scanf("%x", (int*)pointer);
          else scanned = scanf("%x");
          remaining_arguments --;
          if (remaining_arguments > 0)  argument = argument -> next;
          i++;
        }
        if (string[i+1] == 'X'){

          if (remaining_arguments > 0) scanned += scanf("%X", (int*)pointer);
          else scanned = scanf("%X");
          remaining_arguments --;
          if (remaining_arguments > 0)  argument = argument -> next;
          i++;
        }
      }
    }

    return scanned;
  }
  else{

    // track the actual scope stack
    struct ScopeStack * previous_stack = MainNode -> actual_stack;
    // create a the new function scope stack
    struct ScopeStack * new_stack = ScopeStack_Set();

    // Retrieving function declaration node
    int index = FunNodeList_Search (MainNode, function_call -> node.Expr -> exprVal.stringExpr);
    struct FunNode * functionNode = FunNodeList_Get (MainNode, index);
    enum Type function_type = functionNode -> funType;

    // Function scope node
    struct TreeNode * function_scope = create_ScopeNode();

    // Setting global scope at the bottom of the function scope stack
    // Global scope is active by default
    ScopeStack_Push(new_stack, MainNode -> global_scope_stack -> top -> thisScope, 1);

    // Adding symbol table to scope stack
    ScopeStack_Push(new_stack, function_scope, 1);

    // Setting the function scope stack as actual scope stack
    MainNode -> actual_stack = new_stack;

    // Copying symbol table from function declaration node
    SymbolTableCopy(functionNode -> function_scope -> node.ST, function_scope -> node.ST);

    // Parameters assignment
    // Check if there are parameters
    if (function_call -> child_list -> elements != 0){

      struct TreeNode * parameters = function_call -> child_list -> first;
      struct TreeNode * arguments = functionNode -> function_scope -> child_list -> first;

      struct TreeNode * parameter;
      struct TreeNode * argument;

      printf("arguments: %s\n", NodeTypeString(arguments));
      printf("elementi %d\n", arguments -> child_list -> elements);

      for (int i = 0; i < arguments -> child_list -> elements; i++){

        if (i == 0) argument = arguments -> child_list -> first;
        else  argument = argument -> next;

        if (i == 0) parameter = parameters -> child_list -> first;
        else  parameter = parameter -> next;

        printf("argument = %s\n", NodeTypeString(argument));  // FUNZIONE
        printf("parameter = %s\n", ExprTypeString(parameter));  // QUELLO CHE PASSO

        // assign parameter value
        if (argument -> node.DclN -> type == INT_ || argument -> node.DclN -> type == CHAR_){

          struct TreeNode * identifier = create_ExprNode(ID, 0, TreeNode_Identifier(argument), NULL, NULL, 0);
          // value must be taken from the function call stack
          MainNode -> actual_stack = previous_stack;
          int value = Expr_toInt(MainNode, parameter);

          // assignment must be done in the function scope
          MainNode -> actual_stack = new_stack;
          struct TreeNode * valueNode = create_ExprNode(NUM, value, NULL, NULL, NULL, 0);

          struct TreeNode * assignment = create_AssignmentNode(MainNode, identifier, valueNode);
          exec_Asgn(MainNode, assignment);
        }
        if (argument -> node.DclN -> type == INT_V_ || argument -> node.DclN -> type == CHAR_V_){
          if (parameter -> node.Expr -> exprType == ID){

            // value must be taken from the function call stack
            MainNode -> actual_stack = previous_stack;
            enum Type parameter_type = Retrieve_VarType(MainNode, TreeNode_Identifier(parameter));
            struct SymbolTable_Node * parameter_node = SymbolTable_RetrieveVar(MainNode, TreeNode_Identifier(parameter));
            int parameter_dimension = Retrieve_ArrayDim(MainNode, TreeNode_Identifier(parameter));

            if (parameter_type == INT_V_ || parameter_type == CHAR_V_){

              if (argument -> node.DclN -> type == parameter_type){

                MainNode -> actual_stack = new_stack;
                struct SymbolTable_Node * argument_node = SymbolTable_RetrieveVar(MainNode, TreeNode_Identifier(argument));

                int argument_dimension = Expr_toInt(MainNode, argument -> node.DclN -> arrayDim);

                // undeclared array dimension
                // array dimension must be updated
                if (argument -> node.DclN -> ignore){

                  MainNode -> actual_stack = new_stack;

                  argument_node -> arrayDim = parameter_dimension;
                  argument_node -> ignore = 0;
                  MainNode -> actual_stack = previous_stack;

                  argument_dimension = parameter_dimension;
                }

                if (parameter_type == INT_V_) argument_node -> varPtr.intPtr = parameter_node -> varPtr.intPtr;
                if (parameter_type == CHAR_V_) argument_node -> varPtr.charPtr = parameter_node -> varPtr.charPtr;

              }
              else{
                printf("%s incompatible pointer types passing \'%s\' to parameter of type \'%s\'.\n", ErrorMsg(),IdentifierTypeString(parameter_type),IdentifierTypeString(argument -> node.DclN -> type));
                exit(EXIT_FAILURE);
              }
            }
            else {
              printf("%s exec_FunctionCall - argument must be an array identifier.\n", ErrorMsg());
              exit(EXIT_FAILURE);
            }
          }
          else if (parameter -> node.Expr -> exprType == STR){
            if (argument -> node.DclN -> type == CHAR_V_){

              int parameter_dimension = strlen(parameter -> node.Expr -> exprVal.stringExpr) + 1;

              MainNode -> actual_stack = new_stack;
              struct SymbolTable_Node * argument_node = SymbolTable_RetrieveVar(MainNode, TreeNode_Identifier(argument));

              int argument_dimension = Expr_toInt(MainNode, argument -> node.DclN -> arrayDim);

              // undeclared array dimension
              // array dimension must be updated
              if (argument -> node.DclN -> ignore){

                MainNode -> actual_stack = new_stack;

                argument_node -> arrayDim = parameter_dimension;
                argument_node -> ignore = 0;
                MainNode -> actual_stack = previous_stack;

                argument_dimension = parameter_dimension;
                argument_node -> varPtr.charPtr = (char*)malloc(argument_dimension*sizeof(char));
                // out of memory error
                if (argument_node -> varPtr.charPtr == NULL){
                  printf("%s SymbolTable_Set - out of memory.\n", ErrorMsg());
                  exit(EXIT_FAILURE);
                }
              }

              // todo rimuovere
              // STRING BY VALUE
              /*
              MainNode -> actual_stack = new_stack;

              for (int i = 0; i < parameter_dimension; i++){

                struct TreeNode * index_node = create_ExprNode(NUM, i, NULL, NULL, NULL, 0);
                struct TreeNode * identifier = create_ExprNode(VEC, 0, TreeNode_Identifier(argument), index_node, NULL, 0);

                char value = parameter -> node.Expr -> exprVal.stringExpr[i];
                printf("%c\n", value);
                struct TreeNode * valueNode = create_ExprNode(NUM, value, NULL, NULL, NULL, 0);

                struct TreeNode * assignment = create_AssignmentNode(MainNode, identifier, valueNode);
                exec_Asgn(MainNode, assignment);

              }
              */

              argument_node -> varPtr.charPtr = parameter -> node.Expr -> exprVal.stringExpr;

            }
            else{
              printf("%s exec_FunctionCall - char pointer expected.\n", ErrorMsg());
              exit(EXIT_FAILURE);
            }
          }
        }
      }
    }

    MainNode -> actual_stack = new_stack;

    int return_value;
    // function statements exec
    return_value = exec_functionScope(functionNode -> function_scope);

    // restoring previous scope stack
     MainNode -> actual_stack = previous_stack;

     // value returned by function
     if (function_type == INT_) return return_value;
     else if (function_type == CHAR_) return (char)return_value;
  }
}

///////////////////////////  POST INCREMENT DECREMENT   ////////////////////////

int exec_IncDec(struct TreeNode * node){

  if (node -> nodeType == Expr){
    // pre increment
    if (node -> node.Expr -> exprType == PI){

      // value
      int value = Expr_toInt(MainNode, node -> child_list -> first);
      // pre increment
      SymbolTable_AssignValue(MainNode, node -> child_list -> first, value + 1);
      // value post increment
      value ++;


      return value;
    }
    // pre decrement
    else if (node -> node.Expr -> exprType == PD){

      // value
      int value = Expr_toInt(MainNode, node -> child_list -> first);
      // pre decrement
      SymbolTable_AssignValue(MainNode, node -> child_list -> first, value - 1);
      // value post increment
      value --;

      return value;
    }
    // post increment
    else if (node -> node.Expr -> exprType == IP){

      // value pre increment
      int value = Expr_toInt(MainNode, node -> child_list -> first);
      // post increment
      SymbolTable_AssignValue(MainNode, node -> child_list -> first, value + 1);

      return value;
    }
    // post decrement
    else if (node -> node.Expr -> exprType == DP){

      // value pre increment
      int value = Expr_toInt(MainNode, node -> child_list -> first);
      // post increment
      SymbolTable_AssignValue(MainNode, node -> child_list -> first, value - 1);

      return value;
    }
    else{
      printf("%s exec_IncDec - incorrect call. IP / DP Expr TreeNode expected. Type found: %u\n", ErrorMsg(), node -> node.Expr -> exprType);
      exit(EXIT_FAILURE);
    }
  }
  else{
    printf("%s exec_IncDec - incorrect call. Expr node type expected.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  return 0;
}

///////////////////////////  OPERATION   ///////////////////////////////////////

int exec_Operation (struct TreeNode * node){

  if (node -> nodeType == Expr){
    if (isOperation(node)){

      int value;
      struct TreeNode * leftOp = node -> child_list -> first;
      struct TreeNode * rightOp;
      if (node -> node.Expr -> exprType != RND){
        rightOp = node -> child_list -> first -> next;
      }

      int leftOp_value = Expr_toInt(MainNode, leftOp);
      int rightOp_value;
      if (node -> node.Expr -> exprType != RND){
        rightOp_value = Expr_toInt(MainNode, rightOp);
      }

      switch (node -> node.Expr -> exprType) {
        case SUM: value = leftOp_value + rightOp_value;
        break;
        case DIF: value = leftOp_value - rightOp_value;
        break;
        case TIM: value = leftOp_value * rightOp_value;
        break;
        case DIV: if(rightOp_value == 0){
                    printf("%s division by 0!\n", ErrorMsg());
                    exit(EXIT_FAILURE);
                  }
                  value = leftOp_value / rightOp_value;
        break;
        case MOD: value = (int)leftOp_value % (int)rightOp_value;
        break;
        case RND: value = leftOp_value;
        break;
        default:
          printf("%s exec_Operation - unexpected operation type. Type found %u\n", ErrorMsg(), node -> node.Expr -> exprType);
        break;
      }

      return value;
    }
    else{
      printf("%s exec_Operation - incorrect call. SUM/DIF/TIM/DIV/MOD/RND Expr TreeNode expected. Type found: %u\n", ErrorMsg(), node -> nodeType);
      exit(EXIT_FAILURE);
    }
  }
  else{
    printf("%s exec_Operation - incorrect call. Expr TreeNode expected. Type found: %u\n", ErrorMsg(), node -> nodeType);
    exit(EXIT_FAILURE);
  }
}

///////////////////////////  COMPARISON   //////////////////////////////////////

/*
*  returns 0 if the logic value is 0
*  returns 1 if the logic value is 1
*  returns -1 if it fails
*/
int exec_CMP (struct TreeNode * node){

  if (node -> nodeType == Expr){
    if (node -> node.Expr -> exprType == CMP){

      enum cmpType cmpType = node -> node.Expr -> exprVal.cmpExpr;

      // comparison is a binary logic operation with two operands: firstN and secondN
      struct TreeNode * firstN = node -> child_list -> first;
      struct TreeNode * secondN = node -> child_list -> first -> next;

      int firstLogic;
      int secondLogic;
      int logicValue;

      switch (cmpType) {
        case AND_:
                  // logic values of the operands
                  firstLogic = CMP_node_logicValue(MainNode, firstN);
                  secondLogic = CMP_node_logicValue(MainNode, secondN);
                  logicValue = firstLogic && secondLogic;
                  break;
        case OR_:
                  // logic values of the operands
                  firstLogic = CMP_node_logicValue(MainNode, firstN);
                  secondLogic = CMP_node_logicValue(MainNode, secondN);
                  logicValue = firstLogic || secondLogic;
                  break;
        case GREAT_:
                  // actual values of the operands
                  firstLogic = Expr_toInt(MainNode, firstN);
                  //printf("First value: %d of node %u\n", firstLogic, firstN -> node.Expr -> exprType); //debug
                  secondLogic = Expr_toInt(MainNode, secondN);
                  //printf("Second value: %d of node %u\n", secondLogic, secondN -> node.Expr -> exprType); //debug

                  // greater than condition
                  if (firstLogic > secondLogic){
                    logicValue = 1;
                  }
                  else{
                    logicValue = 0;
                  }
        break;
        case LESS_:
                  // actual values of the operands
                  firstLogic = Expr_toInt(MainNode, firstN);
                  secondLogic = Expr_toInt(MainNode, secondN);
                  // less than condition
                  if (firstLogic < secondLogic){
                    logicValue = 1;
                  }
                  else{
                    logicValue = 0;
                  }
        break;
        case EQUAL_:
                  // actual values of the operands
                  firstLogic = Expr_toInt(MainNode, firstN);
                  secondLogic = Expr_toInt(MainNode, secondN);
                  // equal to condition
                  if (firstLogic == secondLogic){
                    logicValue = 1;
                  }
                  else{
                    logicValue = 0;
                  }
        break;
        case DIFF_:
                  // actual values of the operands
                  firstLogic = Expr_toInt(MainNode, firstN);
                  secondLogic = Expr_toInt(MainNode, secondN);
                  // different from condition
                  if (firstLogic != secondLogic){
                    logicValue = 1;
                  }
                  else{
                    logicValue = 0;
                  }
        break;
      }
      //printf("line: %d Logic value %d\n",yylineno, logicValue); //debug
      return logicValue;
    }
    else{
      printf("%s exec_CMP - incorrect call. CMP Expr node expected. Type found: %u\n", ErrorMsg(), node -> nodeType);
      exit(EXIT_FAILURE);
    }
  }
  else{
    printf("%s exec_CMP - incorrect call. Expr TreeNode expected. Type found: %u\n", ErrorMsg(), node -> nodeType);
    exit(EXIT_FAILURE);
  }



  return 0;
}
/*
* Given an Expr TreeNode returns 1 or 0 if the logic value of the node
* is TRUE or FALSE.
* Intergers greater than 1 or less than 0 returns 1
* Integer 0 returns 0, integer 1 returns 1
* An identifier is considered respect to the value stored in the symbol table
*
*/
int CMP_node_logicValue (ProgramNode * prog, struct TreeNode * node){

  int logicValue;
  int value;

  if (node -> nodeType == Expr){

    // retrieve the operand expr type
    enum exprType type = node -> node.Expr -> exprType;

    if (type == NUM){
      value = node -> node.Expr -> exprVal.intExpr;
      // todo rimuovere perchè questo tipo di warning viene segnalato prima
      /*
      if(value == 0){
        logicValue = 0;
      }
      else if (value == 1){
        logicValue = 1;
      }
      else{
        printf("%s logical operation with costant operand.\n", WarnMsg());
        logicValue = 1;
      }
      */
      if(value == 0){
        logicValue = 0;
      }
      else{
        logicValue = 1;
      }
    }
    else if (type == ID){
      char * identifier = TreeNode_Identifier(node);
      enum Type varType = Retrieve_VarType(prog, identifier);
      if (varType == INT_V_ || varType == CHAR_V_){
        logicValue = 1;
      }
      else{
        value = Retrieve_VarValue(prog, identifier, -1);

        if(value == 0){
          logicValue = 0;
        }
        else{
          logicValue = 1;
        }
      }
    }
    else if (type == VEC){

      value = Expr_toInt(prog, node);

      if(value == 0){
        logicValue = 0;
      }
      else{
        logicValue = 1;
      }
    }
    else if (type == CMP){
      logicValue = exec_CMP (node);
    }
    else if(type == STR){
        printf("%s this interpreter does not support pointer to integer conversion.\n", ErrorMsg());
        exit(EXIT_FAILURE);
    }
    else if(type == C){
      value = node -> node.Expr -> exprVal.charExpr;
      if(value == 0){
        logicValue = 0;
      }
      else{
        logicValue = 1;
      }
    }
    else if(type == FC){
      value = Expr_toInt(MainNode, node);
      if(value == 0){
        logicValue = 0;
      }
      else{
        logicValue = 1;
      }
    }
    else if(type == SUM || type == DIF || type == TIM || type == DIV || type == MOD || type == RND){
      value = Expr_toInt(MainNode, node);
      if(value == 0){
        logicValue = 0;
      }
      else{
        logicValue = 1;
      }
    }
    else if(type == PI || type == PD || type == IP || type == DP){
      value = Expr_toInt(MainNode, node);
      if(value == 0){
        logicValue = 0;
      }
      else{
        logicValue = 1;
      }
    }
    else if(type == PA){

      value = Expr_toInt(prog, node);

      if(value == 0){
        logicValue = 0;
      }
      else{
        logicValue = 1;
      }
    }
    else if(type == ADD) logicValue = 1;
    else{
      printf("%s unexpected expression type. Type found %u\n", ErrorMsg(), type);
      exit(EXIT_FAILURE);
    }

    return logicValue;
  }
  else{
    printf("%s CMP_node_logicValue - incorrect call. Expr TreeNode expected. Type found: %u\n", ErrorMsg(), node -> nodeType);
    exit(EXIT_FAILURE);
  }
}

///////////////////////////  EXPRESSION   //////////////////////////////////////

void exec_Expression (struct TreeNode * node){

  if (node -> nodeType == Expr){

    enum exprType type = node -> node.Expr -> exprType;
    // todo aggiungere eventualmente
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
      case FC:  exec_FunctionCall(node);
                break;
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
      case PI:  exec_IncDec(node);
                break;
      case PD:  exec_IncDec(node);
                break;
      case IP:  exec_IncDec(node);
                break;
      case DP:  exec_IncDec(node);
                break;
      case PA:  exec_Asgn(MainNode, node -> child_list -> first);
                break;
      case ADD: printf("%s expression result unused.\n", WarnMsg());
                break;
      default:
                break;
      }
  }
  else{
    printf("%s exec_Expression - expr node type expected.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
}

///////////////////////////  DECLARATION   /////////////////////////////////////
/*
*   Given a declaration node creates a SymbolTable_Node in the actual scope
*/
void exec_DclN (ProgramNode * prog, struct TreeNode * node){

  // CHECK: TreeNode must be a Declaration Node
  Check_NodeType(DclN, node, "exec_DclN");

  char * variable_identifier = TreeNode_Identifier(node);
  // retrieve the actual scope
  struct TreeNode * actualScope = Get_ActualScope(prog);
  // retrieve symbol table from the scope
  struct SymbolTable * ST = actualScope -> node.ST;

  // setting variable type
  enum Type varType = node -> node.DclN -> type;
  int arrayDim = 0;

  if(varType == INT_ || varType == CHAR_){
    arrayDim = -1;
  }
  else if(varType == INT_V_ || varType == CHAR_V_){

    // check if array dimension is defined
    Check_ArrayDimension(node);

    arrayDim = Retrieve_ArrayIndex(prog, node);
    if (arrayDim < 0){
      printf("%s '%s' declared as an array with 0 or negative size\n", ErrorMsg(), variable_identifier);
      exit(EXIT_FAILURE);
    }
  }
  else{
      printf("%s exec_DclN - unexpected variable type. Type found %u.\n", ErrorMsg(), varType);
      exit(EXIT_FAILURE);
    }

  char ignoreFlag = node -> node.DclN -> ignore;

  // adding variable to symbol table
  int add = SymbolTable_Add(ST, variable_identifier, varType, arrayDim, ignoreFlag);
  if(!add){
    printf("%s exec_DclN - declaration of \'%s\' failed.\n", ErrorMsg(), variable_identifier);
    exit(EXIT_FAILURE);
  }

}

///////////////////////////  ASSIGNMENT   /////////////////////////////////////
/*
*   Given an assignment node change the value stored in the SymbolTable_Node for the variables involved
*/
void exec_Asgn (ProgramNode * prog, struct TreeNode * node){
  // check if the node is an assignmentNode
  if (node -> nodeType == Asgn){

    // the last node stores the value to assign to other nodes
    struct TreeNode * valueNode = node -> child_list -> last;
    // value to assign to all the variables
    int value = Expr_toInt(prog, valueNode);

    struct TreeNode * assigned_var = node -> child_list -> first;
    // assignment
    for (int i = 1; i < node -> child_list -> elements; i++){
      SymbolTable_AssignValue(prog, assigned_var, value);
      assigned_var = assigned_var -> next;
    }

  }
  else{
    printf("line:%d %serror%s - exec_Asgn: incorrect call\n",yylineno,ANSI_COLOR_RED,ANSI_COLOR_RESET);
    exit(EXIT_FAILURE);
  }
}

///////////////////////////  DECLARATION AND ASSIGNMENT  //////////////////////
/*
*   Given a declaration node performs the assignment
*/
void exec_DclN_Asgn (struct TreeNode * node){

  if (node -> nodeType == DclAsgn){
    // the first assignment node is the second node in the child list
    struct TreeNode * assignemnt = node -> child_list -> first -> next;

    // node -> child_list -> elements - 1 cause the first node in the list is the declaration node
    for (int i = 0; i < node -> child_list -> elements - 1; i++){

      if (i != 0) assignemnt = assignemnt -> next;
      exec_Asgn(MainNode, assignemnt);
    }
  }
  else{
    printf("%s exec_Asgn - incorrect call. DclAsgn TreeNode type expected. Type found %u.\n", ErrorMsg(), node -> nodeType);
    exit(EXIT_FAILURE);
  }

}

///////////////////////////  MULTI DECLARATION   ///////////////////////////////

void exec_Multi_DclN (struct TreeNode * node){

  Check_NodeType(MultiDc, node, "exec_Multi_DclN");
  struct TreeNode * declaration;

  for (int i = 0; i < node -> child_list -> elements; i++){
    if ( i == 0) declaration = node -> child_list -> first;
    else declaration = declaration -> next;

    if (declaration -> nodeType == DclAsgn)  exec_DclN_Asgn(declaration);
  }
}

///////////////////////////  MULTI ASSIGNMENT   ////////////////////////////////

void exec_Multi_Asgn (struct TreeNode * node){

  if (node -> nodeType == MultiAs){
    for (int i = 0; i < node -> child_list -> elements; i++){
      struct TreeNode * childNode;
      if(i == 0) childNode = node -> child_list -> first;
      else childNode = childNode -> next;

      exec_Asgn(MainNode, childNode);
    }
  }
  else{
    printf("%s exec_Multi_Asgn - unexpected Tree Node type. Expected MultiAs, found %s.\n", ErrorMsg(), NodeTypeString(node));
    exit(EXIT_FAILURE);
  }
}

///////////////////////////  WHILE LOOP   //////////////////////////////////////

void exec_while (struct TreeNode * node){

  if (node -> nodeType == While){
    struct TreeNode * condition = node -> child_list -> first -> next;
    if (condition -> nodeType == Expr){

      int condition_value = Expr_toInt(MainNode, condition);
      int index = 0;
      // todo: rimuovere il limite di 150
      while(condition_value && (index < 150)){
        // execution of the statement in the while scope
        exec_scope(node -> child_list -> first);

        // condition value update
        condition_value = Expr_toInt(MainNode, condition);

        index ++;
      }
      printf("\n%s %d WHILE eseguito con %d iterazioni!%s\n\n", ANSI_BOLD_YELLOW, yylineno, index, ANSI_COLOR_RESET);
    }
    else{
      printf("%s exec_while - unexpected condition Tree Node type. Type found %s.\n", ErrorMsg(), NodeTypeString(condition));
      exit(EXIT_FAILURE);
    }
  }
  else{
    printf("%s exec_while - unexpected Tree Node type. Expected While, found %s.\n", ErrorMsg(), NodeTypeString(node));
    exit(EXIT_FAILURE);
  }

}

///////////////////////////  IF ELSE   /////////////////////////////////////////

void exec_ifElse (struct TreeNode * node){

  Check_NodeType(IfElse, node, "exec_ifElse");

  struct TreeNode * if_node = node -> child_list -> first;
  // checking if condition and executing if scope if the condition is true
  exec_if(if_node);

  // if the if condition was false and an else statement is present
  if (if_node -> node.flag == 0 && node -> child_list -> last -> nodeType == Else)
    // execution of the statement in the else scope
    exec_scope(node -> child_list -> last -> child_list -> first);
}

void exec_if (struct TreeNode * node){
  // argument node must be an if node
  Check_NodeType(If, node, "exec_if");

  struct TreeNode * condition = node -> child_list -> first -> next;
  // condition node must bu an expression node
  Check_NodeType(Expr, condition, "exec_if");

  int condition_value = Expr_toInt(MainNode, condition);

  // if condition is true
  if (condition_value){
    // execution of the statement in the if scope
    exec_scope(node -> child_list -> first);
    // if condition flag
    node -> node.flag = 1;
  }
  // if condition is false
  else node -> node.flag = 0;
}

///////////////////////////  SCOPE   ///////////////////////////////////////////

int exec_functionScope (struct TreeNode * node){

  Check_NodeType(Scope, node, "exec_scope");
  // assign parameters

  struct TreeNode * statement;
  int value;
  // exec statements - first statement must not be executed
  for (int i = 1; i < node -> child_list -> elements; i++){

    if (i == 1) statement = node -> child_list -> first -> next;
    else statement = statement -> next;
    value = exec_statement(statement);
  }

  return value;
}

int exec_scope (struct TreeNode * node){

  Check_NodeType(Scope, node, "exec_scope");

  struct TreeNode * statement;
  for (int i = 0; i < node -> child_list -> elements; i++){

    if (i == 0) statement = node -> child_list -> first;
    else statement = statement -> next;

    exec_statement(statement);
  }

  return 1;
}

///////////////////////////  STATEMENTS   //////////////////////////////////////

int exec_statement (struct TreeNode * node){

  switch (node -> nodeType) {
    case DclN:    /* DO NOTHING */
    break;
    case ArgD:    printf("%s exec_statement - unexpected statment. Type found: %s\n", ErrorMsg(), NodeTypeString(node)); exit(EXIT_FAILURE);
    break;
    case DclAsgn: /*printf("STO ESEGUENDO: %s\n", NodeTypeString(node));*/ exec_DclN_Asgn(node);
    break;
    case Expr:    /*printf("STO ESEGUENDO: %s\n", NodeTypeString(node));*/ exec_Expression(node);
    break;
    case Asgn:    /*printf("STO ESEGUENDO: %s\n", NodeTypeString(node));*/ exec_Asgn(MainNode, node);
    break;
    case Return:  return exec_return(node);
    break;
    case ExprLst: printf("%s exec_statement - unexpected statment. Type found: %s\n", ErrorMsg(), NodeTypeString(node)); exit(EXIT_FAILURE);
    break;
    case FunCall: /* todo */
    break;
    case ArgLst:  printf("%s exec_statement - unexpected statment. Type found: %s\n", ErrorMsg(), NodeTypeString(node)); exit(EXIT_FAILURE);
    break;
    case Scope:   /*printf("STO ESEGUENDO: %s\n", NodeTypeString(node));*/ exec_scope(node);
    break;
    case If:      /*printf("STO ESEGUENDO: %s\n", NodeTypeString(node));*/ exec_ifElse(node);
    break;
    case Else:    /* todo */
    break;
    case IfElse: /*printf("STO ESEGUENDO: %s\n", NodeTypeString(node));*/ exec_ifElse(node);
    break;
    case While:   /*printf("STO ESEGUENDO: %s\n", NodeTypeString(node));*/ exec_while(node);
    break;
    case MultiDc: /*printf("STO ESEGUENDO: %s\n", NodeTypeString(node));*/ exec_Multi_DclN(node);
    break;
    case MultiAs: /*printf("STO ESEGUENDO: %s\n", NodeTypeString(node));*/ exec_Multi_Asgn(node);
    break;
    default:      printf("%s exec_statement - unexpected statment. Type found: %s\n", ErrorMsg(), NodeTypeString(node)); exit(EXIT_FAILURE);
    break;
  }

  return 1;
}













////////////////////////////////////////////////////////////////////////////////
