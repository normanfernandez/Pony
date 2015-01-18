CC	= g++ --std=gnu++11
CFLAGS	=  -o pony -ICore -IInterface -IObj
  
default: Parser.tab.cc lex.yy.c PonyCore.o Expression.o
		$(CC) $(CFLAGS) -static-libgcc -static-libstdc++ Obj/Parser.tab.cc Obj/lex.yy.c Obj/PonyCore.o Obj/Expression.o 

lex.yy.c:	Interface/Lexer.l 
		flex -o Obj/lex.yy.c Interface/Lexer.l
 
Parser.tab.cc:	Interface/Parser.yy
		bison Interface/Parser.yy -d -o Obj/Parser.tab.cc -v

PonyCore.o:	Core/PonyCore.cpp
		$(CC) -c Core/PonyCore.cpp -o Obj/PonyCore.o

core_test: main.cpp
		$(CC) $(CFLAGS) main.cpp PonyCore.cpp	

Expression.o: Core/Expression.cpp
		$(CC) -c Core/Expression.cpp -o Obj/Expression.o

clean:
		rm Obj/* pony