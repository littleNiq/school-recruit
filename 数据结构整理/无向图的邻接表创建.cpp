#include<iostream>
#include<stdlib.h>

using namespace std;

#define MAXVEX 100 /* 最大顶点数,应由用户定义 */
typedef char VertexType; /* 顶点类型应由用户定义 */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */

typedef struct EdgeNode/* 边表结点  */
{
    int adjvex;/* 邻接点域,存储该顶点对应的下标 */
    EdgeType weight;/* 用于存储权值,对于非网图可以不需要 */
    struct EdgeNode *next; /* 链域,指向下一个邻接点 */
} EdgeNode;

typedef struct VextexNode/* 顶点表结点 */
{
    VertexType data;/* 顶点域,存储顶点信息 */
    EdgeNode *firstedge;/* 边表头指针 */
} VextexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numNodes, numEdges; /* 图中当前顶点数和边数 */
} GraphAdjList;


void CreateALGraph1(GraphAdjList *Gp)
{
    int i, j, k;
    EdgeNode *pe;
    cout << "输入顶点数和边数(空格分隔）:" << endl;
    cin >> Gp->numNodes >> Gp->numEdges;

    for (i = 0 ; i < Gp->numNodes; i++)
    {
        cout << "输入顶点信息：" << endl;
        cin >> Gp->adjList[i].data;
        Gp->adjList[i].firstedge = NULL;/* 将边表置为空表 */
    }

    for (k = 0; k <  Gp->numEdges; k++)/* 建立边表 */
    {
        cout << "输入边(vi,vj)的顶点序号i,j（空格分隔）:" << endl;
        cin >> i >> j;
        pe = (EdgeNode *)malloc(sizeof(EdgeNode));
        pe->adjvex = j;/* 邻接序号为j */
        /* 将pe的指针指向当前顶点上指向的结点 */
        pe->next = Gp->adjList[i].firstedge;
        Gp->adjList[i].firstedge = pe;/* 将当前顶点的指针指向pe */

        pe = (EdgeNode *)malloc(sizeof(EdgeNode));
        pe->adjvex = i;
        pe->next = Gp->adjList[j].firstedge;
        Gp->adjList[j].firstedge = pe;
    }
}

void CreateALGraph2(GraphAdjList *Gp)
{
    int i, j, k;
    EdgeNode *pe;
    cout << "输入顶点数和边数(空格分隔）:" << endl;
    cin >> Gp->numNodes >> Gp->numEdges;

    for (i = 0 ; i < Gp->numNodes; i++)
    {
        cout << "输入顶点信息：" << endl;
        cin >> Gp->adjList[i].data;
        Gp->adjList[i].firstedge = NULL;/* 将边表置为空表 */
    }

    for (k = 0; k <  Gp->numEdges; k++)/* 建立边表 */
    {
        cout << "输入边(vi,vj)的顶点序号i,j（空格分隔）:" << endl;
        cin >> i >> j;
        pe = (EdgeNode *)malloc(sizeof(EdgeNode));
        pe->adjvex = j;/* 邻接序号为j */
        /* 将pe的指针指向当前顶点上指向的结点 */
        pe->next = Gp->adjList[i].firstedge;
        Gp->adjList[i].firstedge = pe;/* 将当前顶点的指针指向pe */

    }
}

int main(void)
{
    GraphAdjList GL;
    CreateALGraph1(&GL);

    return 0;
}
