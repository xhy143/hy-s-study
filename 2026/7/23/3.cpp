#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int maxm=25;
struct node{
    int v,dis;
};
vector<node>g[maxn];
int n,m,q,top[maxn],son[maxn],siz[maxn],dep[maxn],f[maxn],dfu[maxn],rk[maxn],clk=0,st[maxn][maxm],lg[maxn],w[maxn];
void dfs(int u,int fa){
    int maxsiz=0;
    siz[u]=1;
    f[u]=fa;
    for(auto &e:g[u]){
        int v=e.v,w=e.dis;
        if(v==fa)continue;
        dep[v]=dep[u]+1;
        ::w[v]=w;
        dfs(v,u);
        if(maxsiz<siz[v]){
            maxsiz=siz[v];
            son[u]=v;
        }
        siz[u]+=siz[v];
    }
}
void dfs2(int u,int fa){
    ++clk;
    rk[clk]=u;
    dfu[u]=clk;
    st[clk][0]=w[u];
    if(son[u]){
        top[son[u]]=top[u];
        dfs2(son[u],u);
    }
    for(auto &e:g[u]){
        int v=e.v;
        if(v==fa||v==son[u]){
            continue;
        }
        top[v]=v;
        dfs2(v,u);
    }
}
void get_rmq(){
    for(int j=1;j<maxm;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
        }
    }
}
int rmq(int posx,int posy){
    if(posx>posy)return 0x3f3f3f3f;
    int len=posy-posx+1;
    return min(st[posx][lg[len]],st[posy-(1<<lg[len])+1][lg[len]]);
}
int query(int x,int y){
    int ans=0x3f3f3f3f;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        ans=min(ans,rmq(dfu[top[x]],dfu[x]));
        x=f[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    ans=min(ans,rmq(dfu[x]+1,dfu[y]));
    return ans;
}
signed main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    lg[1]=0;
    for(int i=2;i<=n;i++) lg[i]=lg[i/2]+1;
    dfs(1,0);
    top[1]=1;w[1]=0x3f3f3f3f;
    dfs2(1,0);
    get_rmq();
    cin>>q;
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<query(x,y)<<'\n';
    }
}