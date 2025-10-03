#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e3+5;
int n,m,i,bl,ans,vis[2005];
queue<int> q;
vector<int> a[MAXN];

void clear(){
    while(!q.empty()) q.pop();
    return;
}

void bfs(int s,int e){
    vis[s]=1;
    q.push(s);
    while(!q.empty()){
        s=q.front();
        for(int j=0;j<a[s].size();j++){
            if(a[s][j]==i || vis[a[s][j]]) continue;
            q.push(a[s][j]);
            vis[a[s][j]]=1;
            if(a[s][j]==e){
                bl=1;
                clear();
                return;
            }
        }
        q.pop();
    }
    return;
}

int main(){
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int u,v;
    cin>>u>>v;
    bfs(u,v);
    if(!bl){
        cout<<-1;
        return 0;
    }
    for(i=1;i<=n;i++){
        if(i==u || i==v) continue;
        bl=0;
        memset(vis,0,sizeof(vis));
        bfs(u,v);
        if(!bl) ans++;
    }
    cout<<ans;
    return 0;
}