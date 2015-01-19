%{

#include <iostream>
#include "PonyInt.h"
#include "PonyCore.h"
#include "Parser.tab.hh"
#include "Expression.hpp"
using namespace std;
int line_number = 1;
#define YY_DECL extern "C" int yylex()

%}
%%

"&"					{ return AND; }
"|"					{ return OR; }
"+"					{ return ADD; }
"-"					{ return SUB; }
"*"					{ return MUL; }
"/"					{ return DIV; }
"=>"					{ puts("ter!");return TERNARY; }
("%")|("mod")		{ return MOD; }
("**")|("pow")		{ return POW; }

("or")|("||")		{ return OR_OP; }
("and")|("&&")		{ return AND_OP; }

("^")|("xor")			{ return XOR; }
"<"					{ return LTHAN; }
"<="					{ return LEQU; }
"<<"					{ return L_OP; }
"<<="					{ return L_EQU; }

">"					{ return GTHAN; }
">="					{ return GEQU; }
">>"					{ return R_OP; }
">>="					{ return R_EQU; }


[ \t]        			{ ; }
[-]?[0-9]+\.[0-9]+ 		{ yylval.fval = atof(yytext);return FLOAT; }
[-]?[0-9]+         		{ yylval.exp = createNumber(atoi(yytext));return INT; }

\'(\\.|[^'])*\'  				{ 
							yylval.sval = strdup(yytext);
							yylval.sval = strtok(yylval.sval,"\'");
							yylval.exp = createStr(yylval.sval);
							return STRING_LITERAL;
						}

\"(\\.|[^"])*\"			{ 
							yylval.sval = strdup(yytext);
							yylval.sval = strtok(yylval.sval,"\"");
							yylval.exp = createStr(translate(yylval.sval));
							return STRING;
						}

':':					{ return COLON; }
"..."					{ return ELLIPSIS; }
\(						{ return LPAREN; }
\)						{ return RPAREN; }
\n           			{++line_number; }
;						{ return SEMICOLON; }
"."            			{ return CONCAT; }
',':					{ return COMMA; }


"++":\					{ return INC; }
"--":\					{ return DEC; }

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

"true"					{  
							yylval.exp = createNumber(1); 
							return TRUE; 
						}
"false"					{  
							yylval.exp = createNumber(0); 
							return FALSE; 
						}

("println")|("writeln")	{ return PRINTLN; }
("print")|("write")		{ return PRINTNL; }
"continue"				{ return CONTINUE; }
"break"					{ return BREAK; }
"return"				{ return RETURN; }
"begin"					{ return TOKEN_BEGIN; }
"byte"					{ yylval.ival = eBYTE; return TYPE_BYTE; }
"short"					{ yylval.ival = eSHORT; return TYPE_SHORT; }
"int"					{ yylval.ival = eINT; return TYPE_INT; }
"float"					{ yylval.ival = eFLOAT; return TYPE_FLOAT; }
"long"					{ yylval.ival = eLONG; return TYPE_LONG; }
"string"				{ yylval.ival = eSTRING; return TYPE_STRING; }
"to_string"				{ return TO_STRING; }
("system")|("console")	{ return SYSCALL; }
"to_int"				{ return TO_INT; }
"end"        			{ return TOKEN_END; }
("read")|("input")		{ return TOKEN_READ; }
"while"					{ return WHILE; }
"for"					{ return FOR;}
"var"        			{ return VAR; }

"sqrt"					{ return SQRT; }
"cbrt"					{ return CBRT; }

[a-zA-Z_]*[a-zA-Z0-9_]+	{ 
							yylval.sval = new char; 
							sscanf(yytext, "%s", yylval.sval);
							yylval.exp = createStr(yylval.sval);
							return TOKEN_ID;
						}

%%

void yyerror(const char *s) {
	cerr << "Parse error!  Line: " << line_number << " Message: " << s << endl;
}

int yywrap()
{
	return 1;
}