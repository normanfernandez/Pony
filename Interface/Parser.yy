%{
#include <cstdio>
#include <iostream>
#include "PonyCore.h"
#include "PonyInt.h"
#include "Expression.hpp"
#define PONY_VERSION "Pony Version 0.6"

using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int line_number;
 
void yyerror(const char *);
%}

%union {
	int ival;
	float fval;
	char *sval;
	struct tagSExpression *exp;
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
%token VAR
%token TYPE_BYTE
%token COLON
%token TYPE_SHORT
%token TERNARY
%token TYPE_INT
%token TYPE_LONG

%token OR_OP

%token EQUAL

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

%left ADD SUB
%left MUL DIV MOD BSIZE OR XOR AND POW

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
		{
			$<ival>$ = $<ival>1;
			printf("expression result: %i\n", $<ival>1);
		}
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
		{
			//nothing!
		}
	|	expression SEMICOLON 
		{ 
			$<ival>$ = evaluateIntExpression($<exp>1); 
			deleteExpression(&$<exp>1); 
		}
	;

primary_expression:
		string {cout << "str generico es: " << yylval.sval << endl;}
	|	number { $<exp>$ = yylval.exp;}
	|	LPAREN expression RPAREN { $<exp>$ = $<exp>2; }
	;
	
expression:
		assignment_expression { $<exp>$ = $<exp>1; }
	|	expression COMMA assignment_expression
	;

assignment_expression:
		conditional_expression { $<exp>$ = $<exp>1; }
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
		conditional_expression { $<exp>$ = $<exp>1; }
	;

conditional_expression:
		logical_or_expression { $<exp>$ = $<exp>1; }
	|	logical_or_expression TERNARY expression COLON conditional_expression { $<ival>$ = ($<ival>1 ? $<ival>3 : $<ival>5 );}
	;
	
logical_or_expression:
		logical_and_expression { $<exp>$ = $<exp>1; }
	|	logical_or_expression OR_OP logical_and_expression { $<exp>$ = createOperation(eLOGIC_OR, $<exp>1, $<exp>3);  }
	;

logical_and_expression:
		inclusive_or_expression { $<exp>$ = $<exp>1; }
	|	logical_and_expression	AND_OP inclusive_or_expression { $<exp>$ = createOperation(eLOGIC_AND, $<exp>1, $<exp>3);  }
	;

inclusive_or_expression:
		exclusive_or_expression { $<exp>$ = $<exp>1; }
	|	inclusive_or_expression OR exclusive_or_expression { $<exp>$ = createOperation(eOR, $<exp>1, $<exp>3);  }
	;

exclusive_or_expression:
		and_expression { $<exp>$ = $<exp>1; }
	|	exclusive_or_expression XOR and_expression { $<exp>$ = createOperation(eXOR, $<exp>1, $<exp>3);  }
	;
	
and_expression:
		equality_expression { $<exp>$ = $<exp>1; }
	|	and_expression AND equality_expression { $<exp>$ = createOperation(eAND, $<exp>1, $<exp>3);  }
	;
	
equality_expression:
		relational_expression { $<exp>$ = $<exp>1; }
	|	equality_expression EQ_OP relational_expression { $<exp>$ = createOperation(eEQUAL, $<exp>1, $<exp>3);  }
	|	equality_expression NE_OP relational_expression { $<exp>$ = createOperation(eNEQUAL, $<exp>1, $<exp>3);  }
	;
relational_expression:
		shift_expression { $<exp>$ = $<exp>1; }
	|	relational_expression LTHAN shift_expression { $<exp>$ = createOperation(eLTHAN, $<exp>1, $<exp>3);  }
	|	relational_expression GTHAN shift_expression { $<exp>$ = createOperation(eGTHAN, $<exp>1, $<exp>3);  }
	|	relational_expression LEQU shift_expression { $<exp>$ = createOperation(eLETHAN, $<exp>1, $<exp>3);  }
	|	relational_expression GEQU shift_expression { $<exp>$ = createOperation(eGETHAN, $<exp>1, $<exp>3);  }
	;
	
shift_expression:
		additive_expression { $<exp>$ = $<exp>1; }
	|	shift_expression L_OP additive_expression { $<exp>$ = createOperation(eLEFT, $<exp>1, $<exp>3);  }
	|	shift_expression R_OP additive_expression { $<exp>$ = createOperation(eRIGHT, $<exp>1, $<exp>3);  }
	;

additive_expression:
		multiplicative_expression { $<exp>$ = $<exp>1;}
	|	additive_expression ADD multiplicative_expression {$<exp>$ = createOperation(ePLUS, $<exp>1, $<exp>3);}
	|	additive_expression SUB  multiplicative_expression { $<exp>$ = createOperation(eSUBTRACT, $<exp>1, $<exp>2); }
	;

multiplicative_expression:
		cast_expression { $<exp>$ = $<exp>1; }
	|	multiplicative_expression MUL cast_expression { $<exp>$ = createOperation(eMULTIPLY, $<exp>1, $<exp>3); }
	|	multiplicative_expression DIV cast_expression { $<exp>$ = createOperation(eDIVIDE, $<exp>1, $<exp>3); }
	|	multiplicative_expression MOD cast_expression { $<exp>$ = createOperation(eMOD, $<exp>1, $<exp>3); }
	|	multiplicative_expression POW cast_expression { $<exp>$ = createOperation(ePOW, $<exp>1, $<exp>3); }
	;
	
cast_expression:
		unary_expression { $<exp>$ = $<exp>1; }
	|	LPAREN type_specifier RPAREN cast_expression
	;
	
unary_expression:
		postfix_expression { $<exp>$ = $<exp>1;}
	|	INC unary_expression { $<ival>$ = ++$<ival>2; }
	|	DEC unary_expression { $<ival>$ = --$<ival>2; }
	|	unary_operator cast_expression
	|	BSIZE unary_expression
	|	BSIZE LPAREN type_specifier RPAREN
	;
unary_operator:
		AND
	| 	'+' 
	|	'-' 
	|	'~' 
	|	'!'
	;

postfix_expression:
		primary_expression { $<exp>$ = $<exp>1;}
	|	postfix_expression '[' expression ']'
	|	postfix_expression LPAREN RPAREN
	|	postfix_expression LPAREN argument_expression_list RPAREN
	|	postfix_expression INC { $<ival>$ = $<ival>1++; }
	|	postfix_expression DEC { $<ival>$ = $<ival>1--; }
	;
	
argument_expression_list:
		assignment_expression
	|	argument_expression_list COMMA assignment_expression
	;


if_statement:
		IF LPAREN expression RPAREN statement 
		{ 
			if(evaluateIntExpression($<exp>3))
			{
				puts("Se cumple el if!");
				$<exp>$ = $<exp>5;
			} 
		}
	|	IF LPAREN expression RPAREN ELSE statement
	;

loop_statement:
		WHILE LPAREN expression RPAREN statement { cout << "el while!: " << endl; }
	|	FOR LPAREN expression_statement expression_statement RPAREN statement { cout << "el for!: " << endl; }
	|	FOR LPAREN expression_statement expression_statement expression RPAREN statement { cout << "el for!: " << endl; }
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
	|	RETURN expression SEMICOLON { cout << "expression: " << evaluateIntExpression($<exp>2) << endl;}
	;


declaration:
		declaration_specifiers SEMICOLON
	|	declaration_specifiers init_declarator_list SEMICOLON
	;

declaration_specifiers:
		type_specifier
	|	type_specifier declaration_specifiers
	|	VAR LTHAN declaration_specifiers GTHAN EQ_OP expression
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

number:
		INT { $<exp>$ = $<exp>1;}
	|	TRUE { $<exp>$ = createNumber(1);}
	|	FALSE { $<exp>$ = createNumber(0);}
	|	FLOAT { $<fval>$ = $<fval>1; }
	;
	
string:
		STRING
	|	STRING_LITERAL
	;

%%

extern "C" int yyparse();

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