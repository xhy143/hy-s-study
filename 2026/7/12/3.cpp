#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define lc ((t) << 1)
#define rc (((t) << 1) | 1)
using namespace std;
const int maxn = 5e5 + 10;
struct info
{
    int sum; 
    int lmax;  
    int rmax; 
    int tmax;   
};
struct node
{
    int l, r;
    info s;
} tree[maxn * 4];
int a[maxn], n, m;
info operator+(const info &a, const info &b)
{
    info t;
    t.sum = a.sum + b.sum;
    t.lmax = max(a.lmax, a.sum + b.lmax);
    t.rmax = max(b.rmax, b.sum + a.rmax);
    t.tmax = max(max(a.tmax, b.tmax), a.rmax + b.lmax);
    return t;
}
void up(int t)
{
    tree[t].s = tree[lc].s + tree[rc].s;
}
void build(int t, int l, int r)
{
    tree[t].l = l;
    tree[t].r = r;
    if (l == r)
    {
        tree[t].s.sum = a[l];
        tree[t].s.lmax = a[l];
        tree[t].s.rmax = a[l];
        tree[t].s.tmax = a[l];
        return;
    }
    int mid = (tree[t].l + tree[t].r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    up(t);
}
void update(int t, int pos, int val)
{
    if (tree[t].l == tree[t].r)
    {
        tree[t].s.sum = val;
        tree[t].s.lmax = val;
        tree[t].s.rmax = val;
        tree[t].s.tmax = val;
        return;
    }
    int mid = (tree[t].l + tree[t].r) >> 1;
    if (pos <= mid)
        update(lc, pos, val);
    else
        update(rc, pos, val);
    up(t);
}
info query(int t, int ql, int qr)
{
    if (ql <= tree[t].l && tree[t].r <= qr)
    {
        return tree[t].s;
    }
    int mid = (tree[t].l + tree[t].r) >> 1;
    if (qr <= mid)
        return query(lc, ql, qr);
    else if (ql > mid)
        return query(rc, ql, qr);
    else
    {
        info left = query(lc, ql, mid);
        info right = query(rc, mid + 1, qr);
        return left + right;
    }
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
        int k, x, y;
        cin >> k >> x >> y;
        
        if (k == 1)
        {
            if (x > y)
                swap(x, y);
            info ans = query(1, x, y);
            cout << ans.tmax << endl;
        }
        else
        {
            update(1, x, y);
        }
    }
    
    return 0;
}//666                                