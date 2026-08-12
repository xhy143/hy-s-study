#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e4+100,maxm=1e6+100;
struct edge{
    int u,v,w,type;
    bool operator<(const edge&b)const{
        return w<b.w;
    }
};
struct original_edge{
    int u,v,w;
    bool operator<(const original_edge&b)const{
        return w<b.w;
    }
};
int n,m,k,fa[maxm],c[11],a[15][maxm];
int find(int x){
    return(fa[x]==x?x:fa[x]=find(fa[x]));
}
bool hb(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return 0;
    fa[x]=y;
    return 1;
}
bool check() {
    int root = find(1);
    for (int i = 2; i <= n; i++) {
        if (find(i) != root) return false;
    }
    return true;
}
vector<original_edge> original_g;
signed main(){
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        original_g.push_back({u,v,w});
        fa[i]=i;
    }
    sort(original_g.begin(),original_g.end());
    for(int i=0;i<k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    int cnt=0;
    vector<edge> g;
    for(auto e:original_g){
        int u=e.u,v=e.v,w=e.w;
        if(!hb(u,v))continue;
        g.push_back({u,v,w,-1});
        cnt++;
        if(cnt==n-1)break;
    }
    for(int i=0;i<k;i++){
        for(int j=1;j<=n;j++){
            g.push_back({n+i+1, j, a[i][j], i});
        }
    }
    sort(g.begin(),g.end());
    int ans=LLONG_MAX;
    for(int mask=0;mask<(1<<k);mask++){
        for (int i = 1; i <= n+k; i++) fa[i] = i;
        int cost = 0;
        int edge_cnt = 0;
        for (auto e : g) {
            bool take = false;
            if (e.type == -1) {
                take = true;
            } else if (mask & (1 << e.type)) {
                take = true;
            }
            if (take && hb(e.u, e.v)) {
                cost += e.w;
                edge_cnt++;
                if (check()) break;
            }
        }
        if (check()) {
            int anscost = cost;
            for (int j = 0; j < k; j++) {
                if (mask & (1 << j)) {
                    anscost += c[j];
                }
            }
            ans = min(ans, anscost);
        }
    }
    cout<<ans<<endl;
}