#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,dp[1000001],sz[1000001];
vector<int>a[1000001];
namespace solve{
    void fs(int u,int f,int depth){
        sz[u]=1;
        dp[1]+=depth;
        for(auto v:a[u]){
            if(v==f) continue;
            fs(v,u,depth+1);
            sz[u]+=sz[v];
        }
    }
    void dfs(int u,int fa){
        for(int v:a[u]){
            if(v==fa) continue;
            dp[v]=dp[u]+n-2*sz[v];
            dfs(v,u);
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<n;i++){
        int s,e;
        cin>>s>>e;
        a[s].push_back(e);
        a[e].push_back(s);
    }
    solve::fs(1,0,0);
    solve::dfs(1,0);
    int ms=0;
    int an=0;
    for(int i=1;i<=n;i++){
        if(dp[i]>ms){
            ms=dp[i];
            an=i;
        }
    }
    cout<<an;
    return 0;
}