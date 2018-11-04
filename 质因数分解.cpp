//分解质因数
//prime_factor()传入n,返回不同质因数的个数
//f存放质因数,nf存放对应质因数的个数
//先调用initprime(),其中第二个initprime()更快

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define maxn 2001000
#define psize 100000

int plist[psize],pcount=0;

int prime(int n){
	int i;
	if((n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7))){
		return 0;
	}
	for(i=0;plist[i]*plist[i]<=n;i++){
		if(!(n%plist[i])){
			return 0;
		}
	}
	return n>1;
}

int prime_factor(int n,int *f,int *nf){
	int cnt=0;
	int n2=sqrt((double)n);
	for(int i=0;n>1&&plist[i]<=n2;++i){
		if(n%plist[i]==0){
			for(nf[cnt]=0;n%plist[i]==0;++nf[cnt],n/=plist[i]);
			f[cnt++]=plist[i];
		}
	}
	if(n>1){
		nf[cnt]=1;
		f[cnt++]=n;
	}
	return cnt;
}

/*

//产生maxn以内的所有素数
//note:2863311530就是10101010101010101010101010101010
//给所有2的倍数赋初值
#include <cmath>
#include <iostream>

using namespace std;

#define maxn 100000000
unsigned int plist[6000000],pcount;
unsigned int isprime[(maxn>>5)+1];

#define setbitzero(a) (isprime[(a)>>5]&=(~(1<<((a)&31))))
#define setbitone(a) (isprime[(a)>>5]|=(1<<((a)&31)))
#define ISPRIME(a) (isprime[(a)>>5]&(1<<((a)&31)))

void initprime(){
	int i,j,m;
	int t=(maxn>>5)+1;
	for(i=0;i<t;i++){
		isprime[i]=2863311530;
	}
	plist[0]=2;
	setbitone(2);
	setbitzero(1);
	m=(int)sqrt(maxn);
	for(pcount=1,i=3;i<=m;i+=2){
		if(ISPRIME(i)){
			for(plist[pcount++]=i,j<=i<<1;j<=maxn;j+=i){
				setbitzero(j);
			}
		}
	}
	if(!(i&1)){
		++i;
	}
	for(;i<=maxn;i+=2){
		if(ISPRIME(i)){
			plist[pcount++]=i;
		}
	}
}
*/