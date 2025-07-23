#include<bits/stdc++.h>
using namespace std;
int n, m, ans = 0;
int G[105][105]={0};
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int pc=0;
void print(int a){
    pc++;
    if(a<=9){
        cout<<"  "<<a;
        return;
    }
    if(a<=99){
        cout<<" "<<a;
        return;
    }
    cout<<a;
}
void dfs(int x, int y,int depth) {
    G[x][y] = depth; 
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && G[nx][ny]==0) {
            dfs(nx, ny,depth+1);
            break;
        }
    }
}

int main() {
    cin >> n >> m;
    dfs(0,0,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            print((G[i][j]));
        }
        cout<<endl;
    }
}