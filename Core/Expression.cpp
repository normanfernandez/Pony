/*
 * Expression.cpp
 *
 *  Created on: Sep 2, 2014
 *      Author: Norman
 */

/*
 * Expression.c
 * Implementation of functions used to build the syntax tree.
 */

#include "Expression.hpp"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Allocates space for expression
 * @return The expression or NULL if not enough memory
 */


SExpression *allocateExpression(int num)
{
    SExpression *b = new SExpression;

    if (b == NULL)
        return NULL;

    b->type = eVALUE;
    b->value = num;

    b->left = NULL;
    b->right = NULL;

    return b;
}


SExpression *allocateExpression()
{
	return allocateExpression(0);
}

SExpression *createNumber(int value)
{

    SExpression *b = allocateExpression(value);
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

void deleteExpression(SExpression **b)
{
    if (*b == NULL)
        return;

    deleteExpression(&((*b)->left));
    deleteExpression(&((*b)->right));

    delete *b;
}
