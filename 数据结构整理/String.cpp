#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 255
typedef char DataType;
char SStr[MAXSIZE];

typedef struct
{
    DataType data[MAXSIZE];
    int len;
} SString;

void SStringCreate(SString *s)
{
    int i,j;
    char c;
    printf("请输入要建立的串的长度");
    scanf("%d",&j);
    for(i=0; i<j; i++)
    {
        printf("请输入串的第%d个字符：",i+1);
        fflush(stdin);  /*清空缓冲区*/
        scanf("%c",&c);
        s->data[i]=c;
    }
    s->len=j;
}

void SStringPrint(SString *s)  //顺序输出串
{
    int i;
    for(i=0; i<s->len; i++)
    {
        printf("%c",s->data[i]);
    }
    printf("\n");
}

int StrEmpty(SString *s)
{
    if(s->len==0)
        return 1;
    else
        return 0;
}

int StrLength(SString *s)
{
    return s->len;
}

void StrCopy(SString *s,SString *t)
{
    int i;
    for(i=0; i<t->len; i++)
    {
        s->data[i]=t->data[i];
    }
    s->len=t->len;
}

int strCompare(SString *s,SString *t)
{
    int i;
    for(i=0; i<s->len&&i<t->len; i++)
    {
        if(s->data[i]!=t->data[i])
            return s->data[i]-t->data[i];
    }
    return s->len-t->len;
}

int Contact(SString *s,SString *t)
{
    int i, flag;
    if(s->len+t->len<=MAXSIZE)	/* 连接后串长小于MAXSIZE */
    {
        for(i=s->len; i<s->len + t->len; i++)
            s->data[i]=t->data[i-s->len];  /* 进行连接 */
        s->len+=t->len;
        flag=1;
    }
    else if(s->len<MAXSIZE) /*连接后串长大于MAXSIZE，串t的部分字符被舍弃*/
    {
        for(i=s->len; i<MAXSIZE; i++)
            s->data[i]=t->data[i-s->len];
        s->len=MAXSIZE;
        flag=0;
    }
    else
        flag=0;	   /* 串s的长度等于MAXSIZE ,串t不被连接 */
    return flag;

}

int main()
{
    return 0;
}
