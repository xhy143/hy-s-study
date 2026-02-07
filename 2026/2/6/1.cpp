#include<bits/stdc++.h>
#define OvO 0
using namespace std;
vector<int> g[100001];
int vis[100001];
void dfs(int v,int n,int b){
    if(vis[v]==1)return;
    vis[v]=1;
    for(int i=1;i<=n;i++){
        if(i==b) continue;
        if(g[v][i]==1){
            dfs(i,n,b);
        }
    }
}
void res(int n,int p){
    for(int i=1;i<=n;i++){
        vis[i]=p;
    }
}
void bfs(int u,int n){
    queue<int>p;
    p.push(u);
    res(n,INT_MAX);
    
    vis[u]=0;
    for(int i=1;i<=n;i++){
        int v=p.front();
        p.pop();
        for(int j:g[v]){
            if(vis[j]==INT_MAX){
                p.push(j);
                vis[j]=vis[v]+1;
            }
        }
        
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int s,e;
        cin>>s>>e;
        g[s].push_back(e);
    }
    bfs(1,n);
    for(int i=1;i<=n;i++){
        if(vis[i]>=0) cout<<vis[i]<<' ';
    }
    return OvO;
}