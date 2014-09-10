FILES	= Lexer.cpp Parser.cpp Expression.cpp main.cpp
CC	= g++
CFLAGS	= -g
  
test:		$(FILES)
		$(CC) $(CFLAGS) $(FILES) -o test.exe
 
Lexer.cpp:	Lexer.l 
		flex Lexer.l
 
Parser.cpp:	Parser.y Lexer.cpp
		win_bison Parser.y
 
clean:
		rm *.o Lexer.cpp Lexer.hpp Parser.cpp Parser.hpp text.exe
