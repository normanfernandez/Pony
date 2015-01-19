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
#include "PonyInt.h"
#include "PonyCore.h"
#include <cmath>
#include <cstdio>


SExpression *allocateVariable(int num, PonyInt size)
{
    SExpression *exp = new SExpression;
    exp->type = eIVARIABLE;
    exp->value = num;
    exp->variable = new IntegerStruct;
    exp->variable->size = size;
    setInteger(&exp->variable, num);

    exp->left = nullptr;
    exp->right = nullptr;

    return exp;
}

SExpression *allocateExpression(int num)
{
    SExpression *exp = new SExpression;
    exp->type = eVALUE;
    exp->value = num;

    exp->left = nullptr;
    exp->right = nullptr;

    return exp;
}

SExpression *allocateFloatExpression(float num)
{
	SExpression *exp = new SExpression;
    exp->type = eFLOAT;
    exp->fvalue = num;
    exp->isfloat =1;

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

SExpression *createFloatNumber(float value)
{
	SExpression *exp = allocateFloatExpression((float)value);
	return exp;
}

SExpression *createStr(char * str)
{
    SExpression *exp = allocateExpression((char*)str);
    return exp;
}

SExpression *createOperation(EOperationType type, SExpression *left, SExpression *right)
{
	if(type == eCONCAT)
	{
		std::string str = evaluateExpression(left) + evaluateExpression(right);
		return createStr((char*)str.c_str());
	}

	SExpression *exp = allocateExpression();

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
