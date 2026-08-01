#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn], n;
string ans, s;
bool ok(char ch)
{
    deque<int> q1, q2;
    int x;
    ans = "";
    s = "";
    ans += ch;
    s += 'L';
    if (ch == 'L')
    {
        for (int i = 2; i <= 2 * n; i++)
        {
            if (a[i] == a[1])
            {
                x = i;
                break;
            }
        }
    }
    else
    {
        for (int i = 1; i < 2 * n; i++)
        {
            if (a[i] == a[2 * n])
            {
                x = i;
                break;
            }
        }
    }
    int st = (ch == 'L') ? 2 : 1;
    for (int i = st; i <= x - 1; i++)
    {
        q1.push_back(a[i]);
    }
    int ed = (ch == 'R') ? 2 * n - 1 : 2 * n;
    for (int i = ed; i >= x + 1; i--)
    {
        q2.push_back(a[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        if (q1.size() >= 2 && q1.front() == q1.back())
        {
            ans += 'L';
            s += 'L';
            q1.pop_front();
            q1.pop_back();
        }
        else if (!q1.empty() && !q2.empty() && q1.front() == q2.back())
        {
            ans += 'L';
            s += 'R';
            q1.pop_front();
            q2.pop_back();
        }
        else if (!q2.empty() && !q1.empty() && q2.front() == q1.back())
        {
            ans += 'R';
            s += 'L';
            q2.pop_front();
            q1.pop_back();
        }
        else if (q2.size() >= 2 && q2.front() == q2.back())
        {
            ans += 'R';
            s += 'R';
            q2.pop_front();
            q2.pop_back();
        }
        else
        {
            return false;
        }
    }
    reverse(s.begin(), s.end());
    ans += s;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= 2 * n; i++)
        {
            cin >> a[i];
        }
        if (ok('L'))
        {
            cout << ans << '\n';
        }
        else if (ok('R'))
        {
            cout << ans << '\n';
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}