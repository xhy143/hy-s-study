#include<bits/stdc++.h>
using namespace std;
#define N 200001
#define M 200001
#define int long long
#define OwO 0
int fa[100001];
int root(int n){
    if(n==fa[n]) return n;
    return fa[n]=root(fa[n]);
}
struct node{
    int u,v,w;
    bool operator <(const node&o) const{
        return w<o.w;
    }
};
vector<node>a;
int n,m;
int kruskal(){
    sort(a.begin(),a.end());
    for(int i=1;i<=n;i++) fa[i]=i;
    int sum=0;
    int cnt=n;
    for(int i=1;i<a.size();i++){
        int u=root(a[i].u),v=root(a[i].v),w=a[i].w;
        if(u==v)continue;
        sum=max(sum,w);
        fa[u]=v;
        cnt--;
    }
    return (cnt==1?sum:-1);
}
signed main(){
    cin>>n>>m;
    int j=1;
    for(int i=1;i<=m;i++){
        int d,e,f;
        cin>>d>>e>>f;
        a.push_back({d,e,f});
        a.push_back({e,d,f});
    }
    cout<<kruskal();
}