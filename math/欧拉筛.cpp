int prime[maxn];
int visit[maxn];
void Prime(){
    mem(visit,0);
    mem(prime, 0);
    for (int i = 2;i <= maxn; i++) {
        cout<<" i = "<<i<<endl;
        if (!visit[i]) {
            prime[++prime[0]] = i;      //纪录素数， 这个prime[0] 相当于 cnt，用来计数
        }
        for (int j = 1; j <=prime[0] && i*prime[j] <= maxn; j++) {
//            cout<<"  j = "<<j<<" prime["<<j<<"]"<<" = "<<prime[j]<<" i*prime[j] = "<<i*prime[j]<<endl;
            visit[i*prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}
