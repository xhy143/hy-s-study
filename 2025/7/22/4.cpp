#include<bits/stdc++.h>
using namespace std;
int G[1001][1001],sx,sy,ex,ey,n,dx[]={1,0,-1,0},dy[]={0,1,0,-1},flag=0,pd=0,vis[10001][10001]={0};
void dfs(int x,int y){
    if(x==ex||y==ey){
        flag=1;
        return;
    }
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(G[nx][ny]==1){
            pd++;
        }
        if(pd==4){
            flag=-1;
            return;
        }
        if(nx>0&&ny>0&&nx<=n&&ny<=n&&G[nx][ny]==0){
            dfs(nx,ny);
            if(flag){
                return;
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>G[i][j];
        }
    }
    cin>>sx>>sy>>ex>>ey;
    if(G[sx][sy]==0||G[ex][ey]==0){
        cout<<"NO";
        return 0;
    }
    dfs(sx,sy);
    if(flag==1){
        cout<<"Yes";
    }
    if(flag=-1){
        cout<<"No";
    }
}