#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
vector<int>g[5010];
int f[maxn],vis[maxn],n,ans=0;
int find(int x){
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
void dfs(int u,int fa){
    for(int i=1;i<=n;i++){
        if(vis[i]) ans^=find(i);
    }
    vis[u]=1;
    for(auto v:g[u]){
        if(v==fa)continue;
        dfs(v,u);
        f[v]=u;
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)f[i]=i;
    dfs(1,0);
    cout<<ans;
}