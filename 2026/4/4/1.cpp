#include<bits/stdc++.h>
using namespace std;

struct edge{
    int e,w;
};
vector<edge> g[100001];
long long dp[100001], a[100001], ans[100001];
int n;
void dfs(int u, int fa){
    dp[u] = a[u];
    for(auto v : g[u]){
        if(v.e == fa) continue;
        dfs(v.e, u);
        dp[u] = min(dp[u], dp[v.e] + 2LL * v.w);
    }
}

void dfs2(int u, int fa, long long ffa){
    ans[u] = min(a[u], ffa);
    for(auto v : g[u]){
        if(v.e == fa) continue;
        ans[u] = min(ans[u], dp[v.e] + 2LL * v.w);
    }
    for(auto v : g[u]){
        if(v.e == fa) continue;
        long long other = a[u];
        for(auto nxt : g[u]){
            if(nxt.e == v.e || nxt.e == fa) continue;
            other = min(other, dp[nxt.e] + 2LL * nxt.w);
        }
        other = min(other,ffa);
        dfs2(v.e, u, other + 2LL * v.w);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int s, e, p;
        cin >> s >> e >> p;
        g[s].push_back({e, p});
        g[e].push_back({s, p});
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    dfs(1, -1);
    dfs2(1, -1, LLONG_MAX);
    
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}