#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>dp(100005,0);
int main(){
    cin>>n;
    int x;
    cin>>x;
    int a[100005];
    a[1]=dp[1]=x;
    for(int i=2;i<=n;i++){
        a[i]=(379*a[i-1]+131)%997;
    }
    int ans=0;
    for(int i=2;i<=n;i++){
        dp[i]=min(a[i],dp[i-1]);
    }
    for(int i=1;i<=n;i++){
        ans+=dp[i];
    }
    cout<<ans;
}