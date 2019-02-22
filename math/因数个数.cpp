#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef long long ll;

const int inf = (int)1e9;
const int maxn = (int)1e6 + 5;
const ll mod = (ll)998244353;
int m, n;
int num[maxn] = { 0 };
int prim[maxn] = { 0 };
bool vis[maxn >> 1] = { false };

void initprime() {
    m = 0;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prim[m++] = i;
        }
        for (int j = 0; j < maxn&&i*prim[j] < maxn; j++) {
            vis[i*prim[j]] = 1;
            if (i % prim[j] == 0) {
                break;
            }
        }
    }
}

int cnt[maxn], ans[maxn];

int cal(int x) {
    int ed = int(sqrt(x));
    int as = 1;
    for (int i = 0; i < m&&prim[i] <= ed; i++) {
        int cnt = 0;
        while (x%prim[i] == 0) {
            x /= prim[i];
            cnt++;
        }
        ed = int(sqrt(x));
        as *= (cnt + 1);
        if (as > 1000000) {
            return -1;
        }
    }
    if (x > 1) {
        as *= 2;
    }if (as > 1000000) {
        return -1;
    }
    return as;
}

void prime();

void solve() {
    prime();
    num[1] = 1;
    num[2] = 2;
    num[3] = 4;
    for (int i = 5; i <= maxn; i++) {
        int tmpe = i;
        int res = 1;
        for (int j = 0; j < m; j++) {
            int tmp = 0;
            while (tmpe%prim[j] == 0) {
                tmp++;
                tmpe /= prim[j];
            }
            res *= (tmp + 1);
            if (tmpe == 1) {
                break;
            }
        }
        if (num[res] == 0) {
            num[res] = tmpe;
        }
    }
}

void prime() {
    int sq = (int)sqrt(maxn);
    prim[0] = 2;
    m = 1;
    for (int i = 3; i < sq; i += 2) {
        if (vis[i >> 1]) {
            continue;
        }
        for (int j = i * i; j <= maxn; j += (i << 1)) {
            vis[j >> 1] = 1;
        }
    }
    for (int i = 1; i <= (maxn >> 1); i++) {
        if (!vis[i]) {
            prim[m++] = i << 1 | 1;
        }
    }
}

void init() {
    initprime();
    for (int i = 1; i < maxn; i++) {
        int t = cal(i);
        if (~t) {
            cnt[i] = t;
        }
    }
    memset(ans, -1, sizeof(ans));
    for (int i = maxn - 1; i >= 1; i--) {
        if (cnt[i] <= 1000000) {
            ans[cnt[i]] = i;
        }
    }
}

int main(void) {
    init();
    int T;
    scanf("%d", &T);
    while (T--) {
        int a;
        scanf("%d", &a);
        printf("%d\n", ans[a] == -1 ? -1 : ans[a]);
    }
}
