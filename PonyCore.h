/*
 * Core file for the Pony Language.
 * Int struct is found here.
 *
 * */

#ifndef PONY_CORE_H
#define PONY_CORE_H

#include "PonyInt.h"
#include <string>
#include <map>

struct _IntStruct
{
	pony_byte size;
	void * val;
};

typedef struct _IntStruct IntegerStruct;


static std::map<const char*, IntegerStruct*> int_list;

//Functions
IntegerStruct * allocateInteger(pony_byte);
std::string getInteger(IntegerStruct*);
void setInteger(IntegerStruct**, intptr_t);

#endif
