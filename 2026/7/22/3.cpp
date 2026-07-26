#include <bits/stdc++.h>
using namespace std;
#define lc ((t) << 1)
#define rc (((t) << 1) + 1)
#define int long long
const int maxn = 1e6 + 10;
struct node
{
    long long l, r, sum;
    long long lazy;
} tree[maxn*4];
int n, m, root, clk = 0;
int a[maxn], in[maxn], out[maxn], rk[maxn];
int ql, qr, qk, ans = 0;
vector<int> g[maxn];
void dfs(int u, int fa)
{
    in[u] = ++clk;
    rk[clk] = u;
    for (int v : g[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
    }
    out[u] = clk;
}
void build(int t, int l, int r)
{
    tree[t].l = l;
    tree[t].r = r;
    tree[t].lazy = 0;
    if (l == r)
    {
        tree[t].sum = a[rk[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    tree[t].sum = tree[lc].sum + tree[rc].sum;
}
void pushup(int t)
{
    tree[t].sum = tree[lc].sum + tree[rc].sum;
}
void pushdown(int t)
{
    if (tree[t].lazy)
    {
        int l = tree[t].l, r = tree[t].r;
        int mid = (l + r) >> 1;
        int lz = tree[t].lazy;
        tree[lc].lazy += lz;
        tree[lc].sum += lz * (mid - l + 1);
        tree[rc].lazy += lz;
        tree[rc].sum += lz * (r - mid);
        tree[t].lazy = 0;
    }
}

void modify(int t)
{
    int l = tree[t].l, r = tree[t].r;
    if (ql <= l && r <= qr)
    {
        tree[t].sum += qk * (r - l + 1);
        tree[t].lazy += qk;
        return;
    }
    pushdown(t);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        modify(lc);
    if (qr > mid)
        modify(rc);
    pushup(t);
}
void getsum(int t)
{
    int l = tree[t].l, r = tree[t].r;
    if (ql <= l && r <= qr)
    {
        ans += tree[t].sum;
        return;
    }
    pushdown(t);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        getsum(lc);
    if (qr > mid)
        getsum(rc);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> root;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(root, 0);
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int pos, u, x;
        cin >> pos >> u;
        if (pos == 1)
        {
            cin >> x;
            ql = in[u], qr = out[u];
            qk = x;
            modify(1);
        }
        else
        {
            ans = 0;
            ql = in[u];
            qr = out[u];
            getsum(1);
            cout << ans << '\n';
        }
    }
    return 0;
}