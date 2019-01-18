#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

const int INF=9999999;

int main(void){
    int u[100],v[100],w[100],dis[100],n,m,ck,flag;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> u[i] >> v[i] >> w[i];
    }
    for(int i=1;i<=n;i++){
        dis[i]=INF;
    }
    dis[1]=0;
    for(int k=1;k<=n-1;k++){
        ck=0;
        for(int i=1;i<=m;i++){
            if(dis[v[i]] > dis[u[i]]+w[i]){
                dis[v[i]]=dis[u[i]]+w[i];
                ck=1;
            }
        }
        if(ck==0){
            break;
        }
    }
    flag=0;
    for(int i=1;i<=m;i++){
        if(dis[v[i]] > dis[u[i]]+w[i]){
            flag=1;
        }
    }
    if(flag== 1){
        cout << "此图包含有负权回路\n";
    }else{
        for(int i=1;i<=n;i++){
            cout << dis[i] << ' ' ;
        }
    }
}