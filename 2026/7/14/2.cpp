#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node
{
    int lc, rc, val, prio, size;
    bool rev;
} tree[N];
int tot = 0, root = 0, n, m;
int nownode(int val)
{
    tree[++tot].val = val;
    tree[tot].size = 1;
    tree[tot].lc = tree[tot].rc = 0;
    tree[tot].prio = rand();
    tree[tot].rev = false;
    return tot;
}
void update(int u)
{
    tree[u].size = tree[tree[u].lc].size + tree[tree[u].rc].size + 1;
}
void pushdown(int u)
{
    if (!u || !tree[u].rev)
        return;
    swap(tree[u].lc, tree[u].rc);
    if (tree[u].lc)
        tree[tree[u].lc].rev ^= 1;
    if (tree[u].rc)
        tree[tree[u].rc].rev ^= 1;
    tree[u].rev = false;
}
void split(int u, int k, int &leftTree, int &rightTree)
{
    if (u == 0)
    {
        leftTree = rightTree = 0;
        return;
    }
    pushdown(u);
    int leftSize = tree[tree[u].lc].size;

    if (k <= leftSize)
    {
        rightTree = u;
        split(tree[u].lc, k, leftTree, tree[u].lc);
        update(u);
    }
    else
    {
        leftTree = u;
        split(tree[u].rc, k - leftSize - 1, tree[u].rc, rightTree);
        update(u);
    }
}
int merge(int leftTree, int rightTree)
{
    if (!leftTree || !rightTree)
    {
        return leftTree + rightTree;
    }

    if (tree[leftTree].prio < tree[rightTree].prio)
    {
        pushdown(leftTree);
        tree[leftTree].rc = merge(tree[leftTree].rc, rightTree);
        update(leftTree);
        return leftTree;
    }
    else
    {
        pushdown(rightTree);
        tree[rightTree].lc = merge(leftTree, tree[rightTree].lc);
        update(rightTree);
        return rightTree;
    }
}
void reverse_range(int l, int r)
{
    int left, mid, right;
    split(root, l - 1, left, mid);
    split(mid, r - l + 1, mid, right);
    tree[mid].rev ^= 1;
    root = merge(merge(left, mid), right);
}
void inorder(int u)
{
    if (!u)
        return;

    pushdown(u);

    inorder(tree[u].lc);
    cout << tree[u].val << " ";
    inorder(tree[u].rc);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        root = merge(root, nownode(i));
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        reverse_range(l, r);
    }
    inorder(root);
    cout << endl;
    return 0;
}