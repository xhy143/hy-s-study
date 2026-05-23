#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[1000001];
int n,a[1000001],pre[1000001];
signed main(){
    cin>>n;
    memset(dp,0x3f3f3f,sizeof(dp));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1){
            pre[i]=a[i]*a[i];
            continue;
        }
        pre[i]=pre[i-1]+a[i]*a[i];
    }
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i]=min(dp[i],dp[j]+(pre[i]-pre[j])*a[i]);
        }
    }
    cout<<dp[n];
}//dp[i]=min(dp[j]-a[i]*pre[j])+pre[i]*a[i];
//             y  -   k   x   =   b 