#include<bits/stdc++.h>
using namespace std;
int dp[200000],w[201],p[201];
int main(){
    int n,k;
    cin>>k>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=k;j>=w[i];j--){
                dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
            
        }
    }
    cout<<(dp[k]==k?"YES":"NO");
}