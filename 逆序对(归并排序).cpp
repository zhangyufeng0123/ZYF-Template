#include<iostream>

using namespace std;

typedef long long ll;

const int maxn=5e5+5;

int a[maxn],b[maxn];
int rr,tem,t,s;

ll ans;

void merg(int ll, int l, int r) {
    rr = l - 1, tem = ll, t = l, s = ll;
    while (ll <= rr && t <= r)
        if (a[ll] <= a[t])
            b[tem++] = a[ll++];
        else {
            ans += l - ll;
            b[tem++] = a[t++];
        }
    while (ll <= rr)
        b[tem++] = a[ll++];
    while (t <= r)
        b[tem++] = a[t++];
    for (; s <= r; s++)
        a[s] = b[s];
}

void mergsort(int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergsort(l, mid);
        mergsort(mid + 1, r);
        merg(l, mid + 1, r);
    }
}

int main(void) {
    int n, i;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ans = 0;
    mergsort(1, n);
    cout << ans << endl;
}