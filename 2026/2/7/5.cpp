#include<bits/stdc++.h>
using namespace std;
#define QAQ 0
#define N 1001
int vis[1001][1001],qvis[1001][1001],dx[]={0,-1,0,1},dy[]={1,0,-1,0},n,m;
char g[1001][1001];
int ans=0;
void dfs(int x,int y){
    if(vis[x][y])return ;
    
    vis[x][y]=1;
    for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&g[nx][ny]=='W'&&vis[nx][ny]==0) {
                dfs(nx,ny);
            }
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&g[nx][ny]=='.'&&qvis[nx][ny]==0) {
                ans++;
                qvis[nx][ny]=1;
            }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>g[i];
    }
    dfs(0,0);
    cout<<ans;
}