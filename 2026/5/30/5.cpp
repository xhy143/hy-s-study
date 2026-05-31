#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
ll phi(ll x)
{
    ll res = x;
    for (ll p = 2; p * p <= x; p++)
    {
        if (x % p == 0)
        {
            res = res / p * (p - 1);
            while (x % p == 0)
                x /= p;
        }
    }
    if (x > 1)
        res = res / x * (x - 1);
    return res;
}
ll ans = 0;
ll n;
void dfs(ll d, int idx, const vector<pair<ll, int>> &factors)
{
    if (idx == factors.size())
    {
        ans += (n / d) * phi(d);
        return;
    }
    ll p = factors[idx].first;
    int cnt = factors[idx].second;

    ll pow_p = 1;
    for (int e = 0; e <= cnt; e++)
    {
        dfs(d * pow_p, idx + 1, factors);
        pow_p *= p;
    }
}
int main()
{
    cin >> n;
    vector<pair<ll, int>> factors;
    ll temp = n;
    for (ll p = 2; p * p <= temp; p++)
    {
        if (temp % p == 0)
        {
            int cnt = 0;
            while (temp % p == 0)
            {
                temp /= p;
                cnt++;
            }
            factors.push_back({p, cnt});
        }
    }
    if (temp > 1)
    {
        factors.push_back({temp,1});
    }
    ans = 0;
    dfs(1, 0, factors);
    cout << ans << endl;
    return 0;
}