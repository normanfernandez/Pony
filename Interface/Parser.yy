%{
#include <cstdio>
#include <iostream>
#include "PonyCore.h"
#include "PonyInt.h"
#include "Expression.hpp"
#include <cmath>
#define PONY_VERSION "Pony Version 0.6"

using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int line_number;
void yyerror(const char *);
int yywrap();
%}

%union {
	int ival;
	float fval;
	char *sval;
	struct tagSExpression *exp;
}

// define the keywords token:
%token TOKEN_BEGIN
%token TOKEN_END
%token SYSCALL
%token PRINTLN
%token PRINTNL
%token WHILE
%token BREAK
%token FOR 
%token CONTINUE
%token ENDL
%token IF
%token ELSE
%token RETURN
%token TOKEN_READ
%token PONY 
%token VAR
%token SQRT
%token CBRT
%token TYPE_BYTE
%token COLON
%token TYPE_SHORT
%token TERNARY
%token TYPE_INT
%token TYPE_LONG
%token TYPE_FLOAT

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
%token TYPE_STRING
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
%token TO_STRING
%token TO_INT
%token SYSTEM
%token NE_OP
%token LPAREN
%token RPAREN
%token COMMA
%token CONCAT
%token SEMICOLON
%token ELLIPSIS
%token WS

%left ADD SUB
%left MUL DIV MOD OR XOR AND POW
%left L_OP R_OP
%right EQUAL

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

statement:
		expression_statement 
		{
			deleteExpression(&$<exp>1);
		}
	|	if_statement 
	|	declaration
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
			$<exp>$ =  $<exp>1;
		}
	;

primary_expression:
		string { $<exp>$ = $<exp>1; }
	|	number { $<exp>$ = $<exp>1; }
	|	LPAREN expression RPAREN { $<exp>$ = $<exp>2; }
	;
	
expression:
		assignment_expression { $<exp>$ = $<exp>1; }
	|	concat_expression { $<exp>$ = $<exp>1; }
	;
	
concat_expression:
		string { $<exp>$ = $<exp>1; }
	|	string CONCAT string { $<exp>$ = createOperation(eCONCAT, $<exp>1, $<exp>3); }
	|	string CONCAT expression { $<exp>$ = createOperation(eCONCAT, $<exp>1, $<exp>3);}
	|	expression CONCAT string { $<exp>$ = createOperation(eCONCAT, $<exp>1, $<exp>3);}
	;

assignment_expression:
		conditional_expression { $<exp>$ = $<exp>1; }
	|	unary_expression EQ_OP assignment_expression 
	|	unary_expression NE_OP assignment_expression
	|	unary_expression MUL_EQU assignment_expression
	|	unary_expression ADD_EQU assignment_expression
	|	unary_expression SUB_EQU assignment_expression
	|	unary_expression DIV_EQU assignment_expression
	|	unary_expression AND_EQU assignment_expression
	|	unary_expression OR_EQU assignment_expression
	|	unary_expression L_EQU assignment_expression
	|	unary_expression R_EQU assignment_expression
	;

constant_expression:
		conditional_expression { $<exp>$ = $<exp>1; }
	;

conditional_expression:
		logical_or_expression { $<exp>$ = $<exp>1; }
	|	logical_or_expression TERNARY expression COLON expression 
		{
			 if(evaluateIntExpression($<exp>1))
			 	$<exp>$ = createNumber(evaluateIntExpression($<exp>3));
			 else
			 	$<exp>$ = createNumber(evaluateIntExpression($<exp>5));
			 
		}
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
	|	additive_expression SUB multiplicative_expression {$<exp>$ = createOperation(eSUBTRACT, $<exp>1, $<exp>3);}
	|	additive_expression multiplicative_expression { $<exp>$ = createOperation(ePLUS, $<exp>1, $<exp>2); }
	;

multiplicative_expression:
		unary_expression { $<exp>$ = $<exp>1; }
	|	multiplicative_expression MUL unary_expression { $<exp>$ = createOperation(eMULTIPLY, $<exp>1, $<exp>3); }
	|	multiplicative_expression DIV unary_expression { $<exp>$ = createOperation(eDIVIDE, $<exp>1, $<exp>3); }
	|	multiplicative_expression MOD unary_expression { $<exp>$ = createOperation(eMOD, $<exp>1, $<exp>3); }
	|	multiplicative_expression POW unary_expression { $<exp>$ = createOperation(ePOW, $<exp>1, $<exp>3); }
	;
	
unary_expression:
		postfix_expression { $<exp>$ = $<exp>1;}
	|	INC unary_expression { $<ival>$ = ++$<ival>2; }
	|	DEC unary_expression { $<ival>$ = --$<ival>2; }
	|	TO_INT LPAREN expression RPAREN
		{
			$<exp>$ = createNumber(to_int($<exp>3));
		}
	|	SQRT LPAREN expression RPAREN 
		{
			$<exp>$ = createNumber((int)sqrt(evaluateIntExpression($<exp>3)));
		}
	|	CBRT LPAREN expression RPAREN 
		{
			$<exp>$ = createNumber((int)cbrt(evaluateIntExpression($<exp>3)));
		}
	|	PRINTLN LPAREN expression RPAREN
		{
			cout << evaluateExpression($<exp>3) << endl;
			fflush(stdout);
			$<exp>$ = createNumber(0);
		}
	|	PRINTNL LPAREN expression RPAREN
		{
			cout << evaluateExpression($<exp>3);
			fflush(stdout);
			$<exp>$ = createNumber(0);
		}
	|	SYSCALL LPAREN expression RPAREN
		{
			system(evaluateExpression($<exp>3).c_str());
			$<exp>$ = createNumber(0);
		}
	|	TOKEN_READ LPAREN TYPE_INT RPAREN
		{
			$<exp>$ = createNumber(intInput());
		}
	|	TOKEN_READ LPAREN TYPE_BYTE RPAREN
		{
			$<exp>$ = createNumber(byteInput());
		}
	|	TOKEN_READ LPAREN TYPE_SHORT RPAREN
		{
			$<exp>$ = createNumber(shortInput());
		}
	|	TOKEN_READ LPAREN TYPE_LONG RPAREN
		{
			$<exp>$ = createNumber(longInput());
		}
	|	TOKEN_READ LPAREN TYPE_LONG RPAREN
		{
			$<exp>$ = createNumber(longInput());
		}
	;
unary_operator:
		AND
	| 	ADD 
	|	SUB 
	|	'~' 
	|	'!'
	;

postfix_expression:
		primary_expression { $<exp>$ = $<exp>1;}
	|	postfix_expression INC 
	|	postfix_expression DEC 
	;
	
if_statement:
		IF LPAREN expression RPAREN compound_statement 
		{ 
			if(evaluateIntExpression($<exp>3))
			{
				$<exp>$ = $<exp>5;
			} 
		}
	|	IF LPAREN expression RPAREN compound_statement ELSE compound_statement
	;

loop_statement:
		WHILE LPAREN expression RPAREN compound_statement { cout << "el while!: " << endl; }
	;

compound_statement:
		statement
	|	TOKEN_BEGIN TOKEN_END
	|	TOKEN_BEGIN statement_list TOKEN_END
	|	TOKEN_BEGIN declaration_list TOKEN_END
	|	TOKEN_BEGIN declaration_list statement_list TOKEN_END
	;

jump_statement:
		CONTINUE SEMICOLON
	|	BREAK SEMICOLON
	;


declaration:
		declaration_specifiers SEMICOLON
	|	declaration_specifiers init_declarator_list SEMICOLON
	;

declaration_specifiers:
		type_specifier
	|	type_specifier declaration_specifiers
	|	VAR LTHAN declaration_specifiers GTHAN TOKEN_ID;
	|	VAR TOKEN_ID EQUAL expression
	;

type_specifier:
		TYPE_INT
	|	TYPE_SHORT
	|	TYPE_LONG
	|	TYPE_BYTE
	|	TYPE_STRING
	;

direct_declarator:
		TOKEN_ID
	|	LPAREN direct_declarator RPAREN
	;

declaration_list:
		declaration
	|	declaration_list declaration
	;	

identifier_list:
		TOKEN_ID
	;

init_declarator:
		direct_declarator
	|	direct_declarator EQ_OP initializer
	;
	
initializer:
		assignment_expression
	;

initializer_list:
		initializer
	;

init_declarator_list:
		init_declarator
	;

number:
		INT { $<exp>$ = $<exp>1;}
	|	TRUE { $<exp>$ = $<exp>1;}
	|	FALSE { $<exp>$ = $<exp>1;}
	|	FLOAT { $<exp>$ = createFloatNumber($<fval>1); }
	;
	
string:
		STRING { $<exp>$ = $<exp>1; }
	|	STRING_LITERAL { $<exp>$ = $<exp>1; }
	|	TO_STRING LPAREN expression RPAREN
		{
			$<exp>$ = createStr((char*)to_string($<exp>3).c_str());
		}
	|	TOKEN_READ LPAREN RPAREN
		{
			$<exp>$ = createStr(strInput());
		}
	|	TOKEN_READ LPAREN TYPE_STRING RPAREN
		{
			$<exp>$ = createStr(strInput());
		}
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
	return 0;
}
