#include<iostream>
using namespace std;
void qsort(int arr[],int low,int high)
{
	if(high <= low)
		return;
	int i = low;
	int j = high;
	int key = arr[i];
	while(i < j)
	{
		while(i < j && key <= arr[j])
			j--;
		arr[i] = arr[j];
		
		while(i < j && key >= arr[i])
			i++;
		arr[j] = arr[i];
	}
	arr[i] = key;
	qsort(arr,low,i-1);
	qsort(arr,i+1,high);
}

int main()
{
	int a[] = {3,2,4,1,6,8};
	int n = sizeof(a)/sizeof(a[0]);
	qsort(a,0, n - 1);
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
} 
