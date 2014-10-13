/*
 * Expression.cpp
 *
 *  Created on: Sep 2, 2014
 *      Author: Norman
 */

#include "Headers/Expression.hpp"
#include <string>
#include <cstdlib>

using namespace std;

/**
 * @brief Allocates space for expression
 * @return The expression or NULL if not enough memory
 */
static SExpression *allocateExpression()
{
    SExpression *b = new SExpression;

    if (b == NULL)
        return NULL;

    b->type = eVALUE;
    b->value = NULL;

    b->left = NULL;
    b->right = NULL;

    return b;
}

SExpression *createNumber(BigInteger * value)
{
    SExpression *b = allocateExpression();

    if (b == NULL)
        return NULL;

    b->type = eVALUE;
    b->value = new BigInteger(value->getNumber());

    return b;
}

SExpression *createOperation(EOperationType type, SExpression *left, SExpression *right)
{
    SExpression *b = allocateExpression();

    if (b == NULL)
        return NULL;

    b->type = type;
    b->left = left;
    b->right = right;

    return b;
}

void deleteExpression(SExpression *b)
{
    if (b == NULL)
        return;

    deleteExpression(b->left);
    deleteExpression(b->right);

    delete b;
}
