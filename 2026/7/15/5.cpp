#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;

struct Node
{
    int cover;
    int zero;
} tree[MAXN * 4];

struct Ticket
{
    int s, t;
};
int N, K;
Ticket cp[MAXN];
int cps = 0;
void build(int t, int l, int r)
{
    tree[t].cover = 0;
    tree[t].zero = r - l + 1;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(t << 1, l, mid);
    build(t << 1 | 1, mid + 1, r);
}
void pushUp(int t, int l, int r)
{
    if (tree[t].cover > 0)
    {
        tree[t].zero = 0;
    }
    else if (l == r)
    {
        tree[t].zero = 1;
    }
    else
    {
        tree[t].zero = tree[t << 1].zero + tree[t << 1 | 1].zero;
    }
}
void update(int t, int l, int r, int ql, int qr, int val)
{
    if (ql <= l && r <= qr)
    {
        tree[t].cover += val;
        pushUp(t, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid)
        update(t << 1, l, mid, ql, qr, val);
    if (qr > mid)
        update((t << 1) + 1, mid + 1, r, ql, qr, val);
    pushUp(t, l, r);
}
int query(int t, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return tree[t].zero;
    }
    if (tree[t].cover > 0)
    {
        return 0;
    }
    int mid = (l + r) >> 1;
    int res = 0;
    if (ql <= mid)
        res += query(t << 1, l, mid, ql, qr);
    if (qr > mid)
        res += query(t << 1 | 1, mid + 1, r, ql, qr);
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    build(1, 1, N);
    for (int i = 0; i < K; i++)
    {
        char op;
        cin >> op;
        if (op == 'B')
        {
            int s, t;
            cin >> s >> t;
            cp[++cps] = {s, t};
            if (s < t)
            {
                update(1, 1, N, s + 1, t, 1);
            }
        }
        else if (op == 'R')
        {
            int idx;
            cin >> idx;
            int s = cp[idx].s;
            int t = cp[idx].t;
            if (s < t)
            {
                update(1, 1, N, s + 1, t, -1);
            }
        }
        else if (op == 'Q')
        {
            int s, t;
            cin >> s >> t;
            if (s >= t)
            {
                cout << 0 << endl;
            }
            else
            {
                int ans = query(1, 1, N, s + 1, t);
                cout << ans << endl;
            }
        }
    }
    return 0;
}