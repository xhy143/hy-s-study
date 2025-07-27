#include<bits/stdc++.h>
using namespace std;
int m,n,ans=0,dx[]={1,0,-1,0},dy[]={0,1,0,-1};
string G[10001];
void dfs(int x,int y){
    G[x][y]='.';
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<n && nx>=0 && ny<m && ny>=0&&G[nx][ny]=='W' ){
            dfs(nx,ny);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>G[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(G[i][j]=='W'){
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<ans;
}