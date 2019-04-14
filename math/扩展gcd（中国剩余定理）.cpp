# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c, d, x, y, gd;
  
ll ex_gcd(ll a, ll b)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    gd = ex_gcd(b, a%b);
    ll t = x;
    x = y;
    y = t-(a/b)*y;
    return gd;
}
  
int main()
{
    ll A, B, C, D, t, tmp=0;
    scanf("%lld%lld%lld%lld",&A,&B,&C,&D);
    a = A;
    b = -C;
    c = D-B;
    gd = ex_gcd(a, b);
    if(c % gd != 0)
        return 0*puts("-1");
    x = x*c/gd;
    y = y*c/gd;
    ll k = b/gd;
    x = (x%k+k)%k;
    if(x < 0) x += abs(k);
    k = abs(k);
    ll l = 0, r = 1e9;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (x + mid * k >= 1e9) {
            r = mid - 1;
            continue;
        }
        if ((c - a * (x + mid * k)) / b >= 0) {
                r = mid - 1;
                tmp = mid;
            } else {
                l = mid + 1;
            }
    }
    printf("%lld\n",B+A*(x+k*tmp));
    return 0;
}