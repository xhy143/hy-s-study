#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node
{
    int lc, rc, val, prio, size;
} tree[N];
int tot = 0, root = 0, n;
vector<int> order; 

int nownode(int val)
{
    tree[++tot].val = val;
    tree[tot].size = 1;
    tree[tot].lc = tree[tot].rc = 0;
    tree[tot].prio = rand();
    return tot;
}
void update(int u)
{
    tree[u].size = tree[tree[u].lc].size + tree[tree[u].rc].size + 1;
}
void split(int u, int key, int &leftTree, int &rightTree)
{
    if (u == 0)
    {
        leftTree = rightTree = 0;
        return;
    }
    if (tree[u].val <= key)
    {
        leftTree = u;
        split(tree[u].rc, key, tree[u].rc, rightTree);
        update(u);
    }
    else
    {
        rightTree = u;
        split(tree[u].lc, key, leftTree, tree[u].lc);
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
        tree[leftTree].rc = merge(tree[leftTree].rc, rightTree);
        update(leftTree);
        return leftTree;
    }
    else
    {
        tree[rightTree].lc = merge(leftTree, tree[rightTree].lc);
        update(rightTree);
        return rightTree;
    }
}
void push(int x)
{
    order.push_back(x); 
    int leftTree, rightTree;
    split(root, x, leftTree, rightTree);
    root = merge(merge(leftTree, nownode(x)), rightTree);
}
void pop(int x)
{
    int left, mid, right;
    split(root, x, left, right);
    split(left, x - 1, left, mid);
    mid = merge(tree[mid].lc, tree[mid].rc);
    root = merge(merge(left, mid), right);
}
int getrank(int u, int x)
{
    int left, right, lsize;
    split(root, x - 1, left, right);
    lsize = tree[left].size;
    root = merge(left, right);
    return lsize + 1;
}
int getk(int u, int k)
{
    if (u == 0)
        return -1;
    int leftsize = tree[tree[u].lc].size;
    if (k == leftsize + 1)
        return tree[u].val;
    else if (k <= leftsize)
        return getk(tree[u].lc, k);
    else
        return getk(tree[u].rc, k - leftsize - 1);
}
int getprev(int x)
{
    return getk(root, getrank(root, x) - 1);
}
int getnext(int x)
{
    return getk(root, getrank(root, x + 1));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        push(p);
    }
    for (int i = 0; i < m; i++)
    {
        int k, x;
        cin >> k >> x;
        k = getk(root, k);
        k ^= x;
        push(k);
    }
    for (int i = 0; i < order.size(); i++)
    {
        cout << order[i] << " ";
    }
    cout << endl;
    return 0;
}