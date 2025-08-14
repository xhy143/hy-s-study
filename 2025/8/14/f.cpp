#include<bits/stdc++.h>
using namespace std;
int G[1001][1001];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1},n,m,ans=0,maxs=-1,mins=10000000,s=0;
void dfs(int x,int y){
    G[x][y]=0;
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<n &&nx>=0 && ny<m && ny>=0 && G[nx][ny]==1){
            s++;
            dfs(nx,ny);
        }
    }
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
            if(G[i][j]==1){
                s=1;
                ans++;
                dfs(i,j);
                if(s<mins){
                    mins=s;
                }
                if(s>maxs){
                    maxs=s;
                }
            }
        }
    }
    cout<<maxs-mins;
}                                         