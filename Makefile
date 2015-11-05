all: cminor

cminor: token.o lex.yy.o main.o parser.tab.o expr.o decl.o stmt.o type.o param_list.o
	gcc parser.tab.o token.o expr.o decl.o stmt.o type.o param_list.o lex.yy.o main.o -o cminor -Wall
main.o: main.c token.h
	gcc -c main.c -Wall
token.o: token.c token.h
	gcc -c token.c -Wall
param_list.o: param_list.c param_list.h
	gcc -c param_list.c -Wall
type.o: type.c type.h
	gcc -c type.c -Wall
stmt.o: stmt.c stmt.h
	gcc -c stmt.c -Wall
decl.o: decl.c decl.h
	gcc -c decl.c -Wall
expr.o: expr.c expr.h
	gcc -c expr.c -Wall
parser.tab.o: parser.tab.c decl.h expr.h stmt.h param_list.h type.h
	gcc -c parser.tab.c -Wall
parser.tab.c: parser.y
	bison parser.y
lex.yy.o: lex.yy.c token.h
	gcc -c lex.yy.c -Wall
lex.yy.c: scanner.l
	flex scanner.l
clean:
	rm *.o lex.yy.c parser.tab.c cminor
