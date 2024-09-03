#ifndef __SQSTACK_H__
#define __SQSTACK_H__
/**********************
*       INCLUDE        
**********************/
#include "malloc.h"
#include "stdio.h"
/**********************
*       DEFINE
**********************/
typedef int ElemType;
typedef struct 
{
    ElemType * base;
    ElemType * top;
    int maxsize;
}SqStack;
typedef enum {
    SQSTACK_OK,
    SQSTACK_ERROR,
    SQSTACK_INVAILD_PARAM,
    SQSTACK_EMPTY,
    SQSTACK_OVERFLOW,
    SQSTACK_MALLOC_ERROR
}SqStack_status;
/**********************
*   EXTERN VARIABLE
**********************/

/**********************
*  FUNCTIONS DECLARE
**********************/
void SqStack_test(void);
SqStack_status SqStack_init(SqStack *S);
SqStack_status SqStack_in(SqStack *S,ElemType elem);
SqStack_status SqStack_out(SqStack *S,ElemType *pelem);
SqStack_status SqStack_free(SqStack *S);
#endif