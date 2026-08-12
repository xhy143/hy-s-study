#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 10005;
const int MAXK = 15;
struct edge {
    int u, v, w, type;
    bool operator<(const edge& other) const {
        return w < other.w;
    }
};
struct map_edge {
    int u, v, w;
    bool operator<(const map_edge& other) const {
        return w < other.w;
    }
};
int fa[MAXN + MAXK];
int n, m, k;
int find(int x) {
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
bool hb(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    fa[x] = y;
    return true;
}
bool check() {
    int root = find(1);
    for (int i = 2; i <= n; i++) {
        if (find(i) != root) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    vector<map_edge> old_g(m);
    for (int i = 0; i < m; i++) {
        cin >> old_g[i].u >> old_g[i].v >> old_g[i].w;
    }
    vector<ll> c(k);
    vector<vector<int>> a(k, vector<int>(n + 1));
    for (int j = 0; j < k; j++) {
        cin >> c[j];
        for (int i = 1; i <= n; i++) {
            cin >> a[j][i];
        }
    }
    sort(old_g.begin(), old_g.end());
    for (int i = 1; i <= n; i++) fa[i] = i;
    vector<edge> mst_edges;
    int cnt = 0;
    for (const auto& e : old_g) {
        if (hb(e.u, e.v)) {
            mst_edges.push_back({e.u, e.v, e.w, -1});
            cnt++;
            if (cnt == n - 1) break;
        }
    }
    vector<edge> g;
    for (auto e : mst_edges) {
        g.push_back(e);
    }
    for (int j = 0; j < k; j++) {
        for (int i = 1; i <= n; i++) {
            g.push_back({n + j + 1, i, a[j][i], j});
        }
    }
    sort(g.begin(), g.end());
    ll answer = LLONG_MAX;
    int nodes = n + k;
    for (int mask = 0; mask < (1 << k); mask++) {
        for (int i = 1; i <= nodes; i++) fa[i] = i;
        ll cost = 0;
        int edge_cnt = 0;
        for (auto e : g) {
            bool take = false;
            if (e.type == -1) {
                take = true;
            } else if (mask & (1 << e.type)) {
                take = true;
            }
            if (take && hb(e.u, e.v)) {
                cost += e.w;
                edge_cnt++;
                if (check()) break;
            }
        }
        if (check()) {
            ll ans_cost = cost;
            for (int j = 0; j < k; j++) {
                if (mask & (1 << j)) {
                    ans_cost += c[j];
                }
            }
            answer = min(answer, ans_cost);
        }
    }
    cout << answer << '\n';
    return 0;
}