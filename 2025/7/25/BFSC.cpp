#include<bits/stdc++.h>
using namespace std;
int n, m, vis[45][45], dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
string G[45];
struct node {
    int x, y, step;
};
int bfs(int x, int y) {
    queue<node> a;
    a.push({x, y, 1});
    vis[x][y] = 1;
    while (!a.empty()) {
        node cur = a.front(); a.pop();
        if (cur.x == n - 1 && cur.y == m - 1) {
            return cur.step;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                !vis[nx][ny] && G[nx][ny] == '.') {
                a.push({nx, ny, cur.step + 1});
                vis[nx][ny] = 1;
            }
        }
    }
    return -1; 
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> G[i];
    }
    cout << bfs(0, 0) << endl;
}