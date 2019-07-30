#include <bits/stdc++.h>

using namespace std;

const int maxnode = 5e5 + 10;
const int MAXM = 10010;
const int MAXN = 510;

struct DLX
{
    int n, m, size;

    int U[maxnode], D[maxnode], R[maxnode], L[maxnode], Row[maxnode], Col[maxnode];
    int H[MAXM], S[MAXM];

    int ansd;

    void init(int _n, int _m)
    {
        n = _n;
        m = _m;

        for (int i = 0; i <= m; i++)
        {
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i - 1;
            R[i] = i + 1;
        }

        R[m] = 0;
        L[0] = m;
        size = m;
        for (int i = 1; i <= n; i++)
        {
            H[i] = -1;
        }
    }

    void Link(int r, int c)
    {
        ++S[Col[++size] = c];
        Row[size] = r;
        D[size] = D[c];
        U[D[c]] = size;
        U[size] = c;
        D[c] = size;

        if (H[r] < 0) H[r] = L[size] = R[size] = size;
        else {
            R[size] = R[H[r]];
            L[R[H[r]]] = size;
            L[size] = H[r];
            R[H[r]] = size;
        }
    }

    void remove (int c) {
        L[R[c]] = L[c], R[L[c]] = R[c];

        for (int i = D[c]; i != c; i = D[i]) {
            for (int j = R[i]; j != i; j = R[j]) {
                U[D[j]] = U[j];
                D[U[j]] = D[j];
                --S[Col[j]];
            }
        }
    }

    void resume (int c) {
        for (int i = U[c]; i != c; i = U[i])
            for (int j = L[i]; j != i; j = L[j])
                ++S[Col[U[D[j]] = D[U[j]] = j]];
        L[R[c]] = R[L[c]] = c;
    }

    void Dance (int d) {
        //jian zhi
        if (ansd != -1 && ansd <= d) return;
        if (R[0] == 0) {
            if (ansd == -1) ansd = d;
            else if (d < ansd) ansd = d;
            return ;
        }

        int c = R[0];
        for (int i = R[0]; i != 0; i = R[i])
            if (S[i] < S[c])
                c = i;
        remove (c);

        for (int i = D[c]; i != c; i = D[i]) {
            for (int j = R[i]; j != i; j = R[j]) remove (Col[j]);
            Dance (d + 1);
            for (int j = L[i]; j != i; j = L[j]) resume (Col[j]);
        }
        resume (c);
    }
};
DLX g;
int main()
{
    int t, n, m, p;
    cin >> t;
    while (t--) {
        cin >> n >> m >> p;
        g.init(p, n*m);
        int x1, x2, y1, y2;

        for (int k = 1; k <= p; k++) {
            cin >> x1 >> y1 >> x2 >> y2;
            for (int i = x1 + 1; i <= x2; i++) {
                for (int j = y1 + 1; j <= y2; j++) {
                    g.Link (k, j + (i - 1)*m);//01矩阵，把给你的矩阵转换为线性
                }
            }
        }
        g.ansd = -1;
        g.Dance (0);
        cout << g.ansd << "\n";
    }
    return 0;
}