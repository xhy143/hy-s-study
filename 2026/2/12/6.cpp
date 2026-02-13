#include<bits/stdc++.h>
#define INF 0x7ffffffffffffff
#define int long long
#define OwO 0
using namespace std;
const int MAXN = 505;
int n, m, q;
int g[MAXN][MAXN];
int dist[MAXN][MAXN];  
bool js[MAXN];  
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) g[i][j] = 0;
            else g[i][j] = INF;
        }
        js[i] = false;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w < g[u][v]) { 
            g[u][v] = w;
            g[v][u] = w;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0; 
    }
    
    cin >> q;
    
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            if (js[x]) continue;
            js[x] = true;
            for (int i = 1; i <= n; i++) {
                    dist[x][i] = min(dist[x][i], g[x][i]);
                    dist[i][x] = min(dist[i][x], g[i][x]);
            }
            vector<int> jscs;
            for (int i = 1; i <= n; i++) {
                if (js[i]) {
                    jscs.push_back(i);
                }
            }
            for (int i =1;i<=n;i++) {
                for (int j =1;j<=n;j++) {
                    if (dist[i][x] < INF && dist[x][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][x] + dist[x][j]);
                    }
                }
            }
        } 
        else {
            int x, y;
            cin >> x >> y;
            
            if (!js[x] || !js[y]) {
                cout << -1 << "\n";
            }
            else if (dist[x][y] >= INF) {
                cout << -1 << "\n";
            }
            else {
                cout << dist[x][y] << "\n";
            }
        }
    }
    
    return OwO;
}
