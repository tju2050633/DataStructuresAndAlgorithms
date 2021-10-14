/*
 * @Author: Lu Jialin 
 * @Date: 2021-09-14 16:15:52 
 * @Last Modified by: Lu Jialin
 * @Last Modified time: 2021-09-15 15:18:32
 */

#include <stdio.h>
#include <stdlib.h>
#include "TestSqList.h"

int main()
{
    int opt = 1;
    SqList list;
    int pos, size, i;
    ElemType e, *data;
    Status s;
    while (opt != 6)
    {
        printf("请输入选项：\n");
        printf("1:测试建立线性表\n");
        printf("2:测试清空线性表\n");
        printf("3:测试求某位置线性表元素值及前驱后继\n");
        printf("4:测试查询某元素位置\n");
        printf("5:测试线性表长度\n");
        printf("6:结束程序\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("线性表长度：\n");
            scanf("%d", &size);
            data = (ElemType *)malloc((size + 1) * sizeof(ElemType));
            if (data == NULL)
                break;
            printf("线性表元素：\n");
            for (i = 1; i <= size; ++i)
            {
                scanf("%d", &data[i]);
            }
            s = Test_CreateList(&list, data, size);

            if (s != success)
                printf("建立线性表失败\n");
            break;
        case 2:
            if (!List_Empty(&list))
            {
                List_Clear(&list);
                if (List_Empty(&list))
                {
                    printf("已经清空线性表\n");
                }
            }
            else
                printf("线性表已空，无法清空");
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
            printf("线性表长度：");
            printf("%d\n", List_Size(&list));
            break;
        default:
            break;
        }
    }
    return 0;
}
