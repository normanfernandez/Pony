SOURCE	= Src/Expression.cpp Src/FileRead.cpp Src/BigInteger.cpp Src/main.cpp 
FRONTEND =  Src/Lexer.cpp Src/Parser.cpp
FRONTEND_ALL = $(FRONTEND) Src/Headers/Lexer.hpp Src/Headers/Parser.hpp
OBJECTS = Src/Obj/Expression.o Src/Obj/BigInteger.o Src/Obj/FileRead.o Src/Obj/Parser.o Src/Obj/Lexer.o
CC	= gcc
CFLAGS	= -c -Wall -std=c++11
  
test:	$(FRONTEND) $(OBJECTS) Src/Obj/main.o
		$(CC) -std=c++11 $(OBJECTS) Src/Obj/main.o -o test.exe

Src/Obj/main.o: $(OBJECTS)
	$(CC) $(CFLAGS) Src/main.cpp -o Src/Obj/main.o
	

Src/Obj/Parser.o: $(FRONTEND)
	$(CC) $(CFLAGS) Src/Parser.cpp -o Src/Obj/Parser.o

Src/Obj/Expression.o: Src/Expression.cpp
	$(CC) $(CFLAGS) Src/Expression.cpp -o Src/Obj/Expression.o
	
Src/Obj/FileRead.o: Src/FileRead.cpp
	$(CC) $(CFLAGS) Src/FileRead.cpp -o Src/Obj/FileRead.o
	
Src/Obj/BigInteger.o: Src/BigInteger.cpp
	$(CC) $(CFLAGS) Src/BigInteger.cpp -o Src/Obj/BigInteger.o

Src/Obj/Lexer.o: Src/Lexer.cpp 
	$(CC) $(CFLAGS) Src/Lexer.cpp -o Src/Obj/Lexer.o

Src/Lexer.cpp:	Src/Lexer.l 
		flex Src/Lexer.l
 
Src/Parser.cpp:	Src/Parser.y Src/Lexer.cpp
		win_bison Src/Parser.y --output=Src/Parser.cpp
 
clean:
		rm $(FRONTEND_ALL) $(OBJECTS) Src/Obj/main.o  text.exe
