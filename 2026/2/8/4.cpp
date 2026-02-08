#include<bits/stdc++.h>
#define mod 1000007
#define 什么78题目 0
using namespace std;
int dp[1001][1001],a[100001],pre[1001][1001];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        pre[i-1][0]=dp[i-1][0];
        for(int j=1;j<=m;j++){
            pre[i-1][j]=(pre[i-1][j-1]+dp[i-1][j])%mod;
        }
        for(int j=0;j<=m;j++){
            int l=j-a[i]-1;
            int val=pre[i-1][j];
            if(l>=0){
                val=(val-pre[i-1][l]+mod)%mod;
            }
            dp[i][j]=val;
        }
    }
    cout<<dp[n][m];
    return 什么78题目;
}