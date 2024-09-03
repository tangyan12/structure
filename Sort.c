/**********************
*       INCLUDE        
**********************/
#include "Sort.h"
#include "stdio.h"
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
* @brief
* @param
* @return
*/
void Straight_insert_sort(int * array,int length)
{
    int i,j;
    if(length <= 1){
        return;
    }
    for (i = 2; i <=length ; i++)
    {
        if(array[i] < array[i-1]){
            array[0] = array[i];
            array[i] = array[i-1];
            for (j = i-2; array[0] < array[j]; j--)
            {
                array[j+1] = array[j];
            }
            array[j+1] = array[0];
        }
    }
}
void Binary_insert_sort(int * array,int length)
{
    int i,j;
    int low,high,middle;
    if(length <= 1){
        return;
    }
    for (i = 2; i <=length ; i++)
    {
        if(array[i] < array[i-1]){
            low = 1;
            high = i-1;
            middle = (low+high)/2;
            array[0] = array[i];
            while (low<=high)
            {
                if(array[0] < array[middle]){
                    high = middle -1;
                }
                else
                    low = middle + 1;
                middle = (low+high)/2;
            }
            for ( j = i-1; j>=high+1; j--)
            {
                array[j+1] = array[j];
            }
            array[high+1] = array[0];
        }
    }
}
void Bubble_sort(int * array,int length)
{
    int m = length-1;
    int flag = 1;
    int temp;
    if(length <= 1){
        return;
    }
    while (flag && m>0)
    {
        flag = 0;
        for (int i = 0; i < m; i++)
        {
            if(array[i] > array[i+1]){
                flag = 1;
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
        m--;
    }
}

void Sort_test(void)
{
    int array[]={0,32,62,22,11,16};
    printf("array now is sort as 32,62,22,11,16\n");
    Straight_insert_sort(array,5);
    for (int i = 1; i <= 5; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");

    int array2[] = {0,12,2,42,22,16};
    printf("array now is sort as 12,2,42,22,16\n");
    Binary_insert_sort(array2,5);
    for (int i = 1; i <= 5; i++)
    {
        printf("%d ",array2[i]);
    }
    printf("\n");

    int array3[] = {19,10,14,19,54,20};
    printf("array now is sort as 19,10,14,19,54,20\n");
    Bubble_sort(array3,6);
    for (int i = 0; i <= 5; i++)
    {
        printf("%d ",array3[i]);
    }
    printf("\n");
}