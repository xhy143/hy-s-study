#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define lc ((t) << 1)
#define rc (((t) << 1) | 1)
using namespace std;
const int maxn = 1e5 + 10;
int Q, M;
int mul_val[maxn]; 
bool is_mul[maxn]; 

struct node
{
    int l, r;
    int sum;  
} tree[maxn * 4];
void up(int t)
{
    tree[t].sum = (tree[lc].sum * tree[rc].sum) % M;
}
void build(int t, int l, int r)
{
    tree[t].l = l;
    tree[t].r = r;
    if (l == r)
    {
        if (is_mul[l])
            tree[t].sum = mul_val[l] % M;
        else
            tree[t].sum = 1;
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
        tree[t].sum = val % M;
        return;
    }
    int mid = (tree[t].l + tree[t].r) >> 1;
    if (pos <= mid)
        update(lc, pos, val);
    else
        update(rc, pos, val);
    up(t);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> Q >> M;
        for (int i = 1; i <= Q; i++)
        {
            is_mul[i] = false;
            mul_val[i] = 0;
        }
        vector<pair<int, int>> ops(Q + 1);
        for (int i = 1; i <= Q; i++)
        {
            int op, val;
            cin >> op >> val;
            ops[i] = {op, val};
            if (op == 1)
            {
                is_mul[i] = true;
                mul_val[i] = val;
            }
        }
        build(1, 1, Q);
        for (int i = 1; i <= Q; i++)
        {
            int op = ops[i].first;
            int val = ops[i].second;
            if (op == 1)
            {
                cout << tree[1].sum % M << endl;
            }
            else
            {
                int pos = val;
                update(1, pos, 1);
                cout << tree[1].sum % M << endl;
            }
        }
    }
    return 0;
}