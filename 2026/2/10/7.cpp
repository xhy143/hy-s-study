#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, k, w[7501][7501], dist[7501], q[7501], tl = 1;
bool vis[1100000];
int Prim()
{
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0;
	for (int i = 1; i <= n; ++ i){
		int u = -1;
		for (int v = 1; v <= n; ++ v){
			if (!vis[v] && (u == -1 || dist[v] < dist[u])){
				u = v;
			}
		}
		vis[u] = true;
		q[tl] = dist[u];
		++ tl;
		for (int v = 1; v <= n; ++ v){
			if (!vis[v]){
				dist[v] = min(dist[v], w[u][v]);
			}
		}
	}
	sort (q + 1, q + tl);
	return q[n - k + 2];
}
signed main() {
    cin >> n >> k;
    for (int i = 1; i < n; ++ i){
    	for (int j = i + 1; j <= n; ++ j){
    		if (i == j){
    			continue;
			}
			w[i][j] = (2019201913 * i + 2019201949 * j) % 2019201997;
			w[j][i] = (2019201913 * i + 2019201949 * j) % 2019201997;
		}
	}
    //这不是数论吗？
	cout << Prim();
    return 0;
}
