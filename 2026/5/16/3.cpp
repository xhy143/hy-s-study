#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9;
int a[101][101];
void add(int x, int y)
{
    a[x][x]++;
    a[y][y]++;
    a[x][y]--;
    a[y][x]--;
}
ll det(int n)
{
    ll res = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            while (a[j][i])
            {
                ll t = a[i][i] / a[j][i];
                for (int k = i; k <= n; k++)
                {
                    a[i][k] = (a[i][k] - t * a[j][k]) % mod;
                    if (a[i][k] < 0)
                        a[i][k] += mod;
                }
                for (int k = i; k <= n; k++)
                {
                    swap(a[i][k], a[j][k]);
                }
                res = (mod - res) % mod;
            }
        }
        res = (res * a[i][i]) % mod;
        if (res < 0)
            res += mod;
    }
    return res;
}
int n, m;
char ch[1001][1001];
int cnt, idx[1001][1001];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ch[i][j];
            if (ch[i][j] == '.')
            {
                idx[i][j] = ++cnt;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (ch[i][j] == '.' && ch[i][j + 1] == '.')
                add(idx[i][j], idx[i][j + 1]);
            if (ch[i][j] == '.' && ch[i + 1][j] == '.')
                add(idx[i][j], idx[i + 1][j]);
        }
    }
    cout << det(cnt - 1) << endl;
    return 0;
}