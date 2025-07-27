#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,step;
};
int n,m,vis[1001][1001],dx[]={1,0,-1,0},dy[]={0,1,0,-1};
string G[10001];
queue<node>a;
int bfs(int x,int y,int ex,int ey){
    a.push({x,y,1});
    vis[x][y]=1;
    while(!a.empty()){
        node e=a.front();
        a.pop();
        if(e.x==ex&&e.y==ey){
            return e.step;
        }
        for(int i=0;i<4;i++){
            int nx=e.x+dx[i];
            int ny=e.y+dy[i];
            if(nx<n&&ny>=0&&nx>=0&&ny<m&&G[nx][ny]=='.'&&vis[nx][ny]==0){
                vis[nx][ny]=1;
                a.push({nx,ny,e.step+1});
            }
        }
    }
    return -1;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>G[i];
    }
    cout<<bfs(0,0,n-1,m-1);
}