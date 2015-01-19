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
("=>")|("?")		{ return TERNARY; }
":"					{ return COLON; }
("is")|("==")		{ return EQ_OP; }
("%")|("mod")		{ return MOD; }
("**")|("pow")		{ return POW; }

("or")|("||")		{ return OR_OP; }
("and")|("&&")		{ return AND_OP; }

("^")|("xor")		{ return XOR; }

"<"					{ return LTHAN; }
"<="				{ return LEQU; }
"<<"				{ return L_OP; }

">"					{ return GTHAN; }
">="				{ return GEQU; }
">>"				{ return R_OP; }


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


\(						{ return LPAREN; }
\)						{ return RPAREN; }
\n           			{++line_number; }
;						{ return SEMICOLON; }
"."            			{ return CONCAT; }

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
"byte"					{ yylval.ival = eBYTE; return TYPE_BYTE; }
"short"					{ yylval.ival = eSHORT; return TYPE_SHORT; }
"int"					{ yylval.ival = eINT; return TYPE_INT; }
"float"					{ yylval.ival = eFLOAT; return TYPE_FLOAT; }
"long"					{ yylval.ival = eLONG; return TYPE_LONG; }
"string"				{ yylval.ival = eSTRING; return TYPE_STRING; }
"to_string"				{ return TO_STRING; }
("system")|("console")	{ return SYSCALL; }
"to_int"				{ return TO_INT; }
("read")|("input")		{ return TOKEN_READ; }

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