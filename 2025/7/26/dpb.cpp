#include<bits/stdc++.h>
using namespace std;
    int n,a[100001],dp[100001];
int main(){
    int x,cnt=0;
    cin>>n>>x;
    a[1]=dp[1]=x;
    for(int i=2;i<=n;i++){
        a[i]=(379*a[i-1]+131)%997;
    }
    for(int i=2;i<=n;i++){
        dp[i]=max(a[i],dp[i-1]);
    }   
    for(int i=0;i<=n;i++){
        cnt+=dp[i];
    }
    cout<<cnt;
}