#include<bits/stdc++.h>
using namespace std;
int X, Y;
string G[155];
int vis[155][155];
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

struct Node {
    int x, y, step;
};

int bfs(int sx, int sy) {
    queue<Node> q;
    q.push({sx, sy, 0});
    vis[sx][sy] = 1;
    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        if (G[cur.y][cur.x] == 'H') return cur.step;
        for (int i = 0; i < 8; i++) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if (nx >= 0 && nx < X && ny >= 0 && ny < Y && !vis[ny][nx] && G[ny][nx] != '*') {
                vis[ny][nx] = 1;
                q.push({nx, ny, cur.step + 1});
            }
        }
    }
    return -1; 
}

int main() {
    cin >> X >> Y;
    for (int i = 0; i < Y; i++) {
        cin >> G[i];
    }
    int sx, sy;
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            if (G[i][j] == 'K') {
                sx = j;
                sy = i;
            }
        }
    }
    cout << bfs(sx, sy) << endl;
}