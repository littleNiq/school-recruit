#include <stdio.h>
#include <stdlib.h>
define MaxSize=100;
//#include "btree.h"
typedef struct BTNode{
  int data;
  struct BTNode *lchild,*rchild;
}BTNode;
void LevelOrder(BTNode *b)
{
    BTNode *p;
    BTNode *qu[MaxSize];    //定义环形队列,存放节点指针
    int front,rear; //定义队头和队尾指针
    front=rear=-1;      //置队列为空队列
    rear++;
    qu[rear]=b;     //根节点指针进入队列
    while (front!=rear) //队列不为空
    {
        front=(front+1)%MaxSize;
        p=qu[front];        //队头出队列
        printf("%c ",p->data);  //访问节点
        if (p->lchild!=NULL)    //有左孩子时将其进队
        {
            rear=(rear+1)%MaxSize;
            qu[rear]=p->lchild;
        }
        if (p->rchild!=NULL)    //有右孩子时将其进队
        {
            rear=(rear+1)%MaxSize;
            qu[rear]=p->rchild;
        }
    }
}

int main()
{
    BTNode *b;
    CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("二叉树b: ");
    DispBTNode(b);
    printf("\n");
    printf("层次遍历序列:\n");
    LevelOrder(b);
    DestroyBTNode(b);
    return 0;
}
