/*
 * @Author: Lu Jialin 
 * @Date: 2021-09-14 16:15:29 
 * @Last Modified by: Lu Jialin
 * @Last Modified time: 2021-09-15 15:18:20
 */

#include <stdio.h>
#include <stdlib.h>
#include "TestLkList.h"

int main()
{
    int opt = 1;
    Ptr list = NULL;
    int pos, size;
    ElemType e;
    Status s;
    while (opt != 6)
    {
        printf("请输入选项：\n");
        printf("1:测试建立链表\n");
        printf("2:测试清空链表\n");
        printf("3:测试求某位置链表元素值及前驱后继\n");
        printf("4:测试查询某元素位置\n");
        printf("5:测试链表长度\n");
        printf("6:结束程序\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("链表长度：\n");
            scanf("%d", &size);
            s = Test_CreateList(&list, size);

            if (s != success)
                printf("建立链表失败\n");
            break;
        case 2:
            Test_ClearList(&list);
            break;
        case 3:
            printf("输入要查找位置：");
            scanf("%d", &pos);
            Test_RetrivalPriorNext(&list, pos);
            break;
        case 4:
            printf("输入要查找元素：");
            scanf("%d", &e);
            Test_Locate(&list, e);
            break;
        case 5:
            printf("链表长度：");
            printf("%d\n", List_Size(&list));
            break;
        default:
            break;
        }
    }
    return 0;
}
