#include<bits/stdc++.h>
using namespace std;
const int maxn=20,maxs=(1<<18)+10;
int n,e,w[maxn],dp[maxs],sum[maxs];
void cl(){
    for(int s=0;s<(1<<n);s++){
        sum[s]=0;
        for(int i=0;i<n;i++){
            if(s&(1<<i)){
                sum[s]+=w[i];
            }
        }
    }
}
int main(){
    cin>>n>>e;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    cl();
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int s=0;s<(1<<n);s++){
        for(int t=s;t;t=(t-1)&s){
            if(sum[t]<=e)dp[s]=min(dp[s],dp[s^t]+1);
        }
    }
    cout<<dp[(1<<n)-1]<<endl;
}