#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define QWQ 0
int ans=0,n,m,vis[100001];
vector<int>a[100001];
void dfs(int v){
    if(vis[v]==1) return ;
    vis[v]=1;
    for(auto u:a[v]){
        dfs(u);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int c,d;
        cin>>c>>d;
        a[c].push_back(d);
        a[d].push_back(c);
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        ans++;
        dfs(i);
    }
    cout<<ans;
    return QWQ;
}