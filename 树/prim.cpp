#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

#define inf 1<<29
const int maxn = 111;

int vis[maxn],mapp[maxn][maxn],n,m,dis[maxn];
int k;

struct node {
    int len, v;//v表示当前节点，len表示该点到已经连通集合的最短距离
    friend bool operator<(node a, node b) {
        return a.len > b.len;
    }
};

int prim(){
    node cur;
    int ans=0;
    priority_queue<node>q;
    fill(dis,dis+maxn,inf);
    fill(vis,vis+maxn,0);
    cur.v=1;
    cur.len=0;
    q.push(cur);
    while(q.size()){
        k++;
        cur=q.top();
        q.pop();
        if(vis[cur.v]) continue;
        vis[cur.v]=1;
        ans+=cur.len;
        for(int i=1; i<=n; i++){
            if(!vis[i] && dis[i] > mapp[i][cur.v]){
                node next;
                next.v=i;
                next.len=mapp[i][cur.v];
                dis[i]=mapp[i][cur.v];
                q.push(next);
            }
        }
    }
    return ans;
}

int main(void){
    while(cin >> m >> n){//n为点数量，m为边数量
        k=0;
        if(m==0){
            break;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                mapp[i][j]=i==j?0:inf;
            }
        }
        int x,y,w;
        for(int i=0;i<m;i++){
            cin >> x >> y >> w;
            mapp[x][y]=min(mapp[x][y],w);
            mapp[y][x]=min(mapp[y][x],w);
        }
        int num=prim();
        if(k!=n){
            cout << '?' << endl;
        }else{
            cout << num << endl;
        }
    }
}