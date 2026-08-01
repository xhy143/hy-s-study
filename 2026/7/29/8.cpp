#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
using ll = long long;
int n, m;
int a[maxn], b[maxn];
ll suma[maxn], sumb[maxn], ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= n; i++)
        suma[i] = suma[i - 1] + a[i];
    for (int i = 1; i <= m; i++)
        sumb[i] = sumb[i - 1] + b[i];
    ans = LLONG_MAX;
    for (int i = 1; i <= n; i++)
    {
        ll res = 0;
        res += 1ll * (i - 1) * a[i] - suma[i - 1];

        int pos = upper_bound(b + 1, b + m + 1, a[i]) - b;
        if (pos <= m)
        {
            res += (sumb[m] - sumb[pos - 1]) - 1ll * (m - pos + 1) * a[i];
        }
        ans = min(ans, res);
    }
    for (int i = 1; i <= m; i++)
    {
        ll res = 0;
        res += (sumb[m] - sumb[i]) - 1ll * (m - i) * b[i];
        int pos = lower_bound(a + 1, a + n + 1, b[i]) - a;
        pos--;
        if (pos >= 1)
        {
            res += 1ll * pos * b[i] - suma[pos];
        }
        ans = min(ans, res);
    }
    cout << ans << '\n';
    return 0;
}