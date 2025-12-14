#include<bits/stdc++.h>
using namespace std;
int dp[10001],a[10001];
int main(){
    
    int n;
    cin>>n;
    if(n==0){
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;i++){
        dp[i]=1;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int maxx=-114514;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            dp[i]=(a[i]<=a[j]?max(dp[j]+1,dp[i]):dp[i]);
            maxx=max(maxx,dp[i]);
        }
    }
    cout<<maxx;
}