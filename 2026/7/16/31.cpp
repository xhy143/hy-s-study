#include <bits/stdc++.h>
using namespace std;
#define lc ((t) << 1)
#define rc (((t) << 1) + 1)
const int maxn = 1e5 + 10;
struct line
{
    int x, y1, y2, val;
    bool operator<(const line &b) const
    {
        if(x!=b.x)return x < b.x;
        return val>b.val;
    }
};
struct node
{
    int l, r, cnt, len;
    int mark,maxval;
} tree[maxn * 8];
int n, ys[maxn * 2], ql, qr, qk;
vector<line> events;
void update(int t)
{
    tree[t].maxval=max(tree[lc].maxval,tree[rc].maxval);
}
void seg_add(int t,int tag){
    tree[t].mark+=tag;
    tree[t].maxval+=tag;
}
void pushdown(int t){
    if(tree[t].mark!=0){
        seg_add(lc,tree[t].mark);
        seg_add(rc,tree[t].mark);
        tree[t].mark=0;
    }
}
void build(int t, int l, int r)
{
    tree[t].l = l;
    tree[t].r = r;
    tree[t].mark = tree[t].maxval = 0;
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
        seg_add(t,qk);
        return;
    }
    pushdown(t);
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
        int x1, x2, y2, y1,val;
        cin >> x1 >> y1 >> x2 >> y2>>val;
        events.push_back({x1, y1, y2, val});
        events.push_back({x2, y1, y2, -val});
        ys[i * 2 - 1] = y2;
        ys[i * 2 - 2] = y1;
    }
    int m = n * 2;
    sort(ys, ys + m);
    m = unique(ys, ys + m) - ys;
    for (auto &e : events)
    {
        e.y1 = lower_bound(ys, ys + m, e.y1) - ys;
        e.y2 = lower_bound(ys, ys + m, e.y2) - ys;
    }
    build(1, 0, m - 1);
    long long ans = 0;
    sort(events.begin(), events.end());
    for (int i = 0; i + 1 < events.size(); i++)
    {
        ql = events[i].y1;
        qr = events[i].y2;
        qk = events[i].val;
        modify(1);
        ans=max(ans,1LL*tree[1].maxval);
    }
    cout << ans << endl;
}