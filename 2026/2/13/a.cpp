#include<bits/stdc++.h>
using namespace std;

vector<int> g[1000001];
int degree[1000001];
int n, m;

int check() {
    vector<int> indegree(n + 1);
    for (int i = 1; i <= n; i++) {
        indegree[i] = degree[i];
    }
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }
    
    int cnt = 0;
    bool unique = true;
    
    while (!pq.empty()) {
        if (pq.size() > 1) {
            unique = false;
        }
        
        int u = pq.top();
        pq.pop();
        cnt++;
        
        for (int v : g[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                pq.push(v);
            }
        }
    }
    
    if (cnt != n) {
        return -1;
    }
    if (unique) {
        return 1;
    }
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        degree[i] = 0;
        g[i].clear();
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        degree[y]++;
        cout << check() << "\n";
    }
    
    return 0;
}