/*****************************/
#if(0)
#include <cstdio>
#include <cstdlib>
#define MAXN 10000 + 10
using namespace std;

int par[MAXN], Rank[MAXN];
typedef struct
{
    int a, b, price;
} Node;
Node a[MAXN];

int cmp(const void*a, const void *b)
{
    return ((Node*)a)->price - ((Node*)b)->price;
}

void Init(int n)
{
    for(int i = 0; i < n; i++)
    {
        Rank[i] = 0;
        par[i] = i;
    }
}

int find(int x)
{
    int root = x;
    while(root != par[root]) root = par[root];
    while(x != root)
    {
        int t = par[x];
        par[x] = root;
        x = t;
    }
    return root;
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if(Rank[x] < Rank[y])
    {
        par[x] = y;
    }
    else
    {
        par[y] = x;
        if(Rank[x] == Rank[y]) Rank[x]++;
    }
}
//n为边的数量，m为村庄的数量
int Kruskal(int n, int m)
{
    int nEdge = 0, res = 0;
    //将边按照权值从小到大排序
    qsort(a, n, sizeof(a[0]), cmp);
    for(int i = 0; i < n && nEdge != m - 1; i++)
    {
        //判断当前这条边的两个端点是否属于同一棵树
        if(find(a[i].a) != find(a[i].b))
        {
            unite(a[i].a, a[i].b);
            res += a[i].price;
            nEdge++;
        }
    }
    //如果加入边的数量小于m - 1,则表明该无向图不连通,等价于不存在最小生成树
    if(nEdge < m-1) res = -1;
    return res;
}
int main()
{
    int n, m, ans;
    while(scanf("%d%d", &n, &m), n)
    {e
        Init(m);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].price);
            //将村庄编号变为0~m-1（这个仅仅只是个人习惯，并非必要的）
            a[i].a--;
            a[i].b--;
        }
        ans = Kruskal(n, m);
        if(ans == -1) printf("?\n");
        else printf("%d\n", ans);
    }
    return 0;
}


#endif
/******************************************/
#if(1)
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int u[101];
int v[101];
int w[101];
int p[101];
int r[101];
int n,m;
bool cmp(int i,int j)
{
    return w[i]<w[j];
}
int found(int x)
{
    return p[x]==x?x:p[x]=found(p[x]);
}
int Kruskal()
{
    int i;
    for(i=1; i<=n; i++)
        p[i]=i;
    for(i=0; i<m; i++)
        r[i]=i;
    sort(r,r+m,cmp);//按照权值大小排序
    int ans = 0;
    for(i=0; i<m; i++)
    {
        int e = r[i];
        int x = found(u[e]);
        int y = found(v[e]);
        if(x!=y)
        {
            printf("%d %d %d\n",u[e],v[e],w[e]);
            ans+=w[e];
            p[x]=y;
        }
    }
    return ans;
}
int main()
{
    int i;
    scanf("%d%d",&n,&m);
    for(i=0; i<m; i++)
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
    printf("%d\n",Kruskal());
    return 0;
}
#endif
