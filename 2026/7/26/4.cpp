#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
vector<int> g[maxn];
int n, m, clk = 0, scc_cnt = 0;
int dfn[maxn], low[maxn], belong[maxn], sz[maxn];
stack<int> st;
bool inst[maxn];
void tj(int u, int fa)
{
    clk++;
    dfn[u] = low[u] = clk;
    st.push(u);
    inst[u] = true;
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        if (!dfn[v])
        {
            tj(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if (inst[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        scc_cnt++;
        int v;
        do
        {
            v = st.top();
            st.pop();
            inst[v] = false;
            belong[v] = scc_cnt;
            sz[scc_cnt]++;
        } while (u != v);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(inst, false, sizeof(inst));
    for (int i = 1; i <= n; i++)
    {
        if (dfn[i] == 0)
            tj(i, 0);
    }
    long long ans = 0;
    for (int i = 1; i <= scc_cnt; i++)
    {
        ans += 1LL * sz[i] * (sz[i]-1);
    }
    cout << ans << '\n';
    return 0;
}