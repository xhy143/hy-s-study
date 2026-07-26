#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+100;
int n,m,ans=0,clk=0,dfn[maxn],low[maxn];
vector<int>g[maxn];
void tj(int u,int fa){
    clk++;
    dfn[u]=low[u]=clk;
    int son=0;
    bool iscut=false;
    for(auto v:g[u]){
        if(v==fa)continue;
        if(!dfn[v]){
            tj(v,u);
            low[u]=min(low[v],low[u]);
            son++;
            if(fa!=0&&low[v]>=dfn[u]){
                iscut=1;
            }
        }
        else low[u]=min(low[u],dfn[v]);
    }
    iscut|=(fa==0&&son>=2);
    ans+=iscut;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    for(int i=1;i<=n;i++)if(dfn[i]==0) tj(i,0);
    cout<<ans<<'\n';
}