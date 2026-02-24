#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0;
    cin>>n;
    int dp[100001];
    for(int i=1;i<=n;i++){
        dp[i]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j*j<=i;j++){
            dp[i]=min(dp[i],dp[i-j*j]+1);
        }
    }
    cout<<dp[n];
    return 0;
}