#include <bits/stdc++.h>

using namespace std;
const int MAX_V=20000+1;
const int INF=1e8;
struct edge
{
    int to,cost;
};
typedef pair<int,int> P;
int V,pre[MAX_V];
vector<edge> G[MAX_V];
int d[MAX_V];
bool used[MAX_V];
int n,m,S,T;
int dijkstra(int s,int t)
{
    priority_queue<P,vector<P>,greater<P> > que;
    memset(used,false,sizeof(used));
    fill(d+1,d+V+1,INT_MAX);
    fill(pre,pre+n+1,-1);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p=que.top();
        que.pop();
        int v=p.second;
        if(d[v]<p.first||used[v])
            continue;
        used[v]=true;
        for(int i=0;i<G[v].size();i++)
        {
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
                pre[i]=v;
            }
        }
    }
    return d[t];
}

vector<int> get_path(int t){
    vector<int >path;
    for(; t != -1;t=pre[t]){
        path.push_back(t);
    }
    reverse(path.begin(), path.end());
    return path;
}

void ini()
{
    for(int i=0;i<=V;i++)
        G[i].clear();
}
int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> m) {
        if(n==0 && m==0){
            break;
        }
        V = n;
        ini();
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            G[a].push_back(edge{b, c});
            G[b].push_back(edge{a, c});
        }
        int ans = dijkstra(1, n);
        if (ans == INT_MAX)
            cout << -1 << endl;
        else{
            cout << ans << endl;
            vector<int> path;
            path=get_path(n);
            cout << 1;
            for(int i=0;i<path.size();i++){
                cout << ' ' << path[i];
            }
            cout << endl;
        }
    }
    return 0;
}