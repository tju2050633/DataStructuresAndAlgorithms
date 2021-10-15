/*
 * @Author: Lu Jialin 
 * @Date: 2021-09-15 15:16:30 
 * @Last Modified by: Lu Jialin
 * @Last Modified time: 2021-09-15 15:49:18
 */
//线性表的基本操作---顺序栈(测试)

#include <stdio.h>
#include <stdlib.h>
#include "TestSqStack.h"

Status Test_CreateStack(StackPtr st, int n)
{
    Status s = fail; //默认失败状态
    int i;
    ElemType e;
    s = Stack_Init(st);
    if (s == success) //如果初始化成功
    {
        for (i = 1; i <= n; ++i) //依次push数据
        {
            printf("输入数据%d:", i);
            scanf("%d", &e);
            s = Stack_Push(st, e);
            if (s != success) //push失败则break
                break;
        }
        Stack_Print(st);
    }
    return s;
}
Status Test_RetrieveTop(StackPtr st, ElemType *e)
{
    Status s = fail;
    if (!Stack_Empty(st)) //栈不空则取出top值
    {
        *e = st->elem[st->top];
        s = success;
    }

    return s;
}
Status Test_PopStack(StackPtr st)
{
    Status s = success;
    ElemType e;
    s = Stack_Pop(st, &e);
    if (s == success)
    {
        printf("已弹出top处元素，其值为%d\n", e);
        Stack_Print(st);
    }

    return s;
}