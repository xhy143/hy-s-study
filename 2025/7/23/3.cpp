#include<bits/stdc++.h>
using namespace std;
int N, M;
int vis[100001] = {0};

int bfs(int start, int target) {
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (x == target) return vis[x] - 1;
        if (x - 1 >= 0 && !vis[x - 1]) {
            vis[x - 1] = vis[x] + 1;
            q.push(x - 1);
        }
        if (x + 1 <= 100000 && !vis[x + 1]) {
            vis[x + 1] = vis[x] + 1;
            q.push(x + 1);
        }
        if (2 * x <= 100000 && !vis[2 * x]) {
            vis[2 * x] = vis[x] + 1;
            q.push(2 * x);
        }
    }
    return -1; 
}

int main() {
    cin >> N >> M;
    cout << bfs(N, M) << endl;
}