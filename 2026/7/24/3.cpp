#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
vector<int> g[maxn],scc_f[maxn],scc_r[maxn];
int minp[maxn],maxp[maxn],f1[maxn],fn[maxn],n,m,q,a[maxn],sxx[maxn],dfn[maxn],low[maxn],clk=0,scc_sum=0;
stack<int>st;
bool inst[maxn],vis1[maxn],visn[maxn];
void tarjan(int u){
    dfn[u]=low[u]=++clk;
    st.push(u);
    inst[u]=true;
    for(int v:g[u]){
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(inst[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        ++scc_sum;
        int v;
        do{
            v=st.top();st.pop();
            inst[v]=false;
            sxx[v]=scc_sum;
            minp[scc_sum]=min(minp[scc_sum],a[v]);
            maxp[scc_sum]=max(maxp[scc_sum],a[v]);
        }while(v!=u);
    }
}

int caln(int u){
    if(visn[u]) return fn[u];
    visn[u]=true;
    if(u==sxx[n]) {
        fn[u]=maxp[u];
        return fn[u];
    }
    fn[u]=-1e9;
    for(int v:scc_f[u]){
        fn[u]=max(fn[u],caln(v));
    }
    if(fn[u]>-1e9) fn[u]=max(fn[u],maxp[u]);
    return fn[u];
}

int cal1(int u){
    if(vis1[u]) return f1[u];
    vis1[u]=true;
    if(u==sxx[1]) {
        f1[u]=minp[u];
        return f1[u];
    }
    f1[u]=1e9;
    for(int v:scc_r[u]){
        f1[u]=min(f1[u],cal1(v));
    }
    if(f1[u]<1e9)f1[u]=min(minp[u],minp[u]);
    return f1[u];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        g[x].push_back(y);
        if(z==2) g[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        minp[i]=1e9;
        maxp[i]=0;
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i);
    }
    for(int u=1;u<=n;u++){
        for(int v:g[u]){
            if(sxx[u]!=sxx[v]){
                scc_f[sxx[u]].push_back(sxx[v]);
                scc_r[sxx[v]].push_back(sxx[u]);
            }
        }
    }
    for(int i=1;i<=scc_sum;i++){
        f1[i]=1e9;
        fn[i]=0;
    }
    int ans=0;
    for(int i=1;i<=scc_sum;i++){
        int minv=cal1(i);
        int maxv=caln(i);
        if(vis1[i] && visn[i]){
            ans=max(ans,maxv-minv);
        }
    }
    cout<<ans<<endl;
    return 0;
}