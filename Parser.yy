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
%token PRINT 
%token VAR
%token QUOTATION
%token SEMICOLON
%token WS

// define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the union:
%token <ival> INT
%token <fval> FLOAT
%token <sval> STRING


%%
pony:
	TOKEN_BEGIN body_section END { cout << "done with a pony file!" << endl; }
	;

body_section:
	body_lines ENDL
	| ENDL
	| WS
	;
	
body_lines:
	body_lines body_line
	| body_line
	| ENDL
	;
	
body_line:
	| PRINT '(' ')' SEMICOLON {cout << "llamando funcion print"<< endl;}
	| VAR '(' ')' SEMICOLON {cout << "se encontro var" << endl;}
	| SEMICOLON {;}
	| WS {;}
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