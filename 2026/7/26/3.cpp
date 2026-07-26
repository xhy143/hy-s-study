#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+100;
#define QWQ 0
vector<int>g[maxn],g_scc[maxn];
long long scc_min_cost[maxn],scc[maxn],a[maxn],indeg[maxn];
stack<int>st;
int n,m,dfn[maxn],low[maxn],clk=0,scc_num=0;
bool inst[maxn];
void tj(int u){
    ++clk;
    dfn[u]=low[u]=clk;
    inst[u]=true;
    st.push(u);
    for(int v:g[u]){
        if(dfn[v]==0){
            tj(v);
            low[u]=min(low[u],low[v]);
        }
        else if(inst[v]){
            low[u]=min(low[u],low[v]);
        }
    }
    if(dfn[u]==low[u]){
        long long min_cost=1e18;
        scc_num++;
        int v;
        do{
            v=st.top();
            st.pop();
            inst[v]=false;
            scc[v]=scc_num;
            min_cost=min(min_cost,a[v]);
        }while(u!=v);
        scc_min_cost[scc_num]=min_cost;
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    memset(inst,false,sizeof(inst));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    for(int i=1;i<=n;i++){
        if(dfn[i]==0)tj(i);
    }
    for(int u=1;u<=n;u++)
        for(int v:g[u])
            if(scc[u]!=scc[v])
                g_scc[scc[u]].push_back(scc[v]);
    memset(indeg,0,sizeof(indeg));
    for(int u=1;u<=scc_num;u++){
        for(int v:g_scc[u]){
            indeg[v]++;
        }
    }
    long long ans=0;
    for(int i=1;i<=scc_num;i++){
        if(indeg[i]==0){
            ans+=scc_min_cost[i];
        }
    }
    cout<<ans<<'\n';
    return QWQ;
}
