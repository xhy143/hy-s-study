#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,col[100001],ans=0;
vector<int> g[100086];
bool dfs(int u,int fa){
    bool t=false;
    for(auto v:g[u]){
        if(v!=fa&&dfs(v,u)) t=true;
    }
    if(t&&col[u]==0) ans++;
    return (col[u]==1||t);
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>col[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int root=-1;
    for(int i=1;i<=n;i++){
        if(col[i]){
            root=i;
            break;
        }
    }
    if(root!=-1) dfs(root,-1);
    else ans=1;
    cout<<ans;
}