#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int fp(int a, int e) {
    int r = 1;
    while (e) {
        if (e & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return r;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int f[100086];
        int ans=0;
        for(int i=m;i>=1;i--){
            f[i]=(fp(m/i,n)+mod)%mod;
            for(int j=i+i;j<=m;j+=i){
                f[i]-=f[j];
                f[i]=(f[i]+mod)%mod;
            }
        }
        cout<<(f[k]+mod)%mod<<endl;
    }
    return 0;
}