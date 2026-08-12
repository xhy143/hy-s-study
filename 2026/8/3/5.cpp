#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10,inf=0x3f3f3f3f3f3f3f3f;
int a[maxn];
struct edge{
    int v,w;
};
vector<edge>g[maxn];
int siz[maxn],dep[maxn],n,ans;
void dfs(int u,int fa){
    siz[u]=1;
    for(edge e:g[u]){
        int v=e.v,w=e.w;
        if(v==fa)continue;
        dep[v]=dep[u]+w;
        dfs(v,u);
        siz[u]+=siz[v];
    }
}
void dfs2(int u,int fa,int mindep){
    if(dep[u]-a[u]>mindep){
        ans+=siz[u];
        return;
    }
    for(edge e:g[u]){
        int v=e.v,w=e.w;
        if(v==fa)continue;
        dfs2(v,u,min(mindep,dep[u]));
    }
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>w;
        v=i+1;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dep[1]=0;
    dfs(1,0);
    dfs2(1,0,inf);
    cout<<ans<<'\n';
    return 0;
}