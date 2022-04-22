#include <iostream>
#include <stdio.h>
using namespace std;
void selectSort(int a[],int n)
{
	int tmp;
	for (int i = 0; i < n; i++)
	{
		tmp = i;
		for (int j = i; j < n; j++)
		{
			if (a[j] < a[tmp])
			{
				tmp = j;
			}
		}
		int tempint = a[i];
		a[i] = a[tmp];
		a[tmp] = tempint;
	}
}

void insertSort(int a[], int n)
{
	for(int i = 1; i < n; i++)
	{
		int tempint = a[i], j = i-1;
		while (j >= 0 && a[j] > tempint)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = tempint;
	}
}
int main()
{
	int a[] = { 5,2,4,6,3,1 };
	int n = sizeof(a) / sizeof(a[0]);
	insertSort(a,n);
	for (int i = 0; i < 6; i++)
		cout << a[i] << " ";
}
