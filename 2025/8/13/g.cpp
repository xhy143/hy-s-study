#include<bits/stdc++.h>
using namespace std;
int c[25][25];
int main() {
    int x, y;
    cin >> x >> y;
    for(int i = 1; i <= x; i++) {
        c[i][1] = c[i][i] = 1;
        for(int j = 2; j < i; j++) {
            c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
    }
    cout << c[x][y] << endl;
    return 0;
}