/*
 * @Author: Lu Jialin 
 * @Date: 2021-09-15 15:12:13 
 * @Last Modified by: Lu Jialin
 * @Last Modified time: 2021-09-15 15:46:41
 */
//线性表的基本操作---顺序栈

#include <stdio.h>
#include <stdlib.h>
#include "LkStack.h"

void Stack_Init(StackPtr st)
{                                                 //初始化链栈
    st->top = (StNodePtr)malloc(sizeof(StNode));  //top在-1号结点
    st->head = (StNodePtr)malloc(sizeof(StNode)); //头结点空间

    st->top->next = st->head;
    st->head->last = st->top;

    st->stack_size = 0;
}
void Stack_Push(StackPtr st, ElemType item)
{
    if (st->top->next == NULL)                             //top下面不是head,即不是第一个压栈元素
        st->top->next = (StNodePtr)malloc(sizeof(StNode)); //压栈，先分配下一结点空间
    st->top->next->last = st->top;                         //下一结点的last是top
    st->top = st->top->next;                               //top移至下一结点
    st->top->elem = item;

    st->stack_size++;
}
ElemType Stack_Pop(StackPtr st)
{
    ElemType e = st->top->elem;
    st->top = st->top->last; //top回退到上一结点

    st->stack_size--;
    return e;
}
ElemType Stack_Top(StackPtr st)
{
    return st->top->elem;
}
bool Stack_Empty(StackPtr st)
{
    return (st->stack_size == 0);
}
void Stack_Print(StackPtr st)
{
    printf("打印链栈元素：");
    StNodePtr p = st->head;
    while (1)
    {
        printf("%d  ", p->elem);
        if (p == st->top)
            break;
        p = p->next;
    }
    printf("\n");
}