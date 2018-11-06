#include<iostream>
#include<cmath>

using namespace std;

typedef long long ll;

const int maxn=2e5+10;

int n;

int main(void){
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        double cnt=0;
        for(int i=2;i<=n;i++){
            cnt+=log(i)/log(10);
        }
        ll ans=floor(cnt);
        ans++;
        cout << ans << endl;
    }
}