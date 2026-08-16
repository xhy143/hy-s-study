#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100,mod=1e5+3;
int n,m,dp[maxn],d[maxn];  
vector<int>g[maxn];
void bfs(){
    queue<int>q;
    memset(d,-1,sizeof(d));
    q.push(1);
    d[1]=0;
    dp[1]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:g[u]){
            if(d[v]==-1){
                d[v]=d[u]+1;
                dp[v]=(dp[u]+dp[v])%mod;
                q.push(v);
            }
            else if(d[u]+1==d[v]){
                dp[v]=(dp[u]+dp[v])%mod;
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs();
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<endl;
    }
    return 0;
}