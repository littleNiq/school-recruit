/********* 拓扑排序 ************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define LL long long

const int INF = 1e9+7;
const int VM = 503;// 点的个数

bool G[VM][VM];//图
int deg[VM];//各个顶点的入度  计数

void toposort(int n)  //拓扑排序
{
    int k = 0;
    for (int i = 1; i <= n; i++)  //共进行|G.V|次操作
    {
        for (int j = 1; j <= n; j++)  //遍历所有的顶点  找入度为0的
        {
            if (deg[j] == 0)  //找到
            {
                printf("%d%c", j, i == n ? '\n' : ' ');//输出
                deg[j]--;//去掉这个点  让deg[j] = -1;
                k = j;//记录这个点
                break;//跳出循环
            }
        }
        for (int j = 1; j <= n; j++)//遍历所有的点
            if (G[k][j] == true)  //找被此点打败过的点
            {
                G[k][j] = false;//标记为找到过
                deg[j]--;//让这个点的入度-1
            }
    }
}

int main()
{
    int n, m;

    while (scanf("%d %d", &n, &m) == 2)  //多组输入， 获取n, m
    {
        memset(G, 0, sizeof(G));//初始化
        memset(deg, 0, sizeof(deg));//初始化
        while (m--)
        {
            int u, v;
            scanf("%d %d", &u, &v);//获取 u,v  u打败过v
            if(G[u][v] == false)  //防止重边 如果被同一个对手打败多次，也太伤v的心了
            {
                G[u][v] = true;//标记为真
                deg[v]++;//v的入度++   一杆长枪入洞了。
            }
        }
        toposort(n);//调用函数
    }
    return 0;
}
