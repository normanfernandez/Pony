%{

#include <iostream>
#include "PonyInt.h"
#include "Parser.tab.hh"
using namespace std;
int line_number = 1;
#define YY_DECL extern "C" int yylex()

%}
%%

[ \t]        			{ ; }
[-]?[0-9]+\.[0-9]+ 		{ yylval.fval = atof(yytext); return FLOAT; }
[-]?[0-9]+         		{ yylval.ival = atoi(yytext); return INT; }
\'(.)*\'  				{ yylval.sval = (char*)std::string(yytext).c_str(); return STRING_LITERAL;}
\"(\\.|[^"])*\"			{ yylval.sval = strdup(yytext); return STRING;}

':':					{ return COLON; }
"..."					{ return ELLIPSIS; }
\(						{ return LPAREN; }
\)						{ return RPAREN; }
\n           			{++line_number; }
;						{ return SEMICOLON; }
.            			;
',':					{ return COMMA; }

"++":\					{ return INC; }
"--":\					{ return DEC; }
'?':					{ return TERNARY; }
"|":					{ return OR; }
'&':					{ return AND; }
("^")|("xor")			{ return XOR; }

"<":					{ return LTHAN; }
"<=":					{ return LEQU; }
"<<":					{ return L_OP; }
"<<=":					{ return L_EQU; }

">":					{ return GTHAN; }
">=":					{ return GEQU; }
">>":					{ return R_OP; }
">>=":					{ return R_EQU; }

"=":					{ return EQUAL; }
("==")|("is")			{ return EQ_OP; }
("!=")|("not")			{ return NE_OP; }
"*=":\					{ return MUL_EQU; }
"+=":\					{ return ADD_EQU; }
"-=":\					{ return SUB_EQU; }
"/=":\					{ return DIV_EQU; }
"^=":\					{ return XOR_EQU; }
\%\=:\					{ return MOD_EQU; }
"&=":\					{ return AND_EQU; }
"|=":\					{ return OR_EQU; }

"if"					{ return IF; }
"else"					{ return ELSE; }

"true"					{  yylval.ival = 1; return TRUE; }
"false"					{  yylval.ival = 0; return FALSE; }

"continue"				{ return CONTINUE; }
"break"					{ return BREAK; }
"return"				{ return RETURN; }
"begin"					{ return TOKEN_BEGIN; }
"byte"					{ yylval.ival = eBYTE; return TYPE_BYTE; }
"short"					{ yylval.ival = eSHORT; return TYPE_SHORT; }
"int"					{ yylval.ival = eINT; return TYPE_INT; }
"long"					{ yylval.ival = eLONG; return TYPE_LONG; }
"end"        			{ return END; }
"print"      			{ return TOKEN_PRINT; }
"read"					{ return TOKEN_READ; }
"while"					{ return WHILE; }
"for"					{ return FOR;}
"var"        			{ return VAR; }


("or")|("||")			{ return OR_OP; }
("and")|("&&")			{ return AND_OP; }

"byte_size"				{ return BSIZE; }

"+":					{ return ADD; }
'-':\					{ return SUB; }
\*:\					{ return MUL; }
\/:\					{ return DIV; }
'%':\					{ return MOD; }

[a-zA-Z_]*[a-zA-Z0-9_]+	{ yylval.sval = strdup(yytext); return TOKEN_ID;}

%%