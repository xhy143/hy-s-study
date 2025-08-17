#include<bits/stdc++.h>
using namespace std;
int R, C;
char G[101][101];
int vis[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct Node {
    int x, y, step;
};

int bfs() {
    queue<Node> q;
    q.push({0, 0, 1});
    vis[0][0] = 1;
    while (!q.empty()) {
        Node cur = q.front(); q.pop();

        if (cur.x == R-1 && cur.y == C-1) return cur.step;

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];

            if (nx >= 0 && nx < R && ny >= 0 && ny < C && !vis[nx][ny] && G[nx][ny] == '.') {

                vis[nx][ny] = 1;
                
                q.push({nx, ny, cur.step + 1});
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> G[i];
    }
    if(bfs()>0){
        cout<<"Yes";
    }
}