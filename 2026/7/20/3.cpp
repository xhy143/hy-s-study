#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int dep[maxn],f[maxn][21];
long long sumw[maxn];
int n,q;
struct edge{
    int v,w;
};
vector<edge>g[maxn];
void dfs(int u,int fa){
    f[u][0]=fa;
    dep[u]=dep[fa]+1;
    for(int i=1;i<=20;i++){
        f[u][i]=f[f[u][i-1]][i-1];
    }
    for(auto v:g[u]){
        if(v.v==fa)continue;
        sumw[v.v]=sumw[u]+v.w;
        dfs(v.v,u);
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    for(int i=20;i>=0;i--) if(dep[u]-dep[v]>=(1<<i)) u=f[u][i];
    if(u==v)return u;
    for(int i=20;i>=0;i--){
        if(f[u][i]!=f[v][i]){
            u=f[u][i];
            v=f[v][i];
        }
    }
    return f[u][0];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dep[0]=0;
    sumw[1]=0;
    cin>>q;
    dfs(1,0);
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        int y=lca(u,v);
        cout<<sumw[u]+sumw[v]-2ll*sumw[y]<<'\n';
    }
}