#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int vis[1001][1001];
        memset(vis,0,sizeof(vis));   
        int ans=1;
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
        string G[10001];
        for(int i=0;i<n;i++){
            cin>>G[i];
        }
        for(int i=0;i<k;i++){
            int nx=x+dx[d],ny=y+dy[d];
            if(nx<n&&nx>=0&&ny<m&&ny>=0&&G[nx][ny]=='.'){
                x=nx,y=ny;
                if(vis[x][y]==0){
                    ans++;
                    vis[x][y]=1;
                    cout<<x<<' '<<y<<endl;
                }
            }else{
                d=(d+1)%4;
            }
        }
        cout<<ans<<endl;
    }
}