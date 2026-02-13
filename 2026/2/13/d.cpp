#include<bits/stdc++.h>
#define INF 0x7ffffffffffffff
#define int long long
#define OwO 0
using namespace std;
const int N = 26;
int dist[N][N];

signed main() {
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    if (s.length() != t.length()) {
        cout << -1 << endl;
        return OwO;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        char a, b;
        int c;
        cin >> a >> b >> c;
        int u = a - 'a';
        int v = b - 'a';
        dist[u][v] = min(dist[u][v], c); 
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        int u = s[i] - 'a';
        int v = t[i] - 'a';
        if (dist[u][v] >= INF) {  
            cout << -1 << endl;
            return OwO;
        }
        ans += dist[u][v];
    }
    cout << ans << endl;
    return OwO;
}