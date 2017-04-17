#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 105;
const int inf = 9999999;
int s[maxn];//用来记录某一点是否被访问过
int map[maxn][maxn];//地图
int dis[maxn];//从原点到某一个点的最短距离(一开始是估算距离)
int n;
int target;

/**
 * 返回从v---->到target的最短路径
 */
int dijkstra(int v)
{
    int i;
    for(i = 1 ; i <= n ; ++i) //初始化
    {
        s[i] = 0;//一开始，所有的点均未被访问过
        dis[i] = map[v][i];
    }
    for(i = 1 ; i < n ; ++i)
    {
        int min = inf;
        int pos;
        int j;
        for(j = 1 ; j <= n ; ++j) //寻找目前的最短路径的最小点
        {
            if(!s[j] && dis[j] < min)
            {
                min = dis[j];
                pos = j;
            }
        }
        s[pos] = 1;
        for(j = 1 ; j <= n ; j++) //遍历u的所有的邻接的边
        {
            if(!s[j] && dis[j] > dis[pos] + map[pos][j])
            {
                dis[j] = dis[pos] + map[pos][j];//对边进行松弛
            }
        }
    }
    return dis[target];
}

int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {

        int i;
        int j;
        for(i = 1 ; i <= n ; ++i)
        {
            for(j = 1 ; j <= n ; ++j)
            {
                if(i == j)
                {
                    map[i][j] = 0;
                }
                else
                {
                    map[i][j] = inf;
                }
            }
        }
        for(i = 1 ; i <= m ; ++i)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            map[a][b] = map[b][a] = c;//这里默认是无向图。。所以要两个方向都做处理,只做一个方向上的处理会WA
        }
        target = n;
        int result = dijkstra(1);
        printf("%d\n",result);
    }

    return 0;
}
