


enum Type ExprNode_valueType  (ProgramNode *, struct TreeNode *);

int exec_IncDec               (struct TreeNode *);
int CMP_node_logicValue       (ProgramNode *, struct TreeNode *);

void exec_Expression          (struct TreeNode *);
void exec_DclN                (ProgramNode *, struct TreeNode *);
void exec_Asgn                (ProgramNode *, struct TreeNode *);
void exec_DclN_Asgn           (struct TreeNode *);
void exec_Multi_DclN          (struct TreeNode *);
void exec_Multi_Asgn          (struct TreeNode *);
int exec_CMP                  (struct TreeNode *);
int exec_Operation            (struct TreeNode *);
void exec_while               (struct TreeNode *);
void exec_if                  (struct TreeNode *);
void exec_scope               (struct TreeNode *);
void exec_statement           (struct TreeNode *);

int exec_arrayDim             (ProgramNode *, struct TreeNode *);
