#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int pos, lo;
    bool operator<(const node &oth) const
    {
        return lo < oth.lo;
    }
};
node lowest[105];
int n, m, k;
signed main()
{
    //freopen("array.in", "r", stdin);
    //freopen("array.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= 104; i++)
    {
        lowest[i].lo = INT_MAX;
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int p;
            cin >> p;
            lowest[j].lo = min(lowest[j].lo, p);
            lowest[j].pos = j;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans += lowest[i].lo;
    }
    if (ans < k)
    {
        cout << -1 << endl;
        return 0;
    }
    int cnt[1001], pre = 0;
    sort(lowest + 1, lowest + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (pre + lowest[i].lo < k)
        {
            cnt[lowest[i].pos] = lowest[i].lo;
            pre += lowest[i].lo;
        }
        else if (pre < k)
        {
            cnt[lowest[i].pos] = k - pre;
            pre = k;
        }
        else
        {
            cnt[lowest[i].pos] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << cnt[i] << ' ';
}