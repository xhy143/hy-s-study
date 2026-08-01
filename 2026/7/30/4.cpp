#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define int long long
#define ovo 0
using namespace std;
int L, bo[30];
string str, x, y;
char com, ch;
stack<pii> stk;
bool err;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T, c, d;
    cin >> T;
    while (T--)
    {
        cin >> L >> str;
        err = 0;
        memset(bo, false, sizeof(bo));
        int ans = 0;
        int res = 0;
        int flag = -1;
        for (int i = 1; i <= L; i++)
        {
            cin >> com;
            if (com == 'F')
            {
                cin >> ch >> x >> y;
                if (err)
                    continue;
                if (bo[ch - 'a'])
                {
                    err = 1;
                    continue;
                }
                bo[ch - 'a'] = 1;
                string tx = x, ty = y;
                if (tx == "n")
                    tx = "30000";
                if (ty == "n")
                    ty = "30000";
                c = stoi(tx);
                d = stoi(ty);
                if (flag == -1)
                {
                    if (d - c >= 1000)
                    {
                        stk.push({ch - 'a', 1});
                        res++;
                        ans = max(ans, res);
                    }
                    else if (d >= c)
                    {
                        stk.push({ch - 'a', 0});
                    }
                    else
                    {
                        stk.push({ch - 'a', -1});
                        flag = ch - 'a';
                    }
                }
                else
                {
                    stk.push({ch - 'a', -1});
                }
            }
            else
            {
                if (err)
                    continue;
                if (stk.empty())
                {
                    err = 1;
                    continue;
                }
                int var = stk.top().fi;
                int type = stk.top().se;
                bo[var] = 0;
                if (flag == var)
                {
                    flag = -1;
                }
                else if (flag == -1 && type == 1)
                {
                    res -= stk.top().se;
                }
                stk.pop();
            }
        }
        if (!stk.empty())
            err = 1;
        while (!stk.empty())
            stk.pop();

        if (err)
        {
            cout << "ERR\n";
            continue;
        }
        if (ans == 0)
        {
            cout << (str == "O(1)" ? "Yes" : "No") << '\n';
        }
        else
        {
            string corr = "O(n^" + to_string(ans) + ")";
            cout << (str == corr ? "Yes" : "No") << '\n';
        }
    }
    return ovo;
}