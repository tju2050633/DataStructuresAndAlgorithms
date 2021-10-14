/*
 * @Author: Lu Jialin 
 * @Date: 2021-09-14 16:14:54 
 * @Last Modified by:   Lu Jialin 
 * @Last Modified time: 2021-09-14 16:14:54 
 */
//线性表的基本操作---顺序存储结构

#pragma once     //  只编译一次
#define bool int //c语言无bool类型
#define LIST_INIT_SIZE 100
#define LIST_INCREAMENT 10

typedef enum Status //status枚举四种状态
{
    success,
    fail,
    fatal,
    range_error
} Status;

typedef int ElemType; //假设要处理的数据是int型

typedef struct SqList
{ //结构体定义顺序表，包含元素指针（数组）、现有表长、总表长
    ElemType *elem;
    int length;
    int list_size;
} SqList, *Ptr, *SqListPtr;

//声明函数
Status List_Init(SqListPtr L);
void List_Destroy(SqListPtr L);
void List_Clear(SqListPtr L);
bool List_Empty(SqListPtr L);
int List_Size(SqListPtr L);
Status List_Retrival(SqListPtr L, int pos, ElemType *elem);
Status List_Locate(SqListPtr L, ElemType elem, int *pos);
Status List_Insert(SqListPtr L, int pos, ElemType elem);
Status List_Delete(SqListPtr L, int pos);
Status List_Prior(SqListPtr L, int pos, ElemType *elem);
Status List_Next(SqListPtr L, int pos, ElemType *elem);
void List_Print(SqListPtr L);
