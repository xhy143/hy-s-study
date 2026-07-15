#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e6 + 10;
const int INF = 1e18;
struct Node
{
    int l, r;
    int mx, mn;
    int fz;
    int rev;
} tree[MAXN * 4];
int n, m;
int a[MAXN];
void up(int t)
{
    tree[t].mx = max(tree[t << 1].mx, tree[(t << 1) + 1].mx);
    tree[t].mn = min(tree[t << 1].mn, tree[(t << 1) + 1].mn);
}
void nownode(int t, int val)
{
    tree[t].mx = val;
    tree[t].mn = val;
    tree[t].fz = val;
    tree[t].rev = 0;
}
void qf(int t)
{
    int tempMx = tree[t].mx;
    int tempMn = tree[t].mn;
    tree[t].mx = -tempMn;
    tree[t].mn = -tempMx;
    if (tree[t].fz != -INF)
    {
        tree[t].fz = -tree[t].fz;
    }
    else
    {
        tree[t].rev ^= 1;
    }
}
void down(int t)
{
    if (tree[t].fz != -INF)
    {
        nownode(t << 1, tree[t].fz);
        nownode((t << 1) + 1, tree[t].fz);
        tree[t].fz = -INF;
    }
    if (tree[t].rev)
    {
        qf(t << 1);
        qf((t << 1) + 1);
        tree[t].rev = 0;
    }
}
void build(int t, int l, int r)
{
    tree[t].l = l;
    tree[t].r = r;
    tree[t].fz = -INF;
    tree[t].rev = 0;
    if (l == r)
    {
        tree[t].mx = tree[t].mn = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(t << 1, l, mid);
    build(t << 1 | 1, mid + 1, r);
    up(t);
}
void update(int t, int l, int r, int ql, int qr, int val)
{
    if (ql <= l && r <= qr)
    {
        nownode(t, val);
        return;
    }
    down(t);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        update(t << 1, l, mid, ql, qr, val);
    if (qr > mid)
        update(t << 1 | 1, mid + 1, r, ql, qr, val);
    up(t);
}
void updateqf(int t, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        qf(t);
        return;
    }
    down(t);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        updateqf(t << 1, l, mid, ql, qr);
    if (qr > mid)
        updateqf(t << 1 | 1, mid + 1, r, ql, qr);
    up(t);
}
int query(int t, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return tree[t].mx;
    }
    down(t);
    int mid = (l + r) >> 1;
    int res = -INF;
    if (ql <= mid)
        res = max(res, query(t << 1, l, mid, ql, qr));
    if (qr > mid)
        res = max(res, query((t << 1) + 1, mid + 1, r, ql, qr));
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 0; i < m; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        }
        else if (op == 2)
        {
            int l, r;
            cin >> l >> r;
            updateqf(1, 1, n, l, r);
        }
        else if (op == 3)
        {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
    return 0;
}