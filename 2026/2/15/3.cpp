#include<bits/stdc++.h>
using namespace std;

int main(){
    int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
    int n, m;
    char mine[101][101]; 

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mine[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mine[i][j] == '*') {
                cout << '*';
            } else {
                int cnt = 0;
                for(int k = 0; k < 8; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && mine[nx][ny] == '*') {
                        cnt++;
                    }
                }
                cout << cnt;
            }
        }
        cout << endl; 
    }

    return 0;
}