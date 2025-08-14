#include <bits/stdc++.h>
using namespace std;

int n, m;
int g[105][105];
bool vis[105][105];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int x, int y, int color) {
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;
    g[x][y] = 0;
    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d], ny = cy + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && g[nx][ny] == color) {
                vis[nx][ny] = true;
                g[nx][ny] = 0;
                q.push({nx, ny});
            }
        }
    }
}

void fall() {
    for (int col = 0; col < n; col++) {
        int write = n - 1;
        for (int h = n - 1; h >= 0; h--) {
            if (g[h][col] != 0) {
                g[write][col] = g[h][col];
                if (write != h) g[h][col] = 0;
                write--;
            }
        }
        // 填充上方空位
        for (int h = write; h >= 0; h--) {
            g[h][col] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    memset(vis, 0, sizeof(vis));
    int startx = n - 1, starty = m - 1;
    int color = g[startx][starty];
    if (color != 0)
        bfs(startx, starty, color);
    fall();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << g[i][j];
            if (j != n - 1) cout << " ";
        }
        cout << endl;
    }
}