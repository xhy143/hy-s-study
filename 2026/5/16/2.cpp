#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const double eps = 1e-8;
int n;             // 方程个数
int m;             // 未知数个数
int a[maxn][maxn]; // a[i][j]:第 i 个方程的第 j 个未知数的系数，a[i][j+1]:常数项
int ans[maxn];     // 解
int where[50];     // 主元位置
int gauss()
{
    int r = 1; // 当前处理的行号
    for (int c = 1; c <= n; c++)
    {
        int t = 0;
        for (int i = r; i <= n; i++)
        {
            if (a[i][c])
            {
                t = i;
                break;
            }
        }
        if (!t)
        {
            continue;
        }
        if (t != r)
        {
            for (int j = c; j <= n + 1; j++)
            {
                swap(a[t][j], a[r][j]);
            }
        }
        where[c] = r;
        for (int i = 1; i <= n; i++)
        {
            if (i == r || !a[i][c])
                continue;
            for (int j = 1; j <= n + 1; j++)
                a[i][j] ^= a[r][j];
        }
        r++;
    }
    return 0;
}
int res;
void dfs(int c, int num)
{ // 处理第c列，按了num次按钮
    if (num >= res)
        return;
    if (c == 0)
    {
        res = num;
        return;
    }
    if (!where[c])
    {
        ans[c] = 0;
        dfs(c - 1, num); 
        ans[c] = 1;
        dfs(c - 1, num + 1);
    }
    else
    {
        int r = where[c];
        ans[c] = a[r][n + 1];
        for (int i = n; i > c; i--)
        {
            ans[c] ^= (a[r][i] & ans[i]);
        }
        if (ans[c])
            dfs(c - 1, num + 1);
        else
            dfs(c - 1, num);
    }
}
int main()
{
    cin >> n>>m;
    for (int i = 1; i <= m; i++)
    {
        int u,v;
        cin>>u>>v;
        a[u][v]=a[v][u]=1;
    }
    for(int i=1;i<=n;i++){
        a[i][i]=a[i][n+1]=1;
    }
    gauss();
    res=n;
    dfs(n, 0);
    cout<<res<<endl;
    return 0;
}