#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int vis[maxn],ans=INT_MAX,in[maxn];
vector<int>g[maxn];
int n;
void tp(){
    queue<int>q;
    for(int i=1;i<=n;i++)if(in[i]==0)q.push(i);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=1;
        in[g[u][0]]--;
        if(in[g[u][0]]==0)q.push(g[u][0]);
    }
}
void dfs(int u,int dep,int fa){
    if(vis[u]==1){
        ans=min(ans,dep);
        return;
    }
    vis[u]=1;
    dfs(g[u][0],dep+1,u);
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int u=i,v;
        cin>>v;
        g[u].push_back(v);
        in[v]++;
    }
    tp();
    ans=n;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i,0,0);
        }
    }
    cout<<ans<<endl;
}