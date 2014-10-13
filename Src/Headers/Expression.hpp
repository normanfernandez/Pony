/*
 * Expression.h
 * Definition of the structure used to build the syntax tree.
 */
#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__
#include "BigInteger.hpp"

/**
 * @brief The operation type
 */
typedef enum tagEOperationType
{
    eVALUE,
    eSTRING,
    eSUBTRACT,
    eMULTIPLY,
    eDIVIDE,
    ePLUS
} EOperationType;

/**
 * @brief The expression structure
 */
typedef struct tagSExpression
{
    EOperationType type;///< type of operation
    char * string;
    BigInteger * value;///< valid only when type is eVALUE
    struct tagSExpression *left; ///< left side of the tree
    struct tagSExpression *right;///< right side of the tree
} SExpression;

/**
 * @brief It creates an identifier
 * @param value The number value
 * @return The expression or NULL in case of no memory
 */
SExpression *createNumber(BigInteger * value);

/**
 * @brief It creates an operation
 * @param type The operation type
 * @param left The left operand
 * @param right The right operand
 * @return The expression or NULL in case of no memory
 */
SExpression *createOperation(EOperationType type, SExpression *left, SExpression *right);

/**
 * @brief Deletes a expression
 * @param b The expression
 */
void deleteExpression(SExpression *b);

#endif // __EXPRESSION_H__
/*
 * Expression.c
 * Implementation of functions used to build the syntax tree.
 */
