#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

typedef long long ll;

const int maxn=1e3+4;
#define INF 0x3f3f3f

int dist[maxn][maxn];

void init(int n){
    memset(dist,INF, sizeof(dist));
    for(int i=0;i<n;i++) dist[i][i]=0;
}

void floyd(int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}

int main(void){
    int m,n;
    while(cin >> m >> n){
        init(m);
        int u,v,w;
        while(n--){
            cin >> u >> v >> w;
            dist[u][v]=min(dist[u][v],w);
            dist[v][u]=min(dist[u][v],w);
        }
        int st,ed;
        cin >> st >> ed;
        floyd(n);
        if(dist[st][ed]!=INF){
            cout << dist[st][ed] << endl;
        }else{
            cout << -1 << endl;
        }
    }
}