#include<bits/stdc++.h>
using namespace std;
long long n,p[1001],g[1001],dp[1000001],k;
int main(){
    cin>>n>>k;
    memset(dp,114514,sizeof(dp));
    long long z=0;
    dp[0]=0;
    for(int i=1;i<=n;i++){
        cin>>g[i]>>p[i];
        z+=g[i];
    }
    for(long long i=1;i<=n;i++){
        for(long long j=z;j>=g[i];j--){
            dp[j]=min(dp[j],dp[j-g[i]]+p[i]);
        }
    }
    for(int i=z;i>=0;i--){
        if(dp[i]<=k){
            cout<<i;
            return 0;
        }
    }
}