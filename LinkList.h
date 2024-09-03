#ifndef __LINKLIST_H__
#define __LINKLIST_H__
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
typedef struct Node
{
    ElemType data;
    struct Node * next;
}LNode,* LinkList_H;
typedef enum {
    LinkList_OK,
    LinkList_ERROR,
    LinkList_INVAILD_PARAM,
    LinkList_EMPTY,
    LinkList_MALLOC_ERROR
}LinkList_status;
/**********************
*   EXTERN VARIABLE
**********************/

/**********************
*  FUNCTIONS DECLARE
**********************/
void LinkList_test(void);
LinkList_status LinkList_init(LinkList_H *L);
LinkList_status LinkList_add_front(LinkList_H L,ElemType elem);
LinkList_status LinkList_add_pos(LinkList_H L,ElemType elem,int pos);
LinkList_status LinkList_del_pos(LinkList_H L,int pos);
LinkList_status LinkList_getvalue(LinkList_H L,ElemType * pelem,int pos);
int LinkList_get_listlength(LinkList_H L);
void LinkList_free_all(LinkList_H L);
#endif