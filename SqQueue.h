#ifndef __SQQUEUE_H__
#define __SQQUEUE_H__
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
    ElemType * data;
    int front;
    int rear;
}SqQueue;
typedef enum {
    SQQUEUE_OK,
    SQQUEUE_ERROR,
    SQQUEUE_INVAILD_PARAM,
    SQQUEUE_EMPTY,
    SQQUEUE_OVERFLOW,
    SQQUEUE_MALLOC_ERROR
}SqQueue_status;
/**********************
*   EXTERN VARIABLE
**********************/

/**********************
*  FUNCTIONS DECLARE
**********************/
void SqQueue_test(void);
SqQueue_status SqQueue_init(SqQueue *Q);
SqQueue_status SqQueue_in(SqQueue *Q,ElemType e);
SqQueue_status SqQueue_out(SqQueue *Q,ElemType *e);
int SqQueue_get_length(SqQueue *Q);
void SqQueue_free(SqQueue *Q);
#endif