#include<bits/stdc++.h>
using namespace std;
vector<int> t[20002];
int n,m,ha[10001];
int fa[10001];
int dps[10001][2];
void dp(int u,int fa){
    dps[u][1]=ha[u];
    if(u==0) return;
    for(auto v:t[u]){
        if(v==fa) continue;
        dp(v,u);
        dps[u][0]+=max(dps[v][1],dps[v][0]);
        dps[u][1]+=dps[v][0];
    }   
}
int main(){
    int n,m,root;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ha[i];
    }
    for(int i=1;i<n;i++){
        int s,e;
        cin>>s>>e;
        t[e].push_back(s);
        fa[s]=e;
    }
    for(int i=1;i<=n;i++){
        if(fa[i]==0) {root=i;break;}
    }
    dp(root,0);
    cout<<max(dps[root][0],dps[root][1]);
}