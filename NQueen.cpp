//�˻ʺ�����˵���׾���һ��ȫ�������⣬ÿһ��ֻ����һ���ʺ����Կ��Զ�ÿ�е��н��б���
#include<cstdio>
#include<math.h>
int count = 0;
const int maxn = 11;
int n, P[maxn], hashTable[maxn] = { false };//P��ǰ����
//(i,P[i])=(x,y)
void genP1(int index)//����
{
	if (index == n + 1)//�ݹ�߽�
	{
		bool flag = true;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (abs(i - j) == abs(P[i] - P[j]))//��һ���Խ�����
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
		count++;//������Ŀ϶��ǺϷ���
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