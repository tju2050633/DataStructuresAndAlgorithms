/*
 * @Author: Lu Jialin 
 * @Date: 2021-09-14 16:15:08 
 * @Last Modified by:   Lu Jialin 
 * @Last Modified time: 2021-09-14 16:15:08 
 */
//线性表的基本操作---链式存储结构

#pragma once         //  只编译一次
#define ElemType int //假设要处理的数据是int型
#define bool int     //c语言无bool类型

typedef enum Status //status枚举四种状态
{
    success,
    fail,
    fatal,
    range_error
} Status;

typedef struct Node
{
    ElemType elem;
    struct Node *next;
} Node, *Ptr;

typedef Ptr *LkListPtr;

//声明函数
Status List_Init(LkListPtr L);
void List_Destroy(LkListPtr L);
void List_Clear(LkListPtr L);
bool List_Empty(LkListPtr L);
int List_Size(LkListPtr L);
Status List_Retrival(LkListPtr L, int pos, ElemType *elem);
Status List_Locate(LkListPtr L, ElemType elem, int *pos);
Status List_Find(LkListPtr L, int pos, Ptr *pAddr);
Status List_Insert(LkListPtr L, int pos, ElemType elem);
Status List_Delete(LkListPtr L, int pos);
Status List_Prior(LkListPtr L, int pos, ElemType *elem);
Status List_Next(LkListPtr L, int pos, ElemType *elem);
void List_Print(LkListPtr L);
