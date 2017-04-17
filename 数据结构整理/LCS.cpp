#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define M 255
int LCS(char query[], char text[])
{
    int len_query=strlen(query),len_text=strlen(text);

    //数组c记录匹配情况,模拟二维矩阵
    char c[len_text];
    int len, i, j;
    len=0;

    for(i=0; i<len_query; i++)
    {
        //不反过来会把之前数组元素冲掉的，因为后面的元素需要根据前面的元素计算
        for(j=len_text-1; j>=0; j--)
        {
            if(query[i] == text[j])
            {
                if(i==0 || j==0)
                    c[j]=1;
                else
                    c[j]=c[j-1]+1;
            }
            else
                c[j] = 0;

            if(c[j] > len)
                len=c[j];
        }
    }
    return len;
}

int main()
{
    char str1[M],str2[M];
    printf("请输入字符串query:");

    scanf("%s", str1);
    printf("请输入字符串text:");

    scanf("%s", str2);
    printf("所求长度为:");

    printf("%d\n",LCS(str1,str2));
    return 0;

}
