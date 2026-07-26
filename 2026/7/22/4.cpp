#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define lc ((t) << 1)
#define rc (((t) << 1) + 1)
#define int long long
const int maxn = 2e5 + 100;
struct node
{
    int u, v, c;
} edge[maxn];
struct treenode
{
    int l, r, lp, rp, ans, mx, mn, tag;
} tree[maxn * 4];
vector<pair<int, int>> g[maxn];
int n, q, ql, qr, in[maxn], out[maxn], dfn[maxn], clk, dep[maxn], qk, w;
void dfs(int u, int fa, int len)
{
    dfn[++clk] = u;
    dep[clk] = len;
    in[u] = clk;
    for (auto &p : g[u])
    {
        int v = p.fi, id = p.se;
        if (v == fa)
            continue;
        if (edge[id].u != u)
        {
            swap(edge[id].u, edge[id].v);
        }
        dfs(v, u, len + edge[id].c);
        dfn[++clk] = u;
        dep[clk] = len;
    }
    out[u] = clk;
}
void update(int t)
{
    tree[t].mx = max(tree[lc].mx, tree[rc].mx);
    tree[t].mn = min(tree[lc].mn, tree[rc].mn);
    tree[t].lp = max(max(tree[lc].lp, tree[rc].lp), tree[lc].mx - tree[rc].mn * 2);
    tree[t].rp = max(max(tree[lc].rp, tree[rc].rp), tree[rc].mx - tree[lc].mn * 2);
    tree[t].ans = max(max(tree[lc].ans, tree[rc].ans), max(tree[lc].mx + tree[rc].rp, tree[rc].mx + tree[lc].lp));
}
void seg_add(int t, int tag)
{
    tree[t].tag += tag;
    tree[t].mx += tag;
    tree[t].mn += tag;
    tree[t].lp -= tag;
    tree[t].rp -= tag;
}
void pushdown(int t)
{
    if (tree[t].tag != 0)
    {
        seg_add(lc, tree[t].tag);
        seg_add(rc, tree[t].tag);
        tree[t].tag = 0;
    }
}
void build(int t, int l, int r)
{
    tree[t].l = l;
    tree[t].r = r;
    if (l == r)
    {
        tree[t].mn = tree[t].mx = dep[l];
        tree[t].lp = tree[t].rp = -dep[l];
        tree[t].ans = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    update(t);
}
void modify(int t)
{
    if (ql <= tree[t].l && tree[t].r <= qr)
    {
        seg_add(t, qk);
        return;
    }
    int mid = (tree[t].l + tree[t].r) >> 1;
    pushdown(t);
    if (ql <= mid)
        modify(lc);
    if (qr > mid)
        modify(rc);
    update(t);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q >> w;
    for (int i = 1; i <= n-1; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edge[i] = {u, v, c};
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    dfs(1, 0, 0);
    build(1, 1, clk);
    int last = 0;
    while (q--)
    {
        int d, v, e;
        cin >> d >> e;
        d = (last + d) % (n - 1);
        d++;
        e = (last + e) % w;
        v = edge[d].v;
        qk = e - edge[d].c;
        edge[d].c = e;
        ql = in[v];
        qr = out[v];
        modify(1);
        cout << tree[1].ans << '\n';
        last = tree[1].ans;
    }
    return 0;
}