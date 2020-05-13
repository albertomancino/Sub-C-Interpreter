enum ScopeType{
  TREE,
  FUNC
};

// SymbolTable_Node type
enum Type{
  INT_,
  CHAR_,
  INT_V_,
  CHAR_V_,
  INT_P_,
  CHAR_P_
};

union VarVal{
  int intVal;
  char charVal;
};

union VarPtr{
  int * intPtr;
  char * charPtr;
};

struct TreeNode;  // avoiding compiler warning
enum nodeType;
enum exprType;

typedef struct FunNode {

  char* funName;
  enum Type funType;
  struct FunNode * next;
  struct TreeNodeList * child_list;
  struct ScopeStack * scope_stack;
  struct TreeNode * function_scope;

} FunNode;

typedef struct FunNodeList { // List of function nodes

  int elements;
  FunNode * first;
  FunNode * last;

} FunNodeList;

typedef struct ProgramNode {
  FunNodeList * function_list;
  // Active function da valutare
  FunNodeList * active_function; // managed as a stack
  // riferimento allo scope attivo
  //struct TreeNode * actual_scope; todo: rimuovere
  struct ScopeStack * actual_stack;
  // todo: se non è possibile avere sotto-scope nello spazio globale non ha senso lo stack
  struct ScopeStack* global_scope_stack;
  // todo: potrebbe non servire più se uso il global_scope_stack
  struct TreeNode * global_scope;
  // warnings counter
  int warnings;
} ProgramNode;


////////////////////////////////////////////////////////////////////////////////
////////////////// SYMBOL TABLE STRUCTURES /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

struct SymbolTable{

  int elements;
  struct SymbolTable_Node * first;
  struct SymbolTable_Node * last;
};

struct SymbolTable_Node{

  char identifier[32];
  enum Type type; // INT_ CHAR_ INT_V_ CHAR_V_
  union VarVal varVal;
  union VarPtr varPtr;
  int arrayDim;
  char ignore;

  struct SymbolTable_Node * next;
};

////////////////////////////////////////////////////////////////////////////////
///////////////// TREE NODE USEFUL FUNCTIONS ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

char * TreeNode_Identifier(struct TreeNode *);
int Retrieve_ArrayIndex(ProgramNode *, struct TreeNode *);
int IsCostant(struct TreeNode *);
int isOperation(struct TreeNode *);
int isAssignable(struct TreeNode *);
int Multiple_Modifications(struct TreeNode *, char*);
enum Type expressionType(struct TreeNode *);
int isStringFormat(char);


// todo RIMUOVERE
struct ErrorList * Error_Set();
void Error_Add (struct ErrorList *, char *);
void PrintErrors (struct ErrorList *);
int Expr_toInt(ProgramNode *, struct TreeNode *);

////////////////////////////////////////////////////////////////////////////////
//////////////////  SYMBOL TABLE FUNCTIONS  ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

struct SymbolTable * SymbolTable_Set();
int SymbolTable_Add(struct SymbolTable *, char *, enum Type, int, char);
int SymbolTable_AddInt (struct SymbolTable *, char *, int);
void SymbolTable_Print(struct SymbolTable *);
struct SymbolTable_Node * SymbolTable_Get(struct SymbolTable *, int);
int SymbolTable_Search(struct SymbolTable *, char *);
int SymbolTable_Put(struct SymbolTable *, struct SymbolTable_Node *, int);
struct SymbolTable_Node * SymbolTable_RetrieveVar (struct ProgramNode *, char *);
struct SymbolTable_Node * SymbolTable_IterativeRetrieveVar (char *);
int Retrieve_VarValue (struct ProgramNode *, char *, int);
int Retrieve_VarPointer (char *, int);
enum Type Retrieve_VarType(struct ProgramNode * , char *);
int Retrieve_ArrayDim(struct ProgramNode *, char *);
int Check_VarWasDeclared (struct ProgramNode *, char *, int);
void SymbolTable_AssignValue (struct ProgramNode *, struct TreeNode *, int);
int IgnoreFlag(char *);
void SymbolTableCopy (struct SymbolTable *, struct SymbolTable *);

////////////////////////////////////////////////////////////////////////////////
////////////////// PROGRAM NODE FUNCTIONS //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

ProgramNode* ProgramNode_Set ();
int CheckFunAlreadyExist (ProgramNode*, char*);


////////////////////////////////////////////////////////////////////////////////
//////////////////  FUNCTION NODE AND LIST METHODS  ////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void FunNodeList_Set (ProgramNode*);
void FunNodeList_Add (ProgramNode*, struct TreeNode *);
int FunNodeList_Search (ProgramNode *, char *);
struct FunNode * FunNodeList_Get (ProgramNode *, int);
enum Type Retrive_FunType(ProgramNode *, char *);

void ActiveFunStack_Set (ProgramNode*);
void ActiveFunStack_Add (ProgramNode*, FunNode*);

////////////////////////////////////////////////////////////////////////////////
//////////////////  SCOPE STACK FUNCTIONS  /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

struct ScopeStack * ScopeStack_Set ();
/*
void ScopeStack_Add(struct ScopeStack *, struct TreeNode *, struct FunNode *);
void ScopeStack_Rem(struct ScopeStack *);
*/

void ScopeStack_Push(struct ScopeStack *, struct TreeNode *, char);
void ScopeStack_Pop(struct ScopeStack *);
struct TreeNode * ScopeStack_Peek(struct ScopeStack *);

void Add_Node_Tree (ProgramNode *, struct TreeNode *);
void SetAs_ActualScope(ProgramNode *, struct TreeNode *, char);
void Remove_ActualScope(struct ProgramNode *);
struct TreeNode * Get_ActualScope(struct ProgramNode *);
int ScopeStack_Elements();
struct Scope * Get_ActualScopeNode();

////////////////////////////////////////////////////////////////////////////////
//////////////////  TREE NODE LIST FUNCTIONS  //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

struct TreeNodeList* TreeNodeList_Set ();
void TreeNodeList_Add (struct TreeNodeList*, struct TreeNode *);
void TreeNodeList_Rem (struct TreeNodeList *);
struct TreeNode * TreeNodeList_IndexSearch (struct TreeNodeList *, int);

////////////////////////////////////////////////////////////////////////////////
//////////////////  PRINT TREE FUNCTIONS  //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void PrintTree (ProgramNode*);
void PrintTreeNode (struct TreeNodeList*);
void PrintTreeNodeType (unsigned int, struct TreeNode *);
void PrintExprType (unsigned int, struct TreeNode *);
char * PrintVarType(enum Type);
void PrintCmpType (unsigned int, struct TreeNode *);
void PrintDepth ();
void PrintTreeNodeList (struct TreeNodeList*);
char * VarTypeString(enum Type);
void PrintActualST(ProgramNode *);
char * NodeTypeString(struct TreeNode *);
char * ExprTypeString(struct TreeNode *);
char * PrintNodeType (enum nodeType);
char * PrintExpressionType (enum exprType);
char * IdentifierTypeString (enum Type);
void PrintScopeStackDimension();

////////////////////////////////////////////////////////////////////////////////
////////////////// ERROR MESSAGES //////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

char * ErrorMsg ();
char * WarnMsg ();

struct ErrorList{

  int elements;
  struct Error * first;
  struct Error * last;
};

struct Error{

  char* errorMsg;
  struct Error * next;

};
