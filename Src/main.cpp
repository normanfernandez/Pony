/*
 * main.c file
 */

#include "Headers/Expression.hpp"
#include "Headers/FileRead.hpp"
#include "Headers/Parser.hpp"
#include "Headers/Lexer.hpp"
#include <iostream>

using namespace std;

extern int yylex_init(yyscan_t);

SExpression *getAST(const char *expr)
{
    SExpression *expression;
    yyscan_t scanner;
    YY_BUFFER_STATE state;

    if (yylex_init(&scanner)) {
        // couldn't initialize
        return NULL;
    }

    state = yy_scan_string(expr);

    if (yyparse(&expression, scanner)) {
        // error parsing
    	cerr << "Error con la expresion" << endl;
        return NULL;
    }

    yy_delete_buffer(state);

    //yylex_destroy(scanner);

    return expression;
}

BigInteger evaluate(SExpression *e)
{
    switch (e->type) {
        case eVALUE:
            return *(e->value);
        case eMULTIPLY:
            return evaluate(e->left) * evaluate(e->right);
        case eDIVIDE:
        	return evaluate(e->left) / evaluate(e->right);
        case eSUBTRACT:
        	return evaluate(e->left) - evaluate(e->right);
        case ePLUS:
            return evaluate(e->left) + evaluate(e->right);
        default:
            // shouldn't be here
            return *(new BigInteger());
    }
}

int main(void)
{
    SExpression *e = NULL;
    char test[]= "100000000*908098879879743";

    e = getAST(test);

    cout << "El resultado de " << test << " es: " << evaluate(e).getNumber() << endl;

    deleteExpression(e);

    return 0;
}
