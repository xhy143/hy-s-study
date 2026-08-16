#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define int long long
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using ll = long long;
int n, m;
int c[maxn], sccnum;
pair<int, int> minc[maxn];
int dfn[maxn], low[maxn], clk, scc[maxn];
bool instack[maxn];
vector<int> adj[maxn];
stack<int> stk;
void tarjan(int u)
{
    dfn[u] = low[u] = ++clk;
    stk.push(u);
    instack[u] = true;
    for (int v : adj[u])
    {
        if (dfn[v] == 0)
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (instack[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        ++sccnum;
        minc[sccnum] = {inf, 0};
        while (true)
        {
            int v = stk.top();
            stk.pop();
            instack[v] = false;
            scc[v] = sccnum;
            if (c[v] < minc[sccnum].fi)
                minc[sccnum] = {c[v], 1};
            else if (c[v] == minc[sccnum].fi)
                minc[sccnum].se++;
            if (u == v)
                break;
        }
    }
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    cin>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(dfn[i]==0){
            tarjan(i);
        }
    }
    int sum=0,cnt=1;
    for(int i=1;i<=sccnum;i++){
        sum+=minc[i].fi;
        cnt=(long long)cnt*minc[i].se%mod;
    }
    cout<<sum<<' '<<cnt<<endl;
}