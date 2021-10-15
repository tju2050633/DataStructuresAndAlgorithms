/*
 * @Author: Lu Jialin 
 * @Date: 2021-09-15 13:47:45 
 * @Last Modified by: Lu Jialin
 * @Last Modified time: 2021-09-15 15:14:40
 */
//线性表的基本操作---顺序栈

#pragma once     //  只编译一次
#define bool int //c语言无bool类型
#define MAXSTACK 100

typedef enum Status //status枚举四种状态
{
    success,
    fail,
    fatal,
    range_error,
    overflow,
    underflow
} Status;

typedef int ElemType; //假设要处理的数据是int型

typedef struct Stack
{
    ElemType *elem; //动态分配空间大小为stack_size
    int top;        //栈的top指针，存放栈顶元素位置，-1表示栈空，stack_size - 1表示栈满
    int stack_size;
} Stack, *StackPtr;

Status Stack_Init(StackPtr st);
Status Stack_Push(StackPtr st, ElemType item);
Status Stack_Pop(StackPtr st, ElemType *item);
Status Stack_Top(StackPtr st, ElemType *item);
bool Stack_Empty(StackPtr st);
void Stack_Print(StackPtr st);