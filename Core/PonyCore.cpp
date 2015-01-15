/*
 * PonyCore.cpp
 *
 *  Created on: Nov 7, 2014
 *      Author: n
 */


#include "PonyCore.h"
#include "PonyInt.h"
#include "Expression.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstring>

extern "C" void yyerror(const char*);

void allocateInteger(const char * var_label,pony_byte size){
	if(int_list.find(var_label) != int_list.end()){
		std::cerr << "variable already declared!" << std::endl;
		exit(-1);
	}
	int_list[var_label] = new IntegerStruct;
	int_list[var_label]->size = size;
	setInteger(&int_list[var_label], 0);
}

std::string getInteger(IntegerStruct * int_struct){
	std::ostringstream convert;
	switch(int_struct->size){
		case eCHAR:
			convert << (pony_short)__getChar(int_struct->val);
		break;

		case eBYTE:
			convert << (pony_short)__getByte(int_struct->val);
		break;

		case eSHORT:
			convert << __getShort(int_struct->val);
		break;

		case eINT:
			convert << __getInt(int_struct->val);
		break;

		case eLONG:
			convert << __getLong(int_struct->val);
		break;
	}
	return convert.str();
}

void setInteger(IntegerStruct ** int_struct, intptr_t num){
	switch((*int_struct)->size){
		case eCHAR:
			(*int_struct)->val = new pony_char;
			__setByte((*int_struct)->val, num);
		break;

		case eBYTE:
			(*int_struct)->val = new pony_byte;
			__setByte((*int_struct)->val, num);
		break;

		case eSHORT:
			(*int_struct)->val = new pony_short;
			__setShort((*int_struct)->val, num);
		break;

		case eINT:
			(*int_struct)->val = new pony_int;
			__setInt((*int_struct)->val, num);
		break;

		case eLONG:
			(*int_struct)->val = new pony_long;
			__setLong((*int_struct)->val, num);
		break;
	}
}


int evaluateIntExpression(SExpression *exp)
{
	switch(exp->type)
	{
		case ePLUS:
			return evaluateIntExpression(exp->left) + evaluateIntExpression(exp->right);
		case eMULTIPLY:
			return evaluateIntExpression(exp->left) * evaluateIntExpression(exp->right);
		case eSUBTRACT:
			return evaluateIntExpression(exp->left) + evaluateIntExpression(exp->right);
		case eDIVIDE:
			return evaluateIntExpression(exp->left) / evaluateIntExpression(exp->right);
		case eMOD:
			return evaluateIntExpression(exp->left) % evaluateIntExpression(exp->right);
		case eLOGIC_OR:
			return evaluateIntExpression(exp->left) || evaluateIntExpression(exp->right);
		case eLOGIC_AND:
			return evaluateIntExpression(exp->left) && evaluateIntExpression(exp->right);
		case eOR:
			return evaluateIntExpression(exp->left) | evaluateIntExpression(exp->right);
		case eAND:
			return evaluateIntExpression(exp->left) & evaluateIntExpression(exp->right);
		case eXOR:
			return evaluateIntExpression(exp->left) ^ evaluateIntExpression(exp->right);
		case ePOW:
			return pow(evaluateIntExpression(exp->left),evaluateIntExpression(exp->right));
		case eVALUE:
			return exp->value;

		default:
			return -1; //Error happens!
	}
}
