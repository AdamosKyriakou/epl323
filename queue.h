/* TODO add comments */

#ifndef QUEUE_H_
#define QUEUE_H_
#endif

typedef struct symtab {
  char *name;
  int type; // 1=int, 2=float, 3=void
  int array; //0=not an array, size=is an array
  int function; // 0=not a function, 1= is a function
  //char *paramNames[10]; 
  void **paramValues;
  int i_value;
  float f_value;
  int paramTypes[10];
} SYMTAB;

typedef struct queueNode {
	struct queueNode *prev;
	SYMTAB *symbol;
	struct queueNode *next;
} QUEUENODE;

typedef struct queue {
	int length;
	QUEUENODE *head;
	QUEUENODE *tail;
} QUEUE;


//struct symtab * symlook(char *s); 
int initQueue(QUEUE **q);

/* 
	int check = initQueue(&q);
	if (check) {
		return EXIT_FAILURE;
	}
*/

QUEUENODE *enqueue(SYMTAB *symbol, QUEUE *q);
QUEUENODE *qLook(QUEUE *q, char *name, int type);
int qLookAll(QUEUE *q, char *name, int type,char *params);
void printQueue(QUEUE *q);
