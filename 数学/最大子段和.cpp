#include<iostream>
#include<algorithm>

using namespace std;

const int N=2e5+4;

typedef long long ll;

ll num[N];

ll Sum(int n){
    ll cursum=0;
    ll maxsum=0;
    int flag=0;
    for(int i=0;i<n;i++){
        cursum+=num[i];
        if(cursum > maxsum){
            maxsum = cursum;
            flag=1;
        }
        else if(cursum < 0){
            cursum=0;
        }
    }
    ll maxx=num[0];
    if(flag == 0){
        for(int i=1;i<n;i++){
            if(num[i] > maxx)
                maxx=num[i];
        }
        return maxx;
    }
    return maxsum;
}

int main(void){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    cout << Sum(n) << endl;
}