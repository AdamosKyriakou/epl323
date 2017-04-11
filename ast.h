#include <stdlib.h>

#define MAXCHILDREN 2
typedef enum {STMT, EXPRESSION} NodeKind;

typedef enum {COMPOUND_STMT, EXPRESSION_STMT } StmtKind;

typedef enum {VAR_EXP, ASSI_EXP, ADD_EXP, SUB_EXP, MULT_EXP, DIV_EXP,
              GT_EXP, LT_EXP, GE_EXP, LE_EXP, EQ_EXP, NE_EXP, CALL_EXP, CONST_EXP, ID_EXP} ExpKind;

   
typedef struct tnode {
    NodeKind nKind;
    union{
        StmtKind sKind;
        ExpKind  eKind;
    }esKind;
    struct tnode *children[MAXCHILDREN];
    float value;
    char *type;
    int lineNumber;
}astNode;

typedef struct tnode * astNodePtr;
static int tmp_counter=0;
astNodePtr newExprNode(ExpKind kind, int line);
astNodePtr newStmtNode(StmtKind kind, int line);
void print_node(astNodePtr node);
