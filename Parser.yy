%{
#include <cstdio>
#include <iostream>
#include "PonyCore.h"
#include "PonyInt.h"
#define PONY_VERSION "Pony Version 0.2.2"

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
%token TOKEN_READ
%token PONY 
%token TOKEN_VAR
%token TYPE_BYTE
%token TYPE_SHORT
%token TYPE_INT
%token TYPE_LONG

%token TOKEN_LESS
%token TOKEN_GREATER
%token TOKEN_EQUAL
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

%token TOKEN_ID
%%

pony:
		TOKEN_BEGIN body footer { cout << "done with a pony file!" << endl; }
	;
	
body:
		body body_line
	| 	body_line
	| 	body endls
	;
	
body_line:
		exp SEMICOLON
	|	endls body_line
	;

exp: 
		TOKEN_PRINT LPAREN STRING RPAREN {cout << $3 << endl;}
	|	TOKEN_PRINT LPAREN NUMBER_OP RPAREN {cout << $<ival>3 << " integer!" << endl;}
	|	TOKEN_READ LPAREN RPAREN { cin >> stdin_buffer; cout << "se escanea: " << stdin_buffer << endl;}
	|	TOKEN_PRINT LPAREN FLOAT RPAREN {cout << $3 << " float!" << endl;}
	|	TOKEN_PRINT LPAREN TOKEN_ID RPAREN 
		{
			cout << "Se lee " << $<sval>3 << endl;
			for(auto it = int_list.begin();
				it != int_list.end(); it++)
				cout << getInteger((*it).second) << endl;
		}
	|	declaration
	|	pony_version	
	|	assingment
	;

declaration:
		TOKEN_VAR LPAREN int_types RPAREN TOKEN_ID 
		{ 
			if(int_list.find($<sval>5) != int_list.end()) 
				yyerror("variable already declared!\n");
			allocateInteger($<sval>1, $<ival>3);
			cout << "Se declara " << $<sval>5 << " del tipo " << $<ival>3 << endl;   
		}
	;

pony_version:
		PONY LPAREN RPAREN { cout << PONY_VERSION << endl; }
	;

assingment: 
		TOKEN_ID TOKEN_EQUAL TOKEN_ID
		{
			cerr << "debug!\n";
			if(int_list.find($<sval>1) == int_list.end()) 
				yyerror("variable not declared!\n");
		}
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
	 	ENDL
	|	ENDL endls
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