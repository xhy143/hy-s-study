#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+100;
#define QWQ 0
vector<int>g[maxn],g_scc[maxn];
long long scc_sum[maxn],f[maxn],scc[maxn],a[maxn];
stack<int>st;
int n,m,dfn[maxn],low[maxn],clk=0,scc_num=0;
bool inst[maxn],vis[maxn];
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
        long long sum=0;
        scc_num++;
        int v;
        do{
            v=st.top();
            st.pop();
            inst[v]=false;
            scc[v]=scc_num;
            sum+=a[v];

        }while(u!=v);
        scc_sum[scc_num]=sum;
    }
    return ;
}
long long cal(int u){
    if(vis[u])return f[u];
    f[u]=scc_sum[u];
    vis[u]=1;
    for(int v:g_scc[u]){
        f[u]=max(f[u],scc_sum[u]+cal(v));
    }
    return f[u];
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
    int q;
    cin>>q;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=q;i++){
        int x;
        cin>>x;
        cout<<cal(scc[x])<<'\n';
    }
    return QWQ;
}