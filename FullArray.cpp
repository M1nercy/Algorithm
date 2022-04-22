#include<cstdio>
const int maxn = 11;
int n, P[maxn], hashTable[maxn] = { false };
void genP(int index)
{
	if (index == n + 1)
	{
		for (int i = 1; i < n; i++)
		{
			printf("%d ", P[i]);//当前排列
		}
		printf("\n");
		return;
	}

	for(int x = 1; x <= n; x++)
	{
		if (hashTable[x] == false)
		{
			P[index] = x;//当前位置为x
			hashTable[x] = true;
			genP(index + 1);
			hashTable[x] = false;
		}
	}

}
