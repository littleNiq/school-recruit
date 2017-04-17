/*****************实现图的邻接表创建*******************/
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 30
typedef char ElemType;
int visited[MAXSIZE];

typedef struct LinkNode
{
    int adjvex;
    ElemType info;
    struct LinkNode *nextarc;
}LinkNode;
typedef struct VexNode
{
    ElemType data;
    LinkNode *firststarc;
}VexNode;
typedef struct
{
    VexNode adjlist[MAXSIZE];
    int n,e;
}AlGraph;

void dfs(AlGraph *G,int v)
{
  LinkNode *p;
  visited[v]=1;
  visit(v);
}
int LocateVex(AlGraph *G,ElemType vp)
{
    int k;
    for(k=0;k<G->n;k++)
    {
        if(G->adjlist[k].data==vp)
            return k;
        return -1;
    }
}
void Create_Graph()
{

}
void AddVertex(AlGraph *G,ElemType vp)
{
  int k,j;
  if(G->n>=MAXSIZE)
  {
      printf("OVERFLOW");
  }
  if(LocateVex(G,vp)==-1)
  {
      G->adjlist[G->n].data=vp;
      G->adjlist[G->n].firststarc=NULL;
      G->n++;
  }
}
void AddArc(AlGraph *G,ElemType vex1,ElemType vex2)
{
   int j,k;
   LinkNode *p;
   k=LocateVex(G,vex1);
   j=LocateVex(G,vex2);
   if(k==-1||j==-1)
   {
    printf("donnot exit");
   }
   p=(LinkNode *)malloc(sizeof(LinkNode));
   p->adjvex=j;
   p->nextarc=G->adjlist[k].firststarc;
   G->adjlist[k].firststarc=p;

   p=(LinkNode *)malloc(sizeof(LinkNode));
   p->adjvex=k;
   p->nextarc=G->adjlist[j].firststarc;
   G->adjlist[j].firststarc=p;
}


int main()
{

    return 0;
}
