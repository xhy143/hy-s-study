#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const int maxn = 2e6 + 10;
const int base = 131;
int p[maxn], len;
string s, t;
unordered_set<unsigned long long> S;
ull h[maxn], b[maxn];
void build_h()
{
    b[0] = 1, h[0] = 0;
    for (int i = 1; i <= len; i++)
    {
        b[i] = b[i - 1] * base;
        h[i] = h[i - 1] * base + s[i - 1];
    }
}
ull get_hash(int l, int r)
{
    l++;
    r++;
    return h[r] - h[l - 1] * b[r - l + 1];
}
signed main()
{
    int tb;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tb;
    while (tb--)
    {
        cin >> t;
        s = "";
        for (char ch : t)
        {
            s += '#';
            s += ch;
        }
        s += "#";
        len = s.size();
        build_h();
        S.clear();
        int ans = 0;
        int l = 0, r = -1;
        for (int i = 0; i < len; i++)
        {
            int mir = l + r - i;
            p[i] = (i <= r) ? min(r - i, p[mir]) : 0;
            if (p[i] == 0 && s[i] != '#')
                S.insert(get_hash(i, i));
            while (i - p[i] - 1 >= 0 && i + p[i] + 1 < len && s[i - p[i] - 1] == s[i + p[i] + 1])
            {
                p[i]++;
                if (s[i + p[i]] != '#')
                {
                    S.insert(get_hash(i - p[i], i + p[i]));
                }
            }
            if (i + p[i] > r)
            {
                l = i - p[i];
                r = i + p[i];
            }
        }
        cout << S.size() << endl;
    }
    return 0;
}