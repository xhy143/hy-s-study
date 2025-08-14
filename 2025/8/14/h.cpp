#include<bits/stdc++.h>
using namespace std;
int G[1001][1001],a[1001][1001];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1},n,m,ans=0,maxx=-1;
int dp[1001][1001];
int dfs(int x,int y){
    if(dp[x][y])return dp[x][y];
    int res=1;
    for(int i=0;i<4;i++){
        int nx=dx[i]+x,ny=dy[i]+y;
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&G[x][y]>G[nx][ny]){
            res=max(res,dfs(nx,ny)+1);
        }
    }
    return dp[x][y]=res;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>G[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans=max(ans,dfs(i,j));
        }
    }
    cout<<ans;
}