#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int DataType;
typedef struct
{
	DataType data[MAXSIZE];
	int front;
	int rear;
}SeqQueue;
void InitQueue(SeqQueue * q){ //置空队
	 q->front=q->rear=MAXSIZE-1;
}
int EmptyQueue(SeqQueue * q){//判队空
	if(q->rear==q->front)return 1;
	else return 0;
}
int InQueue(SeqQueue * q,DataType x)
{//进队
	if(q->front==(q->rear+1)%MAXSIZE){
		printf("队满\n");
	return 0;
	}
	q->rear=(q->rear+1)%MAXSIZE;
	q->data[q->rear]=x;
	return 1;
}
DataType OutQueue(SeqQueue * q){//出队
	if(q->rear==q->front){
		printf("队空下溢\n");
		exit(0);}
	q->front=(q->front+1)%MAXSIZE;
	return(q->data[q->front]);
}
int main()
{
	SeqQueue a;
	InitQueue(&a);//初始化队列
	char ch;
	int n=1,k,i,m,j;
	printf("打印三角形如下\n");
	InQueue(&a,'*');//入队
	for(i=0;i<4;i++)
	{
	 	InQueue(&a,'*');//入队
		for(j=0;j<i+1;j++)
		{
		ch=OutQueue(&a);
		printf("%c",ch);
		InQueue(&a,'*');
		}
	   	printf("\n");
	}
	printf("\n");
	return 0;

}
