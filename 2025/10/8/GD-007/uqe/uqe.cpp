#include <bits/stdc++.h>
using namespace std;
char f[1000001];
int main()
{
    long long i, j, n, m;
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);

    cin >> f;
    sscanf(f, "(%lldx+%lld)(%lldx+%lld)", &i, &j, &n, &m);
    long long a = i * n, b = i * m + j * n, c = j * m, flag = 0;
    if (a == 0 && b == 0 && c == 0)
    {
        return 0;
    }
    if (a != 0)
    {
        if (a != 1)
            printf("%dx^2", a);
        else
            cout << "x^2";
        if (b != 0 || c != 0)
        {
            cout << "+";
        }
    }
    if (b != 0)
    {
        if (b != 1)
            cout << b << "x";
        else
            cout << "x";
        if (c != 0)
            cout << "+";
    }
    if (c != 0)
    {
        cout << c;
    }
}