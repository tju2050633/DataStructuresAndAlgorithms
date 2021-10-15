/*
 * @Author: Lu Jialin 
 * @Date: 2021-09-14 16:15:52 
 * @Last Modified by: Lu Jialin
 * @Last Modified time: 2021-09-15 15:43:18
 */

#include <stdio.h>
#include <stdlib.h>
#include "TestSqStack.h"

int main()
{
    int opt = 1;
    StackPtr stack;
    int i, size;
    ElemType e;
    Status s;
    while (opt != 4)
    {
        printf("请输入选项：\n");
        printf("1:测试建立顺序栈\n");
        printf("2:测试取栈顶元素\n");
        printf("3:测试弹出栈顶元素\n");
        printf("4:结束程序\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("顺序栈长度：\n");
            scanf("%d", &size);
            s = Test_CreateStack(stack, size);
            if (s != success)
                printf("建立顺序栈失败\n");
            break;
        case 2:
            s = Test_RetrieveTop(stack, &e);
            if (s == success)
                printf("栈顶元素为%d\n", e);
            else
                printf("取栈顶元素失败\n");
            break;
        case 3:
            Test_PopStack(stack);
            break;
        default:
            break;
        }
    }
    return 0;
}
