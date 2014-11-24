FILES	= Lexer.cpp Parser.cpp Expression.cpp main.cpp
CC	= g++ --std=c++11
CFLAGS	=  -o pony
  
default: Parser.tab.cc lex.yy.c PonyCore.o
		$(CC) $(CFLAGS) Parser.tab.cc lex.yy.c PonyCore.o -lfl 
 
lex.yy.c:	Lexer.l 
		flex Lexer.l
 
Parser.tab.cc:	Parser.yy
		bison Parser.yy -d

PonyCore.o:	PonyCore.cpp
		$(CC) -c PonyCore.cpp -o PonyCore.o

core_test: main.cpp
		$(CC) $(CFLAGS) main.cpp PonyCore.cpp	

clean:
		rm Parser.tab.* lex.yy.c pony
