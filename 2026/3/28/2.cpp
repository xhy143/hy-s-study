#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;
const int mod = 998244353;

int n, m, c, a[N], deg[N], func[N];
int tp[N], pos[N], val[N];
ll mu = 1, mul[N], dp[N], add[N];
vector<int> e[N];
queue<int> q;

bool vis[N];
void dfs(int id)
{
    vis[id] = 1, mul[id] = (tp[id] == 2 ? val[id] : 1);
    for (int it : e[id])
    {
        if (!vis[it])
            dfs(it);
        mul[id] = mul[id] * mul[it] % mod;
    }
}

int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    cin>>m;
    for (int i = 1; i <= m; i++)
    {
        cin>>tp[i];
        if (tp[i] == 1)
            cin>>pos[i]>>val[i];
        else if (tp[i] == 2)
            cin>>val[i];
        else
        {
            cin>>c;
            while (c--)
            {
                int to ;
                cin>>to;
                e[i].push_back(to), deg[to]++;
            }
        }
    }
    cin>>c;
    for (int i = 1; i <= m; i++)
        if (!vis[i] && !deg[i])
            dfs(i);
    for (int i = 1; i <= c; i++)
        cin>>func[i];
    for (int i = c, f = func[i]; i; i--, f = func[i])
    {
        if (tp[f] == 1)
            dp[f] = (dp[f] + mu);
        else if (tp[f] == 2)
            mu = mu * val[f] % mod;
        else
            dp[f] = (dp[f] + mu), mu = mu * mul[f] % mod;
    }
    for (int i = 1; i <= m; i++)
        if (!deg[i])
            q.push(i);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        if (tp[t] == 1)
            add[pos[t]] = (add[pos[t]] + dp[t] * val[t]) % mod;
        ll z = dp[t];
        reverse(e[t].begin(), e[t].end());
        for (int p : e[t])
        {
            deg[p]--;
            if (!deg[p])
                q.push(p);
            dp[p] = (dp[p] + z) % mod, z = z * mul[p] % mod;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << (a[i] * mu + add[i]) % mod << " ";
    return 0;
}
