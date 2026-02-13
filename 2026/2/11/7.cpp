#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x7fffffffffffffff
struct node{
    int v,w;
};
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;  
vector<node> g[10000001];
int d[5000001];
bool vis[5000001];
char e[1001][1001];
int n,m;
void dijkstra(int s){
    fill(d+1,d+1+(n*m),INF);
    fill(vis+1,vis+1+(n*m),false);
    d[s]=0;
    pq.push({d[s],s});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto v:g[u]){
            int w=v.w;
            if(d[u]+w<d[v.v]){
                d[v.v]=d[u]+w;
                pq.push({d[v.v],v.v});
            }
        }
    }
}
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>e[i]+1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int x=0;x<4;x++){
                int nx=i+dx[x],ny=j+dy[x];
                if(nx>0&&nx<=n&&ny>0&&ny<=m){
                    int dbh=(i-1)*m+j,bh=(nx-1)*m+ny;
                    if(e[nx][ny]!='*'){
                        int w=(e[nx][ny]=='.'?0:e[nx][ny]-'0');
                        g[dbh].push_back({bh,w});
                    }
                }
            }
        }
    }
    dijkstra(1);
    cout<<(d[n*m]==INF?-1:d[n*m]);
}