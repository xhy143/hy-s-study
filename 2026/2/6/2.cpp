#include<bits/stdc++.h>
using namespace std;
#define awa 0
const int MAXN = 1000005;
vector<int> rev_g[MAXN];  
int ans[MAXN];

void dfs(int u, int max_node, vector<bool>& visited) {
    if (visited[u]) return;
    visited[u] = true;
    ans[u] = max_node;
    
    for (int v : rev_g[u]) {
        if (!visited[v]) {
            dfs(v, max_node, visited);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        ans[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        rev_g[v].push_back(u);  
    }
    
    vector<bool> visited(n + 1, false);
    for (int i = n; i >= 1; i--) {
        if (!visited[i]) {
            dfs(i, i, visited);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i];
        if (i < n) cout << " ";
    }
    cout << endl;
    
    return awa;
}