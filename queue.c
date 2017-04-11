/* TODO add comments */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stack.h"

int initQueue(QUEUE **q) {
	*q = (QUEUE *) malloc(sizeof(QUEUE));
	if (*q == NULL ) {
		printf("System out of memory\n");
		return EXIT_FAILURE;
	}
	(*q)->length = 0;
	(*q)->head = NULL;
	(*q)->tail = NULL;
	//printf("Init Queue\n");
	return EXIT_SUCCESS;
}

QUEUENODE * enqueue(SYMTAB *symbol, QUEUE *q) {
	if(q==NULL){
		exit(1);
	}
	QUEUENODE *p = NULL;
	p = (QUEUENODE *) malloc(sizeof(QUEUENODE));
	if (p == NULL ) {
		printf("System out of memory\n");
		return NULL;
	}
	//p->symbol = (SYMTAB*) malloc (sizeof(symbol));
	p->symbol = symbol;

	/* void array of void* for the type of each parameter in function, check if it is a function and then create the array */
	p->symbol->paramValues = (void**)malloc(sizeof(void*));

	p->next = NULL;
	if (q->length == 0) {
		q->head = q->tail = p;
		p->prev = NULL;
	} else {
		q->tail->next = p;
		p->prev = q->tail;
		q->tail = p;
	}
	(q->length)++;
	return p;
}

QUEUENODE *qLook(QUEUE *q, char *name, int type){
	if (q==NULL || name==NULL){
		return NULL;
	}
	QUEUENODE *p = NULL;

	if (q->head!=NULL)
		p = q->head;

	while(p!=NULL){
		if (strcmp(p->symbol->name, name)==0){
			switch(type){
				case 0: if (p->symbol->array == 0 && p->symbol->function == 0) return p;
				case 1: if (p->symbol->array > 0 && p->symbol->function == 0) return p;
				case 2: if (p->symbol->array == 0 && p->symbol->function == 1) return p;
				default: break;
			}
		}
		p=p->next;
	}
	
	return NULL;
}

int qLookAll(QUEUE *q, char *name, int type, char *params){

	QUEUENODE *p = NULL;

	if (q->head!=NULL)
		p = q->head;

	int i = 0;

	int insert = 0;
	while(p!=NULL){
		if (strcmp(p->symbol->name, name)==0){
			 if (p->symbol->array == 0 && p->symbol->function == 1){
					int i=0, insert = 0;
					char *t = (char*)malloc(strlen(params)*sizeof(char));
					strcpy(t, params);
					char *s = strtok(t, ","); //printf("HERE %s paramType=%d\n",s,p->symbol->paramTypes[i]);
					while (i<10 && p->symbol->paramTypes[i]!=0 && s!=NULL){
						if ((strstr(s, "int") > 0 && p->symbol->paramTypes[i]!=1) || \
						    (strstr(s, "float") > 0 && p->symbol->paramTypes[i]!=2) || \
						    (strstr(s, "void") > 0 && p->symbol->paramTypes[i]!=3)){
							insert=1;
						}
						s = strtok(NULL, ",");
						i++;
					}

					if (insert==0 && p->symbol->paramTypes[i]==0 && s==NULL) return 1;
			}
		}
		p=p->next;
	}
	
	return 0;
}

int qLookAndStackSearch(QUEUE *q, char *name, int type, char *params,STACK* st){

	QUEUENODE *p = NULL;
	QUEUENODE *varNode = NULL;

	if (q->head!=NULL)
		p = q->head;


	int i = 0;
	NODE* temp = st->head;
	int insert = 0;//printQueue(st->head->next->h);
	while(temp != NULL){
		p = temp->h->head;
		while(p != NULL){
			if (strcmp(p->symbol->name, name)==0){
				 if (p->symbol->array == 0 && p->symbol->function == 1){
						
						if ((params==NULL || strcmp(params,"")==0) && p->symbol->paramTypes[0]==0)
							return 1;
						int i=0, insert = 0;
						char *t = (char*)malloc(strlen(params)*sizeof(char));
						strcpy(t, params);
						char *s = strtok(t, ",");
						searchStack(st, s, &varNode, 0);
						while (i<10 && p->symbol->paramTypes[i]!=0 && s!=NULL){

							if (varNode->symbol->type != p->symbol->paramTypes[i]){
								insert=1;
							}
							s = strtok(NULL, ",");
							if (s!=NULL){
								searchStack( st, s, &varNode, 0);
							}
							i++;
						}
					
						if (insert==0 && p->symbol->paramTypes[i]==0 && s==NULL)
							return 1;
				}
			}
			p=p->next;
		}
		temp=temp->next;
	}
	
	return 0;

}

void printQueue(QUEUE *q){

	QUEUENODE *temp = q->head;
	//printf("%p\n",q);
	while(temp != NULL){
	
		printf("Name: %s, Type: %d, isArray: %d, isFunction: %d\n", temp->symbol->name, temp->symbol->type, temp->symbol->array, temp->symbol->function);
		if (temp->symbol->type == 1 && temp->symbol->function != 1 && temp->symbol->array == 0)
			printf("Value: %d\n",temp->symbol->i_value);
		else if (temp->symbol->type == 2 && temp->symbol->function != 1 && temp->symbol->array == 0)
			printf("Value: %f\n",temp->symbol->f_value);
		temp=temp->next;

	}

}

/*int enqueueAscending(char *str, QUEUE2 *q) {
	QUEUENODE2 *p = NULL;
	QUEUENODE2 *cur = NULL, *prev = NULL;
	cur = q->head;
	p = (QUEUENODE2 *) malloc(sizeof(QUEUENODE2));
	if (q == NULL ) {
		printf("Empty Queue\n");
		return EXIT_FAILURE;
	}
	if (p == NULL ) {
		printf("System out of memory\u2026\n");
		return EXIT_FAILURE;
	}
	p->string = (char*) malloc (strlen(str)*sizeof(char*));
	strcpy(p->string, str);
	if (q->head == NULL){
		p->next = NULL;
		q->head = p;
		q->length++;
		return EXIT_SUCCESS;
	}
	int check;
	if ((check = strcmp(p->string, q->head->string)) < 0){
		p->next = q->head;
		q->head = p;
		q->length++;
		return EXIT_SUCCESS;
	}
	while ((cur!=NULL) && ((check = strcmp(p->string, cur->string))>0)){
		prev = cur;
		cur = cur->next;
	}
	prev->next = p;
	p->next = cur;
	q->length++;

	return EXIT_SUCCESS;
}*/


/*
int dequeue(QUEUE *q, char **retstr) {
	QUEUENODE *p = NULL; // copy pointer used for free()
	if ((q == NULL )|| (q->head == NULL)){
		printf("Sorry, queue is empty \n");
		return EXIT_FAILURE;
	}
	if (retstr == NULL ) {
		printf("Retstr is null");
		return EXIT_FAILURE;
	}
	p = q->tail;
	*retstr = q->tail->string;
	q->tail = q->tail->prev;
	free(p);
	--(q->length);
	if (q->length == 0) {
		q->tail = NULL;
	}
	return EXIT_SUCCESS;
}
*/
