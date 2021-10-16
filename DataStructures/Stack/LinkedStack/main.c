/*
 * @Author: Lu Jialin 
 * @Date: 2021-09-14 16:15:52 
 * @Last Modified by: Lu Jialin
 * @Last Modified time: 2021-09-15 15:43:18
 */

#include <stdio.h>
#include <stdlib.h>
#include "LkStack.h"

int main()
{
    int opt = 1;
    StackPtr stack;
    int size;
    ElemType e;
    while (opt != 4)
    {
        printf("请输入选项：\n");
        printf("1:测试建立链栈\n");
        printf("2:测试取栈顶元素\n");
        printf("3:测试弹出栈顶元素\n");
        printf("4:结束程序\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            Stack_Init(stack);
            printf("输入元素个数：");
            scanf("%d", &size);
            for (int i = 1; i <= size; i++)
            {
                printf("输入%d号元素：",i);
                scanf("%d", &e);
                Stack_Push(stack, e);
            }
            Stack_Print(stack);
            break;
        case 2:
            if (stack != NULL && stack->stack_size > 0)
                printf("栈顶元素为%d\n", stack->top->elem);
            else
                printf("取栈顶元素失败\n");
            break;
        case 3:
            if (stack != NULL && stack->stack_size > 0)
            {
                e = Stack_Pop(stack);
                printf("出栈成功，出栈元素为%d\n",e);
            }
            else
                printf("出栈失败\n");

            break;
        default:
            break;
        }
    }
    return 0;
}
