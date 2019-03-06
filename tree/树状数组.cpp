#include<bits/stdc++.h>

using namespace std;

const int maxn = (int) 5e5 + 100;

int tree[maxn];
int num = 2;

void update(int index, int n) {
    for (int i = index; i <= num; i += (i & -i)) {
        tree[i] += n;
    }
}

int query_sum(int n) {
    int ans = 0;
    for (int i = n; i > 0; i -= (i & -i)) {
        ans += tree[i];
    }
    return ans;
}

int main(void) {
    int T;
    scanf("%d",&T);
    for (int i = 1; i <= T; i++) {
        memset(tree, 0, sizeof(tree));
        cout << "Case " << i << ":" << endl;
        int n;
        int end = 0;
        scanf("%d",&n);
        num = n;
        for (int e = 1; e <= n; e++) {
            int nu;
            scanf("%d",&nu);
            //cin >> nu;
            update(e, nu);
        }
        string com;
        int e, r;
        while (1) {
            cin >> com;
            int flag = com[0] - 'A';
            switch (flag) {
                case 0: {//相加
                    scanf("%d%d",&e,&r);
                    update(e, r);
                }
                    break;
                case 4://结束
                    end = 1;
                    break;
                case 16: {//询问
                    scanf("%d%d",&e,&r);
                    //cin >> e >> r;
                    cout << query_sum(r) - query_sum(e - 1) << endl;
                }
                    break;
                case 18: {//相减
                    scanf("%d%d",&e,&r);
                    //cin >> e >> r;
                    update(e, -r);
                }
                    break;
                default:
                    break;
            }
            if (end == 1) {
                break;
            }
        }
    }

}