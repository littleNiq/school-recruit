/**********************/
#if(0)
#include<iostream>
using namespace std;

#define MAX 0x7FFFFFFF			//最大可能值，用于哨兵

void Merge(int *A, int low, int mid, int high)
{
	if(A == NULL)return;

	int n1 = mid-low+1;
	int n2 = high-mid;
	int *left = new int[n1+1];
	int *right = new int[n2+1];
	for(int i=0; i<n1; i++)
		left[i] = A[i+low];
	for(int j=0; j<n2; j++)
		right[j] = A[j+mid+1];

	//哨兵元素
	left[n1] = MAX;
	right[n2] = MAX;

	//将left[low...mid]和right[mid+1, high]共high-low+1 个元素有序合并
	int i=0,j=0;
	for(int k=low; k<=high; k++)
	{
		if(left[i]<=right[j])
		{
			A[k] = left[i];
			i++;
		}
		else
		{
			A[k] = right[j];
			j++;
		}
	}
}

//归并排序
void Merge_Sort(int *A, int low, int high)
{
	if(low<high)
	{
		int mid = (low+high)/2;
		Merge_Sort(A, low, mid);
		Merge_Sort(A, mid+1, high);
		Merge(A, low, mid, high);
	}
}

void Print(int *A, int low, int high)
{
	for(int i=low; i<=high; i++)
		cout<<A[i]<<" ";
	cout<<endl;
}

int main()
{
	int array[11] = {3, 5, 1, 9, 20, 4, 13, 6, 4, 12, 8};
	int low = 0;
	int high = sizeof(array)/sizeof(int)-1;
	Merge_Sort(array, low, high);
	Print(array, low, high);
	//system("pause");
	return 0;
}
#endif
/****************************************/
#if(1)
#include <stdio.h>
void Merge(int a[],int low,int mid,int high)
{
    int b[10];
    int i = low;
    int j = mid;
    int k = 0;
    while(i<mid&&j<high)
        b[k++]=a[i]<a[j]?a[i++]:a[j++];
    while(i<mid)b[k++]=a[i++];
    while(j<high)b[k++]=a[j++];
    for(i=0;i<k;i++)
        a[low+i]=b[i];
}
void MergeSort(int a[],int n)
{
    int i,j;
    for(i=1;i<n;i*=2)
    {
        for(j=0;j+2*i<=n;j+=2*i)
            Merge(a,j,j+i,j+2*i);
        if(j+i<n-1)Merge(a,j,j+i,n);
        printf("i = %d ",i);
        for(j=0;j<10;j++)
        printf("%d ",a[j]);
        printf("\n");
    }
}
int main()
{
    int a[]={5,3,26,1,0,9,4,8,7};
    MergeSort(a,10);
    for(int i=0;i<10;i++)
        printf("%d ",a[i]);
    return 0;
}
#endif
