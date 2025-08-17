#include<bits/stdc++.h>
using namespace std;

struct node{
    int x, y, cnt; 
};

int G[3][3];
int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};
string  wz() {
    string s;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            s += (char)(G[i][j] + '0');
        }
    }
    return s;
}

bool isTarget() {
    return  wz() == "123804765";
}

void bfs(int  X, int  Y) {
    queue<node> q;
    set<string> visited; 

  
    q.push({ X,  Y, 0});
    visited.insert( wz());

    while (!q.empty()) {
        node curr = q.front();
        q.pop();
        if (isTarget()) {
            cout << curr.cnt << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                swap(G[curr.x][curr.y], G[nx][ny]);
                string k =  wz();

                if (visited.find(k) == visited.end()) {
                    visited.insert(k);
                    q.push({nx, ny, curr.cnt + 1});
                }
                swap(G[curr.x][curr.y], G[nx][ny]);
            }
        }
    }
}

int main() {
    string ls;
    cin >> ls;
    int x = 0, y = 0; 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            G[i][j] = ls[i * 3 + j] - '0';
            if (G[i][j] == 0) {
                x = i;
                y = j;
            }
        }
    }

    bfs(x, y);
    return 0;
}