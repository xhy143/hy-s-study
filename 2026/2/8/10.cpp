#include<bits/stdc++.h>
#define QWQ 0
#define INF 0x7fffffff
using namespace std;
int a[100001],siz[1000001]={1},ans=-1;
int froot(int u){
    if(a[u]==u) return u;
    return a[u]=froot(a[u]);
}
void hb(int x,int y){
    x=froot(x),y=froot(y);
    if(x==y)return;
    if(siz[x]>siz[y]){
        a[y]=x;
        siz[x]+=siz[y];
        ans=max(ans,siz[x]);
        return;
    }else if(siz[x]<siz[y]){
        a[x]=y;
        siz[y]=siz[x]+siz[y];
    }else{
        a[x]=y;
        siz[y]=siz[x]+siz[y];
    }
    ans=max(ans,siz[y]);
    return ;
}
int main(){
    int T;
    int n;
    cin>>n;
    cin>>T;
    for(int i=1;i<=n;i++) a[i]=i,siz[i]=1;
    while(T--){
        int pos,s,x,y;
        cin>>x>>y;
        hb(x,y);
        cout<<ans<<endl;
    }
    return QWQ;
}