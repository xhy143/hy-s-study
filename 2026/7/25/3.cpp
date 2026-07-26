#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+100;
int T,n,m,clk=0,dfn[maxn],low[maxn];
vector<int>g[maxn];
vector<pair<int,int>>ans;
stack<int>sta;
stack<pair<int,int>>stae;
void tj(int u,int fa){
    clk++;
    dfn[u]=low[u]=clk;
    sta.push(u);
    for(auto v:g[u]){
        if(v==fa)continue;
        if(!dfn[v]){
            stae.push({u,v});
            tj(v,u);
            low[u]=min(low[v],low[u]);
            if(low[v]>=dfn[u]){
                int t1=0,t2=0;
                int w;
                do{
                    w=sta.top();
                    sta.pop();
                    t1++;
                }while(w!=v);
                t1++;
                int e1,e2;
                do{
                    e1=stae.top().first,e2=stae.top().second;
                    stae.pop();
                    t2++;
                }while(e1!=u||e2!=v);
                if(t1>2)ans.push_back({t1,t2});
            }
        }
        else {
            low[u]=min(low[u],dfn[v]);
            if(dfn[v]<dfn[u]) stae.push({u,v});
        }
    }
}
signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        clk=0;
        ans.clear();
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        for(int i=1;i<=n;i++)if(dfn[i]==0) tj(i,0);
        sort(ans.begin(),ans.end());
        cout<<ans.size()<<'\n';
        for(int i=0;i<ans.size();i++)
            cout<<ans[i].first<<' '<<ans[i].second<<'\n';
        cout<<endl;
        for(int i=1;i<=n;i++)g[i].clear();
    }
}