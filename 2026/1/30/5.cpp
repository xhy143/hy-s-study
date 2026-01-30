#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int e,val;
};
vector<node>m[10001];
int vis[100001];
signed dfs(int s,int e,int ans,int fa){
    if(s==e){
        cout<<ans<<endl;
        return 0;
    }
    for(auto v:m[s]){
        if(v.e==fa)continue;
        
        dfs(v.e,e,ans+v.val,s);
    }
    return 0;
}
signed main(){
    int n;
    cin>>n;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        int val;
        cin>>val;
        m[a].push_back({b,val});
        m[b].push_back({a,val});
    }
    int T;
    cin>>T;
    while(T--){
        int a,b;
        cin>>a>>b;
        dfs(a,b,0,-1);
    }
}