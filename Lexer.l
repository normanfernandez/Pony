%{
#include <iostream>
#include "PonyInt.h"
#include "Parser.tab.hh"
using namespace std;
int line_number = 1;
#define YY_DECL extern "C" int yylex()
%}
%%
[ \t]        			{ ;}
[0-9]+\.[0-9]+ 			{ yylval.fval = atof(yytext); return FLOAT; }
[0-9]+         			{ yylval.ival = atoi(yytext); return INT; }
\'[a-zA-Z0-9 _]+\'  	{ yylval.sval = strtok(strdup(yytext), "\'"); return STRING;}
;						{ return SEMICOLON; }
\(						{ return LPAREN; }
\)						{ return RPAREN; }
\n             			{++line_number; return ENDL;}
.              			;
'<'						{ return TOKEN_LESS; }
'>'						{ return TOKEN_GREATER; }
'='						{ return TOKEN_EQUAL; }
"begin"					{ return TOKEN_BEGIN; }
"byte"					{ yylval.ival = eBYTE; return TYPE_BYTE; }
"short"					{ yylval.ival = eSHORT; return TYPE_SHORT; }
"int"					{ yylval.ival = eINT; return TYPE_INT; }
"long"					{ yylval.ival = eLONG; return TYPE_LONG; }
"end"          			{ return END; }
"print"        			{ return TOKEN_PRINT; }
"read"					{ return TOKEN_READ; }
"var"          			{ return TOKEN_VAR; }
"pony"					{ return PONY; }
[a-zA-Z_][a-zA-Z0-9_]+	{ yylval.sval = strdup(yytext); return TOKEN_ID;}

%%