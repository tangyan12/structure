#ifndef __SQLIST_H__
#define __SQLIST_H__
/**********************
*       INCLUDE        
**********************/
#include "malloc.h"
#include "stdint.h"
#include "stdio.h"
/**********************
*       DEFINE
**********************/
typedef int ElemType;

typedef struct 
{
    ElemType *elem;
    int length;
}SqList;

typedef enum {
    SQLIST_OK,
    SQLIST_ERROR,
    SQLIST_INVAILD_PARAM,
    SQLIST_EMPTY,
    SQLIST_OVERFLOW,
    SQLIST_MALLOC_ERROR
}SqList_status;
/**********************
*   EXTERN VARIABLE
**********************/

/**********************
*  FUNCTIONS DECLARE
**********************/

SqList_status SqList_init(SqList *L);
SqList_status SqList_getvalue(SqList *L,ElemType *pelem,int pos);
SqList_status SqList_add(SqList *L,ElemType elem,int pos);
SqList_status SqList_del(SqList *L,int pos);
SqList_status SqList_free(SqList *L);
void SqList_test(void);
#endif