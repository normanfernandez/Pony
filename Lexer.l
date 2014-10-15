%{
 
#include "Expression.hpp"
#include "Parser.hpp"
 
#include <stdio.h>
 
%}
 
%option outfile="Lexer.cpp" header-file="Lexer.hpp"
%option warn nodefault
%option reentrant noyywrap never-interactive nounistd
%option bison-bridge
 
LPAREN      "("
RPAREN      ")"
PLUS        "+"
MINUS		"-"
MULTIPLY    "*"
SLASH		"/"
SEMICOLON	";"
QUOTATION	["]
PRINT		"print"

LETTER		[a-zA-Z]
CHARSET		[a-zA-Z0-9]+ 
NUMBER      [0-9]+
WS          [ \r\n\t]*
ID 			{LETTER}{CHARSET | NUMBER}*
 
%%
 
{WS}            { /* Skip blanks. */ }
{NUMBER}        { sscanf(yytext, "%d", &yylval->value); return TOKEN_NUMBER; }
{SEMICOLON}		{ return TOKEN_SEMICOLON;}

{PRINT}			{ return TOKEN_PRINT;}
{QUOTATION}		{ return TOKEN_QUOTATION;}
{MULTIPLY}      { return TOKEN_MULTIPLY; }
{PLUS}          { return TOKEN_PLUS; }
{SLASH}			{ return TOKEN_SLASH; }
{MINUS}			{ return TOKEN_MINUS;}
{LPAREN}        { return TOKEN_LPAREN; }
{RPAREN}        { return TOKEN_RPAREN; }
.               {  }
 
%%
 
int yyerror(const char *msg) {
    fprintf(stderr,"Error:%s\n",msg); return 0;
}