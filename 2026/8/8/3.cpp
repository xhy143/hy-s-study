#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 3e5 + 5;
const int LOG = 20;
struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w > other.w; 
    }
};
int n, m, q;
vector<Edge> edges;
vector<pair<int, int>> tree[maxn];  
int fa[maxn]; 
int depth[maxn];
int up[maxn][LOG];  
int minw[maxn][LOG]; 
bool vis[maxn];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void kruskal() {
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; i++) fa[i] = i;
    int cnt = 0;
    for (auto &e : edges) {
        int fu = find(e.u), fv = find(e.v);
        if (fu != fv) {
            fa[fu] = fv;
            tree[e.u].push_back({e.v, e.w});
            tree[e.v].push_back({e.u, e.w});
            cnt++;
            if (cnt == n - 1) break;
        }
    }
}
void dfs(int u, int father, int weight) {
    vis[u] = true;
    depth[u] = depth[father] + 1;
    up[u][0] = father;
    minw[u][0] = weight;  
    for (int j = 1; j < LOG; j++) {
        up[u][j] = up[up[u][j-1]][j-1];
        minw[u][j] = min(minw[u][j-1], minw[up[u][j-1]][j-1]);
    }
    for (auto e : tree[u]) {
        int v=e.first,w=e.second;
        if (v != father) {
            dfs(v, u, w);
        }
    }
}
int query(int u, int v) {
    if (find(u) != find(v)) return -1;  
    int ans = INT_MAX;
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int j = 0; diff; j++, diff >>= 1) {
        if (diff & 1) {
            ans = min(ans, minw[u][j]);
            u = up[u][j];
        }
    }
    if (u == v) return ans;
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[u][j] != up[v][j]) {
            ans = min(ans, min(minw[u][j], minw[v][j]));
            u = up[u][j];
            v = up[v][j];
        }
    }
    ans = min(ans, min(minw[u][0], minw[v][0]));
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    edges.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    kruskal();
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < LOG; j++) {
            minw[i][j] = INT_MAX;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            depth[i] = 0;
            dfs(i, i, INT_MAX); 
        }
    }
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << query(x, y) << '\n';
    }
    return 0;
}