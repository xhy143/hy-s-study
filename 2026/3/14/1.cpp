#include<bits/stdc++.h>
using namespace std;
int n,v[1001][1001],dp[100001][101];
int main(){
    cin>>n;
    for(int i=0;i<n*n+n;i++) {
        int s,e,vl;
        cin>>s>>e>>vl;
        v[s][e]=vl;
    }
    memset(dp,0x3f,sizeof(dp));
    dp[1][0]=0;
    for(int s=1;s<(1<<n+1);s++){
        for(int i=0;i<=n;i++){
            if(s&(1<<i)){
                for(int j=0;j<=n;j++){
                    if(i==j||!(s&(1<<j))){
                        continue;
                    }
                    int pre=s^(1<<i);
                    dp[s][i]=min(dp[s][i],dp[pre][j]+v[j][i]);
                }
            }
        }
    }
    int ans=0x7fffffff;
    for(int i=1;i<=n;i++){
        ans=min(ans,dp[(1<<(n+1))-1][i]+v[i][0]);
    }
    cout<<ans;
}