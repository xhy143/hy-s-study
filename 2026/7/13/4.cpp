#include <bits/stdc++.h>
#define int long long
#define lc ((t) << 1)
#define rc (((t) << 1) + 1)
#define endl '\n'
using namespace std;
const int maxn = 50000 + 10;
struct node
{
    int l, r;
    int lmax, rmax, mx;
    int tag;
} tree[maxn * 4];

int n, m;
void up(int t)
{
    int lenL = tree[lc].r - tree[lc].l + 1;
    int lenR = tree[rc].r - tree[rc].l + 1;
    tree[t].lmax = tree[lc].lmax;
    if (tree[lc].lmax == lenL)
        tree[t].lmax += tree[rc].lmax;
    tree[t].rmax = tree[rc].rmax;
    if (tree[rc].rmax == lenR)
        tree[t].rmax += tree[lc].rmax;
    tree[t].mx = max(max(tree[lc].mx, tree[rc].mx), tree[lc].rmax + tree[rc].lmax);
}
void seg_set(int t, int tag)
{
    int len = tree[t].r - tree[t].l + 1;
    tree[t].tag = tag;
    if (tag == 0)
    {
        tree[t].lmax = tree[t].rmax = tree[t].mx = len;
    }
    else
    {
        tree[t].lmax = tree[t].rmax = tree[t].mx = 0;
    }
}
void down(int t)
{
    if (tree[t].tag != -1)
    {
        seg_set(lc, tree[t].tag);
        seg_set(rc, tree[t].tag);
        tree[t].tag = -1;
    }
}
void build(int t, int l, int r)
{
    tree[t].l = l;
    tree[t].r = r;
    tree[t].tag = -1;
    if (l == r)
    {
        tree[t].lmax = tree[t].rmax = tree[t].mx = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    up(t);
}
void update(int t, int ql, int qr, int val)
{
    if (ql <= tree[t].l && tree[t].r <= qr)
    {
        seg_set(t, val);
        return;
    }
    down(t);
    int mid = (tree[t].l + tree[t].r) >> 1;
    if (ql <= mid)
        update(lc, ql, qr, val);
    if (qr > mid)
        update(rc, ql, qr, val);
    up(t);
}
int query(int t, int len)
{
    if (tree[t].l == tree[t].r)
    {
        return tree[t].l;
    }
    down(t);
    int mid = (tree[t].l + tree[t].r) >> 1;
    if (tree[lc].mx >= len)
    {
        return query(lc, len);
    }
    if (tree[lc].rmax + tree[rc].lmax >= len)
    {
        return tree[lc].r - tree[lc].rmax + 1;
    }
    return query(rc, len);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    build(1, 1, n);

    for (int i = 1; i <= m; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x;
            cin >> x;
            if (tree[1].mx < x)
            {
                cout << 0 << endl;
            }
            else
            {
                int pos = query(1, x);
                cout << pos << endl;
                update(1, pos, pos + x - 1, 1);
            }
        }
        else
        {
            int x, y;
            cin >> x >> y;
            update(1, x, x + y - 1, 0);
        }
    }
    return 0;
}