#include<bits/stdc++.h>
using namespace std;
int main(){
    int dp1[100001],dp2[100001],h[100001],n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(h[i]>h[j]){
                dp1[i]=max(dp1[i],dp1[j]+1);
            }
        }
    }
    for(int i=n;i>0;i--){
        for(int j=n+1;j>i;j--){
            if(h[i]>h[j]){
                dp2[i]=max(dp2[i],dp2[j]+1);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp1[i]+dp2[i]-1);
    }
    cout<<n-ans<<endl;
}