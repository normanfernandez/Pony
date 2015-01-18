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
#include <cmath>
#include <cstdio>


SExpression *allocateExpression(int num)
{
    SExpression *exp = new SExpression;
    exp->type = eVALUE;
    exp->value = num;

    exp->left = nullptr;
    exp->right = nullptr;

    return exp;
}

SExpression *allocateExpression(char * str)
{
    SExpression *exp = new SExpression;
    exp->type = eSTRING;
    exp->str = std::string(str);
    exp->value = -1;

    exp->left = nullptr;
    exp->right = nullptr;

    return exp;
}

SExpression *allocateExpression()
{
	return allocateExpression(0);
}

SExpression *createNumber(int value)
{
    SExpression *exp = allocateExpression((int)value);
    return exp;
}

SExpression *createStr(char * str)
{
    SExpression *exp = allocateExpression((char*)str);
    return exp;
}

SExpression *createOperation(EOperationType type, SExpression *left, SExpression *right)
{
    SExpression *exp = allocateExpression();
    if (exp == nullptr)
        return nullptr;

    exp->type = type;
    exp->left = left;
    exp->right = right;

    return exp;
}

void deleteExpression(SExpression **exp)
{
    if (*exp)
        return;

    deleteExpression(&((*exp)->left));
    deleteExpression(&((*exp)->right));

    delete *exp;
    *exp = nullptr;
}
