#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int z[maxn], cnt[maxn], ok[maxn];
string str;
int n, ans;
int main()
{
    int tcase;
    cin >> tcase;
    while (tcase--)
    {
        cin >> str;
        n = str.size();
        ans = z[0] = 0;
        int l = 0, r = 0;
        for (int i = 1; i < n; i++)
        {
            z[i] = 0;
            if (i <= r)
                z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && str[i + z[i]] == str[z[i]])
            {
                z[i]++;
            }
            if (i + z[i] - 1 > r)
            {
                l = i;
                r = i + z[i] - 1;
            }
        }
        for (int i = 0; i <= n; i++)
            ok[i] = cnt[i] = 0;
        for (int i = n - 1; i > 0; i--)
        {
            int k = n - i;
            if (z[i] == k)
            {
                ok[z[i]] = 1;
                cnt[z[i]]++;
            }
            else if (z[i])
                cnt[z[i]]++;
        }
        ok[n] = 1;
        cnt[n] = 1;
        for (int i = n - 1; i >= 1; i--)
            cnt[i] += cnt[i + 1];
        for (int i = 1; i <= n; i++)
            if (ok[i])
                cout << i << ' ' << cnt[i] << endl;
    }
    return 0;
}