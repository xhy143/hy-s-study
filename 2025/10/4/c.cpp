#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct State {
    int x, y, hp;
};

int T, N, M;
char grid[105][105];
int max_hp[105][105];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool bfs() {
    memset(max_hp, 0, sizeof(max_hp));
    queue<State> q;
    q.push({1, 1, 10});
    max_hp[1][1] = 10;

    while (!q.empty()) {
        State cur = q.front(); q.pop();
        int x = cur.x, y = cur.y, hp = cur.hp;

        if (x == N && y == M) return true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if (grid[nx][ny] == '#') continue;

            int nhp = hp;
            if (grid[nx][ny] == 'S') nhp = 10;
            else if (grid[nx][ny] >= '1' && grid[nx][ny] <= '9')
                nhp -= (grid[nx][ny] - '0');

            if (nhp <= 0) continue;
            if (nhp <= max_hp[nx][ny]) continue;

            max_hp[nx][ny] = nhp;
            q.push({nx, ny, nhp});
        }
    }
    return false;
}

int main() {
    freopen("spring.in", "r", stdin);
    freopen("spring.out", "w", stdout);

    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                cin >> grid[i][j];

        if (bfs()) cout << "possible\n";
        else cout << "impossible\n";
    }
    return 0;
}