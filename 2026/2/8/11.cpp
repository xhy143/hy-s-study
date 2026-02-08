#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m;
string g[N];
int compId[N][N],compSize[N * N];
bool vis[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(int x, int y, int id) {
    vis[x][y] = true;
    compId[x][y] = id;
    compSize[id]++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
            g[nx][ny] == '.' && !vis[nx][ny]) {
            dfs(nx, ny, id);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    int compCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.' && !vis[i][j]) {
                compCount++;
                dfs(i, j, compCount);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '*') {
                set<int> lj; 
                int tot = 1;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                        g[nx][ny] == '.') {
                        int id = compId[nx][ny];
                        if (lj.find(id) == lj.end()) {
                            lj.insert(id);
                            tot += compSize[id];
                        }
                    }
                }
                ans = max(ans, tot);
            }
        }
    }
    if (ans == 0) {
        ans = n * m;
    }
    cout << ans << endl;
    return 0;
}