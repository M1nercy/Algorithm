//八皇后问题说到底就是一个全排列问题，每一列只能有一个皇后，所以可以对每列的行进行遍历
#include<cstdio>
#include<math.h>
int count = 0;
const int maxn = 11;
int n, P[maxn], hashTable[maxn] = { false };//P当前排列
//(i,P[i])=(x,y)
void genP1(int index)//暴力
{
	if (index == n + 1)//递归边界
	{
		bool flag = true;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (abs(i - j) == abs(P[i] - P[j]))//在一条对角线上
				{
					flag = false;
				}
			}
		}
		if (flag)
			count++;
		return;
	}
	for(int x = 1; x < n; x++)
	{
		if (hashTable[x] == false)
		{
			P[index] = x;
			hashTable[x] = true;
			genP1(index + 1);
			hashTable[x] = false;
		}
	}
}

void genP2(int index)//
{
	if (index == n + 1)
	{
		count++;//到这里的肯定是合法的
		return;
	}
	for (int x = 1; x <= n; x++)
	{
		if (hashTable[x] == false) {
			bool flag = true;
			for (int pre = 1; pre < index; pre++)
			{
				if (abs(index - pre) == abs(x - P[pre]))
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				P[index] = x;
				hashTable[x] = true;
				genP2(index + 1);
				hashTable[x] = false;
			}
		}
	}
}