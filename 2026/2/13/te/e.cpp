#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,int> pii;

const int N = 100010;
const ll INF = 1e18;

vector<pii> g[N];
ll dist[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        ll a;
        cin >> a;
        g[i].push_back({a, i+1});
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        ll f;
        cin >> x >> y >> f;
        g[x].push_back({f, y});
    }
    fill(dist, dist + n + 1, INF);
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        pii top = pq.top(); pq.pop();
        ll d = top.first;
        int u = top.second;
        
        if (d != dist[u]) continue;
        
        for (int i = 0; i < g[u].size(); i++) {
            ll w = g[u][i].first;
            int v = g[u][i].second;
            
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    cout << dist[n] << endl;
    return 0;
}