//
// Created by Lenovo on 2022/4/7.
//DFS深度优先搜索 解决背包问题

#include<iostream>
using namespace std;
int n,V,maxValue=0;//n物品数量 v背包容量 maxvalue最大价值
const int maxn = 30;
int w[maxn],c[maxn];//w重量 c价值

void DFS(int index,int sumW,int sumC)
{
    if(index == n)
    {
        //不超过最大背包容量时更新最大价值
        if(sumW <= V && sumC > maxValue)
            maxValue = sumC;
        return;
    }
    if(sumW > V)
        return;
    //对于每件物品有拿和不拿两种选择
    DFS(index+1,sumW,sumC);
    DFS(index+1,sumW+w[index],sumC+c[index]);
}

int main()
{
    n = 5;
    V = 8;
    w[0] = 3,w[1]=5,w[2] = 1,w[3] = 2,w[4] = 2;
    c[0] = 4,c[1]=5,c[2] = 2,c[3] = 1,c[4] = 3;
    DFS(0,0,0);
    cout << maxValue;
}