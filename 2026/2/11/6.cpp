#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x7fffffffffffffff
int n, m, d[100001];
struct node {
    int v, w;
};
vector<node> g[100001];
bool vis[100001];

void bfs(int s) {
    deque<int> q;
    q.push_back(s);
    d[s] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto edge : g[u]) {
            int v = edge.v;
            int w = edge.w;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                if (w == 0) {
                    q.push_front(v);
                } else {
                    q.push_back(v);
                }
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
        g[i].clear();
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    
    bfs(1);
    
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
    
    return 0;
}