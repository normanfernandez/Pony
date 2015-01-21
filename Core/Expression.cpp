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
    exp->value = new IntegerStruct;
    exp->value->size = size;
    setInteger(&exp->value, num);
    __setNodesNull(exp);
    return exp;
}

SExpression *allocateExpression(int num, PonyInt size)
{
    SExpression *exp = new SExpression;
    exp->type = eVALUE;
    exp->value = new IntegerStruct;
    exp->value->size = size;
    setInteger(&exp->value, num);

    __setNodesNull(exp);
    return exp;
}

SExpression *allocateFloatExpression(float num)
{
	SExpression *exp = new SExpression;
    exp->type = eFLOAT;
    exp->fvalue = num;
    exp->isfloat = 1;

    __setNodesNull(exp);
    return exp;
}

SExpression *allocateExpression(char * str)
{
    SExpression *exp = new SExpression;
    exp->type = eSTRING;
    exp->str = std::string(str);
    exp->value = nullptr;

    __setNodesNull(exp);
    return exp;
}

SExpression *allocateExpression()
{
	return allocateExpression(0, eINT);
}

SExpression *createNumber(int value, PonyInt type)
{
    return allocateExpression(value, type);
}

SExpression *createNumber(int value)
{
    return createNumber(value, eINT);
}

SExpression *createFloatNumber(float value)
{
	return allocateFloatExpression((float)value);
}

SExpression *createStr(char * str)
{
    return allocateExpression((char*)str);
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
    delete (*exp)->value;
    deleteExpression(&((*exp)->left));
    deleteExpression(&((*exp)->right));

    delete *exp;
    *exp = nullptr;
}
