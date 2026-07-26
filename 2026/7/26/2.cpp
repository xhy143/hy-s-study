#include <bits/stdc++.h>
#define lc ((t) << 1)
#define rc (((t) << 1) + 1)
using namespace std;
#define int long long
const int maxn = 1e5 + 100;
struct node
{
    int l, r, tag, sum;
} tree[maxn * 4];
vector<int> g[maxn];
int n, m, a[maxn], top[maxn], dfu[maxn], clk = 0, siz[maxn], son[maxn], in[maxn], out[maxn], rk[maxn], f[maxn], ql, qr, qk, ans_val;
void dfs(int u, int fa)
{
    siz[u] = 1;
    int maxsize = 0;
    f[u] = fa;
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        if (siz[v] > maxsize)
        {
            maxsize = siz[v];
            son[u] = v;
        }
        siz[u] += siz[v];
    }
}
void dfs2(int u, int fa)
{
    dfu[u] = ++clk;
    rk[clk] = u;
    in[u] = clk;
    if (son[u])
    {
        top[son[u]] = top[u];
        dfs2(son[u], u);
    }
    for (auto v : g[u])
    {
        if (v == fa || v == son[u])
            continue;
        top[v] = v;
        dfs2(v, u);
    }
    out[u] = clk;
}
void update(int t)
{
    tree[t].sum = tree[lc].sum ^ tree[rc].sum;
}
void build(int t, int l, int r)
{
    tree[t].tag = 0;
    tree[t].l = l;
    tree[t].r = r;
    if (l == r)
    {
        tree[t].sum = a[rk[l]];
        return;
    }
    int mid = (l + r) / 2;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    update(t);
}
void seg_add(int t, int val)
{
    if ((tree[t].r - tree[t].l + 1) % 2 == 1)
    {
        tree[t].sum ^= val;
    }
    tree[t].tag ^= val;
}
void push_down(int t)
{
    if (tree[t].tag == 0)
        return;
    seg_add(lc, tree[t].tag);
    seg_add(rc, tree[t].tag);
    tree[t].tag = 0;
}
void add(int t)
{
    if (ql <= tree[t].l && tree[t].r <= ql)
    {
        tree[t].sum = qk;
        return;
    }
    push_down(t);
    int mid = (tree[t].l + tree[t].r) >> 1;
    if (ql <= mid)
        add(lc);
    else
        add(rc);
    update(t);
}
void query(int t)
{
    if (ql <= tree[t].l && tree[t].r <= qr)
    {
        ans_val ^= tree[t].sum;
        return;
    }
    push_down(t);
    int mid = (tree[t].l + tree[t].r) >> 1;
    if (ql <= mid)
        query(lc);
    if (qr > mid)
        query(rc);
}
int query_path(int x)
{
    int root = 1;
    int res = 0;
    while (top[x] != top[root])
    {
        int y = top[x];
        ql = dfu[y];
        qr = dfu[x];
        ans_val = 0;
        query(1);
        res ^= ans_val;
        x = f[y];
    }
    ql = dfu[root];
    qr = dfu[x];
    ans_val = 0;
    query(1);
    res ^= ans_val;
    return res;
}
int lca(int x, int y)
{
    while (top[x] != top[y])
    {
        if (dfu[top[x]] < dfu[top[y]])
            swap(x, y);
        x = f[top[x]];
    }
    return dfu[x] < dfu[y] ? x : y;
}
int solve(int x, int y)
{
    int l = lca(x, y);
    int res = query_path(x) ^ query_path(y) ^ a[l];
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    top[1] = 1;
    dfs2(1, 0);
    build(1, 1, n);
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, val;
            cin >> x >> val;
            ql = dfu[x];
            qk = val;
            add(1);
            a[x] = val;
        }
        else
        {
            int x, y;
            cin >> x >> y;
            int ans = solve(x, y);
            cout << ans << '\n';
        }
    }
    return 0;
}