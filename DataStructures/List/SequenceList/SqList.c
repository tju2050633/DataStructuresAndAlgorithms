/*
 * @Author: Lu Jialin 
 * @Date: 2021-09-14 16:14:39 
 * @Last Modified by:   Lu Jialin 
 * @Last Modified time: 2021-09-14 16:14:39 
 */
//线性表的基本操作---顺序存储结构

#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

Status List_Init(SqListPtr L)
{                    //初始化顺序表
    Status s = fail; //默认状态是失败
    if (L != NULL)   //当线性表存在
    {
        L->elem = (ElemType *)malloc(sizeof(ElemType) * (LIST_INIT_SIZE + 1)); //给线性表的elem指针分配空间（比总长大一，因为第一个位置不用）
        if (L->elem)    //如果elem指针不为空（分配空间成功）
        {
            L->list_size = LIST_INIT_SIZE;
            L->length = 0;
            s = success;
        }
    }
    return s;
}
void List_Destroy(SqListPtr L)
{
    if (L) //如果线性表存在
    {
        if (L->elem) //如果elem指针不为空
        {
            free(L->elem); //释放elem指针，使之指向空，线性表长度置为0
            L->elem = NULL;
            L->length = 0;
        }
    }
}
void List_Clear(SqListPtr L)
{
    if (L) //如果线性表存在
    {
        L->length = 0; //清空就是length置为0
    }
}
bool List_Empty(SqListPtr L)
{
    return (L->length == 0); //判空就是length是否为0
}
int List_Size(SqListPtr L)
{
    return L->length; //线性表size就是length
}
Status List_Retrival(SqListPtr L, int pos, ElemType *elem)
{
    Status s = range_error; //默认发生越界错误
    if (L)                  //如果线性表存在
    {
        if (pos >= 1 && pos <= L->length) //如果pos合法
        {
            *elem = L->elem[pos]; //pos处元素存入elem形参
            s = success;
        }
    }
    return s;
}
Status List_Locate(SqListPtr L, ElemType elem, int *pos)
{
    Status s = range_error; //默认发生越界错误
    int i = 1;
    if (L) //如果线性表存在
    {
        for (i = 1; i <= L->length; ++i) //遍历寻找匹配元素，i存入pos形参
        {
            if (L->elem[i] == elem)
            {
                *pos = i;
                s = success;
                break;
            }
        }
    }
    return s;
}
Status List_Insert(SqListPtr L, int pos, ElemType elem)
{
    Status s = range_error; //默认发生越界错误
    int i;
    if (L) //如果线性表存在
    {
        if (pos >= 1 && pos <= L->length + 1) //如果pos合法
        {
            if (L->length < L->list_size) //线性表未满
            {
                for (i = L->length; i >= pos; --i) //从后往前元素后移一位
                    L->elem[i + 1] = L->elem[i];
                L->elem[i + 1] = elem; //elem形参存入线性表
                L->length++;       //线性表长度加一
                s = success;
            }
        }
    }
    return s;
}
Status List_Delete(SqListPtr L, int pos)
{
    Status s = range_error; //默认发生越界错误
    int i;
    if (L) //如果线性表存在
    {
        if (pos >= 1 && pos <= L->length) //如果pos合法
        {
            for (i = pos; i < L->length; i++) //从前往后元素前移一位
                L->elem[i] = L->elem[i + 1];
            L->length--; //线性表长度减一
            s = success;
        }
    }
    return s;
}
Status List_Prior(SqListPtr L, int pos, ElemType *elem)
{
    Status s = range_error; //默认发生越界错误
    if (L)                  //如果线性表存在
    {
        if (pos > 1 && pos <= L->length) //如果pos合法
        {
            *elem = L->elem[pos - 1];
            s = success;
        }
    }
    return s;
}
Status List_Next(SqListPtr L, int pos, ElemType *elem)
{
    Status s = range_error; //默认发生越界错误
    if (L)                  //如果线性表存在
    {
        if (pos >= 1 && pos < L->length) //如果pos合法
        {
            *elem = L->elem[pos + 1];
            s = success;
        }
    }
    return s;
}
void List_Print(SqListPtr L)
{
    printf("打印线性表元素：");
    int i;
    if (L) //如果线性表存在
    {
        for (i = 1; i <= L->length; ++i) //遍历线性表并打印元素
        {
            printf("%d ", L->elem[i]);
            if (i % 10 == 0) //每十个元素换行
                printf("\n");
        }
    }
    printf("\n");
}
