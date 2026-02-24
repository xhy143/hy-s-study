#include<bits/stdc++.h>
using namespace std;

char m[12][12];
int f[3], c[3], ans;
bool zt[10][10][10][10][4][4];

void move(int &x, int &y, int &dir, int type) {
    int nx = x, ny = y;
    
    if (dir == 0) nx--;      
    else if (dir == 1) ny++; 
    else if (dir == 2) nx++; 
    else if (dir == 3) ny--; 
    if (nx < 1 || nx > 10 || ny < 1 || ny > 10 || m[nx][ny] == '*') {
        dir = (dir + 1) % 4;
    } else {
        x = nx;
        y = ny;
    }
}

int main() {
    for (int i = 0; i <= 11; i++) {
        m[i][0] = '*';
        m[i][11] = '*';
        m[0][i] = '*';
        m[11][i] = '*';
    }
    
    
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cin >> m[i][j];
            if (m[i][j] == 'F') {
                f[0] = i;  
                f[1] = j;  
            }
            if (m[i][j] == 'C') {
                c[0] = i;  
                c[1] = j;  
            }
        }
    }
    f[2] = 0;  
    c[2] = 0;  
    
    memset(zt, 0, sizeof(zt));
    ans = 0;
    
    while (true) {
        if (f[0] == c[0] && f[1] == c[1]) {
            cout << ans << endl;
            return 0;
        }
        if (zt[f[0]][f[1]][c[0]][c[1]][f[2]][c[2]]) {
            cout << 0 << endl;
            return 0;
        }
        zt[f[0]][f[1]][c[0]][c[1]][f[2]][c[2]] = true;
        move(f[0], f[1], f[2], 0);
        move(c[0], c[1], c[2], 1);
        
        ans++;
        if (ans > 1000000) { 
            cout << 0 << endl;
            return 0;
        }
    }
    
    return 0;
}