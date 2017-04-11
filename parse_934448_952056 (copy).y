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
 #include <string.h>
 #include "stack.h"
// #include "queue.h"
 extern char* yytext; /* using flex */
 extern int yylineno;
 #define YYDEBUG_LEXER_TEXT yytext
 
 char* errorStr = "";
 STACK *s=NULL;

%}
%union {
	int a_number;
	char* str;
	float f_number;
}

%error-verbose

%start program
%token <a_number> NUM
%token <f_number> FLOAT
%token <str> ELSE IF INT VOID RETURN WHILE GTOE LTOE EQUAL NEQUAL PP PE MM ME ID NO_ELSE FOR
%type <str> program declaration_list declaration var_declaration fun_declaration type_specifier params param_list param compound_stmt local_declarations statement_list statement expression_stmt selection_stmt iteration_stmt return_stmt expression var simple_expression additive_expression relop addop term mulop factor call args arg_list doubleAddSub
%nonassoc NO_ELSE
%nonassoc ELSE
%%
program: declaration_list						{printf("Final\n");pop(s);}
;
declaration_list: declaration_list declaration				{}
  | declaration								{}
;
declaration: var_declaration						{}
  |fun_declaration							{printf("Function \n");pop(s);}
;
var_declaration: type_specifier ID ';'					{
										SYMTAB *symbol = (SYMTAB*) malloc (sizeof(symbol));
										symbol->name = (char*) malloc ((strlen($2))*sizeof(char));
										strcpy(symbol->name, $2);
										(symbol->name)[strlen(symbol->name)] = '\0';
										if($$==NULL){
											/*do nothing*/
										}
										else if (strcmp($$, "int")==0){
											symbol->type=1;
										}
										else if (strcmp($$, "float")==0){
											symbol->type=2;
										}
										else if (strcmp($$, "void")==0){
											symbol->type=3;
										}
										symbol->function=0;
										symbol->array=0;
										enqueue(symbol, s->head->h);
										//printf("Scope: %d\n", s->size); 
										//printQueue( s->head->h);
									}
  | type_specifier ID '[' NUM ']' ';'					{ 
										SYMTAB *symbol = (SYMTAB*) malloc (sizeof(symbol));
										symbol->name = (char*) malloc ((strlen($2))*sizeof(char));
										strcpy(symbol->name, $2);
										(symbol->name)[strlen(symbol->name)] = '\0';

										if($$==NULL){
											//do nothing
										}
										else if (strcmp($$, "int")==0){
											symbol->type=1;
										}
										else if (strcmp($$, "float")==0){
											symbol->type=2;
										}
										else if (strcmp($$, "void")==0){
											symbol->type=3;
										}
										symbol->function=0;
										symbol->array=$4;
										enqueue(symbol, s->head->h);
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
fun_declaration: type_specifier ID '(' params ')' compound_stmt		{										
										SYMTAB *symbol = (SYMTAB*) malloc (sizeof(symbol));
										symbol->name = (char*) malloc ((strlen($2))*sizeof(char));
										strcpy(symbol->name, $2);
										(symbol->name)[strlen(symbol->name)] = '\0';
										if($$==NULL){
											/*do nothing*/
										}
										else if (strcmp($$, "int")==0){
											symbol->type=1;
										}
										else if (strcmp($$, "float")==0){
											symbol->type=2;
										}
										else if (strcmp($$, "void")==0){
											symbol->type=3;
										}
										symbol->function=1;
										symbol->array=0;
										enqueue(symbol, s->head->h);
										printf("Scopesaddfaef: %d\n",s->size-1);

									}
  | type_specifier ID '(' error ')' compound_stmt			{yyerrok;}
  | error ID '(' params ')' compound_stmt				{yyerrok;} 
  | error type_specifier ID '(' params ')' compound_stmt		{yyerrok;} 
  | type_specifier error '(' params ')' compound_stmt			{yyerrok;}
  | type_specifier ID '(' params ')' error				{yyerrok;}
;
params: param_list							{}
  | VOID								{
										$$ = (char*) malloc (strlen("void")*sizeof(char));
										strcpy($$, "void");
									}
  | 									{yyerror("No parameters given:");}
;
param_list: param_list ',' param					{}
  | param								{}
  | error ',' error							{yyerrok;}
  | error ',' param							{yyerrok;}
  | param_list ',' error						{yyerrok;}
;
param: type_specifier ID						{}
  | type_specifier ID '[' ']'						{}
  | error ID '[' ']'							{yyerrok;}
  | error type_specifier ID						{yyerrok;}
  | type_specifier error 						{yyerrok;}
;
compound_stmt: '{' local_declarations statement_list '}'		{	
										QUEUE *q=NULL; 
										if (initQueue(&q) == EXIT_FAILURE)
											exit(1);
										push(q, s);
									}
  | '{' local_declarations error '}'					{yyerrok;}
;
local_declarations: 							{/*empty*/}
  | local_declarations var_declaration					{}
;
statement_list:  							{/*empty*/}
  | statement_list statement						{}
;
statement: expression_stmt						{}
  | compound_stmt							{}
  | selection_stmt							{pop(s); printf("Selection\n");}
  | iteration_stmt							{pop(s); printf("Iteration\n");}
  | return_stmt								{}
;
expression_stmt: expression ';'						{}
  | ';'									{}
  | expression error							{yyerrok;}
;
selection_stmt: IF'('expression')'statement %prec NO_ELSE		{}
  | IF'('expression')'statement ELSE statement				{}
  | IF'('error')'statement %prec NO_ELSE				{yyerrok;}
  | IF'('error')'statement ELSE statement				{yyerrok;}
;
iteration_stmt: WHILE '(' expression ')' statement			{}
  | WHILE '(' error ')' statement					{yyerrok;}
  | FOR '(' expression ';' expression ';' expression ')' statement      {}
  | FOR '(' error ';' expression ';' expression ')' statement    	{yyerrok;}
  | FOR '(' expression ';' error ';' expression ')' statement      	{yyerrok;}
  | FOR '(' expression ';' expression ';' error ')' statement      	{yyerrok;}
  | FOR '('')'								{yyerrok;}
;
return_stmt: RETURN ';'							{}
  | RETURN expression ';'						{}
  | RETURN error							{yyerrok;}
;
expression: var '=' expression						{}
  | var '=' error expression						{yyerrok;}
  | simple_expression							{}
;
var: ID									{
										$$ = (char*) malloc (strlen($1)*sizeof(char));
										strcpy($$, $1);
									}
  | ID'['expression']'							{}
;
simple_expression: additive_expression relop additive_expression	{}
  | additive_expression							{}
;
relop: GTOE								{}
  | LTOE								{}
  | EQUAL								{}
  | NEQUAL								{}
  | '<'									{}
  | '>'									{}
;
additive_expression: additive_expression addop term			{}
  | term								{}
  | term doubleAddSub							{}
;
addop: '+'								{}
  | '-'									{}
;
doubleAddSub: PP							{}
  | PE term								{}
  | MM									{}
  | ME term								{}
;
term: term mulop factor							{}
  | factor								{}
;
mulop: '*'								{}
  | '/'									{}
;
factor: '('expression')'						{}
  | var									{}
  | call								{}
  | NUM									{}
;
call: ID'('args')'							{}
  | ID '('error')'							{yyerrok;}
;
args: arg_list								{}
  |									{/*empty*/}
;
arg_list: arg_list','expression						{}
  | expression								{}
;
%%

int main(void){
   s = initStack();
   QUEUE *q=NULL;
   if (initQueue(&q) == EXIT_FAILURE)
	exit(1);
   push(q, s); 
   return yyparse();
}

yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  fprintf(stderr, "Line %d: %s (%s) %s \n", yylineno, s, yytext, errorStr); 
}
