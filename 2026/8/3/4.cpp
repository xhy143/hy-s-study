#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m, d;
int d1[maxn], d2[maxn], du[maxn], a[maxn];
vector<int> adj[maxn];
void dfs(int u, int fa) {
    if (a[u]) d1[u] = 0;
    for (int v: adj[u]) {
        if (v == fa) continue;
        dfs(v, u);
        if (d1[v] != -1) {
            if (d1[v] + 1 > d1[u]) {
                d2[u] = d1[u];
                d1[u] = d1[v] + 1;
            }
            else if (d1[v] + 1 > d2[u]) {
                d2[u] = d1[v] + 1;
            }
        }
    }
}
void dfs2(int u, int fa) {
    if (a[u]) du[u] = max(du[u], 0);
    for (int v: adj[u]) {
        if (v == fa) continue;
        if (du[u] != -1) {
            du[v] = max(du[v], du[u] + 1);
        }
        if (a[u]) {
            du[v] = max(du[v], 1);
        }
        if (d1[v] != -1 && d1[v] + 1 == d1[u]) {
            if (d2[u] != -1) {
                du[v] = max(du[v], d2[u] + 1);
            }
        }
        else {
            if (d1[u] != -1) {
                du[v] = max(du[v], d1[u] + 1);
            }
        }
        dfs2(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> d;
    memset(d1, -1, sizeof(d1));
    memset(d2, -1, sizeof(d2));
    memset(du, -1, sizeof(du));
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    dfs2(1, 0);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        bool ok1 = (d1[i] == -1 || d1[i] <= d);
        bool ok2 = (du[i] == -1 || du[i] <= d);
        if (ok1 && ok2) {
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}