#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int N,M,T;
char a[10][10];
int vis[10][10],flag;
int x_begin,x_end,y_end,y_begin;
int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};

void dfs(int x, int y, int times){
    int n,m,i;
    if(x==x_end&&y==y_end&&times==T){
        flag=1;
        return;
    }
    if(times>=T){
        return;
    }
    for(i=0;i<4;i++){
        if(x+dir[i][0]>=1&&x+dir[i][0]<=N&&y+dir[i][1]>=1&&y+dir[i][1]<=M){
            n=x+dir[i][0];
            m=y+dir[i][1];
            if(a[n][m]!='X'&&vis[n][m]!=1){
                vis[n][m]=1;
                dfs(n,m,times+1);
                if(flag>0){
                    return;
                }
                vis[n][m]=0;
            }
        }
    }
}

int main(void){
    int t;
    while(cin >> N >> M >> T){
        if(N==0&&M==0&&T==0){
            break;
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++) {
                cin >> a[i][j];
                if(a[i][j]=='S'){
                    x_begin=i;
                    y_begin=j;
                }
                else if(a[i][j]=='D'){
                    x_end=i;
                    y_end=j;
                }
            }
        }
        flag=0;
        t=0;
        memset(vis,0, sizeof(vis));
        if(abs(x_begin-x_end)+abs(y_end-y_begin)>T||(x_end+x_begin+y_begin+y_end)%2!=T%2){
            cout << "NO" << endl;
            continue;
        }
        vis[x_begin][y_begin]=1;
        dfs(x_begin,y_begin,t);
        if(flag==0){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
}