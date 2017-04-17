/**********¹ş·òÂüÊ÷*********/
#include<stdio.h>
#define MAX 200
typedef struct
{
    int weight;
    int parent,lchild,rchild;
} HTNode;

int Create_Huffman(HTNode HT[], int n)
{
    int w;
    int k,j,m=2*n-1;
    for(k=1; k<m; k++)
    {
        if(k<=n)
        {
            printf("\n please input weight:w=?");
            scanf("%d",&w);
            HT[k].weight=w;
        }
        else
            HT[k].weight=0;
        HT[k].parent=HT[k].lchild=HT[k].rchild=0;
    }
    for(k=n+1; k<=m; k++)
    {
        int w1=32767,w2=w1;
        int p1=0,p2=0;
        for(j=1; j<k; j++)
        {
            if(HT[j].parent==0)
                if(HT[j].weight<w1)
                {
                    w2=w1;
                    p2=p1;
                    w1=HT[j].weight;
                    p1=j;
                }
                else
                {
                    w2=HT[j].weight;
                    p2=j;
                }
        }
        HT[k].lchild=p1;
        HT[k].rchild=p2;
        HT[k].weight=w1+w2;
        HT[p1].parent=k;
        HT[p2].parent=k;
    }
    return HT[m].weight;
}

int main()
{
    HTNode p[100];
    int a;
    a=Create_Huffman(p,4);
    printf("%d",a);
    return 0;
}
