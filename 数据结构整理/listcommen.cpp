/*
  寻找两个单链表的公共区域（链表相交问题）.
  有两个较长的单向链表a和b，为了找出节点node满足node in a并且node in b。
  请设计空间使用尽量小的算法。（c/c++/java或伪码表示都可以）
*/
#include<stdio.h>
#include<stdlib.h>
typedef int size_t;
struct node
{
    int v;
    node *next;
};
/*
返回链表的长度
链表为空 返回0
*/
size_t listLen(node * p)
{
    size_t num = 0;
    while(p!=NULL)
    {
        num++;
        p = p->next;
    }
    return num;
}
// 如果找到了 则返回指针 指向公共节点
// 如果不存在 则返回空指针
node * findFirstCommenNode(node * pheada, node * pheadb)
{
    size_t lenA = listLen(pheada);
    size_t lenB = listLen(pheadb);

    node * plistA = pheada;
    node * plistB = pheadb;
    //调整长度，让plistA 指向较长的一个链表
    if (lenA < lenB)
    {
        plistB = pheada;
        plistA = pheadb;
        size_t t = lenA;
        lenA = lenB;
        lenB = t;
    }
    while(lenA > lenB)
    {
        plistA = plistA->next;
        --lenA;
    }
    //一样长了
    //寻找公共节点
    while (plistA!=NULL && plistA != plistB)
    {
        plistA = plistA->next;
        plistB = plistB->next;
    }
    return plistA;
}
