#include<bits/stdc++.h>
using namespace std;
#define N 200001
#define M 200001
#define int long long
#define OwO 0
#define INF 0x7fffffff
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
}a[M];
int n,m;
int kruskal(){
    sort(a+1,a+m+1);
    for(int i=1;i<=n;i++) fa[i]=i;
    int sum=0;
    int cnt=n;
    int ans=-INF;
    for(int i=1;i<m;i++){
        int u=root(a[i].u),v=root(a[i].v),w=a[i].w;
        if(u==v)continue;
        sum+=w;
        fa[u]=v;
        cnt--;
        ans=max(ans,w);
    }
    return (cnt==1?ans:-1);
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    cout<<kruskal();
}