#include<stdio.h>
//直接插入排序
void insert(int n,int a[])
{
    if(a==NULL)
        return;
    for(int i=1; i<n; i++)
    {
        int j=i-1;
        int t=a[i];
        while(j>=0&&a[j]>t)
        {
            a[j+1]=a[j];
            --j;
        }
        a[j+1]=t;
    }
}

void shellsort1(int a[], int n)
{
    int i, j, gap;

    for (gap = n / 2; gap > 0; gap /= 2) //步长
        for (i = 0; i < gap; i++)        //直接插入排序
        {
            for (j = i + gap; j < n; j += gap)
                if (a[j] < a[j - gap])
                {
                    int temp = a[j];
                    int k = j - gap;
                    while (k >= 0 && a[k] > temp)
                    {
                        a[k + gap] = a[k];
                        k -= gap;
                    }
                    a[k + gap] = temp;
                }
        }
}

void select(int a[], int n)
{
        int i,j,t,k;
        for(i=0; i<n-1; i++)
        {
            k=i;
            for(j=i+1; j<n; j++)
                if(a[k]>a[j])
                    k=j;
            if(j!=i)
            {
                t=a[i];
                a[i]=a[k];
                a[k]=t;
            }
        }
}

void quickSort(int s[], int l, int r)
{
	if (l< r)
	{
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while(i < j && s[j]>= x) // 从右向左找第一个小于x的数
				j--;
			if(i < j)
				s[i++] = s[j];
			while(i < j && s[i]< x) // 从左向右找第一个大于等于x的数
				i++;
			if(i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quickSort(s, l, i - 1); // 递归调用
		quickSort(s, i + 1, r);
	}
}

void bubble(int a[], int n)
{
    int i,j,t;
    for(i=0; i<n-1; i++)
        for(j=0; j<n-1-i; j++)
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }

}

void creatHeap(int r[],int m,int n)
{
   int i,j,f;
   i=m;
   j=2*i;
   r[0]=r[i];
   f=0;
   while(j<=n&&f!=1)
   {
       if(j<n&&r[j]>r[j+1])
        j++;
       if(r[0]<r[j])
        f=1;
       else
       {
           r[i]=r[j];
           i=j;
           j=2*i;
           r[i]=r[0];
       }
   }
}

void Heapsort(int x[],int n)
{
    int i;
    for(i=n/2;i>=1;i--)
    {
        creatHeap(x,i,n);
    }
    for(i=n;i>=1;i--)
    {
        printf("%d ",x[1]);
        x[1]=x[i];
        creatHeap(x,1,i);
        //x[n-i]=x[1];
    }
    //printf("\n");
}


int main()
{
    int i,a[8]= {0,2,6,4,2,1,3,6};
    //insert(7,a);//1
    // shellsort1(a,7);//2
    // bubble(a,7);//3
    // quickSort(a,0,6);//5
    Heapsort(a,7);//6
   //  select(a,7);//4
   //  for(i=1; i<8; i++)
       // printf("%d ",a[i]);
}
