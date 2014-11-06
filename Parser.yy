%{
#include <cstdio>
#include <iostream>
#define PONY_VERSION "Pony Version 0.2.1"
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

// define the keywords token:
%token TOKEN_BEGIN
%token END 
%token ENDL
%token TOKEN_PRINT
%token PONY 
%token VAR
%token TYPE_BYTE
%token TYPE_SHORT
%token TYPE_INT
%token TYPE_LONG

%token LESS_TOKEN
%token GREATER_TOKEN
%token LPAREN
%token RPAREN
%token SEMICOLON
%token WS

%left '+' '-'
%left '*' '/' '%'

// define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the union:
%token <ival> INT
%token <fval> FLOAT
%token <sval> STRING

//%token TOKEN_ID
%%
pony:
		TOKEN_BEGIN body footer { cout << "done with a pony file!" << endl; }
	;
	
body:
		body body_line
	| 	body_line
	| 	body endls
	| 	endls
	;
	
body_line:
		exp SEMICOLON
	| 	endls body_line
	;

exp: 
		TOKEN_PRINT LPAREN STRING RPAREN {cout << $3 << " pony!" << endl;}
	|	TOKEN_PRINT LPAREN NUMBER_OP RPAREN {cout << $<ival>3 << " integer!" << endl;}
	|	TOKEN_PRINT LPAREN FLOAT RPAREN {cout << $3 << " float!" << endl;}
	|	int_types {cout << $<sval>1 << " type!" << endl;}
	|	PONY LPAREN RPAREN { cout << PONY_VERSION << endl; }
	;

NUMBER_OP:
		NUMBER_OP '+' NUMBER_OP {$<ival>$ = $<ival>1 + $<ival>2;}
	|	INT
	;

int_types:
		TYPE_BYTE 
	|	TYPE_SHORT 
	|	TYPE_INT 
	|	TYPE_LONG
	;
	
footer:
		END endls
	| 	END
	;

endls:
		endls ENDL
	| 	ENDL
	;

%%

int main(int argc, char * argv[]) {
	if(argc <= 1)
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