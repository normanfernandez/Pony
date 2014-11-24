#ifndef PONY_INT_H
#define PONY_INT_H
#include <cstdint>

//Integer types for the language
#define PONY_BYTE_MAX __INT8_MAX__
#define PONY_SHORT_MAX __INT16_MAX__
#define PONY_INT_MAX __INT32_MAX__
#define PONY_LONG_MAX __INT64_MAX__

//Byte size constants
enum { eBYTE = 1, eSHORT = 2, eINT = 4, eLONG = 8};

typedef int8_t 	pony_byte;
typedef int16_t pony_short;
typedef int32_t pony_int;
typedef int64_t pony_long;

#define __getByte(num) 		\
	*(pony_byte*)num

#define __getShort(num)		\
	*(pony_short*)num

#define __getInt(num) 		\
	*(pony_int*)num

#define __getLong(num) 		\
	*(pony_long*)num

#define __setByte(num, val) \
	*(pony_byte*)num = val

#define __setShort(num, val)\
	*(pony_short*)num = val

#define __setInt(num, val) 	\
	*(pony_int*)num = val

#define __setLong(num, val) \
	*(pony_long*)num = val

#endif
