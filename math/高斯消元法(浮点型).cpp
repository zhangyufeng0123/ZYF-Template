#include<bits/stdc++.h>
#define rg register
#define il inline
#define maxn 500005
#define eps 1e-8
#define ll long long
using namespace std;
bool vis[maxn];
double a[300][300],b[maxn],res[maxn];
bool Gauss(int m,int n){
    for (int i = 1;i<=m;++i){
        if (fabs(a[i][i]) < eps){//若该项为0，则进行 行交换
            int j = i + 1;
            while (fabs(a[j][i]) < eps && j<=m) ++j;//在当前列中找到一个非零项
            if (j > m) return 0;//如果没有找到，说明没有唯一解，直接return
            if (j<=m) {swap(a[i],a[j]);swap(res[i],res[j]);}//进行 行交换
        }
        for (int j=i+1;j<=m;++j){
            if (fabs (a[j][i]) > eps){//只操作该列非0元素所在的行
                double chu = a[j][i] / a[i][i];//简单的消元
                for (int k = i;k<=n;++k){
                    a[j][k] -= (a[i][k] * chu);
                }
                res[j] -= (res[i] * chu);
            }
        }
    }
    for (int i = n;i>=1;--i){//暴力回代
        double x = res[i];
        for (int j=n;j>i;--j){
            x -= a[i][j] * b[j];//减去已知值
        }
        b[i] = x / a[i][i];//得到未知数
    }
    return 1;
}
int main(){
    rg int n,m;
    scanf("%d",&m);
    n = m;
    for (rg int i=1;i<=m;++i){
        for (rg int j=1;j<=n;++j){
            scanf("%lf",&a[i][j]);
        }
        scanf("%lf",&res[i]);//这里为了结果清晰就没有增广了
    }
    if (!Gauss(m,n)) {cout<<"No Solution";return 0;}
    for (rg int i=1;i<=n;++i) printf("%.2f\n",b[i]);
    return 0;
}