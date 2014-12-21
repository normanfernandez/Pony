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
%token WHILE
%token BREAK
%token FOR 
%token CONTINUE
%token ENDL
%token IF
%token ELSE
%token RETURN
%token TOKEN_PRINT
%token TOKEN_READ
%token PONY 
%token TOKEN_VAR
%token TYPE_BYTE
%token COLON
%token TYPE_SHORT
%token TERNARY
%token TYPE_INT
%token TYPE_LONG

%token OR_OP
%token OR

%token ADD_EQU
%token MUL_EQU
%token SUB_EQU
%token DIV_EQU
%token R_EQU
%token L_EQU
%token MOD_EQU
%token OR_EQU
%token XOR_EQU
%token AND_EQU

%token R_OP
%token L_OP
%token AND
%token XOR
%token AND_OP
%token GEQU
%token LEQU
%token DEC
%token INC
%token LTHAN
%token TRUE
%token FALSE
%token GTHAN
%token EQ_OP
%token NE_OP
%token LPAREN
%token RPAREN
%token COMMA
%token SEMICOLON
%token ELLIPSIS
%token WS

%left '+' '-'
%left '*' '/' '%' BSIZE

// define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the union:
%token <ival> INT
%token <fval> FLOAT
%token <sval> STRING
%token <sval> STRING_LITERAL

%token TOKEN_ID
%%

pony:
		statement_list
		{ cout << "done with a pony file!" << endl; }
	;

translation_unit:
		external_declaration
	|	translation_unit external_declaration
	;

external_declaration:
		function_definition
	|	declaration
	;

function_definition:
		declaration_specifiers direct_declarator declaration_list compound_statement
	|	declaration_specifiers direct_declarator compound_statement
	|	direct_declarator declaration_list compound_statement
	|	direct_declarator compound_statement
	;

statement:
		expression_statement
	|	if_statement
	|	declaration
	|	function_definition
	|	loop_statement
	|	jump_statement
	;

statement_list:
		statement
	|	statement_list statement
	;

expression_statement:
		SEMICOLON
	|	expression SEMICOLON
	;

primary_expression:
		STRING {cout << "str es: " << yylval.sval << endl;}
	|	INT {cout << "el numero es: " << yylval.ival << endl;}
	|	TRUE {cout << "la vaina e true!" << endl;}
	|	FALSE {cout << "la vaina e false!" << endl;}
	|	FLOAT {cout << "el numero es: " << yylval.fval << endl;}
	|	STRING_LITERAL {cout << "str es: " << yylval.sval << endl;}
	|	LPAREN expression RPAREN
	;
	
expression:
		assignment_expression
	|	expression COMMA assignment_expression
	;

assignment_expression:
		conditional_expression
	|	unary_expression assignment_operator assignment_expression
	;

assignment_operator:
		EQ_OP
	|	NE_OP
	|	MUL_EQU
	|	ADD_EQU
	|	SUB_EQU
	|	DIV_EQU
	|	XOR_EQU
	|	AND_EQU
	|	OR_EQU
	|	L_EQU
	|	R_EQU
	;

constant_expression:
		conditional_expression
	;

conditional_expression:
		logical_or_expression
	|	logical_or_expression TERNARY expression COLON conditional_expression
	;
	
logical_or_expression:
		logical_and_expression
	|	logical_or_expression OR_OP logical_and_expression
	;

logical_and_expression:
		inclusive_or_expression
	|	logical_and_expression	AND_OP inclusive_or_expression
	;

inclusive_or_expression:
		exclusive_or_expression
	|	inclusive_or_expression OR exclusive_or_expression 
	;

exclusive_or_expression:
		and_expression
	|	exclusive_or_expression XOR and_expression
	;
	
and_expression:
		equality_expression
	|	and_expression AND equality_expression
	;
	
equality_expression:
		relational_expression
	|	equality_expression EQ_OP relational_expression
	|	equality_expression NE_OP relational_expression
	;
relational_expression:
		shift_expression
	|	relational_expression LTHAN shift_expression
	|	relational_expression GTHAN shift_expression
	|	relational_expression LEQU shift_expression
	|	relational_expression GEQU shift_expression
	;
	
shift_expression:
		additive_expression
	|	shift_expression L_OP additive_expression
	|	shift_expression R_OP additive_expression
	;

additive_expression:
		multiplicative_expression
	|	additive_expression '+' multiplicative_expression
	|	additive_expression '-' multiplicative_expression
	;

multiplicative_expression:
		cast_expression
	|	multiplicative_expression '*' cast_expression
	|	multiplicative_expression '/' cast_expression
	|	multiplicative_expression '%' cast_expression
	;
	
cast_expression:
		unary_expression
	|	LPAREN type_specifier RPAREN cast_expression
	;
	
unary_expression:
		postfix_expression
	|	INC unary_expression
	|	DEC unary_expression
	|	unary_operator cast_expression
	|	BSIZE unary_expression
	|	BSIZE LPAREN type_specifier RPAREN
	;
unary_operator:
		'&' 
	| 	'*' 
	| 	'+' 
	|	'-' 
	|	'~' 
	|	'!'
	;

postfix_expression:
		primary_expression
	|	postfix_expression '[' expression ']'
	|	postfix_expression LPAREN RPAREN
	|	postfix_expression LPAREN argument_expression_list RPAREN
	|	postfix_expression INC
	|	postfix_expression DEC
	;
	
argument_expression_list:
		assignment_expression
	|	argument_expression_list COMMA assignment_expression
	;


if_statement:
		IF LPAREN expression RPAREN statement
	|	IF LPAREN expression RPAREN ELSE statement
	;

loop_statement:
		WHILE LPAREN expression RPAREN statement
	|	FOR LPAREN expression_statement expression_statement RPAREN statement
	|	FOR LPAREN expression_statement expression_statement expression RPAREN statement
	;

compound_statement:
		TOKEN_BEGIN END
	|	TOKEN_BEGIN statement_list END
	|	TOKEN_BEGIN declaration_list END
	|	TOKEN_BEGIN declaration_list statement_list END
	;

jump_statement:
		CONTINUE SEMICOLON
	|	BREAK SEMICOLON
	|	RETURN SEMICOLON
	|	RETURN expression SEMICOLON
	;


declaration:
		declaration_specifiers SEMICOLON
	|	declaration_specifiers init_declarator_list SEMICOLON
	;

declaration_specifiers:
		type_specifier
	|	type_specifier declaration_specifiers
	;

type_specifier:
		TYPE_INT
	|	TYPE_SHORT
	|	TYPE_LONG
	|	TYPE_BYTE
	;

direct_declarator:
		TOKEN_ID
	|	LPAREN direct_declarator RPAREN
	|	direct_declarator '[' constant_expression ']'
	|	direct_declarator LPAREN parameter_type_list RPAREN
	|	direct_declarator LPAREN identifier_list RPAREN
	|	direct_declarator LPAREN RPAREN
	;

declaration_list:
		declaration
	|	declaration_list declaration
	;	

parameter_type_list:
		parameter_list
	|	parameter_list COMMA ELLIPSIS
	;

identifier_list:
		TOKEN_ID
	| 	identifier_list COMMA TOKEN_ID
	;

parameter_list:
		parameter_declaration
	|	parameter_list COMMA parameter_declaration
	;

init_declarator:
		direct_declarator
	|	direct_declarator EQ_OP initializer
	;
	
initializer:
		assignment_expression
	|	'{' initializer_list '}'
	| 	'{' initializer_list COMMA '}'
	;

initializer_list:
		initializer
	|	initializer_list COMMA initializer
	;

init_declarator_list:
		init_declarator
	|	init_declarator_list COMMA init_declarator
	;

parameter_declaration:
		declaration_specifiers direct_declarator
	|	declaration_specifiers
	;

pony_version:
		PONY LPAREN RPAREN { cout << PONY_VERSION << endl; }
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