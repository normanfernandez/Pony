FILES	= Lexer.cpp Parser.cpp Expression.cpp main.cpp
CC	= g++
CFLAGS	= --std=c++11 -o pony
  
default: Parser.tab.cc lex.yy.c PonyCore.cpp
		$(CC) $(CFLAGS) Parser.tab.cc lex.yy.c PonyCore.cpp -lfl 
 
lex.yy.c:	Lexer.l 
		flex Lexer.l
 
Parser.tab.cc:	Parser.yy
		bison Parser.yy -d

core_test: main.cpp
		$(CC) $(CFLAGS) main.cpp PonyCore.cpp	

clean:
		rm Parser.tab.* lex.yy.c pony
