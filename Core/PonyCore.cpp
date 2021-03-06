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
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <string>
#include <cmath>
#include <cstring>

extern "C" void yyerror(const char*);

void allocateInteger(const char * var_label,pony_byte size){
	if(int_list.find(var_label) != int_list.end()){
		std::cerr << "variable already declared!" << std::endl;
	}
	int_list[var_label] = new IntegerStruct;
	int_list[var_label]->size = size;
	setInteger(&int_list[var_label], 0);
}

std::string getInteger(IntegerStruct * int_struct){
	std::ostringstream convert;
	switch(int_struct->size){
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

std::string to_string(SExpression * exp)
{
	if(exp->type == eSTRING){
		return evaluateExpression(exp);
	}

	std::stringstream ss;

	if(exp->isfloat == 1){
		ss << evaluateFloatExpression(exp);
		return ss.str();
	}
	else if(exp->type == eIVARIABLE){
		return getInteger(exp->value);
	}
	else{
		ss << evaluateIntExpression(exp);
		return ss.str();
	}

}

int to_int(SExpression * exp)
{
	if(exp->type == eVALUE)
	{
		return __getInt(exp->value);
	}
	else if(exp->isfloat == 1)
	{
		return (int)exp->fvalue;
	}
	else if(exp->type == eSTRING)
	{
		return atoi(exp->str.c_str());
	}
	else
	{
		return -1;
	}
}

char *translate(char *string)
{
	/*Function source from:
	 * https://stackoverflow.com/questions/10686022/printing-strings-char-loaded-from-file-without-escaped-special-sequences-lik/10686377#10686377
	 * Thanks you so much Jerry Coffin! ^^
	 * */
      char *here=string;
      size_t len=strlen(string);
      int num;
      int numlen;

      while (NULL!=(here=strchr(here,'\\')))
      {
            numlen=1;
            switch (here[1])
            {
            case '\\':
                  break;

            case 'r':
                  *here = '\r';
                  break;

            case 'n':
                  *here = '\n';
                  break;

            case 't':
                  *here = '\t';
                  break;

            case 'v':
                  *here = '\v';
                  break;

            case 'a':
                  *here = '\a';
                  break;

            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
                  numlen = sscanf(here,"%o",&num);
                  *here = (char)num;
                  break;

            case 'x':
                  numlen = sscanf(here,"%x",&num);
                  *here = (char) num;
                  break;
            }
            num = here - string + numlen;
            here++;
            memmove(here,here+numlen,len-num );
      }
      return string;
}

pony_byte byteInput()
{
	pony_short a;
	std::cin >> a;
	pony_byte b = (pony_byte)a;
	return b;
}

pony_short shortInput()
{
	pony_short a;
	std::cin >> a;
	return a;
}

pony_int intInput()
{
	pony_int a;
	std::cin >> a;
	return a;
}

pony_long longInput()
{
	pony_long a;
	std::cin >> a;
	return a;
}

char * strInput()
{
	char *  buff = new char[1024];
	fscanf(stdin, "%s", buff);
	return (buff);
}

std::string evaluateExpression(SExpression *exp)
{
	if(exp->type == eSTRING)
		return exp->str;
	else if(exp->isfloat == 1)
	{
		std::stringstream intstr;
		intstr << evaluateFloatExpression(exp);
		return std::string(intstr.str());
	}
	else
	{
		std::stringstream intstr;
		intstr << evaluateIntExpression(exp);
		return std::string(intstr.str());
	}
}

float evaluateFloatExpression(SExpression *exp)
{
	switch(exp->type)
	{
		case ePLUS:
			return evaluateFloatExpression(exp->left) + evaluateFloatExpression(exp->right);
		case eMULTIPLY:
			return evaluateFloatExpression(exp->left) * evaluateFloatExpression(exp->right);
		case eSUBTRACT:
			return evaluateFloatExpression(exp->left) - evaluateFloatExpression(exp->right);
		case eDIVIDE:
			return evaluateFloatExpression(exp->left) / evaluateFloatExpression(exp->right);
		case eMOD:
			return fmod(evaluateFloatExpression(exp->left),evaluateFloatExpression(exp->right));
		case eLOGIC_OR:
			return evaluateFloatExpression(exp->left) || evaluateFloatExpression(exp->right);
		case eLOGIC_AND:
			return evaluateFloatExpression(exp->left) && evaluateFloatExpression(exp->right);
		case ePOW:
			return pow(evaluateFloatExpression(exp->left),evaluateFloatExpression(exp->right));
		case eLTHAN:
			return evaluateFloatExpression(exp->left) < evaluateFloatExpression(exp->right);
		case eLETHAN:
			return evaluateFloatExpression(exp->left) <= evaluateFloatExpression(exp->right);
		case eGTHAN:
			return evaluateFloatExpression(exp->left) > evaluateFloatExpression(exp->right);
		case eGETHAN:
			return evaluateFloatExpression(exp->left) >= evaluateFloatExpression(exp->right);
		case eEQUAL:
			return evaluateFloatExpression(exp->left) == evaluateFloatExpression(exp->right);
		case eNEQUAL:
			return evaluateFloatExpression(exp->left) != evaluateFloatExpression(exp->right);

		case eFLOAT:
			return exp->fvalue;
		case eVALUE:
			return __getInt(exp->value->val);

		default:
			return -1; //Error happens!
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
			return evaluateIntExpression(exp->left) - evaluateIntExpression(exp->right);
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
		case eLTHAN:
			return evaluateIntExpression(exp->left) < evaluateIntExpression(exp->right);
		case eLETHAN:
			return evaluateIntExpression(exp->left) <= evaluateIntExpression(exp->right);
		case eGTHAN:
			return evaluateIntExpression(exp->left) > evaluateIntExpression(exp->right);
		case eGETHAN:
			return evaluateIntExpression(exp->left) >= evaluateIntExpression(exp->right);
		case eEQUAL:
			return evaluateIntExpression(exp->left) == evaluateIntExpression(exp->right);
		case eNEQUAL:
			return evaluateIntExpression(exp->left) != evaluateIntExpression(exp->right);
		case eLEFT:
			return evaluateIntExpression(exp->left) << evaluateIntExpression(exp->right);
		case eRIGHT:
			return evaluateIntExpression(exp->left) >> evaluateIntExpression(exp->right);
		case eLEFTE:
			return evaluateIntExpression(exp->left) << evaluateIntExpression(exp->right);
		case eRIGHTE:
			return evaluateIntExpression(exp->left) >> evaluateIntExpression(exp->right);
		case eVALUE:
			return __getInt(exp->value->val);

		default:
			return -1; //Error happens!
	}
}
