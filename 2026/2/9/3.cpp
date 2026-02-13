#include<bits/stdc++.h>
using namespace std;
#define OaO 0
const int MOD = 1e9 + 7;
const int MAXN = 1000005;
int nxt[MAXN], degree[MAXN], vis[MAXN];
int n;
void topu(){
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(degree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 1; 
        int v = nxt[u];
        degree[v]--;
        if(degree[v] == 0) {
            q.push(v);
        }
    }
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        degree[i] = 0;
        vis[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        int e;
        cin >> e;
        nxt[i] = e;
        degree[e]++;
    }
    topu();
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[i] == 0 && degree[i] > 0) { 
            int u = i;
            int len = 0;
            while(vis[u] == 0) {
                vis[u] = 1;
                len++;
                u = nxt[u];
            }
            ans++;
        }
    }
    cout << ans << endl;
    return OaO;
}