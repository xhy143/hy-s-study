#include<bits/stdc++.h>
using namespace std;
int n,m,dp[5001][5001],val[5001];
vector<int>a[5001];
namespace solve{
    void dfs(int u){
        dp[u][0]=0;
        dp[u][1]=val[u];
        for(auto v:a[u]){
            dfs(v);
            for(int i=m;i>=1;i--){
                for(int k=1;k<=m;k++){
                    if(dp[u][i]!=-1&&dp[v][k]!=-1){
                        dp[u][i+k]=max(dp[u][i+k],dp[u][i]+dp[v][k]);
                    }
                }
            }
        }
    }
}
int main(){
    cin>>n>>m;
    m++;
    for(int i=1;i<=n;i++){
        int pre;
        cin>>pre>>val[i];
        a[pre].push_back(i);
    }
    memset(dp,-1,sizeof(dp));
    solve::dfs(0);
    cout<<dp[0][m]<<endl;
    return 0;
}