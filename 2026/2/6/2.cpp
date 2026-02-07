#include<bits/stdc++.h>
using namespace std;
#define AWA 0
const int MAXN = 1000001;
vector<int> g[MAXN];
int ans[MAXN];
void dfs(int u, int max_node) {
    if (ans[u] != 0) return;  
    ans[u] = max_node;  
    for (int v : g[u]) {
        if (ans[v] == 0) {
            dfs(v, max_node);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = n; i >= 1; i--) {
        if (ans[i] == 0) {
            dfs(i, i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return AWA;
}