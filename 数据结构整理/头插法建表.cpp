/***************头插法建表*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
}LinkList;
int main()
{
    LinkList *head,*r,*s;
    char ch;
    int num;
    head=(LinkList *)malloc(sizeof(LinkList));
    head->next=NULL;
    while(1)//头插法建表
    {
        scanf("%d",num);
        ch=getchar();
        r=(LinkList *)malloc(sizeof(LinkList));
        r->data=num;
        r->next=head->next;
        head->next=r;
        if(ch=='\n')
            break;
    }
}
