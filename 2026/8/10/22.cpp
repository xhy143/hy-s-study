#include<bits/stdc++.h>
using namespace std;
#define int long long
int g[35][35];
int n,m;
int js(int mark){
    mark<<=1;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if((g[i][j]==1)&&(((mark>>i)&1)!=((mark>>j)&1))){
                ans++;
            }
        }
    }
    return ans;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u][v]=1;
        g[v][u]=1;
    }
    int minn=INT_MAX,mina=0;
    for(int i=1;i<=(1<<(n+1))-1;i++){
        int now=js(i);
        if(now==minn){
            mina++;
        }else if(now<minn){
            mina=0;
            minn=now;
        }
    }
    cout<<mina;
    return 0;
}
/*bool check(long long T) {
    vector<long long> dp(K+1, INF);
    dp[0] = 0;
    
    for(int i = 1; i <= K; i++) {
        long long cur_time = 0;
        bool ok = true;
        for(int j = i; j <= K && ok; j++) {
            // 检查订单j的等待时间
            if(j == i) {
                cur_time = dist[1][u[j]];
            } else {
                cur_time += dist[u[j-1]][u[j]];
            }
            if(cur_time - s[j] > T) {
                ok = false;
                break;
            }
            
            // 批次[i,j]可行
            long long start_time = max(t[j], dp[i-1]);
            long long finish_time = start_time + batch_cost[i][j];
            dp[j] = min(dp[j], finish_time);
        }
    }
    
    return dp[K] < INF;
}*/