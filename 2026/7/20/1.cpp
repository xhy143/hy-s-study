#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
vector<int>g[maxn];
int dep[maxn],lastans,f[maxn][21];
int n,q;
void dfs(int u,int fa){
    f[u][0]=fa;
    dep[u]=dep[fa]+1;
    for(int i=1;i<=20;i++){
        f[u][i]=f[f[u][i-1]][i-1];
    }
    for(auto v:g[u]){
        if(v==fa)continue;
        dfs(v,u);
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
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin>>q;
    dep[0]=0;
    memset(f,0,sizeof(f));
    dfs(1,0);
    lastans=0;
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        u^=lastans;v^=lastans;
        lastans=lca(u,v);
        cout<<lastans<<endl;
    }
}