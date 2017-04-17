/*************    二分查找及其变种   *******************/
#include<stdio.h>
int binarySearch(int a[], int n, int key)
{
    int low = 0;
    int high = n;
    int mid = 0;
    while(low <= high)
    {
        mid = low + ((high-low) >> 1);
        if(key == a[mid])
        {
            return mid;
        }
        else if(key < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int binarymin(int a[], int val, int l, int r)
{
    if(a == NULL || r < 0) return -1;
    int mid = 0;
    int ans = -1;
    while( l <= r )
    {
        mid = l + (r - l)/2;
        if(a[mid] >= val)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}
int binarymax(int * arr, int val, int l, int r)
{
    if(arr == NULL || r < 0) return -1;
    int mid = 0;
    int ans = -1;
    while(l <= r)
    {
        mid = l + (r - l)/2;
        if(arr[mid] <= val)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int a[10]= {1,3,7,7,9,9,9,9,16,16};
    int t=9;
    int binary1,binary2;
    printf("%d\n",binary1=binarymin(a,t,0,9));//查找符合要求的最小位置
    printf("%d\n",binary2=binarymax(a,t,0,9));//查找符合要求的最大位置
    printf("%d\n",binarySearch(a,9,t));//查找符合条件的位置
}
