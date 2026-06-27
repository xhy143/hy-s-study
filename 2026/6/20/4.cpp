#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int f[100086];
        int ans=0;
        for(int i=min(n,m);i>=1;i--){
            f[i]=(n/i)*(m/i);
            for(int j=i+i;j<=min(n,m);j+=i){
                f[i]-=f[j];
            }
            ans+=i*f[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}