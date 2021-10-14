/*
 * @Author: Lu Jialin 
 * @Date: 2021-09-14 16:15:00 
 * @Last Modified by:   Lu Jialin 
 * @Last Modified time: 2021-09-14 16:15:00 
 */
//线性表的基本操作---顺序存储结构(测试)

#include "SqList.h"

Status Test_CreateList(SqListPtr list, ElemType data[], int n);
Status Test_ClearList(SqListPtr list);
Status Test_RetrivalPriorNext(SqListPtr list, int pos);
Status Test_Locate(SqListPtr list, ElemType e);
void Test_Size(SqListPtr list);
