FILES	= Lexer.cpp Parser.cpp Expression.cpp main.cpp
CC	= g++
CFLAGS	= -g
  
default: Parser.tab.cc lex.yy.c
		$(CC) Parser.tab.cc lex.yy.c -lfl -o pony
 
lex.yy.c:	Lexer.l 
		flex Lexer.l
 
Parser.tab.cc:	Parser.yy
		bison Parser.yy -d
 
clean:
		rm Parser.tab.* lex.yy.c pony
