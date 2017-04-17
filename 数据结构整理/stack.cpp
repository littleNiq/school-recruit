/*使用栈实现数制转换*/
#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct snode
{
  DataType data;
  struct snode *next;
}LinkStack;

//置空栈。
LinkStack * InitStack()
{
    return NULL;
}

int EmptyStack(LinkStack *Top)
{
    return (Top==NULL?1:0);
}

LinkStack *Push(LinkStack *Top,DataType x)
{
    LinkStack *p;
    p=(LinkStack *)malloc(sizeof(LinkStack));
    p->data=x;
    p->next=Top;/*由于在链栈中没有附加头结点，所以在执行进栈操作时，新结点将成为当前栈顶，因此，必须修改栈顶指针Top的*/
    Top=p;
    return (Top);
}

LinkStack *Pop(LinkStack *Top,DataType *x)
{
    LinkStack *p;
    if(Top==NULL)
    {
        printf("error");
        return NULL;
    }
    p=Top;
    *x=p->data;
    Top=Top->next;
    free(p);
    return Top;
}

DataType GetTop(LinkStack *Top){
  if(Top==NULL){
    printf("error");
  }
  else
    return Top->data;
}

void ConverDtoR(int N,int r)
{
  int x;
  LinkStack *s;
  s=InitStack();
  while(N)
  {
    x=N%r;
    s=Push(s,x);
    printf("%d",x);
    N/=r;
  }
  printf("\n");
  printf("转换后的%d进制数值为：",r);
  while(!EmptyStack(s))
  {
      s=Pop(s,&x);
      printf("%d",x);
  }
}

int main()
{
  int num,j;
  printf("请输入需要转换的数字");
  scanf("%d",&num);
  printf("请输入需要转换的进制");
  scanf("%d",&j);
  ConverDtoR(num,j);
  return 0;
}
