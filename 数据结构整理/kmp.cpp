#include<stdio.h>
#include<string.h>
typedef char DataType;
void get_next(DataType *T,int *next,int tlength)
{
    int i=1;
    int j=0;
    next[1]=0;
    while(i<T[0])
    {
        if(j=0||T[i]==T[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
            j=next[j];
    }
}
//返回子串T在主串S第pos个字符的位置。若不存在，则返回0。
int index_KMP(DataType *S,DataType *T,int pos,int tlength,int slength,int *next)
{
    int i=pos;
    int j=1;
    // get_next(T,next);
    while(i<=slength&&j<=tlength)
    {
        if(j==0||S[i]==T[j])
        {
            i++;
            j++;
        }
        else
            j=next[j];
    }
    if(j>tlength)
        return i-tlength;
    else
        return 0;
}

int main()
{
    int locate,tlength,slength,next[256];
    DataType s[256],t[256];
    printf("请输入第一个串：");
    slength=strlen(gets(s+1));
    printf("请输入第二个串：");
    tlength=strlen(gets(t+1));
    get_next(t,next,tlength);
    locate=index_KMP(s,t,0,tlength,slength,next);
    printf("匹配位置：%d\n",locate);
    return 0;
}
