%{
#include <cstdio>
#include <iostream>
using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int line_number;
 
void yyerror(const char *s);
%}

%union {
	int ival;
	float fval;
	char *sval;
}

// define the constant-string tokens:
%token TOKEN_BEGIN
%token END 
%token ENDL
%token LPAREN RPAREN
%token TOKEN_PRINT
%token PONY 
%token VAR
%token SEMICOLON
%token WS
%token PLUS '+'

// define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the union:
%token <ival> INT
%token <fval> FLOAT
%token <sval> STRING


%%
pony:
	TOKEN_BEGIN body footer { cout << "done with a pony file!" << endl; }
	;
	
body:
	body body_line
	| body_line
	| body endls
	| endls
	;
	
body_line:
	exp SEMICOLON
	| endls body_line
	;

exp: 
		TOKEN_PRINT LPAREN STRING RPAREN {cout << $3 << " pony!" << endl;}
	|	TOKEN_PRINT LPAREN INT RPAREN {cout << $3 << " integer!" << endl;}
	|	TOKEN_PRINT LPAREN FLOAT RPAREN {cout << $3 << " float!" << endl;}
	|	VAR LPAREN RPAREN  {cout << "se encontro var" << endl; }
	|	PONY LPAREN RPAREN { cout << "Pony Version 0.1.1" << endl; }
	;

footer:
END endls
	| END
	;

endls:
	endls ENDL
	| ENDL
	;

%%

int main(int argc, char * argv[]) {
	if(argc < 1)
	{
		cerr << "No input file detected!" << endl;
		return	1;
	}
	FILE *myfile = fopen(argv[1], "r");
	
	if (!myfile) {
		cerr << "Can't open file: " << argv[1] << endl;
		return -1;
	}
	
	yyin = myfile;
	
	do 
	{
		yyparse();
	} while (!feof(yyin));
	
}

void yyerror(const char *s) {
	cerr << "Parse error!  Line: " << line_number << " Message: " << s << endl;
	exit(-1);
}