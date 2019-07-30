ll prime(ll n)
{
    if(n < 2)return 0;
    if(n ==2 || n == 3)return 1;
    if(n % 6 != 1 && n % 6 != 5)return 0;
    for(ll i = 5; i * i <= n; i += 6)
    {
        if(n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}