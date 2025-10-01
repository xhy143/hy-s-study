#include<bits/stdc++.h>
using namespace std;

void solve(){
    int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
    int vis[1001][1001];
    string G[10001] ;
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    int x,y,d;
    cin>>x>>y>>d;
    for(int i=0;i<n;i++){
        cin>>G[i];
    }
    int ans=1;
    vis[x][y]=0;
    for(int i=0;i<k;i++){
        int nx=x+dx[d],ny=y+dy[d];
        if((nx<n&&ny<m&&nx>=0&&ny>=0)&&G[nx][ny]=='.'){
            x=nx,y=ny;
            if(vis[x][y]==0){
                vis[x][y]=1;
                ans++;
            }
        }else{
            d=(d+1)%4;
        }
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
}