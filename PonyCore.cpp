/*
 * PonyCore.cpp
 *
 *  Created on: Nov 7, 2014
 *      Author: n
 */


#include "PonyCore.h"
#include "PonyInt.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

IntegerStruct * allocateInteger(pony_byte size){
	IntegerStruct * int_struct = new IntegerStruct;
	int_struct->size = size;
	setInteger(&int_struct, 0);
	return int_struct;
}

std::string getInteger(IntegerStruct * int_struct){
	std::string str;
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
	str = convert.str();
	return str;
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
