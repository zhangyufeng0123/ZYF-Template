#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int weight[1005];
int value[1005];
int main()
{
    int n,m;
    cin>>m>>n;
    memset(dp,0,sizeof(dp));//数组清空,其实同时就把边界给做了清理
    for(int i=1; i<=n; i++)
        cin>>weight[i]>>value[i];
    //从1开始有讲究的因为涉及到dp[i-1][j],从0开始会越界
    for(int i=1; i<=n; i++)//判断每个物品能否放进
    {
        for(int j=0; j<=m; j++)//对每个状态进行判断
        //这边两重for都可以倒着写，只是需要处理最边界的情况，滚动数组不一样
        {
            if(j>=weight[i])//能放进
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
 
            else dp[i][j]=dp[i-1][j];//不能放进
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
