%{
 
#include "Headers/Expression.hpp"
#include "Headers/BigInteger.hpp"
#include "Headers/Parser.hpp"
#include "Headers/Lexer.hpp"

extern "C"
{
	int yyparse(void);
    void yyerror(char *s){}
    int yywrap(void){return 1;}
}
 
void yyerror(SExpression **expression, yyscan_t scanner, const char *msg) {
    // Add error handling routine as needed
    fprintf(stderr, "%s\n", msg);
}
 
%}
 
%code requires {
 
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
struct YYLTYPE;
#endif

}
 
%output  "Src/Parser.cpp"
%defines "Src/Headers/Parser.hpp"
 
%define api.pure
%lex-param   { yyscan_t scanner }
%parse-param { SExpression **expression }
%parse-param { yyscan_t scanner }
 
%union {
    BigInteger * value;
    char * id;
    SExpression *expression;
}
 
%left TOKEN_PLUS TOKEN_MINUS
%left TOKEN_MULTIPLY TOKEN_SLASH
 
%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_PLUS
%token TOKEN_SEMICOLON
%token TOKEN_SINGLE
%token TOKEN_PRINT
%token TOKEN_QUOTATION
%token TOKEN_SLASH
%token TOKEN_MINUS
%token TOKEN_MULTIPLY
%token <value> TOKEN_NUMBER
%token <id> TOKEN_CHARSET
 
%type <expression> expr
 
%%
 
input
    : expr { *expression = $1; }
    ;

expr
    : expr[L] TOKEN_PLUS expr[R] { $$ = createOperation( ePLUS, $L, $R ); }
    | expr[L] TOKEN_MULTIPLY expr[R] { $$ = createOperation( eMULTIPLY, $L, $R ); }
    | expr[L] TOKEN_MINUS expr[R] { $$ = createOperation( eSUBTRACT, $L, $R ); }
    | expr[L] TOKEN_SLASH expr[R] { $$ = createOperation( eDIVIDE, $L, $R ); }
    | TOKEN_LPAREN expr[E] TOKEN_RPAREN { $$ = $E; }
    | TOKEN_NUMBER { $$ = createNumber($1); }
    ;
 
%%