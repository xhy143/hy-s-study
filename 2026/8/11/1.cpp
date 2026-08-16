#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int C[70][70], fact[70];
int dp[30][30][30][3]; // u,l,d,last:0u 1l 2d
void init()
{
    for (int i = 0; i < 70; i++)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }
    fact[0] = 1;
    for (int i = 1; i < 70; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
}
int fpow(int d, int z)
{
    if (z == 0)
        return 1;
    if (z % 2 == 0)
    {
        int p = fpow(d, z / 2) % mod;
        return (p * p % mod + mod) % mod;
    }
    else
    {
        int p = fpow(d, z / 2) % mod;
        return ((p * p) % mod * d + mod) % mod;
    }
}
// C(n,m)=n!/m!(n-m)! a==a*(p-2) (mod p)
int solve(int u, int l, int d)
{
    if (u + l + d == 0)
    {
        return 1;
    }
    dp[1][0][0][0] = u;
    dp[0][1][0][1] = l;
    dp[0][0][1][2] = d;
    for (int i = 0; i <= u; i++)
    {
        for (int j = 0; j <= l; j++)
        {
            for (int k = 0; k <= d; k++)
            {
                if (u + l + k == 0)
                    continue;
                if (i > 0)
                {
                    if (j < l)
                    {
                        dp[i][j + 1][k][1] = (dp[i][j + 1][k][1] + dp[i][j][k][0] * (l - j)) % mod;
                    }
                    if (k < d)
                    {
                        dp[i][j][k + 1][2] = (dp[i][j][k + 1][2] + dp[i][j][k][0] * (d - k)) % mod;
                    }
                }
                if (j > 0)
                {
                    if (i < u)
                    {
                        dp[i + 1][j][k][0] = (dp[i + 1][j][k][0] + dp[i][j][k][1] * (u - i)) % mod;
                    }
                    if (k < d)
                    {
                        dp[i][j][k + 1][2] = (dp[i][j][k + 1][2] + dp[i][j][k][1] * (d - k)) % mod;
                    }
                }
                if (k > 0)
                {
                    if (i < u)
                    {
                        dp[i + 1][j][k][0] = (dp[i + 1][j][k][0] + dp[i][j][k][2] * (u - i)) % mod;
                    }
                    if (j < l)
                    {
                        dp[i][j + 1][k][1] = (dp[i][j + 1][k][1] + dp[i][j][k][2] * (l - j)) % mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int t = 0; t < 3; t++)
    {
        ans = (ans + dp[u][l][d][t]) % mod;
    }
    return ans;
}
signed main()
{
    int u, l, d;
    cin >> u >> l >> d;
    init();
    int b=C[26][u]%mod,z=C[26][l]%mod,x=C[10][d]%mod;
    cout<<b<<' '<<z<<' '<<x<<' '<<endl;
    int choose=b*z*x;
    cout << choose*solve(u, l, d)%mod;
}