/*
 * Core file for the Pony Language.
 * Int struct is found here.
 *
 * */

#ifndef PONY_CORE_H
#define PONY_CORE_H

#include "PonyInt.h"
#include "Expression.hpp"
#include <string>
#include <map>

struct _IntStruct
{
	pony_byte size;
	void * val;
};

typedef struct _IntStruct IntegerStruct;
static std::string stdin_buffer;
static std::map<const char*, IntegerStruct*> int_list;

//Functions
void allocateInteger(const char *, pony_byte);
std::string getInteger(IntegerStruct*);
void setInteger(IntegerStruct**, intptr_t);
pony_byte byteInput();
pony_int intInput();
pony_short shortInput();
pony_long longInput();
char * strInput();
std::string to_string(SExpression *);
int to_int(SExpression *);
std::string evaluateExpression(SExpression *);
int evaluateIntExpression(SExpression *);
float evaluateFloatExpression(SExpression *exp);
#endif
