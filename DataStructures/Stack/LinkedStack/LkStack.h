/*
 * @Author: Lu Jialin 
 * @Date: 2021-09-15 13:47:45 
 * @Last Modified by: Lu Jialin
 * @Last Modified time: 2021-09-15 15:14:40
 */
//线性表的基本操作---链栈

#pragma once     //  只编译一次
#define bool int //c语言无bool类型
#define MAXSTACK 100

typedef int ElemType; //假设要处理的数据是int型

typedef struct StNode
{
    ElemType elem;
    struct StNode *next;
    struct StNode *last;
} StNode, *StNodePtr;

typedef struct Stack
{
    StNodePtr head; //头指针
    StNodePtr top;  //尾指针
    int stack_size;

} Stack, *StackPtr;

void Stack_Init(StackPtr st);
void Stack_Push(StackPtr st, ElemType item);
ElemType Stack_Pop(StackPtr st);
ElemType Stack_Top(StackPtr st);
bool Stack_Empty(StackPtr st);
void Stack_Print(StackPtr st);