int yylineno;

enum nodeType {
  Ukn,            // 0 uknown node, not defined yet
  DclN,           // 1 Declaration
  ArgD,           // 2 Arguments Declaration
  DclAsgn,        // 3 Declaration and Assignment
  Expr,           // 4 Expr
  Asgn,           // 5 Assignment
  Return,         // 6 Return
  ExprLst,        // 7 Expr List
  FunCall,        // 8 Function Call
  ArgLst,         // 9 Arguments List
  Scope,          // 10 Scope Node
  If,             // 11 If Node
  Else,           // 12 Else
  IfElse,         // 13 If Else
  While,          // 14 While
  MultiDc,        // 15 Multi Declaration
  MultiAs         // 16 Multi Assignment

};

enum exprType {
  NUM,            // 0 Integer
  ID,             // 1 Identifier
  VEC,            // 2 Array
  STR,            // 3 String
  C,              // 4 Char
  FC,             // 5 Function Call
  SUM,            // 6 Sum
  DIF,            // 7 Subtraction
  TIM,            // 8 Multiplication
  DIV,            // 9 Division
  MOD,            // 10 Modulo
  RND,            // 11 Round Parentheses
  CMP,            // 12 Comparison
  PI,             // 13 Pre Increment
  PD,             // 14 Pre Decrement
  IP,             // 15 Post Decrement
  DP,             // 16 Post Decrement
  PA              // 17 Parathesis Assignment
};

enum cmpType{
  AND_,
  OR_,
  GREAT_,
  LESS_,
  EQUAL_,
  DIFF_
};





struct TreeNode * create_DeclarationNode              (enum Type, struct TreeNode *);
struct TreeNode * create_ScopeNode                    ();
struct TreeNode * create_ExprNode                     (enum exprType, long, char *, struct TreeNode *, struct TreeNode *, enum cmpType);
struct TreeNode * create_MultiAssignment              (struct TreeNode *, struct TreeNode *);
struct TreeNode * create_MultiDeclaration             (struct TreeNode *, struct TreeNode *, char);
struct TreeNode * create_Declaration_AssignmentNode   (struct TreeNode *, struct TreeNode *);
struct TreeNode * create_AssignmentNode               (struct ProgramNode *, struct TreeNode *, struct TreeNode *);
struct TreeNode * create_ReturnNode                   (struct TreeNode *);
struct TreeNode * create_Expr_ListNode                (struct TreeNode *, struct TreeNode *);
struct TreeNode * create_Arg_ListNode                 (struct TreeNode *, struct TreeNode *);
struct TreeNode * create_Function_CallNode            (ProgramNode * , char *, struct TreeNode *);
struct TreeNode * create_OperationNode                (ProgramNode *, struct TreeNode *, struct TreeNode *, enum exprType);
struct TreeNode * create_ComparisonNode               (ProgramNode *, struct TreeNode *, struct TreeNode *, enum cmpType);
struct TreeNode * create_IncDecNode                   (enum exprType, struct TreeNode *);
struct TreeNode * create_IfElseNode                   (struct TreeNode *, struct TreeNode *);
struct TreeNode * create_ElseNode                     (struct TreeNode *);
struct TreeNode * create_ElseDeclaration              ();
struct TreeNode * create_IfDeclaration                ();
struct TreeNode * create_IfNode                       (struct TreeNode *, struct TreeNode *);
struct TreeNode * create_WhileNode                    (struct TreeNode *, struct TreeNode *);
struct TreeNode * create_Condition                    (struct TreeNode *);
struct TreeNode * create_WhileDeclaration             ();
struct TreeNode * TreeNodeInitialization              ();
void create_FunctionNode                              (struct TreeNode *, struct TreeNode *);
void create_GlobalDeclarationNode                     (ProgramNode *, struct TreeNode *);
void create_MainFunction                              (struct ProgramNode *, struct TreeNode *);
void Check_ExprConcistency                            (ProgramNode *, struct TreeNode *);
void Check_CharConcistency                            (int);
void Check_IdentifierConcistency                      (ProgramNode *, struct TreeNode *);
void Check_ArrayConcistency                           (ProgramNode *, struct TreeNode *);
void Check_FunctionCallConcistency                    (ProgramNode *, struct TreeNode *);
void Check_PrintfCallConcistency                      (struct TreeNode *);
void Check_OperationConcistency                       (ProgramNode *, struct TreeNode *);
void Check_ComparisonConcistency                      (ProgramNode *, struct TreeNode *);
void Check_AsgnConcistency                            (struct ProgramNode *, struct TreeNode *, struct TreeNode *);
void Check_DeclConcistency                            (struct TreeNode *);
int Check_ArrayDimension                              (struct TreeNode *);
void Check_NodeType                                   (enum nodeType, struct TreeNode *, char *);
void Check_ExprType                                   (enum exprType, struct TreeNode *, char *);
void Check_FunctionParameters                         (struct TreeNode *);
void CheckParameterAssignment                         (struct TreeNode * , struct TreeNode * );
int Check_Main                                        ();
char Check_activation                                 ();
void Scope_Activation                                 ();


////////////////////////////////////////////////////////////////////////////////
//////////////////  NODES STRUCTURES  //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

//  todo remove
/*struct funCall{
  char identifier[1023];
};*/

struct exprNode {

  enum exprType exprType;
  char known;

  union exprVal{
    int intExpr;
    char charExpr;
    char * stringExpr;
    enum cmpType cmpExpr;
  } exprVal;
};

struct DeclarationNode {
  char * identifier;
  enum Type type;
  struct TreeNode * arrayDim;
  char ignore;
};

struct ArgumentsDeclaration {

  struct DeclarationNode * identifier;
};


////////////////////////////////////////////////////////////////////////////////
//////////////////  TREE NODE AND LIST  ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

struct TreeNode{

  enum nodeType nodeType;

  union node{
    struct DeclarationNode * DclN;
    struct ArgumentsDeclaration * ArgD;
    struct exprNode * Expr;
    struct funCall * FunCall;
    struct SymbolTable * ST;
           int flag;
  } node;

  struct TreeNode * next;
  struct TreeNodeList * child_list;

};

struct TreeNodeList{

  int elements;
  struct TreeNode * first;
  struct TreeNode * last;

};


struct Scope{
  struct TreeNode * thisScope;
  struct Scope * prevScope;
  char active;
};

struct ScopeStack{
  int elements;
  struct Scope *top;
};
