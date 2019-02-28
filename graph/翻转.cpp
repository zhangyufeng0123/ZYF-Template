#include<iostream>
#include<cstring>

using namespace std;

const int maxn = 20;

int g[maxn][maxn], t[maxn][maxn], f[maxn][maxn];

int cnt, n, m;
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

void flip(int i, int j) {
    ++cnt, f[i][j] = 1;
    t[i][j] = !t[i][j];
    for (int k = 0; k < 4; k++) {
        if (i + dx[k] > -1 && j + dy[k] > -1) {
            t[i + dx[k]][j + dy[k]] ^= 1;
        }
    }
}

bool ok(int k) {
    cnt = 0;
    memcpy(t, g, sizeof(t));
    for (int j = 0; j < m; j++) {
        if (k & (1 << (m - 1 - j))) {
            flip(0, j);
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            if(t[i - 1][j]) flip(i,j);
        }
    }
    for(int j = 0; j < m; j++){
        if(t[n - 1][j]){
            return false;
        }
    }
    return true;
}

int main(void){
    int ans, p;
    while(~scanf("%d%d", &n, &m)){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%d", &g[i][j]);
            }
        }
        ans = n * m + 1, p = -1;
        for(int i = 0; i < (1 << m); i++){
            if(ok(i) && cnt < ans){
                ans = cnt, p = i;
            }
        }
        memset(f, 0, sizeof(f));
        if(p >= 0){
            ok(p);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    printf("%d%c", f[i][j], j < m - 1 ? ' ': '\n');
                }
            }
        }else{
            puts("IMPOSSIBLE");
        }
    }
}