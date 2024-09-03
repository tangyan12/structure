/**********************
*       INCLUDE        
**********************/
#include "LinkList.h"
/**********************
*       DEFINE
**********************/

/**********************
*   GLOBAL VARIABLE
**********************/

/**********************
*     FUNCTIONS
**********************/
/** 
单链表：
    优点：
        内存不会浪费
    缺点：
        稍微有点复杂
双链表：
    双链表和单链表的区别就是结点中指针域的个数，所以插入删除时需要特别注意前驱和后继指针域的修改
    双链表一般都是循环链表，循环链表的话判断链表遍历完所有结点的条件应该是p ！= L(头结点)，还是比较复杂的
*/
LinkList_status LinkList_init(LinkList_H *L)
{
    LNode * lnode = (LNode *)malloc(sizeof(LNode));
    if(lnode == NULL){
        return LinkList_MALLOC_ERROR;
    }
    lnode->next = NULL;
    *L = lnode;
    return LinkList_OK;
}
LinkList_status LinkList_add_front(LinkList_H L,ElemType elem)
{
    LNode * lnode = (LNode*)malloc(sizeof(LNode));
    if(lnode == NULL){
        return LinkList_MALLOC_ERROR;
    }
    lnode->data = elem;
    lnode->next = L->next;
    L->next = lnode;
    return LinkList_OK;
}
LinkList_status LinkList_add_pos(LinkList_H L,ElemType elem,int pos)
{
    LNode * p = L; int j=0;
    while ( p && (j < pos-1))//为什么要从头结点开始，因为头结点就是第0个结点,就跟数组一样
    {
        p = p->next;
        j++;
    }
    if(!p || j>pos-1){
        return LinkList_INVAILD_PARAM;
    }
    LNode * lnode = (LNode*)malloc(sizeof(LNode));
    if(lnode == NULL){
        return LinkList_MALLOC_ERROR;
    }
    lnode->data = elem;
    lnode->next = p->next;
    p->next = lnode;
    return LinkList_OK;
}
LinkList_status LinkList_del_pos(LinkList_H L,int pos)
{
    LNode * p=L;LNode * q; int j=0;
    while ( p->next && (j < pos-1))//这里是为了确保第pos-1个节点的指针域不为空，因为如果为空，则第pos个节点不存在
    {
        p = p->next;
        j++;
    }
    if(!(p->next) || j>pos-1){
        return LinkList_INVAILD_PARAM;
    }
    LNode * lnode = (LNode*)malloc(sizeof(LNode));
    if(lnode == NULL){
        return LinkList_MALLOC_ERROR;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return LinkList_OK;
}
int LinkList_get_listlength(LinkList_H L)
{
    LNode *p=L->next;//为什么从首元结点开始，按数组的方法确实是从0开始，但是头结点不算有效的结点
    int length = 0;
    while (p)
    {
        p = p->next;
        length++;
    }
    return length;
}
void LinkList_free_all(LinkList_H L)
{
    LNode *p = L;
    LNode *q;
    while (p)
    {
        q = p;
        p = p->next;
        free(q);
    }
    
}
LinkList_status LinkList_getvalue(LinkList_H L,ElemType * pelem,int pos)
{
    LNode *p = L->next;
    int j = 1;
    while (p && j<pos)
    {
        p = p->next;
        j++;
    }
    if(!p || j>pos){
        return LinkList_INVAILD_PARAM;
    }
    *pelem = p->data;
    return LinkList_OK;
}
void LinkList_test(void)
{
    int res;
    LinkList_H L;
    res = LinkList_init(&L);
    if(res != 0){
        printf("init error");
        return;
    }
    printf("init ok\n");
    printf("now list length is %d\n",LinkList_get_listlength(L));
    res = LinkList_add_front(L,1);
    if(res != 0){
        printf("add front error");
        return;
    }
    printf("now list length is %d\n",LinkList_get_listlength(L));
    res = LinkList_add_pos(L,2,2);
    if(res != 0){
        printf("add pos error");
        return;
    }
    printf("now list length is %d\n",LinkList_get_listlength(L));
    printf("first node is %d,second node is %d\n",L->next->data,L->next->next->data);

    res = LinkList_del_pos(L,1);
    if(res != 0){
        printf("del error");
        return;
    }
    printf("now list length is %d\n",LinkList_get_listlength(L));
    printf("first node is %d\n",L->next->data);
    ElemType elem;
    res = LinkList_getvalue(L,&elem,1);
    if(res != 0){
        printf("get error");
        return;
    }
    printf("get data %d\n",elem);
    LinkList_free_all(L);
    printf("success");
}