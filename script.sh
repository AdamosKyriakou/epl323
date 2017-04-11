bison -d parse_934448_952056.y
flex parse_934448_952056.fl
gcc parse_934448_952056.tab.c lex.yy.c stack.c queue.c ast.c -lfl -o parse.out
