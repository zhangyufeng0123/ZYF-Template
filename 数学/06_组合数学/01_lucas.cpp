// 1 <= n, m <= 1000000000, 1 < p < 100000, p is prime

const int maxn = 100010;
ll f[maxn], inv[maxn];
void CalFact(){
	f[0] = 1;
	for(int i = 1; i < maxn; i++)	f[i] = (f[i - 1] * i) % p;
		inv[maxn - 1] = Pow(f[maxn - 1], p - 2, p);
	for(int i = maxn - 2; ~i; i--)	inv[i] = inv[i + 1] * (i + 1) % p;
}

ll lucas(ll n, ll m, ll p){
	ll ret = 1;
	while(n && m){
		ll a = n % p, b = m % p;
		if(a < b)	return 0;
		ret = ret *f[a] % p * inv[b] % p * inv[a - b] % p;
		n /= p, m /= p;
	}
	return ret;
}