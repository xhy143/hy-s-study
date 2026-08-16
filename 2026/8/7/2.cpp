#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e4+10;
int n,m,st,ed,dep[maxn];
vector<int>g[maxn],gr[maxn];
bool visr[maxn],bo[maxn];
void dfsr(int u){
    visr[u]=1;
    for(auto v:gr[u]){
        if(!visr[v])dfsr(v);
    }
}
void bfs(){
    memset(dep,-1,sizeof(dep));
    queue<int>q;
    if(bo[st]){
        q.push(st);
        dep[st]=0;
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:g[u]){
            if(bo[v]){
                if(dep[v]==-1){
                    dep[v]=dep[u]+1;
                    q.push(v);
                }
            }
        }
    }
    cout<<dep[ed]<<endl;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
    cin>>st>>ed;
    dfsr(ed);
    for(int i=1;i<=n;i++){
        bo[i]=1;
        for(int v:g[i])if(!visr[v])bo[i]=0;
    }
    bfs();
    return 0;
}