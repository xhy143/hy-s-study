#include <bits/stdc++.h>
using namespace std;
const int maxn = 110; 
const double eps = 1e-8; 
int n;                   // 方程个数
int m;                   // 未知数个数
double a[maxn][maxn];    // a[i][j]:第 i 个方程的第 j 个未知数的系数，a[i][j+1]:常数项
double ans[maxn];        // 解
int gauss()
{
    int r = 1; // 当前处理的行号
    for (int c = 1; c <= m; c++)
    {
        int t = r;
        for (int i = r + 1; i <= n; i++)
        {
            if (abs(a[i][c]) > abs(a[t][c]))
            {
                t = i;
            }
        }
        if (abs(a[t][c]) < eps)
        {
            continue;
        }
        if (t != r)
        {
            for (int j = c; j <= m + 1; j++)
            {
                swap(a[t][j], a[r][j]);
            }
        }
        double div = a[r][c]; // 主元值
        for (int j = c; j <= m + 1; j++)
        {
            a[r][j] /= div;
        }
        for (int i = r + 1; i <= n; i++)
        {
            if (abs(a[i][c]) < eps)
                continue;
            double factor = a[i][c];//消元因子
            for (int j = c; j <= m + 1; j++)
            {
                a[i][j] -= factor * a[r][j];
            }
        }

        r++;
    }
    for (int i = r; i <= n; i++)
    {
        if (abs(a[i][m + 1]) > eps)
        {
            throw -1;
        }
    }
    if (r <= m)
    {
        throw 2;
    }
    for (int i = m; i >= 1; i--)
    {
        ans[i] = a[i][m + 1];
        for (int j = i + 1; j <= m; j++)
        {
            ans[i] -= a[i][j] * ans[j];
        }
    }

    return 0;
}

int main()
{
    cin >> n;
    m = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m + 1; j++)
        {
            cin >> a[i][j];
        }
    }

    try
    {
        gauss();
        for (int i = 1; i <= m; i++)
        {
            cout << 'x' << i << '=';
            cout << fixed << setprecision(2) << ans[i] << endl;
        }
    }
    catch (int e)
    {
        if (e == -1)
        {
            cout << -1 << endl;
        }
        else if (e == 2)
        {
            cout << 0 << endl;
        }
    }
    return 0;
}