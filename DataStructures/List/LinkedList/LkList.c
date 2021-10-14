/*
 * @Author: Lu Jialin 
 * @Date: 2021-09-14 16:15:11 
 * @Last Modified by: Lu Jialin
 * @Last Modified time: 2021-09-15 14:32:48
 */
//线性表的基本操作---链式存储结构

#include <stdio.h>
#include <stdlib.h>
#include "LkList.h"

//函数实现
Status List_Init(LkListPtr L) //L是指向头指针的指针，使用时(*L)表示头指针
{
    Status s = fail;
    Ptr p;          //头指针
    if (*L == NULL) //头指针的指针初始为空指针
    {
        p = (Ptr)malloc(sizeof(Node)); //为头指针分配空间（头结点）
        if (p == NULL)                 //分配失败则返回失败状态
            return s;
        *L = p;
        (*L)->next = NULL; //头指针的next指向空
        s = success;
    }
    return s;
}
void List_Destroy(LkListPtr L)
{
    List_Clear(L); //销毁链表，就是先清空，然后把头结点释放、指向空
    if (*L)
    {
        free(*L);
        *L = NULL;
    }
}
void List_Clear(LkListPtr L)
{
    Ptr p; //辅助指针，始终在*L前面、负责一个个释放结点
    if (*L)
    {
        p = (*L)->next;
        while (p) //p未指向空时
        {
            (*L)->next = p->next; //头结点指向p的下一个，释放p，p指向下一个（即此时头结点的下一个）
            free(p);
            p = (*L)->next;
        }
    }
}
bool List_Empty(LkListPtr L)
{
    return ((*L)->next == NULL); //头结点下一个指向空，链表就为empty
}
int List_Size(LkListPtr L)
{
    int len = 0;
    Ptr p = (*L)->next;
    while (p) //p指向结点时，len++
    {
        len++;
        p = p->next;
    }
    return len;
}
Status List_Retrival(LkListPtr L, int pos, ElemType *elem)
{
    Status s = range_error;
    Ptr p = (*L)->next;
    int i = 1;
    while (p && i < pos) //i从1开始，加了pos - 1次得到pos，p也指向pos处结点
    {
        ++i;
        p = p->next;
    }
    if (p && i == pos) //指向了pos处，则存储elem值
    {
        *elem = p->elem;
        s = success;
    }
    return s;
}
Status List_Locate(LkListPtr L, ElemType elem, int *pos)
{
    Status s = fail;
    Ptr p = (*L)->next;
    int i = 1; //p指向第一个结点，i=1，p和i一起前进
    while (p)
    {
        if (p->elem == elem) //找到了elem元素值，则break
        {
            s = success;
            *pos = i;
            break;
        }
        i++;
        p = p->next;
    }
    return s;
}
Status List_Find(LkListPtr L, int pos, Ptr *pAddr)
{ //与List_Retrival一样，只是得到的是指向该位置的指针
    Status s = fail;
    int i = 0;
    Ptr p = *L;
    while (i < pos && p) //i和p一起前进
    {
        p = p->next;
        ++i;
    }
    if (i == pos)
    {
        *pAddr = p;
        s = success;
    }
    return s;
}
Status List_Insert(LkListPtr L, int pos, ElemType elem)
{
    Status s = fail;
    Ptr p; //要用p，q两个指针
    Ptr q = NULL;
    s = List_Find(L, pos - 1, &q); //将q定位到pos - 1处
    if (s == success)
    {
        p = (Ptr)malloc(sizeof(Node)); //p分配空间给新值，成功则存值、插入链表
        if (p)
        {
            p->elem = elem;
            p->next = q->next;
            q->next = p;
        }
        else
            s = fail;
    }
    return s;
}
Status List_Delete(LkListPtr L, int pos)
{
    Status s = fail;
    Ptr p; //要用p，q两个指针
    Ptr q = NULL;
    s = List_Find(L, pos - 1, &q); //将q定位到pos - 1处
    if (s == success)
    {
        p = q->next; //p定位到pos处，成功则改变链表结构、释放p处结点，p指向空
        if (p)
        {
            q->next = p->next;
            free(p);
            p = NULL;
        }
        else
            s = fail;
    }
    return s;
}
Status List_Prior(LkListPtr L, int pos, ElemType *elem)
{
    Status s;
    Ptr p; //要用p，q两个指针
    Ptr q = NULL;
    s = List_Find(L, pos - 1, &q); //将q定位到pos - 1处
    if (s == success)
    {
        *elem = q->elem; //要找的前驱就是q的elem
        s = success;
    }
    return s;
}
Status List_Next(LkListPtr L, int pos, ElemType *elem)
{
    Status s;
    Ptr q = NULL;
    s = List_Find(L, pos, &q); //将q定位到pos处
    if (s == success)
    {
        if (q->next)
        {
            *elem = q->next->elem; //q的next的elem就是要找的后继
            s = success;
        }
        else
            s = fail;
    }
    return s;
}
void List_Print(LkListPtr L)
{
    printf("打印链表元素：");
    Ptr p = (*L)->next;
    int i = 1;
    while (p)
    {
        printf("%d ", p->elem);
        p = p->next;
        if (i++ % 10 == 0)
            printf("\n");
    }
    printf("\n");
}
