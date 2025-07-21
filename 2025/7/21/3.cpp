#include<bits/stdc++.h>
using namespace std;
int n,vis[101][101],ans=0,dx[]={1,0,-1},dy[]={0,1,0},x=50,y=50;
void dfs(int depth){
    if(depth==n){
        ans++;
        return;
    }
    for(int i=0;i<3;i++){
        if(vis[x+dx[i]][y+dy[i]]==0){
            x+=dx[i];
            y+=dy[i];
            vis[x][y]=1;
            dfs(depth+1);
            vis[x][y]=0;
            y-=dy[i];
            x-=dx[i];
        }
    }
}
int main(){
    cin>>n;
    vis[50][50]=1;
    dfs(0);
    cout<<ans;
}