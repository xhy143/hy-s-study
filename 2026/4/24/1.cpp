#include<bits/stdc++.h>
using namespace std;
int f[100001],n,m;
int find(int u){
    if(f[u]==u) return u;
    return f[u]=find(f[u]);
}
bool v[100001];
void hb(int x,int y){
    if(find(x)==find(y)) return;
    f[find(y)]=find(x);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        hb(u,v);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!v[find(i)])ans++,v[find(i)]=1;
    }
    cout<<ans-1;
}