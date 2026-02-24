#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
vector<int> g[MAXN];
int n, k;
int a[MAXN];
bool qq[MAXN];
pair<int, int> bfs(int start) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    int zy = start;
    int maxDist = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (qq[u]) {
            if (dist[u] > maxDist) {
                maxDist = dist[u];
                zy = u;
            }
        }
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return {zy, maxDist};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    memset(qq, 0, sizeof(qq));
    
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        qq[a[i]] = true;
    }
    if (k == 1) {
        cout << "0\n";
        return 0;
    }
    pair<int, int> p1 = bfs(a[1]);  
    pair<int, int> p2 = bfs(p1.first);
    
    cout << p2.second << "\n";
    
    return 0;
}
