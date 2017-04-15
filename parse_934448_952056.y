/****************************************************************/
/* Part A - Compiler       					*/
/* Adamos Kyriakou 934448   					*/
/* Theocharis Psalios 952056 					*/
/*								*/
/* How to compile:						*/
/* bison -d parse_934448_952056.y				*/
/* flex parse_934448_952056.fl					*/
/* gcc parse_934448_952056.tab.c lex.yy.c -lfl -o parse.out	*/
/****************************************************************/

%{
 /* C declarations used in action */
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "stack.h"
// #include "queue.h"
 extern char* yytext; /* using flex */
 extern int yylineno;
 #define YYDEBUG_LEXER_TEXT yytext
 
 char* errorStr = "", *parameters, *funName = NULL;
 STACK *s=NULL;
 int isCompound = 0, isNum = 0, isFloat = 0, isLeft=0; //Used to find blocks inside functions
 int isArray=0;
 int flag=1, expType = -1, termType = -1;
 int argsList[10], argsCounter = 0;
 QUEUENODE *f = NULL, *g=NULL;
 QUEUENODE **t;

 void myError (char *errorStr);
 void pushQueue();
 void pushQueue1();
 int containsNumber(char *string);
 QUEUENODE * insertInQueue(char* ret, char* two, int isFunction, int isArray);
%}
%union {
	int a_number;
	char* str;
	float f_number;
}

%error-verbose

%start program
%token <a_number> NUM
%token <f_number> FLOAT_NUM
%token <str> ELSE IF INT VOID RETURN WHILE GTOE LTOE EQUAL NEQUAL PP PE MM ME ID NO_ELSE FOR FLOAT 
%type <str> program declaration_list declaration var_declaration fun_declaration type_specifier params param_list param compound_stmt local_declarations statement_list statement expression_stmt selection_stmt iteration_stmt return_stmt expression var simple_expression additive_expression relop addop term mulop factor call args arg_list doubleAddSub
%nonassoc NO_ELSE
%nonassoc ELSE
%%
program: declaration_list						{printf("Pop Final\n");pop(s); isCompound=0;}
;
declaration_list: declaration_list declaration				{/*printQueue(s->head->h);*/}
  | declaration								{}
;
declaration: var_declaration						{}
  | fun_declaration							{printf("Pop in Function \n");pop(s); isCompound=0;}
;
var_declaration: type_specifier ID ';'					{
										if (qLook(s->head->h,$2,0) == NULL)
											insertInQueue($$, $2, 0, 0);
										else{
											errorStr = (char*)malloc(strlen("Variable ")*sizeof(char));
											strcat(errorStr,"Variable ");
											strcat(errorStr,$2);
											strcat(errorStr," is already declared");
											myError(errorStr);
											errorStr=NULL;
										}
										
									}
  | type_specifier ID '[' NUM ']' ';'					{ 
										if (qLook(s->head->h,$2,1) == NULL)
											insertInQueue($$, $2, 0, $4);
										else{
											errorStr = (char*)malloc(strlen("Array ")*sizeof(char));
											strcat(errorStr,"Array ");
											strcat(errorStr,$2);
											strcat(errorStr," is already declared");
											myError(errorStr);
										}
										isNum=0;
										//TODO: create array to store the values
										//TODO: check for duplicate function opos to proigoumeno kodika
									}
  | error ID '[' NUM ']' ';'						{yyerrok;}
  | error ID ';'							{yyerrok;}
  | type_specifier error ';'         					{yyerrok;} 
;
type_specifier: INT							{
										$$ = (char*) malloc (strlen("int")*sizeof(char));
										strcpy($$, "int");
									}
  | VOID								{
										$$ = (char*) malloc (strlen("void")*sizeof(char));
										strcpy($$, "void");
									}
  | FLOAT								{
										$$ = (char*) malloc (strlen("float")*sizeof(char));
										strcpy($$, "float");
									}
;
fun_declaration: type_specifier ID '('{
					funName = (char*)malloc(strlen($2));
					strcpy(funName, $2);
					f=qLook(s->head->h,$2,2); 
					//printf("\nscope:%d\n",s->head->scope);
					/*flag = 1;	
					if ((f=qLook(s->head->h,$2,2)) != NULL){
						flag=1;
						switch (f->symbol->type){
							case 1: { flag=strcmp("int", $1); break;}
							case 2: { flag=strcmp("float", $1); break;}
							case 3: { flag=strcmp("void", $1); break;}						
						}
					} 
					printf("flag:%d",flag);*/
 					g=insertInQueue($1, $2, 1, 0); pushQueue(); printf("\nPush in Function\n");
					isCompound=1;
				//}
				       } params ')' compound_stmt {
										
								    }
//  | type_specifier ID '(' error ')' compound_stmt			{yyerrok;}
  | error ID '(' params ')' compound_stmt				{yyerrok;} 
  | error type_specifier ID '(' params ')' compound_stmt		{yyerrok;} 
  | type_specifier error '(' params ')' compound_stmt			{yyerrok;}
//  | type_specifier ID '(' params ')' error				{yyerrok;}
;
params: param_list							{
										$$= (char*) malloc ((strlen($1))*sizeof(char)); strcpy($$,$1); printf("Params:%s\n",$$);
										char *temp = (char*) malloc (strlen($1)*sizeof(char)); strcpy(temp,$1);

										int insert = qLookAll(s->head->next->h,funName,2,temp);

										/*if (flag == 0){	
											int i=0;
											char *p = strtok(temp, ",");
											while (i<10 && f->symbol->paramTypes[i]!=0 && p!=NULL){
												if ((strstr(p, "int ") != NULL && f->symbol->paramTypes[i]!=1)||
												    (strstr(p, "float ") != NULL && f->symbol->paramTypes[i]!=2)||
												    (strstr(p, "void ") != NULL && f->symbol->paramTypes[i]!=3)){
													insert=1;
												}
												p = strtok(NULL, ",");
												i++;
											}
											
											if (insert==0 && f->symbol->paramTypes[i]==0 && p==NULL){
												errorStr = (char*)malloc(strlen("Function ")*sizeof(char));
												strcat(errorStr,"Function ");
												strcat(errorStr,f->symbol->name);
												strcat(errorStr," is already declared");
												myError(errorStr);
											} else{
												insert=0;
											}
											flag=2;
										}*/
		
										if (insert == 1){
											errorStr = (char*)malloc(strlen("Function ")*sizeof(char));
											strcat(errorStr,"Function ");
											strcat(errorStr,f->symbol->name);
											strcat(errorStr," is already declared");
											myError(errorStr);
										}

										strcpy(temp,$1);
										char *p = strtok(temp, ",");
										int i = 0;

										while (p!=NULL){
											if (strstr(p, "int ") != NULL) {g->symbol->paramTypes[i]=1;}
											else if (strstr(p, "float ") != NULL) {g->symbol->paramTypes[i]=2;}
											else if (strstr(p, "void ") != NULL) {g->symbol->paramTypes[i]=3;}
												
											p = strtok(NULL, ",");
											i++;
										}

										//int i = 0;
										/*for (i=0; i<10; i++)
											printf("G: %d\n",g->symbol->paramTypes[i]);*/

									}
  | VOID								{
										if (flag==0 && (f->symbol->paramTypes[0])==0){
											errorStr = (char*)malloc(strlen("Function ")*sizeof(char));
											strcat(errorStr,"Function ");
											strcat(errorStr,f->symbol->name);
											strcat(errorStr," is already declared");
											myError(errorStr);
											flag=2;
										}
										else{
											$$ = (char*) malloc (strlen("void")*sizeof(char));
											strcpy($$, "void");
										}
									}
  | 									{yyerror("No parameters given:");}
;
param_list: param_list ',' param					{$$= (char*) malloc ((strlen($3)+2+strlen($1))*sizeof(char)); strcpy($$,$1);strcat($$,",");  strcat($$,$3); }
  | param								{$$= (char*) malloc (strlen($1)*sizeof(char)); strcpy($$,$1);}
  | error ',' error							{yyerrok;}
  | error ',' param							{yyerrok;}
  | param_list ',' error						{yyerrok;}
;
param: type_specifier ID						{
										strcat($$," ");
										strcat($$,$2);
										insertInQueue(strtok($1," "), $2, 0, 0); // Enqueue parameter
									}
  | type_specifier ID '[' ']'						{
										strcat($$," ");
										strcat($$,$2);
										strcat($$,"[]");
										//$$= (char*) malloc ((strlen($1)+strlen($2)+1)*sizeof(char)); strcpy($$,$1);strcat($$," ");strcat($$,$2);
										insertInQueue(strtok($1," "), $2, 0, 1); // Enqueue array parameter
									}
  | error ID '[' ']'							{yyerrok;}
  | error type_specifier ID						{yyerrok;}
  | type_specifier error 						{yyerrok;}
;
compound_stmt: '{' local_declarations statement_list '}'		{}	
  | '{' local_declarations error '}'					{yyerrok;}
;
local_declarations: 							{/*empty*/}
  | local_declarations var_declaration					{}
;
statement_list:  							{/*empty*/}
  | statement_list statement						{}
;
statement: expression_stmt						{}
  | { if (isCompound != 1){ pushQueue(); printf("Push in Compound\n"); isCompound=2;  }} compound_stmt	{
														if (isCompound == 2){
															pop(s); printf("Pop in Compound\n"); 
															isCompound=2;
														} 
													}
  | {pushQueue(); printf("Push in If/Else\n"); isCompound=1;} selection_stmt				{pop(s); printf("Pop in If/Else\n");isCompound=0;}
  | {pushQueue(); printf("Push in Iteration\n"); isCompound=1; printf("GOT IN FOR\n");}iteration_stmt				{pop(s); printf("Pop in Iteration\n");isCompound=0;}
  | return_stmt								{}
;
expression_stmt: expression ';'						{/*$$= (char*) malloc (strlen($1)*sizeof(char)); strcpy($$,$1); strcat($$,";");*/}
  | ';'									{/*$$= (char*) malloc (strlen(";")*sizeof(char)); strcpy($$,";");*/}
  | expression error							{yyerrok;}
;
selection_stmt: IF'('expression')' statement %prec NO_ELSE		{
												//pushQueue(); printf("Push in If\n");
									}
  | IF'('expression')' statement ELSE {pop(s); printf("Pop in If\n"); pushQueue(); printf("Push in Else\n");} statement				{
										//pushQueue(); printf("Push in If2\n");
									}
  | IF'('error')'statement %prec NO_ELSE				{yyerrok;}
  | IF'('error')'statement ELSE statement				{yyerrok;}
;
iteration_stmt: WHILE '(' expression ')'{isCompound=1;} statement	{	
										//pushQueue(); printf("Push in Iteration\n");
									}
  | WHILE '(' error ')' statement					{yyerrok;}
  | FOR '(' expression ';' expression ';' expression ')' {isCompound=1;} statement      {}
  | FOR '(' error ';' expression ';' expression ')' statement    	{yyerrok;}
  | FOR '(' expression ';' error ';' expression ')' statement      	{yyerrok;}
  | FOR '(' expression ';' expression ';' error ')' statement      	{yyerrok;}
  | FOR '('')'								{yyerrok;}
;
return_stmt: RETURN ';'							{}
  | RETURN expression ';'						{}
  | RETURN error							{yyerrok;}
;
expression: var '=' expression						{ 
										/*$$= (char*) malloc (strlen($1)*sizeof(char)); 
										strcpy($$,$1);
										strcat($$,"=");
										strcat($$,$3);*/
										QUEUENODE *temp = NULL;
										char *string = (char*)malloc(strlen($3));
										strcpy(string,$3);
										if (isArray==0){
									  		searchStack(s,$1, &temp,0);
										}
										else{
											char *str = (char*)malloc(strlen($1)*sizeof(char));
											strcpy(str,$1);
									  		searchStack(s,strtok(str,"["), &temp,1);
											isArray=0;
										}
										//printf("$$: %s N: %d F: %d TEMP: %p\n",$3,isNum,isFloat,temp);
										/*If expression is a number check if the type matches var type*/
										if (isNum == 1 && temp->symbol->type != 1){
											errorStr = (char*)malloc(strlen("assignment of int to float ")*sizeof(char));
											strcat(errorStr,"Assignment of int to float ");
											myError(errorStr);
											errorStr=NULL;
										}
										else if (isFloat == 1 && temp->symbol->type != 2){
											errorStr = (char*)malloc(strlen("assignment of float to int ")*sizeof(char));
											strcat(errorStr,"Assignment of float to int ");
											myError(errorStr);
											errorStr=NULL;
										}
										/*If expression does contain number then check if the type matches var*/
										else if (strstr(string," ") == NULL && strstr(string,"-") == NULL && strstr(string,"+") == NULL && strstr(string,"*") == NULL && strstr(string,"/") == NULL){
											//printf("HERERERERERERERERERERERERERERE: %s\n",string);					
											if (containsNumber(string) == 1 || strstr(string, ".") != NULL){ // only one number	
												if (strlen(string) == 1){
													if (temp != NULL && temp->symbol->type != 1){
														//printf("NUM123: %s temp: %d\n",string,temp->symbol->type);
														errorStr = (char*)malloc(strlen("assignment of float to int ")*sizeof(char));
														strcat(errorStr,"Assignment of float to int ");
														myError(errorStr);
														errorStr=NULL;												
													}
												}
												else{
													if (temp != NULL && temp->symbol->type != 2){
														//printf("NUM: %s temp: %d\n",string,temp->symbol->type);
														errorStr = (char*)malloc(strlen("assignment of int to float ")*sizeof(char));
														strcat(errorStr,"Assignment of int to float ");
														myError(errorStr);
														errorStr=NULL;
													}
												}
													
											}
											else{  // only one var
											}
										}								
										expType = -1; termType = -1;
									}
  | var '=' '-' expression						{
										QUEUENODE *temp = NULL;
										char *string = (char*)malloc(strlen($4));
										strcpy(string,$4);
										if (isArray==0){
									  		searchStack(s,$1, &temp,0);
										}
										else{
											char *str = (char*)malloc(strlen($1)*sizeof(char));
											strcpy(str,$1);
									  		searchStack(s,strtok(str,"["), &temp,1);
											isArray=0;
										}
										//printf("$$: %s N: %d F: %d TEMP: %p\n",$3,isNum,isFloat,temp);
										/*If expression is a number check if the type matches var type*/
										if (isNum == 1 && temp->symbol->type != 1){
											errorStr = (char*)malloc(strlen("assignment of int to float ")*sizeof(char));
											strcat(errorStr,"Assignment of int to float ");
											myError(errorStr);
											errorStr=NULL;
										}
										else if (isFloat == 1 && temp->symbol->type != 2){
											errorStr = (char*)malloc(strlen("assignment of float to int ")*sizeof(char));
											strcat(errorStr,"Assignment of float to int ");
											myError(errorStr);
											errorStr=NULL;
										}
										/*If expression does contain number then check if the type matches var*/
										else if (strstr(string," ") == NULL && strstr(string,"-") == NULL && strstr(string,"+") == NULL && strstr(string,"*") == NULL && strstr(string,"/") == NULL){
											//printf("HERERERERERERERERERERERERERERE: %s\n",string);					
											if (containsNumber(string) == 1 || strstr(string, ".") != NULL){ // only one number	
												if (strlen(string) == 1){
													if (temp != NULL && temp->symbol->type != 1){
														//printf("NUM123: %s temp: %d\n",string,temp->symbol->type);
														errorStr = (char*)malloc(strlen("assignment of float to int ")*sizeof(char));
														strcat(errorStr,"Assignment of float to int ");
														myError(errorStr);
														errorStr=NULL;												
													}
												}
												else{
													if (temp != NULL && temp->symbol->type != 2){
														//printf("NUM: %s temp: %d\n",string,temp->symbol->type);
														errorStr = (char*)malloc(strlen("assignment of int to float ")*sizeof(char));
														strcat(errorStr,"Assignment of int to float ");
														myError(errorStr);
														errorStr=NULL;
													}
												}
													
											}
											else{  // only one var
											}
										}								
										expType = -1; termType = -1;

									}
  | var '=' error expression						{yyerrok;}
  | simple_expression							{isNum = 0; isFloat=0; /*printf("SIMPLE: %s\n",$$);*/}
;
var: ID									{
										$$ = (char*) malloc (strlen($1)*sizeof(char));
										strcpy($$, $1);

										char *str = (char*)malloc(strlen($1));
										strcpy(str,$1);
										QUEUENODE *temp = NULL;
									  	searchStack(s,str, &temp, 0);
										

										if (temp==NULL){
											errorStr = (char*)malloc(strlen("variable ")*sizeof(char));
											strcat(errorStr,"Variable ");
											strcat(errorStr,$$);
											strcat(errorStr," is not declared");
											myError(errorStr);
											errorStr=NULL;
									  	}

									}
  | ID'['expression']'							{ 
										
										$$ = (char*) malloc (strlen($1)*sizeof(char));
										strcpy($$, $1);
										strcat($$,"[");
										/*if (isNum == 1){printf("IAM HERE %d\n",$3);										
											char *s = (char*)malloc(sizeof(char)*5);
											sprintf(s,"%d",$3);
											strcat($$,s);
											isNum=0;
										}
										else 
											strcat($$,$3);*/
										strcat($$,"]");
										char *str = (char*)malloc(strlen($1));
										strcpy(str,$1);
										QUEUENODE *temp = NULL;
									  	searchStack(s,str, &temp, 1);
										
										isArray=1;

										if (temp==NULL){
											errorStr = (char*)malloc(strlen("array ")*sizeof(char));
											strcat(errorStr,"Array ");
											strcat(errorStr,$$);
											strcat(errorStr," is not declared");
											myError(errorStr);
											errorStr=NULL;
									  	}
											
									}
;
simple_expression: additive_expression relop additive_expression	{
										
									}
  | additive_expression							{
									
									}
;
relop: GTOE								{/*$$ = (char*) malloc (strlen(">=")*sizeof(char)); strcpy($$, ">=");*/}
  | LTOE								{/*$$ = (char*) malloc (strlen("<=")*sizeof(char)); strcpy($$, "<=");*/}
  | EQUAL								{/*$$ = (char*) malloc (strlen("==")*sizeof(char)); strcpy($$, "==");*/}
  | NEQUAL								{/*$$ = (char*) malloc (strlen("!=")*sizeof(char)); strcpy($$, "!=");*/}
  | '<'									{/*$$ = (char*) malloc (strlen("<")*sizeof(char)); strcpy($$, "<");*/}
  | '>'									{/*$$ = (char*) malloc (strlen(">")*sizeof(char)); strcpy($$, ">");*/}
;
additive_expression: additive_expression addop term			{
										/*printf("ADDITIVE:%s ADDOP:%s TERM:%s\n",$1,$2,$3);
										printf("isNum=%d, isFloat=%d\n",isNum, isFloat);
										printf("termType=%d, expType=%d\n",termType, expType);*/

										char* temp = (char*)malloc(strlen($1));
										strcpy(temp,$1);

										f=NULL;
										searchStack(s, $1, &f, 0);
										if (f == NULL && strstr($1,"[") != NULL)
											searchStack(s, strtok(temp,"["), &f, 1);
										if (f == NULL)
											searchStack(s, $1, &f, 2);

										temp = (char*)malloc(strlen($3));
										strcpy(temp,$3);

										g=NULL;
										searchStack(s, $3, &g, 0);
										if (g == NULL && strstr($3,"[") != NULL)
											searchStack(s, strtok(temp,"["), &g, 1);
										if (g == NULL)
											searchStack(s, $3, &g, 2);
/*
									if (f!=NULL)	
										printf("F:%p, G:%p, isNum:%d, isFloat:%d Type:%d\n",f,g,isNum,isFloat,f->symbol->type);*/

										/*Check for type for var, array, function*/
										int type = -1;
										if (isNum == 1 && isFloat == 1){
											errorStr = (char*)malloc(strlen("Operation between different types ")*sizeof(char));
											strcat(errorStr,"Operation between different types ");
											myError(errorStr);
											errorStr=NULL;
										}
										else if (f!=NULL && g!= NULL && f->symbol->type != g->symbol->type){
											errorStr = (char*)malloc(strlen("Operation between different types ")*sizeof(char));
											strcat(errorStr,"Operation between different types ");
											myError(errorStr);
											errorStr=NULL;
										}

										/*Check for var, array, function and integer*/
										else if ((f!=NULL && (f->symbol->type == 1) && (isNum != 1)) || (g!=NULL && (g->symbol->type == 1) && (isNum != 1))){
											errorStr = (char*)malloc(strlen("Operation between different types ")*sizeof(char));
											strcat(errorStr,"Operation between different types ");
											myError(errorStr);
											errorStr=NULL;
										}
										else if ((f!=NULL && (f->symbol->type == 2) && (isFloat != 1)) || (g!=NULL && (g->symbol->type == 2) && (isFloat != 1))){
											errorStr = (char*)malloc(strlen("Operation between different types ")*sizeof(char));
											strcat(errorStr,"Operation between different types ");
											myError(errorStr);
											errorStr=NULL;
										}
	
										/*Return the type of the expression*/
										if (isNum == 1)
											$$ = "int";
										else if (isFloat == 1)
											$$ = "float";
										else if (f !=NULL){
											switch(f->symbol->type){
												case 1: { $$ = "int"; break;}
												case 2: { $$ = "float"; break;}
												case 3: { $$ = "void"; break;}
											}
										}
										/*If the computation is correct put type in global var*/
										/*if (f != NULL)
											expType = f->symbol->type;
										else {
											if (g != NULL)
												expType = g->symbol->type;
											else
												expType = -1;
										}*/
										/*astNode* exp = newExprNode(ADD_EXP,yylineno);
										exp->children[0]->type=$1;
										exp->children[1]->type=$3;
										printf("COMPARE: %d",strcmp($1,$3));
										printf("\n");*/
									}
  | term								{
										$$ = (char*) malloc (strlen($1)*sizeof(char)); strcpy($$, $1);
									}
  | term doubleAddSub							{
										printf("TERM: %s DOUBLEADD: %s\n",$1,$2);
									}
;
addop: '+'								{$$ = (char*) malloc (strlen("+")*sizeof(char)); strcpy($$, "+");}
  | '-'									{$$ = (char*) malloc (strlen("-")*sizeof(char)); strcpy($$, "-");}
;
doubleAddSub: PP							{/*$$ = (char*) malloc (strlen("++")*sizeof(char)); strcpy($$, "++");*/}
  | PE term								{/*
										$$ = (char*) malloc (strlen("+=")*sizeof(char));
										strcpy($$, "+=");
										strcat($$, $2);
									*/}
  | MM									{/*$$ = (char*) malloc (strlen("--")*sizeof(char)); strcpy($$, "--");*/}
  | ME term								{/*
										$$ = (char*) malloc (strlen("-=")*sizeof(char));
										strcpy($$, "-=");
										strcat($$, $2);
									*/}
;
term: term mulop factor							{
										/*printf("TERM:%s MULOP:%s FACTOR:%s\n",$1,$2,$3);
										QUEUENODE *temp = NULL;
										int type=-1;
										if (strstr($1,"(")!=NULL){
									  		searchStack(s,$1, &temp, 2);
										}
										else if (strstr($1,"[")!=NULL){
									  		searchStack(s,$1, &temp, 1);
										}
										else{
									  		searchStack(s,$1, &temp, 0);
										}	
										if (temp!=NULL){
											type = temp->symbol->type;
										}*/

										/*printf("MULT:%s TERM:%s FACTOR:%s\n",$1,$2,$3);
										printf("isNum=%d, isFloat=%d\n",isNum, isFloat);*/

										char* temp = (char*)malloc(strlen($1));
										strcpy(temp,$1);

										f=NULL;
										searchStack(s, $1, &f, 0); 
										if (f == NULL && strstr(temp,"[") != NULL)
											searchStack(s, strtok(temp,"["), &f, 1);
										if (f == NULL)
											searchStack(s, $1, &f, 2);

										temp = (char*)malloc(strlen($3));
										strcpy(temp,$3);

										g=NULL;
										searchStack(s, $3, &g, 0);
										if (g == NULL && strstr($3,"[") != NULL)
											searchStack(s, strtok(temp,"["), &g, 1);
										if (g == NULL)
											searchStack(s, $3, &g, 2);

										//printf("isNUM:%d\n",f->symbol->type,isNum);

										/*Check for type for var, array, function*/
										if (f!=NULL && g!= NULL && f->symbol->type != g->symbol->type){
											errorStr = (char*)malloc(strlen("Operation between different types ")*sizeof(char));
											strcat(errorStr,"Operation between different types ");
											myError(errorStr);
											errorStr=NULL;
										}

										//printf("F: %p, type: %d, isNum=%d\n",f ,f->symbol->type, isNum);
										/*Check for var, array, function and integer*/
										else if ((f!=NULL && (f->symbol->type == 1) && (isNum != 1)) || (g!=NULL && (g->symbol->type == 1) && (isNum != 1))){
											errorStr = (char*)malloc(strlen("Operation between different types ")*sizeof(char));
											strcat(errorStr,"Operation between different types ");
											myError(errorStr);
											errorStr=NULL;
										}
										else if ((f!=NULL && (f->symbol->type == 2) && (isFloat != 1)) || (g!=NULL && (g->symbol->type == 2) && (isFloat != 1))){
											errorStr = (char*)malloc(strlen("Operation between different types ")*sizeof(char));
											strcat(errorStr,"Operation between different types ");
											myError(errorStr);
											errorStr=NULL;
										
										}
										/*If the computation is correct put type in global var*/
										/*if (f != NULL)
											termType = f->symbol->type;
										else {
											if (g != NULL)
												termType = g->symbol->type;
											else
												termType = -1;
										}*/
									}
  | factor								{
										$$=$1;	
									}
;
mulop: '*'								{$$ = (char*) malloc (strlen("*")*sizeof(char)); strcpy($$, "*");}
  | '/'									{$$ = (char*) malloc (strlen("/")*sizeof(char)); strcpy($$, "/");}
;
factor: '('expression')'						{
									  /*$$=(char*)malloc(strlen($2)*sizeof(char));
									  strcpy($$,$2);*/
									}
  | var									{ 
										isNum = 0;
										$$=$1;
										//printQueue(s->head->h);
										//printf("VAR: %s\n",$1);
										/*f=NULL;
										char *str = (char*)malloc(strlen($1));
										strcpy(str,$1);
										searchStack(s,strtok(str,"["),&f,0);
										searchStack(s,str,&g,1); 
										if (g==NULL){
											errorStr = (char*)malloc(strlen("Array ")*sizeof(char));
											strcat(errorStr,"Array ");
											strcat(errorStr,$1);
											strcat(errorStr," is not declared");
											myError(errorStr);
											errorStr=NULL;	
										}
										if (f==NULL){
											errorStr = (char*)malloc(strlen("Variable5 ")*sizeof(char));
											strcat(errorStr,"Variable5 ");
											strcat(errorStr,$1);
											strcat(errorStr," is not declared");
											myError(errorStr);
											errorStr=NULL;	
										}*/

									}
  | call								{ $$=$1; }
  | NUM									{
										isNum = 1;// printf("IS NUM\n");
										char *s = (char*)malloc(sizeof(char)*5);
										sprintf(s,"%d",$1);
										$$=(char*)malloc(strlen(s)*sizeof(char)); 
										strcpy($$,s);
									}
  | FLOAT_NUM								{
										isFloat = 1;
										char *s = (char*)malloc(sizeof(char)*10);
										sprintf(s,"%5.3f",$1);
										$$=(char*)malloc(strlen(s)*sizeof(char)); 
										strcpy($$,s);
									}
;
call: ID'('args')'							{ //TODO: find the parameters in the stack and add their values(void**), *****function or array as argument in function****
										f=NULL;
										searchStack(s,$1,&f,2);
										
										if (f == NULL){
											errorStr = (char*)malloc(strlen("Function ")*sizeof(char));
											strcat(errorStr,"Function ");
											strcat(errorStr,$1);
											strcat(errorStr," is not declared");
											myError(errorStr);
											errorStr=NULL;
										}
										else {

											char *temp = (char*) malloc (strlen($3)*sizeof(char)); strcpy(temp,$3);
											int insert = qLookAndStackSearch(s->head->next->h,$1,2,temp,s);

											if (insert == 0){
												errorStr = (char*)malloc(strlen("Function ")*sizeof(char));
												strcat(errorStr,"Function ");
												strcat(errorStr,$1);
												strcat(errorStr," is not declared");
												myError(errorStr);
												errorStr=NULL;
											}
											else
												$$ = (void*)f->symbol;
										}
										$$=$1;
										

									}
  | ID '('error')'							{yyerrok;}
;
args: arg_list								{$$= (char*) malloc (strlen($1)*sizeof(char)); strcpy($$,$1);}
  |									{$$= (char*) malloc (strlen("")*sizeof(char)); strcpy($$,"");}
;
arg_list: arg_list','expression						{$$= (char*) malloc ((strlen($1)+strlen($3)+2)*sizeof(char)); strcpy($$,$1); strcat($$,","); strcat($$,$3); }
  | expression								{$$= (char*) malloc (strlen($1)*sizeof(char)); strcpy($$,$1);}
;
%%
void pushQueue(){
   QUEUE *q=NULL; 
   if (initQueue(&q) == EXIT_FAILURE)
	exit(1);
   push(q, s);
}

void pushQueue1(){
   QUEUE *q=NULL; 
   if (initQueue(&q) == EXIT_FAILURE)
	exit(1);
   push(q, s);
}

QUEUENODE * insertInQueue(char* ret, char* two, int isFunction, int isArray){
   SYMTAB *symbol = (SYMTAB*) malloc (sizeof(symbol));
   symbol->name = (char*) malloc ((strlen(two))*sizeof(char));
   strcpy(symbol->name, two);

   int i = 0;
   for (i=0; i<10; i++)
	symbol->paramTypes[i] = 0;

   (symbol->name)[strlen(symbol->name)] = '\0';
   if(ret==NULL){
      /*do nothing*/
   }
   else if (strcmp(ret, "int")==0){
      symbol->type=1;
   }
   else if (strcmp(ret, "float")==0){
      symbol->type=2;
   }
   else if (strcmp(ret, "void")==0){
      symbol->type=3;
   }
   symbol->function=isFunction;
   symbol->array=isArray;
   /*if (isFunction==1){
	int i=0;
	for (i=0;i<sizeof(symbol->paramTypes)/4;i++){
		symbol->paramTypes[i]=0;
	}
   }*/
   QUEUENODE *p = enqueue(symbol, s->head->h);
   return p;
}

int containsNumber(char *string){

	if (strstr(string,"1") != NULL || strstr(string,"2") != NULL || strstr(string,"3") != NULL || strstr(string,"4") != NULL || strstr(string,"5") != NULL || strstr(string,"6") != NULL || strstr(string,"7") != NULL || strstr(string,"8") != NULL || strstr(string,"9") != NULL )
		return 1;
	return 0;
}

int main(void){
   s = initStack();
   QUEUE *q=NULL; 
   if (initQueue(&q) == EXIT_FAILURE)
	exit(1);
   push(q, s); printf("Push in Main\n");
   return yyparse();
}

void myError (char *errorStr){
	fprintf(stderr, "Line %d: %s \n", yylineno, errorStr);
}

yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  fprintf(stderr, "Line %d: %s (%s) %s \n", yylineno, s, yytext, errorStr); 
}
