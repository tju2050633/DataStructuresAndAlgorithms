/*
 * @Author: Lu Jialin 
 * @Date: 2021-09-14 16:14:57 
 * @Last Modified by: Lu Jialin
 * @Last Modified time: 2021-09-15 15:17:59
 */
//线性表的基本操作---顺序存储结构(测试)

#include <stdio.h>
#include <stdlib.h>
#include "TestSqList.h"

Status Test_CreateList(SqListPtr list, ElemType data[], int n)
{                    //创建顺序表
    Status s = fail; //默认失败状态
    int i;
    s = List_Init(list);
    if (s == success) //如果初始化成功
    {
        for (i = 1; i <= n; ++i) //依次插入数据
        {
            s = List_Insert(list, i, data[i]);
            if (s != success) //插入失败则break
                break;
        }
        List_Print(list);
    }
    return s;
}
Status Test_ClearList(SqListPtr list)
{                          //清空顺序表
    Status s = fail;       //默认失败状态
    if (!List_Empty(list)) //顺序表不空，才清空
    {
        List_Clear(list);
        if (List_Empty(list))
        {
            s = success;
        }
    }
    return s;
}
Status Test_RetrivalPriorNext(SqListPtr list, int pos)
{
    Status s = range_error; //默认越界错误
    ElemType e;
    s = List_Retrival(list, pos, &e);
    if (s == success) //如果取元素成功
    {
        printf("%d的元素是%d", pos, e); //打印目标元素

        s = List_Prior(list, pos, &e); //获取前驱
        if (s == success)
            printf("%d的直接前驱元素值是%d\n", pos, e);
        else
            printf("没有直接前驱\n");

        s = List_Next(list, pos, &e); //获取后继
        if (s == success)
            printf("%d的直接后继是%d\n", pos, e);
        else
            printf("没有直接后继\n");
    }
    else
    {
        printf("位置不合法");
    }
    return s;
}
Status Test_Locate(SqListPtr list, ElemType e)
{
    Status s = range_error; //默认越界错误
    int pos;

    s = List_Locate(list, e, &pos);
    if (s == success)
        printf("%d的位置是%d\n", e, pos);
    else
        printf("查找失败\n");

    return s;
}
void Test_Size(SqListPtr list)
{ //打印顺序表长度
    int len;
    len = List_Size(list);
    printf("线性表的长度%d\n", len);
}
