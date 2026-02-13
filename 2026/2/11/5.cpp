#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x7fffffffffffffff
struct node{
    int v,w;
};
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;     //我很对不起yzm但答案就长这样****************************************************** */
vector<node> g[100001];
int m,d[500001],n;
bool vis[500001];
void dijkstra(int s){
    fill(d+1,d+1+n,INF);
    fill(vis+1,vis+1+n,false);
    d[s]=0;
    pq.push({d[s],s});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto v:g[u]){
            int w=v.w;
            if(d[u]+w<d[v.v]){
                d[v.v]=d[u]+w;
                pq.push({d[v.v],v.v});
            }
        }
    }
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int e,b,w;
        cin>>e>>b>>w;
        g[e].push_back({b,w});
        g[b].push_back({e,w});
    }
    int T;
    cin>>T;
    dijkstra(n);
    while(T--){
        int p;
        cin>>p;
        cout<<(d[p]==INF?-1:d[p])<<endl;
    }
}
/* 
                                     0000000

欢迎回到phigros！
__________________________________
接下来将进行游戏玩法教学

Rrhar'il                             AT Lv.825
*/