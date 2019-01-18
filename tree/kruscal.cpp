#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

const int INF=0x3f3f3f;
const int maxn=1e4+5;

typedef long long ll;

struct edge{
    int a,b;
    int v;
}s[maxn];

int pre[maxn];

bool cmp(edge a, edge b){
    return a.v < b.v;
}

int Find(int a){
    int root=a;
    int tmp;
    while(root!=pre[root]){
        root=pre[root];
    }
    while(a != root){
        tmp=a;
        a=pre[a];
        pre[tmp]=root;
    }
    return root;
}

void combine(int a, int b){
    int x=Find(a);
    int y=Find(b);

    if(x > y){
        swap(x,y);
    }
    pre[y]=x;
}

int kruscal(int n, int m){
    int ans=0;
    for(int i=0;i<m;i++){
        if(Find(s[i].a)!=Find(s[i].b)){
            combine(s[i].a,s[i].b);
            ans+=s[i].v;
            n--;
        }
        if(n==1){
            break;
        }
    }
    cout << ans << endl;
}

int main(void){
    int n;
    int a,b,c;
    int cnt;
    while(cin >> n){
        if(n==0){
            break;
        }
        memset(s,0, sizeof(s));
        for(int i=0;i<=n;i++){
            pre[i]=i;
        }
        cnt=0;
        for(int j=0;j<n*(n-1)/2;j++){
            cin >> a >> b >> c;
            s[cnt].a=a;
            s[cnt].b=b;
            s[cnt++].v=c;
        }
        sort(s,s+cnt,cmp);
        kruscal(n,n*(n-1)/2);
    }
}