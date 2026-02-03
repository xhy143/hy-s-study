#include <bits/stdc++.h>
using namespace std;

vector<int> t[100001];
int dist_s[100001], dist_t[100001];

// 进行一次 BFS/DFS，记录距离
void dfs(int u, int f, int dist, int* d) {
    d[u] = dist;
    for (int v : t[u]) {
        if (v != f) {
            dfs(v, u, dist + 1, d);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        t[x].push_back(y);
        t[y].push_back(x);
    }
    
    // 第一次 DFS，从节点1开始，找到最远的节点s
    dfs(1, -1, 0, dist_s);
    int s = 1;
    for (int i = 2; i <= n; i++) {
        if (dist_s[i] > dist_s[s]) {
            s = i;
        }
    }
    
    // 第二次 DFS，从s开始，找到最远的节点t，并记录dist_s
    dfs(s, -1, 0, dist_s);
    int t = s;
    for (int i = 1; i <= n; i++) {
        if (dist_s[i] > dist_s[t]) {
            t = i;
        }
    }
    
    // 第三次 DFS，从t开始，记录dist_t
    dfs(t, -1, 0, dist_t);
    
    // 输出每个节点的最大距离
    for (int i = 1; i <= n; i++) {
        cout << max(dist_s[i], dist_t[i]) << endl;
    }
    
    return 0;
}