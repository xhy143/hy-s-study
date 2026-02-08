#include<bits/stdc++.h>
using namespace std;
vector<int>g[100001];
int vis[100001]={0};
void dfs(int v){
    if(v==0||vis[v]){
        return ;
    }
    vis[v]=1;
    cout<<v<<' ';
    sort(g[v].begin(),g[v].end());
    for(int u:g[v]){
        dfs(u);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int s,e;
        cin>>s>>e;
        g[s].push_back(e);
    }
    dfs(1);
}