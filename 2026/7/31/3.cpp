#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 10;
int n, m, q, u, v, t, a[maxn];
queue<ll> A, B, C;
ll inc = 0; 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> q >> u >> v >> t;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= n; i++) A.push(a[i]);
    for (int i = 1; i <= m; i++) {
        ll la = A.empty() ? -1 : A.front() + inc;
        ll lb = B.empty() ? -1 : B.front() + inc;
        ll lc = C.empty() ? -1 : C.front() + inc;
        ll x;
        if (la >= lb && la >= lc) x = la, A.pop();
        else if (lb >= la && lb >= lc) x = lb, B.pop();
        else x = lc, C.pop();
        inc += q;
        ll y = x * u / v, z = x - y;
        B.push(y - inc);
        C.push(z - inc);
        if (i % t == 0) cout << x << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= n + m; i++) {
        ll la = A.empty() ? -1 : A.front() + inc;
        ll lb = B.empty() ? -1 : B.front() + inc;
        ll lc = C.empty() ? -1 : C.front() + inc;
        ll x;
        if (la >= lb && la >= lc) x = la, A.pop();
        else if (lb >= la && lb >= lc) x = lb, B.pop();
        else x = lc, C.pop();

        if (i % t == 0) cout << x << ' ';
    }
    cout << '\n';
    return 0;
}