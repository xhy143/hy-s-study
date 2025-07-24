#include<bits/stdc++.h>
using namespace std;
int n, m;
char G[105][105];
int vis[105][105];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct Node {
    int x, y, step;
};

int bfs(int sx, int sy, int ex, int ey) {
    queue<Node> q;
    q.push({sx, sy, 0});
    vis[sx][sy] = 1;
    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        if (cur.x == ex && cur.y == ey) return cur.step;
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && (G[nx][ny] == '.' || G[nx][ny] == 'T')) {
                vis[nx][ny] = 1;
                q.push({nx, ny, cur.step + 1});
            }
        }
    }
    return -1; 
}

int main() {
    cin >> n >> m;
    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++) {
        cin >> G[i];
        for (int j = 0; j < m; j++) {
            if (G[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (G[i][j] == 'T') {
                ex = i;
                ey = j;
            }
        }
    }
    cout << bfs(sx, sy, ex, ey) << endl;
}