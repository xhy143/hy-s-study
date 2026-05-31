#include <bits/stdc++.h>
using namespace std;
const int maxn = 3.2e7 + 10;
bool fpri[maxn];
vector<int> primes;
void ispr()
{
    fpri[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!fpri[i])
        {
            primes.push_back(i);
        }
        for (int p : primes)
        {
            if (1ll * i * p >= maxn)
                break;
            fpri[i * p] = true;
            if (i % p == 0)
                break;
        }
    }
}
bool is_prime(long long n)
{
    if (n < maxn)
    {
        return !fpri[n];
    }
    else
    {
        for (int i : primes)
        {
            if (1ll * i * i > n)
                break;
            if (n % i == 0)
                return false;
        }
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int T;
    ispr();
    cin >> T;
    while (T--)
    {
        long long n;
        cin >> n;
        cout << (is_prime(n) ? "YES" : "NO") << endl;
    }
}