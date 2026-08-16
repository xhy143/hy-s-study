#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 105;
const int INF = 1e18;
int n, m, k;
vector<pair<int, int>> adj[MAXN];
int dist[MAXN][MAXN];
int s[MAXN], t[MAXN];
int u[MAXN];
void init()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = (i == j ? 0 : INF);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto &e : adj[i])
        {
            dist[i][e.first] = min(dist[i][e.first], e.second);
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
int time(int i, int j)
{
    int res = dist[1][u[i]];
    for (int k = i; k < j; k++)
    {
        res += dist[u[k]][u[k + 1]];
    }
    res += dist[u[j]][1];
    return res;
}
bool check(int T)
{
    vector<int> dp(k + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= k; i++)
    {
        int max_dist = 0;
        for (int j = i; j <= k; j++)
        {
            int start = max(t[j], dp[i - 1]);
            int end = start + time(i, j);
            bool ok = true;
            for (int k = i; k <= j; k++)
            {
                int dd = start + dist[1][u[k]];
                if (dd - s[k] > T)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                dp[j] = min(dp[j], end);
            }
        }
    }
    return dp[k] < INF;
}
signed main()
{
    freopen("retired.in", "r", stdin);
    freopen("retired.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> s[i] >> u[i] >> t[i];
    }
    init();
    int l = 0, r = 1e18;
    while (l < r)
    {
        int mid = (l + r) / 2;
        bool flag = check(mid);
        // cout<<mid<<' '<<flag<<endl;
        if (flag)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}