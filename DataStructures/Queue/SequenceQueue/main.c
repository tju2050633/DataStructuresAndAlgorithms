/*
 * @Author: Lu Jialin 
 * @Date: 2021-09-14 16:15:52 
 * @Last Modified by: Lu Jialin
 * @Last Modified time: 2021-10-03 10:32:39
 */

#include <stdio.h>
#include <stdlib.h>
#include "SqQueue.h"

int main()
{
    int opt = 1;
    SqQueuePtr queue;
    int size;
    ElemType e;
    while (opt != 5)
    {
        printf("请输入选项：\n");
        printf("1:测试建立队列\n");
        printf("2:测试打印队列\n");
        printf("3:测试出队\n");
        printf("4:测试入队\n");
        printf("5:结束程序\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("输入队列长度：\n");
            scanf("%d", &size);
            Queue_Init(queue, size);
            printf("已初始化队列，请进行入队操作\n");
            break;
        case 2:
            Queue_Print(queue);
            break;
        case 3:
            e = Queue_Out(queue);
            if (e == -999)
                printf("出队失败，队列已空\n");
            else
                printf("出队成功，出队元素为%d\n", e);
            break;
        case 4:
            printf("输入入队元素：");
            scanf("%d", &e);
            Queue_In(queue, e);
        case 5:
            break;
        default:
            break;
        }
    }
    return 0;
}
