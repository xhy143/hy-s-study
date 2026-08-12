#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
struct edge{
    int v;int d;
};
vector<edge>g[maxn];
int n,dp[maxn],ans;
vector<int>vec;
void dfs(int u,int fa){
    for(auto e:g[u]){
        int v=e.v,d=e.d;
        if(v==fa)continue;
        dp[1]+=d;
        dfs(v,u);
    }
}
void dfs2(int u,int fa){
    for(auto e:g[u]){
        int v=e.v,d=e.d;
        if(v==fa)continue;
        if(d==0)dp[v]=dp[u]+1;
        else dp[v]=dp[u]-1;
        dfs2(v,u);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back({v,0});
        g[v].push_back({u,1});
    }
    dfs(1,0);
    dfs2(1,0);
    ans=dp[1];
    vec.push_back(1);
    for(int i=2;i<=n;i++){
        if(dp[i]<ans){
            vec.clear();
            vec.push_back(i);
            ans=dp[i];
        }
        else if(dp[i]==ans)vec.push_back(i);
    }
    cout<<ans<<endl;
    for(auto now:vec){
        cout<<now<<' ';
    }
}