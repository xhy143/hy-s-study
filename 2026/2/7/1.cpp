#include<bits/stdc++.h>
#define INF 0x7fffffff
#define mod 80112002
#define OvO 0
using namespace std;
int n,m;
int dp[1000001];
int indegree[1000001]={0};
vector<int>g[1000001];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        indegree[b]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
            dp[i]=1;
        }
    }
    while(!q.empty()){
        int a=q.front();
        q.pop();
        for(int b:g[a]){
            dp[b]=(dp[b]+dp[a])%mod;
            indegree[b]--;
            if(indegree[b]==0) q.push(b);
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
        if(g[i].empty()){
            res=(res+dp[i])%mod;
        }
    }
    cout<<res;
    return OvO;
}