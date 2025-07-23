#include<iostream>
using namespace std;
int n, m, ans = 0;
int G[105][105];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y) {
    G[x][y] = 0; 
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && G[nx][ny] > 0) {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            G[i][j] = row[j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] > 0) {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
}