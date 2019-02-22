#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
const int MAX = 1e6+100;
struct hh{
    int u,v,w;
    int nt;
}a[MAX];
int dis[MAX],head[MAX];
bool vis[MAX];
int n,tot,point,len;
ll ans;//注意要用long long
void add(int u,int v,int w){
    a[tot].v=v;
    a[tot].u=u;
    a[tot].w=w;
    a[tot].nt=head[u];
    head[u]=tot++;
}
void bfs(int s){//找树的直径模板
    memset(vis,false,sizeof(vis));//第二次要初始化，第一次一块带上了，嘻嘻~~不超时
    memset(dis,0,sizeof(dis));//第二次要初始化，第一次一块带上了，嘻嘻~~不超时
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for (int i = head[x]; ~i; i = a[i].nt){
            int y=a[i].v;
            if(!vis[y]){
                dis[y]=dis[x]+a[i].w;
                if(len<dis[y]){
                    len=dis[y];
                    point=y;
                }
                vis[y]=true;
                q.push(y);
            }
        }
    }
}
int main(){
    cin >> n;
    memset(head,-1,sizeof(head));
    for (int i = 0; i < n-1;i++){
        int u,v,w;
        cin >> u >> v >> w;
        add(u,v,w);//无向边，为双向的
        add(v,u,w);
        ans+=w<<1;//树的权值*2
    }
    len=0;
    bfs(1);//找到最远点
    len=0;//len为树的直径~~，记住要初始化！
    bfs(point);//找直径，必须跑两边，记住！！！
    cout << ans-len << endl;
    return 0;
}
