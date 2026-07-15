#include <bits/stdc++.h>
#define int long long
#define lc ((t) << 1)
#define rc (((t) << 1) + 1)
#define endl '\n'
using namespace std;
const int maxn = 1e5 + 10;
struct info
{
    int len;
    int cnt[2], lx[2], rx[2], mx[2];

    info()
    {
        len = 0;
        for (int i = 0; i < 2; i++)
        {
            cnt[i] = lx[i] = rx[i] = mx[i] = 0;
        }
    }

    info operator+(const info &oth) const
    {
        info c;
        c.len = len + oth.len;
        for (int i = 0; i <= 1; i++)
        {
            c.cnt[i] = cnt[i] + oth.cnt[i];
            c.lx[i] = (lx[i] == len) ? len + oth.lx[i] : lx[i];
            c.rx[i] = (oth.rx[i] == oth.len) ? oth.len + rx[i] : oth.rx[i];
            c.mx[i] = max(max(mx[i], oth.mx[i]),rx[i] + oth.lx[i]);
        }
        return c;
    }
};
struct node
{
    int l, r;
    int settag;
    int revtag;
    info s;
} tree[maxn * 4];

int n, m, a[maxn], ql, qr, qk;
info ans;
void up(int t)
{
    tree[t].s = tree[lc].s + tree[rc].s;
}
void seg_set(int t, int val)
{
    tree[t].s.cnt[val] = tree[t].s.lx[val] = tree[t].s.rx[val] = tree[t].s.mx[val] = tree[t].s.len;
    val ^= 1;
    tree[t].s.cnt[val] = tree[t].s.lx[val] = tree[t].s.rx[val] = tree[t].s.mx[val] = 0;
    val ^= 1;
    tree[t].settag = val;
    tree[t].revtag = 0;
}
void seg_rev(int t)
{
    swap(tree[t].s.cnt[0], tree[t].s.cnt[1]);
    swap(tree[t].s.lx[0], tree[t].s.lx[1]);
    swap(tree[t].s.rx[0], tree[t].s.rx[1]);
    swap(tree[t].s.mx[0], tree[t].s.mx[1]);
    if (tree[t].settag != -1)
    {
        tree[t].settag ^= 1;
    }
    else
    {
        tree[t].revtag ^= 1;
    }
}
void down(int t)
{
    if (tree[t].settag != -1)
    {
        seg_set(lc, tree[t].settag);
        seg_set(rc, tree[t].settag);
        tree[t].settag = -1;
    }
    if (tree[t].revtag)
    {
        seg_rev(lc);
        seg_rev(rc);
        tree[t].revtag = 0;
    }
}
void build(int t, int l, int r)
{
    tree[t].l = l;
    tree[t].r = r;
    tree[t].settag = -1;
    tree[t].revtag = 0;
    tree[t].s.len = r - l + 1;

    if (l == r)
    {
        int val = a[l];
        tree[t].s.cnt[val] = tree[t].s.lx[val] = tree[t].s.rx[val] = tree[t].s.mx[val] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    up(t);
}
void setv(int t)
{
    if (ql <= tree[t].l && tree[t].r <= qr)
    {
        seg_set(t, qk);
        return;
    }
    down(t);
    int mid = (tree[t].l + tree[t].r) >> 1;
    if (ql <= mid)
        setv(lc);
    if (qr > mid)
        setv(rc);
    up(t);
}
void rev(int t)
{
    if (ql <= tree[t].l && tree[t].r <= qr)
    {
        seg_rev(t);
        return;
    }
    down(t);
    int mid = (tree[t].l + tree[t].r) >> 1;
    if (ql <= mid)
        rev(lc);
    if (qr > mid)
        rev(rc);
    up(t);
}
void ask(int t)
{
    if (ql <= tree[t].l && tree[t].r <= qr)
    {
        ans = ans + tree[t].s;
        return;
    }
    down(t);
    int mid = (tree[t].l + tree[t].r) >> 1;
    if (ql <= mid)
        ask(lc);
    if (qr > mid)
        ask(rc);
}
void clear_ans()
{
    ans.len = 0;
    for (int i = 0; i <= 1; i++)
    {
        ans.cnt[i] = 0;
        ans.lx[i] = 0;
        ans.rx[i] = 0;
        ans.mx[i] = 0;
    }
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
    for (int i = 1; i <= m; i++)
    {
        int pos;
        cin >> pos >> ql >> qr;
        ql++;
        qr++;
        if (pos == 0)
        {
            qk = 0;
            setv(1);
        }
        else if (pos == 1)
        {
            qk = 1;
            setv(1);
        }
        else if (pos == 2)
        {
            rev(1);
        }
        else if (pos == 3)
        {
            clear_ans();
            ask(1);
            cout << ans.cnt[1] << endl;
        }
        else if (pos == 4)
        {
            clear_ans();
            ask(1);
            cout << ans.mx[1] << endl;
        }
    }
    return 0;
}