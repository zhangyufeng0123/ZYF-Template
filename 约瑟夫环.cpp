#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,tot=0;//n,m如题意,tot记录报的数字
    cin >> n >> m;
    queue<int>que;//定义队列
    for(int i=1;i<=n;i++)
        que.push(i);//初始化
    while(!que.empty())//当队列里还有人就一直循环
    {
        int k=que.front();//取出队首
        que.pop();//删除队首
        tot++;//报的数字加1
        if(tot%m==0)
            cout << k << ' ';
        else que.push(k);//否则再放进队尾
    }
    return 0;//程序结束啦
}