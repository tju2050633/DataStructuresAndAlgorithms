/*
 * @Author: Lu Jialin 
 * @Date: 2021-09-15 15:12:13 
 * @Last Modified by: Lu Jialin
 * @Last Modified time: 2021-09-15 15:46:41
 */
//线性表的基本操作---顺序栈

#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"

Status Stack_Init(StackPtr st)
{                    //初始化顺序栈
    Status s = fail; //默认状态是失败
    if (st != NULL)  //当顺序栈存在
    {
        st->elem = (ElemType *)malloc(sizeof(ElemType) * MAXSTACK);
        if (st->elem) //如果elem指针不为空（分配空间成功）
        {
            st->stack_size = MAXSTACK;
            st->top = -1;
            s = success;
        }
    }
    return s;
}
Status Stack_Push(StackPtr st, ElemType item)
{
    Status s = success;
    if (st->top == MAXSTACK - 1) //栈满则返回溢出
    {
        s = overflow;
    }
    else //栈未满则top++，top处元素赋值
    {
        st->top++;
        st->elem[st->top] = item;
    }

    return s;
}
Status Stack_Pop(StackPtr st, ElemType *item)
{
    Status s = success;
    if (Stack_Empty(st)) //栈空则下溢
        s = underflow;
    else //否则先取出top处值，top再--
        *item = st->elem[st->top--];

    return s;
}
Status Stack_Top(StackPtr st, ElemType *item)
{
    Status s = success;
    if (Stack_Empty(st))
        s = underflow;
    else
        *item = st->elem[st->top];

    return s;
}
bool Stack_Empty(StackPtr st)
{
    return (st->top == -1);
}
void Stack_Print(StackPtr st)
{
    printf("打印顺序栈元素：");
    int i;
    if (st) //如果顺序栈存在
    {
        for (i = 0; i <= st->top; ++i) //遍历顺序栈并打印元素
        {
            printf("%d ", st->elem[i]);
            if (i % 10 == 0 && i != 0) //每十个元素换行
                printf("\n");
        }
    }
    printf("\n");
}