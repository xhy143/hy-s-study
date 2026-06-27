#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int fp(int a,int b){
    int res=1;
    while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res%mod;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<((fp(4,n)-fp(3,n)-fp(3,n)+fp(2,n))%mod+mod)%mod<<endl;
    }
}