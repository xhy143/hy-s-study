#include<bits/stdc++.h>
using namespace std;
int dp[100001],cost[1000001];
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    dp[0]=0;
    dp[1]=cost[1-1]+1;
    dp[2]=min(cost[2-1]+4,dp[1]+cost[2-1]+1);
    dp[3]=min(cost[3-1]+9,min(dp[2]+cost[3-1]+1,dp[1]+cost[3-1]+4));
    for(int i=4;i<=n;i++){
       int c1=cost[i-1]+pow(1,2),c2=cost[i-1]+pow(2,2),c3=cost[i-1]+pow(3,2);
        dp[i]=min(dp[i-1]+c1,min(dp[i-2]+c2,dp[i-3]+c3));
        //cout<<dp[i]<<' ';
    }
    cout<<dp[n];
}