#ifndef STACK_H
#define STACK_H
#endif

#include <stdlib.h>
#include "queue.h"
 #include "ast.h"


/*typedef struct{
	int a;
} HASHTABLE;*/

typedef struct node{
	QUEUE* h;
	struct node* next;
	int scope;
} NODE;

typedef struct {
	NODE* head;
	int size;
} STACK;

int isEmpty(STACK* s);
STACK* initStack();
int push(QUEUE* h, STACK* s);
NODE* pop(STACK* s);
