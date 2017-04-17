#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef char DataType;
#define MAXSIZE 50
typedef struct BiTNode
{
     DataType data ;
     struct BiTNode  *lchild , *rchild ;
}BiTree;

BiTree *CreateTree()
{
  BiTree *p;
  DataType ch;
  ch=getchar();
  if(ch==' ')
	  p=NULL;
  else
  {
	p=(BiTree *)malloc(sizeof(BiTree));
	p->data=ch;
	p->lchild=CreateTree();
	p->rchild=CreateTree();
  }
  return p;
}

void  PreorderTraverse(BiTree  *T)
{   if  (T!=NULL)
     {
	     printf("%c",T->data);
         PreorderTraverse(T->lchild);
         PreorderTraverse(T->rchild);
     }
}

int high(BiTree *T)
{

	int m,n;
	if(T==NULL)
		return 0;
	else
	{
		n=high(T->lchild);
		m=high(T->rchild);
		if(n>m)
		    return n+1;
		else
		    return m+1;
	}
}

int main()
{
  BiTree *tree;
  printf("请输入先序遍历序列,eg:ABCD...\n");
  tree=CreateTree();
  PreorderTraverse(tree);
  printf("\n%d\n",high(tree));
  return 0;
}
