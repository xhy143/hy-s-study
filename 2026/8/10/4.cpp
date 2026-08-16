#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int v,w;
};
const int maxn=2e5+10;
int n,m;
vector<node>g[maxn];
int col[maxn];
bool dfs(int u,int fa,int c,int x){
    col[u]=c;
    for(auto e:g[u]){
        int v=e.v,w=e.w;
        if(w<=x)continue;
        if(col[v]==-1){
            if(!dfs(v,u,c^1,x))return 0;
        }
        else if(col[v]!=col[u]^1)return 0;
    }
    return 1;
}
bool check(int w){
    memset(col,-1,sizeof(col));
    for(int i=1;i<=n;i++){
        if(col[i]==-1){
            if(!dfs(i,0,0,w)){
                return false;
            }
        }
    }
    return 1;
}
signed main(){
    cin>>n>>m;
    int maxw=0;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        maxw=max(maxw,w);
    }
    int l=0,r=1e9+10,ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans;
}