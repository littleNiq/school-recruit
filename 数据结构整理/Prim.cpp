#include<stdio.h>
#include<string.h>
#include<math.h>
double d[102][2], w[102][102], minCost[102];
int n, pre[102], hash[102];

double getDist(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double Prim()
{
    memset(hash, 0, sizeof(hash));
    hash[1] = 1;
    for(int i=1; i<=n; ++i)
    {
        minCost[i] = w[1][i];
        pre[i] = 1;
    }
    double sum=0;
    for(int i=1; i<n; ++i)
    {
        int u=-1;
        for(int j=1; j<=n; ++j)if(!hash[j])
            {
                if(u==-1||minCost[j]<minCost[u])
                    u=j;
            }
        sum += w[pre[u]][u];
        hash[u] = 1;
        for(int j=1; j<=n; ++j)if(!hash[j])
            {
                if(minCost[j]>w[u][j])
                {
                    minCost[j] = w[u][j];
                    pre[j] = u;
                }
            }
    }
    return sum;
}//prim
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
        scanf("%lf%lf",&d[i][0],&d[i][1]);
    memset(w, 0, sizeof(w));
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)if(i!=j)
                w[i][j] = getDist(d[i][0],d[i][1],
                                  d[j][0],d[j][1]);
    printf("%.2f\n", Prim());
    return 0;
}
