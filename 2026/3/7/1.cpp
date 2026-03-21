#include<bits/stdc++.h>
using namespace std;
int n,dp[100001][2];
vector<int> a[100001];
namespace solve{
    void dfs(int u,int f){
        dp[u][0]=0;
        dp[u][1]=1;
        for(auto v:a[u]){
            if(v==f)continue;
            dfs(v,u);
            dp[u][0]+=dp[v][1];
            dp[u][1]+=min(dp[v][1],dp[v][0]);
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int e,b;
        cin>>b>>e;
        for(int j=0;j<e;j++){
            int p;
            cin>>p;
            a[b].push_back(p);
        }
    }
    solve::dfs(0,-1);
    cout<<min(dp[0][0],dp[0][1]);
}