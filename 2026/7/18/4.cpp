#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[20001][2];
signed main(){
    int n;
    cin>>n;
    dp[0][0]=dp[0][1]=dp[1][1]=dp[1][0]=1;
    for(int i=2;i<=n;i++){
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-2][0];
    }
    cout<<max(dp[n][0],dp[n][1]);
}