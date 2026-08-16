#include <bits/stdc++.h>
using namespace std;
int n, m, g[35][35], a[35], ans = INT_MAX, cnt = 0;
void check()
{
    int cut = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (g[i][j] && a[i] != a[j])
            {
                cut++;
            }
        }
    }
    if (cut < ans)
    {
        ans = cut;
        cnt = 1;
    }
    else if (cut == ans)
    {
        cnt++;
    }
}
void dfs(int x, int cnta)
{
    if (cnta > n / 2)
        return;
    if (cnta + (n - x + 1) < n / 2)
        return;
    if (x > n)
    {
        check();
        return;
    }
    a[x] = 1;
    dfs(x + 1, cnta + 1);
    a[x] = 0;
    dfs(x + 1, cnta);
}
int main()
{
    freopen("split.in","r",stdin);
    freopen("split.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    dfs(1, 0);
    cout << cnt/2 << endl;

    return 0;
}