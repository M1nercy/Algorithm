#include<iostream>
using namespace std;
//有bug 看思想 归并排序效率低不喜欢
//归并：将数组A的[L1,R1]与[L2,R2]区间合并为有序区间
void merge(int A[],int L1,int L2,int R1,int R2)
{
    int maxn = R2-L1;
    int i = L1,j = L2;
    int temp[maxn], index = 0;
    while(i <= R1 && j <= R2)
    {
        if(A[i] <= A[j])
            temp[index++] = A[i++];
        else
            temp[index++] = A[j++];
    }
    while(i <= R1) temp[index++] = A[i++];
    while(j <= R2) temp[index++] = A[j++];
    //归并后数组写回A
    for(int k = 0; k < index; k++)
    {
        A[L1+k] = temp[k];
    }
}
//归并排序
void mergesort(int A[],int left, int right)
{
    if(left == right)
        return;
    int mid = ( left+right )/2;
    mergesort(A,left,mid);
    mergesort(A,mid+1,right);
    merge(A,left,mid,mid+1,right);
}

int main()
{
    int a[] = {3,2,4,1,6,8};
    int n = sizeof(a)/sizeof(a[0]);
    mergesort(a,0, n - 1);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
