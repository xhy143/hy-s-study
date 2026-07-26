#include <bits/stdc++.h>
using namespace std;
#define lc ((t) << 1)
#define rc (((t) << 1) + 1)
const int maxn = 1e5 + 10;
struct line
{
    int x, y1, y2, type;
    bool operator<(const line &b) const
    {
        return x < b.x;
    }
};
struct node
{
    int l, r, cnt, len;
} tree[maxn * 8];
int n, ys[maxn * 2], ql, qr, qk;
vector<line> events;
void update(int t)
{
    int l = tree[t].l, r = tree[t].r;
    if (tree[t].cnt > 0)
        tree[t].len = ys[r + 1] - ys[l];
    else if (l == r)
        tree[t].len = 0;
    else
        tree[t].len = tree[lc].len + tree[rc].len;
}
void build(int t, int l, int r)
{
    tree[t].l = l;
    tree[t].r = r;
    tree[t].len = tree[t].cnt = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
}
void modify(int t)
{
    if (ql <= tree[t].l && qr >= tree[t].r)
    {
        tree[t].cnt += qk;
        update(t);
        return;
    }
    int mid = (tree[t].l + tree[t].r) >> 1;
    if (ql <= mid)
        modify(lc);
    if (qr > mid)
        modify(rc);
    update(t);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x1, x2, y2, y1;
        cin >> x1 >> y1 >> x2 >> y2;
        events.push_back({x1, y1, y2, 1});
        events.push_back({x2, y1, y2, -1});
        ys[i * 2 - 1] = y2;
        ys[i * 2 - 2] = y1;
    }
    int m = n * 2;
    sort(ys, ys + m);
    m = unique(ys, ys + m) - ys;
    for (auto &e : events)
    {
        e.y1 = lower_bound(ys, ys + m, e.y1) - ys;
        e.y2 = lower_bound(ys, ys + m, e.y2) - ys - 1;
    }
    build(1, 0, m - 1);
    long long ans = 0;
    sort(events.begin(), events.end());
    for (int i = 0; i + 1 < events.size(); i++)
    {
        ql = events[i].y1;
        qr = events[i].y2;
        qk = events[i].type;
        modify(1);
        int dx = events[i + 1].x - events[i].x;
        ans += 1LL * dx * tree[1].len;
    }
    cout << ans << endl;
}