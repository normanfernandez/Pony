%{
#include <iostream>
#include "Parser.tab.hh"
using namespace std;
int line_number = 1;
#define YY_DECL extern "C" int yylex()
%}
%%
[ \t]          { return WS;}
begin		{ return TOKEN_BEGIN; }
end            { return END; }
print        { return PRINT; }
var           { return VAR; }
[0-9]+\.[0-9]+ { yylval.fval = atof(yytext); return FLOAT; }
[0-9]+         { yylval.ival = atoi(yytext); return INT; }
[a-zA-Z0-9]+   {
	// we have to copy because we can't rely on yytext not changing underneath us:
	yylval.sval = strdup(yytext);
	return STRING;
}
\"			{return QUOTATION;}
;			{return SEMICOLON;}
\n             {++line_number; return ENDL;}
.              ;
%%