#include<stdio.h>
#include<string.h>
char a[2003],b[2003];
int dp[2003][2003];
int max1(int a,int b)
{
    if(a>b) return a;
    else  return b;
}
int main()
{
    while(scanf("%s%s",&a,&b)!=EOF)
    {
        int n1=strlen(a);
        int n2=strlen(b);
        int i,j;
        for(i=0; i<=n1; i++)
            dp[i][0]=0;
        for(i=0; i<=n2; i++)
            dp[0][i]=0;
        for(i=0; i<n1; i++)
            for(j=0; j<n2; j++)
            {
                if(a[i]==b[j])
                    dp[i+1][j+1]=dp[i][j]+1;
                else
                {
                    dp[i+1][j+1]=max1(dp[i][j+1],dp[i+1][j]);
                }
            }
        printf("%d\n",dp[n1][n2]);
    }
    return 0;
}
