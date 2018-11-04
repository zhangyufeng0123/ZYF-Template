typedef long long ll;

ll powmod(ll a, ll b, ll mod){
    ll base=a%mod,res=1;
    for(;b;b>>=1){
        if(b&1){
            res=res*base%mod;
        }
        base=base*base%mod;
    }
    return res;
}