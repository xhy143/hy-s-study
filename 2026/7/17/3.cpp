#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
struct node
{
    int son[26], fail, cnt, last;
} tree[maxn];
int tot;
void init()
{
    tot = 0;
    memset(tree[0].son, 0, sizeof(tree[0].son));
    tree[0].fail = tree[0].last = tree[0].cnt = 0;
}
int newnode()
{
    ++tot;
    memset(tree[tot].son, 0, sizeof(tree[tot].son));
    tree[tot].fail = tree[tot].last = tree[tot].cnt = 0;
    return tot;
}
void insert(const string &s)
{
    int u = 0;
    for (char c : s)
    {
        int idx = c - 'a';
        if (!tree[u].son[idx])
            tree[u].son[idx] = newnode();
        u = tree[u].son[idx];
    }
    tree[u].cnt++;
}
void build()
{
    queue<int> que;
    for (int i = 0; i < 26; i++)
    {
        if (tree[0].son[i])
        {
            tree[tree[0].son[i]].fail = 0;
            tree[tree[0].son[i]].last = 0;
            que.push(tree[0].son[i]);
        }
    }
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for (int i = 0; i < 26; i++)
        {
            int &v = tree[u].son[i];
            if (v)
            {
                tree[v].fail = tree[tree[u].fail].son[i];
                int f = tree[v].fail;
                tree[v].last = (tree[f].cnt ? f : tree[f].last);
                que.push(v);
            }
            else
            {
                v = tree[tree[u].fail].son[i];
            }
        }
    }
}
int query(const string &s)
{
    int u=0, ans = 0;
    for (char c : s)
    {
        u = tree[u].son[c - 'a'];
        for (int t = u; t && tree[t].cnt != -1; t = tree[t].last)
        {
            ans += tree[t].cnt;
            tree[t].cnt = -1;
        }
    }
    return ans;
}
int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        init();
        string str, s;
        for (int i = 0; i < n; i++)
        {
            cin >> str;
            insert(str);
        }
        build();
        cin >> s;
        cout << query(s) << endl;
    }
    return 0;
}