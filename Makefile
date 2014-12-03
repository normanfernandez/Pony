FILES	= Lexer.cpp Parser.cpp Expression.cpp main.cpp
CC	= g++ --std=c++11
CFLAGS	=  -o pony -ICore -IInterface -IObj
  
default: Parser.tab.cc lex.yy.c PonyCore.o
		$(CC) $(CFLAGS) Obj/Parser.tab.cc Obj/lex.yy.c Obj/PonyCore.o -lfl 
 
lex.yy.c:	Interface/Lexer.l 
		flex -o Obj/lex.yy.c Interface/Lexer.l
 
Parser.tab.cc:	Interface/Parser.yy
		bison Interface/Parser.yy -d -o Obj/Parser.tab.cc

PonyCore.o:	Core/PonyCore.cpp
		$(CC) -c Core/PonyCore.cpp -o Obj/PonyCore.o

core_test: main.cpp
		$(CC) $(CFLAGS) main.cpp PonyCore.cpp	

clean:
		rm Obj/* pony