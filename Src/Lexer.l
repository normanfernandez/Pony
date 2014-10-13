%{
 
#include "Headers/Expression.hpp"
#include "Headers/Parser.hpp"
 
#include <stdio.h>

struct YYLTYPE;
%}
 
%option outfile="Src/Lexer.cpp" header-file="Src/Headers/Lexer.hpp"
%option noyywrap warn nodefault
%option never-interactive nounistd
%option bison-bridge
 
LPAREN      "("
RPAREN      ")"
PLUS        "+"
MINUS		"-"
MULTIPLY    "*"
SLASH		"/"
SEMICOLON	";"
QUOTATION	["]
SINGLE		[']

LETTER		[a-zA-Z]
CHARSET		[a-zA-Z0-9]+ 
NUMBER      [0-9]+
WS          [ \r\n\t]*
ID 			{LETTER}{CHARSET | NUMBER}*
 
%%
 
{WS}            { /* Skip blanks. */ }
{NUMBER}        { return TOKEN_NUMBER; }
{SEMICOLON}		{ return TOKEN_SEMICOLON;}

{QUOTATION}		{ return TOKEN_QUOTATION;}
{SINGLE}		{ return TOKEN_SINGLE; }
{MULTIPLY}      { return TOKEN_MULTIPLY; }
{CHARSET}		{ return TOKEN_CHARSET; }
{PLUS}          { return TOKEN_PLUS; }
{SLASH}			{ return TOKEN_SLASH; }
{MINUS}			{ return TOKEN_MINUS;}
{LPAREN}        { return TOKEN_LPAREN; }
{RPAREN}        { return TOKEN_RPAREN; }
.               {  }
 
%%