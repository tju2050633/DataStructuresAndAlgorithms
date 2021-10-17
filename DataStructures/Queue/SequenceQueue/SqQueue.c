/*
 * @Author: Lu Jialin 
 * @Date: 2021-09-14 16:14:39 
 * @Last Modified by: Lu Jialin
 * @Last Modified time: 2021-10-03 10:34:26
 */
//线性表的基本操作---顺序存储结构

#include <stdio.h>
#include <stdlib.h>
#include "SqQueue.h"

void Queue_Init(SqQueuePtr qu, int size)
{
    qu->elem = (ElemType *)malloc(sizeof(ElemType) * (size + 1));
    qu->size = size;
    qu->length = 0;
    qu->head = 0;
    qu->tail = 0; //head指向第一个元素前面一个元素，tail指向最后一个元素
}
ElemType Queue_Out(SqQueuePtr qu)
{
    ElemType e;
    if (Queue_Empty(qu))
    {
        printf("队列已空，出队失败\n");
        return -999;
    }
    else
    {
        qu->head++;
        if (qu->head > qu->size) //假上溢，head恢复至1处
            qu->head = 1;
        e = qu->elem[qu->head];
        qu->elem[qu->head] = 0;

        qu->length--;
    }
    return e;
}
void Queue_In(SqQueuePtr qu, ElemType item)
{
    if (Queue_Full(qu))
    {
        printf("队列已满，入队失败\n");
        return;
    }
    else
    {
        qu->tail++;
        if (qu->tail > qu->size) //假上溢，tail恢复至1处
            qu->tail = 1;
        qu->elem[qu->tail] = item;

        qu->length++;
    }
}
bool Queue_Empty(SqQueuePtr qu)
{
    return qu->length == 0;
}
bool Queue_Full(SqQueuePtr qu)
{
    return qu->length == qu->size;
}
void Queue_Print(SqQueuePtr qu)
{
    printf("打印队列元素：");
    for (int i = 1; i <= qu->size; i++)
    {
        printf("%d ", qu->elem[i]);
        if (i % 10 == 0 && i != 0) //每十个元素换行
            printf("\n");
    }
    printf("\n");
}