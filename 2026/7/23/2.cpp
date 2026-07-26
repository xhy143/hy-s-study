#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
struct edge{
    int v,dis;
};
int top[maxn],son[maxn],siz[maxn],dep[maxn],n,q,f[maxn],sumx[maxn];
vector<edge>g[maxn];
void dfs(int u,int fa){
    int maxsiz=0;
    siz[u]=1;
    f[u]=fa;
    for(auto &e:g[u]){
        int v=e.v,w=e.dis;
        if(v==fa)continue;
        dep[v]=dep[u]+1;
        sumx[v]=sumx[u]+w;
        dfs(v,u);
        if(maxsiz<siz[v]){
            maxsiz=siz[v];
            son[u]=v;
        }
        siz[u]+=siz[v];
    }
}
void dfs2(int u,int fa){
    if(son[u]){
        top[son[u]]=top[u];
        dfs2(son[u],u);
    }
    for(auto &e:g[u]){
        int v=e.v,w=e.dis;
        if(v==fa||v==son[u])continue;
        top[v]=v;
        dfs2(v,u);
    }
}
int lca(int x,int y){
    long long ans=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]){
            swap(x,y);
        }
        ans+=sumx[x]-sumx[f[top[x]]];
        x=f[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    ans+=sumx[y]-sumx[x];
    return ans;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(1,0);
    top[1]=1;
    dfs2(1,0);
    cin>>q;
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<lca(x,y)<<'\n';
    }
}