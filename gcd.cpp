#include<iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? gcd(b,a % b);
}

void exgcd(ll a, ll b, ll &d, ll &x, ll &y){
    if(!b){
        d=a,x=1,y=0;
    }else{
        exgcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}
//欧几里德算法又称辗转相除法，用于计算两个整数a,b的最大公约数（greatest common divisor）。
//扩展欧几里德算法是用来在已知a, b求解一组x，y，使它们满足贝祖等式： ax+by = gcd(a, b) =d
//（解一定存在，根据数论中的相关定理）。扩展欧几里德常用在求解模线性方程及方程组中。

ll getinv(ll a, ll p){
    ll d,x,y;
    exgcd(a,p,d,x,y);
    return (x+p)%p==0?p:(x+p)%p;
}
//方程ax≡1(mod p),的解称为a关于模p的逆，当gcd(a,p)==1（即a，p互质）时，方程有唯一解，否则无解。
//对于一些题目会要求把结果MOD一个数，通常是一个较大的质数，对于加减乘法通过同余定理可以直接拆开计算，
//但对于(a/b)%MOD这个式子，是不可以写成(a%MOD/b%MOD)%MOD的，但是可以写为(a*b^-1)%MOD,其中b^-1表示b的逆元。