#include <bits/stdc++.h>
using namespace std;
const int MAXN = 65005;
vector<int> adj[MAXN], radj[MAXN];
bool reach[2005][2005];
void solve_bfs(int N, int M) {
    for (int u = 1; u <= N; u++) {
        bool vis[2005] = {false};
        queue<int> q;
        q.push(u);
        vis[u] = true;
        reach[u][u] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int v : adj[x]) {
                if (!vis[v]) {
                    vis[v] = true;
                    reach[u][v] = true;
                    q.push(v);
                }
            }
        }
    }
    
    int cnt = 0;
    long long sum = 0;
    for (int u = 1; u <= N; u++) {
        bool ok = true;
        for (int v = 1; v <= N; v++) {
            if (u == v) continue;
            if (!reach[u][v] && !reach[v][u]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cnt++;
            sum += u;
        }
    }
    cout<<cnt<<' '<<sum;
}

int main() {
    freopen("key.in", "r", stdin);
    freopen("key.out", "w", stdout);
    int N, M;
    cin>>N>>M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    solve_bfs(N, M);
    return 0;
}