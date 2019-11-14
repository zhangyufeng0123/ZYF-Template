inline ll ksc(ll x, ll y, ll p){	//p是mod
	ll z = (long double) x / p * y;
	ll res = (unsigned long long)x * y - (unsigned long long)z * p;
	return (res + p) % p;
}