typedef long long ll;

ll powmod(ll a, ll b, ll mod){
	ll ans=1;
	while(b){
		if(b&1){
			ans=ans*a%mod;
		}
		a=a*a%mod;
	}
	ans%=mod;
	return ans;
}