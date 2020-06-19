all: compiler
	clear

compiler: lex.yy.c parser.tab.c parser.tab.h
	gcc lex.yy.c parser.tab.c  main.c exec.c -o sub-C-int -w

lex.yy.c: lexer.l parser.tab.h
	flex lexer.l

parser.tab.c parser.tab.h: parser.y
	bison -d parser.y
