/**********************
*       INCLUDE        
**********************/
#include "SqQueue.h"
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
循环队列：
    该例为循环队列：
        实际应用有：串口收发+DMA+FIFO
    这里的数据区特意留了一个空位置用来方便判断队列是否满
*/
SqQueue_status SqQueue_init(SqQueue *Q)
{
    ElemType * data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    if(data == NULL){
        SQQUEUE_MALLOC_ERROR;
    }
    Q->data = data;
    Q->front = 0;
    Q->rear = 0;
    return SQQUEUE_OK;
}
SqQueue_status SqQueue_in(SqQueue *Q,ElemType e)
{
    if((Q->rear+1)%MAXSIZE == Q->front){
        return SQQUEUE_OVERFLOW;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1)%MAXSIZE;
    return SQQUEUE_OK;
}
SqQueue_status SqQueue_out(SqQueue *Q,ElemType *e)
{
    if(Q->rear == Q->front){
        return SQQUEUE_EMPTY;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front+1)%MAXSIZE;
    return SQQUEUE_OK;
}
int SqQueue_get_length(SqQueue *Q)
{
    return (Q->rear - Q->front + MAXSIZE)%MAXSIZE;
}
void SqQueue_free(SqQueue *Q)
{
    free(Q->data);
}
void SqQueue_test(void)
{
    printf("now init queue\n");
    int res;
    SqQueue Q;
    res = SqQueue_init(&Q);
    if(res != 0){
        printf("init error\n");
        return;
    }
    printf("now add something to queue\n");
    for (int i = 0; i < 3; i++)
    {
        res = SqQueue_in(&Q,i);
        if(res != 0){
            printf("add error\n");
            return;
        }
    }
    printf("now queue length is %d\n",SqQueue_get_length(&Q));
    ElemType e;
    while(1)
    {
        res = SqQueue_out(&Q,&e);
        if(res != 0){
            if(res == SQQUEUE_EMPTY){
                printf("read over\n");
                break;
            }
            else{
                printf("out error\n");
                return;
            }
        }
        printf("read %d from queue\n",e);
    }
    SqQueue_free(&Q);
}