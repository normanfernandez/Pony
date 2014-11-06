%{
#include <iostream>
#include "Parser.tab.hh"
using namespace std;
int line_number = 1;
#define YY_DECL extern "C" int yylex()
%}
%%
[ \t]        	{ ;}
[0-9]+\.[0-9]+ 		{ yylval.fval = atof(yytext); return FLOAT; }
[0-9]+         		{ yylval.ival = atoi(yytext); return INT; }
\'[a-zA-Z0-9 _]+\'  		{ yylval.sval = strtok(strdup(yytext), "\'"); return STRING;}
;						{ return SEMICOLON; }
\(						{ return LPAREN; }
\)						{ return RPAREN; }
\n             			{++line_number; return ENDL;}
.              			;
'<'						{ return LESS_TOKEN; }
'>'						{ return GREATER_TOKEN; }
begin					{ return TOKEN_BEGIN; }
byte					{ yylval.sval = strdup(yytext); return TYPE_BYTE; }
short					{ yylval.sval = strdup(yytext); return TYPE_SHORT; }
int						{ yylval.sval = strdup(yytext); return TYPE_INT; }
long					{ yylval.sval = strdup(yytext); return TYPE_LONG; }
end            			{ return END; }
print        			{ return TOKEN_PRINT; }
var           			{ return VAR; }
pony					{ return PONY; }


%%