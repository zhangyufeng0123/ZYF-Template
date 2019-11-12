//注意需要
//srand(time(NULL));
int modular_exp(int a, int m, int n) {
    if (m == 0) {
        return 1;
    }
    if (m == 1) {
        return (a % n);
    }
    ll w = modular_exp(a, m / 2, n);
    w = w * w % n;
    if (m & 1) {
        w = w * a % n;
    }
    return w;
}

bool Miller_Rabin(int n) {
    if (n == 2) {
        return true;
    }
    for (int i = 0; i < maxn; i++) {
        int a = rand() % (n - 2) + 2;
        if (modular_exp(a, n, n) != a) {
            return false;
        }
    }
    return true;
}