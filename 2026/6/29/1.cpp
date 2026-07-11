#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,w;
};
vector<edge>g;
int n,m,fa[10001],G[2001][2001];
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void hb(int x,int y){
    int fx=find(x),fy=find(y);
    fa[fx]=fy;
}
bool cmp(edge x,edge y){
    return x.w<y.w;
}
int main(){
    cin>>n>>m;
    fill(&G[0][0], &G[0][0] + 2001*2001, 1000000001);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        G[u][v]=min(G[u][v],w);
        G[v][u]=min(G[v][u],w);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(G[i][j]!=1000000001){
                g.push_back({i,j,G[i][j]});
            }
        }
    }
    sort(g.begin(),g.end(),cmp);
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    int ans=0;
    for(auto now:g){
        int u=now.u,v=now.v,w=now.w;
        if(find(u)!=find(v)){
            hb(u,v);
            ans=w;
        }
    }
    cout<<ans;
}