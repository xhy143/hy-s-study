#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e4+10,maxk=510;
vector<int>g[maxn];
int dp[maxn][maxk];
int n,k,ans;
void dfs(int u,int fa){
    dp[u][0]=1;
    for(int v:g[u]){
        if(v==fa)continue;
        dfs(v,u);
        for(int i=0;i<k;i++){
            if(dp[v][i]==0)break;
            int j=k-i-1;
            ans+=dp[v][i]*dp[u][j];
        }
        for(int i=0;i<k;i++){
            if(dp[v][i]==0)break;
            dp[u][i+1]+=dp[v][i];
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout<<ans<<endl;
}