#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
void in(int n,int* a){
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
}
int main(){
    int n,a[10001],b[10001];
    memset(dp,0,sizeof(dp));
    cin>>n;
    in(n,a);
    in(n,b);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][n];
}