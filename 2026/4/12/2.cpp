#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[105][105][105]; // dp[x][y][t]
int n, k;
ll g[105][105]; 

ll dfs(int x, int y, int t) {
    if (x < 0 || x >= n || y < 0 || y > x) return -1e18; 
    if (x == n - 1) { 
        if (t < k) return max(g[x][y], 3 * g[x][y]); 
        else return g[x][y]; 
    }
    if (dp[x][y][t] != -1e18) return dp[x][y][t];

    ll res = -1e18;
    res = max(res, dfs(x + 1, y, t) + g[x][y]);
    if (t < k) {
        res = max(res, dfs(x + 1, y, t + 1) + 3 * g[x][y]);
    }
    res = max(res, dfs(x + 1, y + 1, t) + g[x][y]);
    if (t < k) {
        res = max(res, dfs(x + 1, y + 1, t + 1) + 3 * g[x][y]);
    }

    return dp[x][y][t] = res;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int t = 0; t <= k; t++) {
                dp[i][j][t] = -1e18;
            }
        }
    }
    cout << dfs(0, 0, 0) << endl;
    return 0;
}