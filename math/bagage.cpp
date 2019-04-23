//0-1背包

#include <iostream>
#include <cstring>
#define MAXN 10000
using namespace std;

int dp[MAXN];
int w[MAXN] = {0, 2, 1, 3, 2};
int v[MAXN] = {0, 3, 2, 4, 2};
int W = 5, n = 4;

int solve(int n, int W) {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) { // i从1开始，递增
        for (int j = W; j >= 0; j--) { // j按递减顺序填表
            if (j < w[i]) {
                dp[j] = dp[j];
            }
            else {
                dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
            }
        }
    }
    return dp[W];
}

int main() {
    cout << solve(n, W) << endl;
    return 0;
}

//完全背包
#include <iostream>
#include <cstring>
#define MAXN 1000
using namespace std;

int dp[MAXN];
int w[MAXN] = {0, 3, 4, 2};
int v[MAXN] = {0, 4, 5, 3};
int W = 7, n = 3;

int solve(int n, int W) {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i]) {
                dp[j] = dp[j];
            }
            else {
                dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
            }
        }
    }
    return dp[W];
}

int main() {
    cout << solve(n, W) << endl; // 10
    return 0;
}

//完全背包
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

struct Pack
{
    int sum, cost;
    Pack(int s, int c) : sum (s), cost(c) {}
};

const int Maxv = 1001;
deque <Pack> Q;
int N, V, F[Maxv];

int main()
{
    cin >> N >> V;
    for (int i = 1, p, w, c; i <= N; i ++)
    {
        cin >> p >> w >> c; p = min(p, V / w);
        for (int j = 0; j < w; j ++)
        {
            Q.clear();
            for (int k = 0; k <= (V - j) / w; k ++)
            {
                int y = F[k * w + j] - k * c;
                while (Q.size() && Q.back().cost <= y) Q.pop_back();
                Q.push_back(Pack(k, y));
                if (Q.front().sum < k - c) Q.pop_front();
                F[k * w + j] = Q.front().cost + k * c;
            }
        }
    }
    cout << F[V] << endl;
    return 0;
}

//背包
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
 
const int MAX=100000;
int dp[MAX];
int c[MAX],w[MAX];
int v;
 
void ZeroOnePack(int cost,int wei)//01
{
    int i;
    for(i = v;i>=cost;i--)
    {
        dp[i] = max(dp[i],dp[i-cost]+wei);
    }
}
 
void CompletePack(int cost,int wei)//完全
{
    int i;
    for(i = cost;i<=v;i++)
    {
        dp[i] = max(dp[i],dp[i-cost]+wei);
    }
}
 
void MultiplePack(int cost,int wei,int cnt)//多重
{
    if(v<=cnt*cost)//如果总容量比这个物品的容量要小，那么这个物品可以直到取完，相当于完全背包
    {
        CompletePack(cost,wei);
        return ;
    }
    else//否则就将多重背包转化为01背包
    {
        int k = 1;
        while(k<=cnt)
        {
            ZeroOnePack(k*cost,k*wei);
            cnt = cnt-k;
            k = 2*k;
        }
        ZeroOnePack(cnt*cost,cnt*wei);
    }
}
 
int main()
{
    int n;
    while(~scanf("%d%d",&n,&v),n+v)
    {
        int i;
        for(i = 0;i<n;i++)
        scanf("%d",&c[i]);
        for(i = 0;i<n;i++)
        scanf("%d",&w[i]);
        memset(dp,0,sizeof(dp));
        for(i = 0;i<n;i++)
        {
            MultiplePack(c[i],c[i],w[i]);
        }
        int sum = 0;
        for(i = 1;i<=v;i++)
        {
            if(dp[i]==i)
            {
                sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}