#include<bits/stdc++.h>
using namespace std;
int a[1001][1001],dp[1001][1001];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
            dp[i][j]=a[i][j];
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=i;j++){
            dp[i][j]=a[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    cout<<dp[1][1];
}