#include <stdio.h>
#include "stack.h"

int isEmpty(STACK* s){

	if (s==NULL || s->head==NULL)
		return 1;
	return 0;

}

STACK* initStack(){
	
	STACK* s = (STACK*)malloc(sizeof(STACK));
	
	if (s == NULL)
		return NULL;
	
	s->head = NULL;
	s->size = 0;
	//printf("Stack\n");
	return s;

}

int push(QUEUE* h, STACK* s){

	NODE* p = NULL;
	p = (NODE*)malloc(sizeof(NODE));
	if (p == NULL){
		return 0;
	}
	p->h = h;
	p->next = NULL;
	/* Add the scope which the queue represents */
	p->scope = s->size;
	
	/*First element*/
	if (s->head == NULL){
		s->head = p;
	}
	else{
		/*Get to top and add p*/		
		p->next = s->head;
		s->head = p;
		/* TODO na mpei kwdikas pou na enwnei tin proigoumeni oura me auti pou einai sto top */
	}
	(s->size)++;
	//printf("push\n");
	return 1;
	
}

NODE* pop(STACK* s){

	//printQueue(s->head->h);
	NODE* p = NULL;
	if (s->head == NULL)
		return NULL;

	p = s->head;
	s->head = p->next;
	(s->size)--;
	//printf("pop\n");
	// TODO free(p) sto main program

	return p;

}

void searchStack(STACK* s, char* name, QUEUENODE **retVal, int type){	//type=0 var, type=1 array, type=2 function

	NODE *cur = s->head;
	QUEUENODE *t = NULL;

	while (cur != NULL){
		if (cur->h != NULL)
			t=qLook(cur->h, name, type);
		if (t != NULL){
			*retVal=t;
			return;
		}
		else
			cur=cur->next;
	}
	retVal = NULL;
	return;

}
