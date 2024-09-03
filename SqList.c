/**********************
*       INCLUDE        
**********************/
#include "SqList.h"

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
缺点：
    顺序表长度固定，可能会造成大量的空间浪费
    顺序表的插入和删除较为繁琐费时，因为每次要移动数组成员位置
优点：
    思维逻辑简单
    因为物理上也是连续的，所以每个元素地址很好确定
*/
SqList_status SqList_init(SqList *L)
{
    ElemType * elem = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    if(elem == NULL){
        return SQLIST_MALLOC_ERROR;
    }
    L->elem = elem;
    L->length = 0;
    return SQLIST_OK;
}
SqList_status SqList_getvalue(SqList *L,ElemType *pelem,int pos)
{
    if(pos < 1 || pos >L->length ){
        return SQLIST_INVAILD_PARAM;
    }
    *pelem = L->elem[pos-1];
    return SQLIST_OK;
}
SqList_status SqList_add(SqList *L,ElemType elem,int pos)
{
    if(L->length >= MAXSIZE){
        return SQLIST_OVERFLOW;
    }
    if(pos <1){
        return SQLIST_INVAILD_PARAM;
    }
    for (int i = L->length-1; i >= pos-1; i--)
    {
        L->elem[i+1] = L->elem[i];
    }
    L->elem[pos-1] = elem;
    L->length++;
    return SQLIST_OK;
}
SqList_status SqList_del(SqList *L,int pos)
{
    if(L->length == 0){
        return SQLIST_EMPTY;
    }
    if(pos <1 || pos >L->length){
        return SQLIST_INVAILD_PARAM;
    }
    for (int i = pos; i <= L->length-1; i++)
    {
        L->elem[i-1] = L->elem[i];
    }
    L->length--;
    return SQLIST_OK;
}
SqList_status SqList_free(SqList *L)
{
    free(L->elem);
    return SQLIST_OK;
}
void SqList_test(void)
{
    int res;
    SqList L ={0};
    res = SqList_init(&L);
    if(res != SQLIST_OK){
        printf("init error\n");
    }
    res = SqList_add(&L,1,1);
    if(res != SQLIST_OK){
        printf("add error\n");
    }
    res = SqList_add(&L,2,1);
    if(res != SQLIST_OK){
        printf("add 2 error");
    }
    res = SqList_del(&L,1);
    if(res != SQLIST_OK){
        printf("del error");
    }
    printf("elem[0] = %d",L.elem[0]);
    printf("elem[1] = %d",L.elem[1]);
    printf("now list length is %d",L.length);
    SqList_free(&L);
}
/*线性表的查找因为会根据数据元素类型不同产生较大差异*/