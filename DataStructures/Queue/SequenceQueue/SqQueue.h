/*
 * @Author: Lu Jialin 
 * @Date: 2021-10-03 09:52:53 
 * @Last Modified by: Lu Jialin
 * @Last Modified time: 2021-10-03 09:56:58
 */
#pragma once     //  只编译一次
#define bool int //c语言无bool类型

typedef int ElemType; //假设要处理的数据是int型

typedef struct SqQueue
{ //结构体定义顺序队列，包含元素指针（数组）、现有队长
    ElemType *elem;
    int size, length;
    int head, tail;
} SqQueue, *SqQueuePtr;

//声明函数
void Queue_Init(SqQueuePtr qu, int size);
ElemType Queue_Out(SqQueuePtr qu);
void Queue_In(SqQueuePtr qu, ElemType item);
bool Queue_Empty(SqQueuePtr qu);
bool Queue_Full(SqQueuePtr qu);
int Queue_Size(SqQueuePtr qu);
void Queue_Print(SqQueuePtr qu);
