#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+100;
vector<int>g[maxn];
int n,m,ans=0,clk=0,dfn[maxn],low[maxn];
void tj(int u,int fa){
    clk++;
    dfn[u]=low[u]=clk;
    for(auto v:g[u]){
        if(v==fa)continue;
        if(!dfn[v]){
            tj(v,u);
            low[u]=min(low[v],low[u]);
            if(low[v]>dfn[u])ans++;
        }else{
            low[u]=min(low[u],dfn[v]);
        }
    }
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
    for(int i=1;i<=n;i++)if(dfn[i]==0)tj(i,0);
    cout<<ans<<endl;
}