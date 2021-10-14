/*
 * @Author: Lu Jialin 
 * @Date: 2021-09-14 16:15:05 
 * @Last Modified by: Lu Jialin
 * @Last Modified time: 2021-09-15 15:18:05
 */
//线性表的基本操作---链式存储结构(测试)

#include <stdio.h>
#include <stdlib.h>
#include "TestLkList.h"

Status Test_CreateList(LkListPtr list, int n)
{                    //创建顺序表
    Status s = fail; //默认失败状态
    int i;
    ElemType e;
    s = List_Init(list);
    if (s == success) //如果初始化成功
    {
        for (i = 1; i <= n; ++i) //依次插入数据
        {
            printf("输入数据%d:", i);
            scanf("%d", &e);
            s = List_Insert(list, i, e);
            if (s != success) //插入失败则break
                break;
        }
        List_Print(list);
    }
    return s;
}
Status Test_ClearList(LkListPtr list)
{                          //清空顺序表
    Status s = fail;       //默认失败状态
    if (!List_Empty(list)) //顺序表不空，才清空
    {
        List_Clear(list);
        if (List_Empty(list))
        {
            printf("已成功清空链表\n");
            s = success;
        }
    }
    else
        printf("链表已空，无法清空\n");
    return s;
}
Status Test_RetrivalPriorNext(LkListPtr list, int pos)
{
    Status s = range_error; //默认越界错误
    ElemType e;
    s = List_Retrival(list, pos, &e);
    if (s == success) //如果取元素成功
    {
        printf("%d号元素是%d\n", pos, e); //打印目标元素

        s = List_Prior(list, pos, &e); //获取前驱
        if (s == success)
            printf("%d号直接前驱元素值是%d\n", pos, e);
        else
            printf("没有直接前驱\n");

        s = List_Next(list, pos, &e); //获取后继
        if (s == success)
            printf("%d号直接后继是%d\n", pos, e);
        else
            printf("没有直接后继\n");
    }
    else
    {
        printf("位置不合法");
    }
    return s;
}
Status Test_Locate(LkListPtr list, ElemType e)
{
    Status s = range_error; //默认越界错误
    int pos;

    s = List_Locate(list, e, &pos);
    if (s == success)
        printf("%d的位置是%d号\n", e, pos);
    else
        printf("查找失败\n");

    return s;
}
void Test_Size(LkListPtr list)
{ //打印顺序表长度
    int len;
    len = List_Size(list);
    printf("线性表的长度为%d\n", len);
}
