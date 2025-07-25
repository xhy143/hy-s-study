#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>dp(50,0);
int main(){
    cin>>n;
    dp[1]=1;
    dp[2]=1;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n];    
}