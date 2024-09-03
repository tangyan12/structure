/**********************
*       INCLUDE        
**********************/
#include "SqStack.h"
/**********************
*       DEFINE
**********************/
#define MAXSIZE 100
/**********************
*   GLOBAL VARIABLE
**********************/

/**********************
*     FUNCTIONS
**********************/
/** 
顺序栈：
    优点：简单易懂，只要操作两个指针就可以，且相关函数只有出栈和入栈
    缺点：浪费空间
*/
SqStack_status SqStack_init(SqStack *S)
{
    ElemType * pelem = (ElemType *)malloc(sizeof(ElemType)*MAXSIZE);
    if(pelem == NULL){
        return SQSTACK_MALLOC_ERROR;
    }
    S->base = pelem;
    S->top = S->base;
    S->maxsize = MAXSIZE;
    return SQSTACK_OK;
}
SqStack_status SqStack_in(SqStack *S,ElemType elem)
{
    if(S->top - S->base >= S->maxsize){
        return SQSTACK_OVERFLOW;
    }
    *(S->top) = elem;
    S->top++;
    return SQSTACK_OK;
}
SqStack_status SqStack_out(SqStack *S,ElemType *pelem)
{
    if(S->top == S->base){
        return  SQSTACK_EMPTY;
    }
    *pelem = *(S->top-1);
    S->top--;
    return SQSTACK_OK;
}
SqStack_status SqStack_free(SqStack *S)
{
    free(S->base);
    return SQSTACK_OK;
}
void SqStack_test(void)
{
    SqStack S;
    int res;
    res = SqStack_init(&S);
    if(res != 0){
        printf("init error"); 
        return;
    }
    for (int i = 0; i < 5; i++)
    {
        res = SqStack_in(&S,i);
        if(res != 0){
            printf("in error,i = %d\n",i);
            return;
        }
    }
    int out_data;
    for (int i = 0; i < 5; i++)
    {
        res = SqStack_out(&S,&out_data);
        if(res != 0){
            printf("out error,i = %d\n",i);
            return;
        }
        printf("stack out %d\n",out_data);
    }
    SqStack_free(&S);
}