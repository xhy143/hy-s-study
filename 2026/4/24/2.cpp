#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f 

int n, m;
struct edge {
    int e, w;      
};
vector<edge> g[100001];   
long long zdl[100001];    

void djstl(int s) {
    for(int i = 1; i <= n; i++) {
        zdl[i] = 1e18;  
    }
    zdl[s] = 0;
    priority_queue<pair<long long, int>, 
                   vector<pair<long long, int>>, 
                   greater<pair<long long, int>>> pq;
    pq.push({0, s});
    
    while(!pq.empty()) {
        long long d = pq.top().first; 
        int u = pq.top().second; 
        pq.pop();
        
        if(d != zdl[u]) continue;
        
        for(auto &edge : g[u]) {
            int v = edge.e;
            int w = edge.w;
            if(zdl[u] + w < zdl[v]) {
                zdl[v] = zdl[u] + w;
                pq.push({zdl[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    
    int s;
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    
    djstl(s);
    
    for(int i = 1; i <= n; i++) {
        if(i == s) continue;
        if(zdl[i] == 1e18) 
            cout << "0 ";
        else 
            cout << zdl[i] << " ";
    }
    
    return 0;
}