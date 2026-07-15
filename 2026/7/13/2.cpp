#include <bits/stdc++.h>
#define int long long
#define lc ((t) << 1)
#define rc (((t) << 1) + 1)
#define endl '\n'
#define addtag tag
using namespace std;
const int maxn = 1e6 + 10;
struct node
{
    int l, r;
    int sum, tag, multag;
} tree[maxn * 4];
int n, m, ql, qr, qk, ans, a[maxn], mod;
void up(int t)
{
    tree[t].sum = (tree[lc].sum + tree[rc].sum) % mod;
}
void seg_add(int t, int tag)
{
    tree[t].sum = (tree[t].sum + tag * (tree[t].r - tree[t].l + 1)) % mod;
    tree[t].tag = (tree[t].tag + tag) % mod;
}
void seg_mul(int t, int multag)
{
    tree[t].sum = tree[t].sum * multag % mod;
    tree[t].tag = tree[t].tag * multag % mod;
    tree[t].multag = tree[t].multag * multag % mod;
}
void down(int t)
{
    if (tree[t].multag != 1)
    {
        seg_mul(lc, tree[t].multag);
        seg_mul(rc, tree[t].multag);
        tree[t].multag = 1;
    }
    if (tree[t].tag)
    {
        seg_add(lc, tree[t].tag);
        seg_add(rc, tree[t].tag);
        tree[t].tag = 0;
    }
}
void build(int t, int l, int r)
{
    tree[t].l = l, tree[t].r = r, tree[t].multag = 1;
    if (l == r)
    {
        tree[t].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    up(t);
}
void ask(int t)
{
    if (ql <= tree[t].l && tree[t].r <= qr)
    {
        (ans += tree[t].sum) %= mod;
        return;
    }
    down(t);
    int mid = (tree[t].l + tree[t].r) >> 1;
    if (ql <= mid)
        ask(lc);
    if (qr > mid)
        ask(rc);
    return;
}
void add(int t)
{
    if (ql <= tree[t].l && tree[t].r <= qr)
    {
        seg_add(t, qk);
        return;
    }
    down(t);
    int mid = (tree[t].l + tree[t].r) >> 1;
    if (ql <= mid)
        add(lc);
    if (qr > mid)
        add(rc);
    up(t);
}
void mul(int t)
{
    if (ql <= tree[t].l && tree[t].r <= qr)
    {
        seg_mul(t, qk);
        return;
    }
    down(t);
    int mid = (tree[t].l + tree[t].r) >> 1;
    if (ql <= mid)
        mul(lc);
    if (qr > mid)
        mul(rc);
    up(t);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> mod;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int pos;
        cin >> pos;
        if (pos == 2)
        {
            cin >> ql >> qr >> qk;
            add(1);
        }
        else if (pos == 3)
        {
            cin >> ql >> qr;
            ans = 0;
            ask(1);
            cout << ans << endl;
        }
        else
        {
            cin >> ql >> qr >> qk;
            mul(1);
        }
    }
}