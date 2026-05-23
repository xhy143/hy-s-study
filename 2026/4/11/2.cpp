#include<bits/stdc++.h>
#define ovO 0;
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector <int> cost(n+1);
    for(int i=1;i<=n;i++){
        cin>>cost[i];
    }
    vector<int>dp(n+1);
    deque<int>dq;
    dp[0]=0;
    dq.push_back(0);
    for(int i=1;i<=n;i++){
        while(!dq.empty()&&dq.front()<i-m){
            dq.pop_front();
        }
        dp[i]=cost[i]+dp[dq.front()];
        while(!dq.empty()&&dp[i]<=dp[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    int ans=1e9;
    for(int i=n-m+1;i<=n;i++){
        ans=min(ans,dp[i]);
    }
    cout<<ans<<endl;
    return ovO
}