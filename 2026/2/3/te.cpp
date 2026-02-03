#include <bits/stdc++.h>
using namespace std;
vector<int> t[100001];
int deeps[100001], deept[100001];
void dfs(int u, int f, int deep, int* d) {
    d[u] = deep;
    for (int v : t[u]) {
        if (v != f) {
            dfs(v, u, deep + 1, d);
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
    dfs(1, -1, 0, deeps);
    int s = 1;
    for (int i = 2; i <= n; i++) {
        if (deeps[i] > deeps[s]) {
            s = i;
        }
    }
    dfs(s, -1, 0, deeps);
    int t = s;
    for (int i = 1; i <= n; i++) {
        if (deeps[i] > deeps[t]) {
            t = i;
        }
    }
    dfs(t, -1, 0, deept);
    for (int i = 1; i <= n; i++) {
        cout << max(deeps[i], deept[i]) << endl;
    }
    
    return 0;
}
