#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define lc ((t << 1))
#define rc (((t) << 1) | 1)
using namespace std;
const int maxn = 1e6 + 10;
struct info
{
    int sum, sum2, sum3;
};
struct node
{
    int l, r;
    info s;
} tree[maxn * 4];
int a[maxn], n, m, ql, qr, qk, k;
info ans;
info operator+(const info &a, const info &b)
{
    info t;
    t.sum = a.sum + b.sum;
    t.sum2 = a.sum2 + b.sum2;
    t.sum3 = a.sum3 + b.sum3;
    return t;
}
void up(int t) { tree[t].s = tree[lc].s + tree[rc].s; }
void build(int t, int l, int r)
{
    tree[t].l = l;
    tree[t].r = r;
    if (l == r)
    {
        tree[t].s.sum = a[l];
        tree[t].s.sum2 = tree[t].s.sum * a[l];
        tree[t].s.sum3 = tree[t].s.sum2 * a[l];
        return;
    };
    int mid = (tree[t].l + tree[t].r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    up(t);
}
void add(int t)
{
    if (tree[t].l == tree[t].r)
    {
        tree[t].s.sum += qk;
        tree[t].s.sum2 = tree[t].s.sum * tree[t].s.sum;
        tree[t].s.sum3 = tree[t].s.sum2 * tree[t].s.sum;
        return;
    }
    int mid = (tree[t].l + tree[t].r) >> 1;
    if (ql <= mid)
        add(lc);
    else
        add(rc);
    up(t);
}
void ask(int t)
{
    if (ql <= tree[t].l && tree[t].r <= qr)
    {
        ans = ans + tree[t].s;
        return;
    }
    int mid = (tree[t].l + tree[t].r) >> 1;
    if (ql <= mid)
        ask(lc);
    if (qr > mid)
        ask(rc);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int pos;
        cin >> pos;
        if (pos == 1)
        {
            cin >> ql >> qk;
            add(1);
        }
        else
        {
            cin >> ql >> qr >> k;
            ans = {0, 0, 0};
            ask(1);
            int res = 1ll * (qr - ql + 1) * k * k * k;
            res += ans.sum * k * k * 3 + ans.sum2 * k * 3 + ans.sum3;
            
            cout << res << endl;
        }
    }
    return 0;
}//100多行我日了