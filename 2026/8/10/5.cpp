#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, m;
int f[maxn], fa[maxn * 2], T, F, U;
int find(int u) {
    if (fa[u] == u) return u;
    return fa[u] = find(fa[u]);
}
void merge(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return;
    fa[u] = v;
}
int get(int x) {
    if (x < 0) return n + 1 - x;
    else return x;
}
int main() {
    //freopen("tribool.in", "r", stdin);
    //freopen("tribool.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) f[i] = i;
        for (int i = 0; i <= 2 * n + 2; i++) fa[i] = i;
        T = n + 1;
        U = 0;
        F = -T;
        for (int i = 1; i <= m; i++) {
            char ch;
            int x, y;
            cin >> ch >> x;
            if (ch == '+' || ch == '-') cin >> y;
            
            if (ch == 'T') f[x] = T;
            else if (ch == 'F') f[x] = F;
            else if (ch == 'U') f[x] = U;
            else if (ch == '+') f[x] = f[y];
            else if (ch == '-') f[x] = -f[y];
        }
        for (int i = 1; i <= n; i++) {
            merge(i, get(f[i]));
            merge(i + n + 1, get(-f[i]));
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (find(i) == find(i + n + 1)) cnt++;
        }
        cout << cnt << '\n';
    }
    
    return 0;
}