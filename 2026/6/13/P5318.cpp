#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> g[100001];
int vis1[100001],vis2[100001];
void dfs(int u){
    vis1[u]=1;
    cout<<u<<' ';
    for(auto v:g[u]){
        if(vis1[v]==1)continue;
        dfs(v);
    }
}
void bfs(int root){
    queue<int>q;
    q.push(root);
    vis2[root]=1;
    while(!q.empty()){
        int u=q.front();
        cout<<u<<' '; 
        q.pop();
        for(auto v:g[u]){
            if(vis2[v]==1)continue;
            vis2[v]=1;
            q.push(v);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        sort(g[i].begin(),g[i].end());
    }
    dfs(1);
    cout<<endl;
    bfs(1);
}