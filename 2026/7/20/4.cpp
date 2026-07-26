#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int dep[maxn],f[maxn][21],st[maxn][21];
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
        st[u][i]=min(st[f[u][i-1]][i-1],st[u][i-1]);
    }
    for(auto &v:g[u]){
        if(v.v==fa)continue;
        st[v.v][0]=v.w;
        dfs(v.v,u);
    }
}
int query(int u,int v){
    int ans=0x3f3f3f3f;
    if(dep[u]<dep[v])swap(u,v);
    for(int i=20;i>=0;i--) if(dep[u]-dep[v]>=(1<<i)) {ans=min(ans,st[u][i]),u=f[u][i];}
    if(u==v)return ans;
    for(int i=20;i>=0;i--){
        if(f[u][i]!=f[v][i]){
            ans=min(ans,min(st[u][i],st[v][i]));
            u=f[u][i];
            v=f[v][i];
        }
    }
    ans=min(ans, min(st[u][0], st[v][0]));
    return ans;
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
    memset(st,0x3f,sizeof(st));
    dep[0]=-1;
    dfs(1,0);
    cin>>q;
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        cout<<query(u,v)<<'\n';
    }
    return 0;
}