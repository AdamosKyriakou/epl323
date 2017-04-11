#include "ast.h"
#include <stdio.h>
//creates a new expression node
astNodePtr  newExprNode(ExpKind kind,int line) 
{
	astNodePtr expr_node = (astNodePtr)(malloc(sizeof(astNode)));
	expr_node->type = (char*)malloc(100);
	expr_node->nKind = EXPRESSION;
    expr_node->esKind.eKind = kind;
	/* Init all Children */
    int i;	
	for(i=0;i<MAXCHILDREN;i++){
		expr_node->children[i]=(astNodePtr)malloc(sizeof(astNode));
	}

	expr_node->lineNumber = line;

	return expr_node;
}

//creates a new statement node
astNodePtr newStmtNode(StmtKind kind, int line)
{
	astNodePtr stmt_node = (astNodePtr)(malloc(sizeof(astNode)));
	stmt_node->nKind = STMT;
    stmt_node->esKind.sKind = kind;
    /* Init all Children */
	int i;
	for(i=0;i<MAXCHILDREN;i++)
               	stmt_node->children[i]=NULL;
	
	stmt_node->lineNumber = line;

        return stmt_node;
}

void print_node(astNodePtr node){
    if (node->nKind == EXPRESSION){
        switch(node->esKind.eKind){
            case CONST_EXP: 
		//printf("(");
                printf("%5.2f",node->value);
		//printf(")[%5.2f]",node->value);
                break;
            case ID_EXP: 
		//printf("(");
                printf("%5.2f",node->value);
		//printf(")[%5.2f]",node->value);
                break;
            case MULT_EXP: 
		printf("(");
                /*printf("MULT_EXP %d\n",node->value);*/
                print_node(node->children[0]);
                printf("*");
                print_node(node->children[1]);
		printf("[%5.2f])",node->value);
                break;
            case DIV_EXP: 
		printf("(");
                /*printf("DIV_EXP %d\n",node->value);*/
                print_node(node->children[0]);
                printf("/");
                print_node(node->children[1]);
		printf("[%5.2f])",node->value);
                break;
            case ADD_EXP: 
		printf("(");
               /* printf("ADD_EXP %d\n",node->value);*/
                print_node(node->children[0]);
                printf("+");
                print_node(node->children[1]);
		printf("[%5.2f])",node->value);
                break;
             case SUB_EXP: 
		printf("(");
                /*printf("SUB_EXP %d\n",node->value);*/
                print_node(node->children[0]);
                printf("-");
                print_node(node->children[1]);
		printf("[%5.2f])",node->value);
                break;
            default:
                printf("OTHER %d\n",node);    
        }
    }else if (node->nKind == STMT){
        switch(node->esKind.sKind){
            case EXPRESSION_STMT:
		node->value = node->children[1]->value; 
                printf("\nEXPRESSION_STMT = ");
		printf("(%5.2f)",node->value);
                print_node(node->children[0]);
                print_node(node->children[1]);
                break;
            default:
                printf("OTHER %d\n",node);    
        }

    }
}
