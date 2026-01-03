#include<bits/stdc++.h>
using namespace std;
int dp[10001][10001],w[10001],p[10001];
int main(){
    int n,k;
    cin>>k>>n;
    for(int i=0;i<n;i++){
        cin>>w[i]>>p[i];
    }
    for(int i=0;i<n;i++){
        for(int j=k-1;j>=0;j--){
            dp[i][j]=max(dp[i][j-1],dp[i-1][j-w[i]]+p[i]);
        }
    }
    cout<<dp[n-1][k];
}