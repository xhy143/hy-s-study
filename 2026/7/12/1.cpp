#include<bits/stdc++.h>
#define ls (u<<1)
#define rs ((u<<1)|1)
#define int long long
#define endl '\n'
#define h cin.tie(0);
#define y ios::sync_with_stdio(0);
using namespace std;
const int maxn =1e6+10;
int a[maxn],n,m,ql,qr,qk,ans=0;
struct node{
    int l,r;
    int sum;
}g[maxn*4];
void up(int u){
    g[u].sum=g[ls].sum+g[rs].sum;
}
void build(int u,int l,int r){
    g[u].l=l,g[u].r=r;
    if(l==r){
        g[u].sum=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    up(u);
}
void ask(int u){
    if(ql<=g[u].l&&g[u].r<=qr){
        ans+=g[u].sum;
        return ;
    }
    int mid=g[u].l+g[u].r;
    mid>>=1;
    if(ql<=mid)ask(ls);
    if(qr>mid)ask(rs);
    return;
}
void add(int u){
    if(g[u].l==g[u].r){
        g[u].sum+=qk;
        return ;
    }
    int mid=(g[u].l+g[u].r)>>1;
    if(ql<=mid)add(ls);
    else add(rs);
    up(u);
}
signed main(){
    h y
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int pos;
        cin>>pos;
        if(pos==1){
            cin>>ql>>qk;
            add(1);
        }
        else{
            cin>>ql>>qr;
            ans=0;
            ask(1);
            cout<<ans<<endl;
        }
    }
    return 0;
}