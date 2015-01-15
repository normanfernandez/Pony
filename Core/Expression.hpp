/*
 * Expression.h
 * Definition of the structure used to build the syntax tree.
 */
#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__

/**
 * @brief The operation type
 */
typedef enum tagEOperationType
{
    eVALUE,
    eSUBTRACT,
    eMULTIPLY,
    eDIVIDE,
    ePLUS,
    eLOGIC_OR,
    eLOGIC_AND,
    eAND,
    eOR,
    eXOR,
    ePOW,
    eLTHAN,
    eGTHAN,
    eLETHAN,
    eGETHAN,
    eEQUAL,
    eNEQUAL,
    eLEFT,
    eRIGHT,
    eLEFTE,
    eRIGHTE,
    eMOD
} EOperationType;

/**
 * @brief The expression structure
 */
typedef struct tagSExpression
{
    EOperationType type;///< type of operation

    int value;///< valid only when type is eVALUE
    struct tagSExpression *left; ///< left side of the tree
    struct tagSExpression *right;///< right side of the tree
} SExpression;

/**
 * @brief It creates an identifier
 * @param value The number value
 * @return The expression or NULL in case of no memory
 */
SExpression *createNumber(int value);
SExpression *allocateExpression();
SExpression *allocateExpression(int num);
SExpression *createOperation(EOperationType type, SExpression *left, SExpression *right);
void deleteExpression(SExpression **b);

#endif // __EXPRESSION_H__
/*
 * Expression.c
 * Implementation of functions used to build the syntax tree.
 */