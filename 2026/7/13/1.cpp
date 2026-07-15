#include<bits/stdc++.h>
#define int long long
#define lc ((t)<<1)
#define rc (((t)<<1)+1)
#define endl '\n'
using namespace std;
const int maxn=1e6+10;
struct node{
    int l,r;
    int sum,tag;
}tree[maxn*4];
int n,m,ql,qr,qk,ans,a[maxn];
void up(int t){
    tree[t].sum=tree[lc].sum+tree[rc].sum;
}
void seg_add(int t,int tag){
    tree[t].sum+=tag*(tree[t].r-tree[t].l+1);
    tree[t].tag+=tag;
}
void down(int t){
    if(tree[t].tag){
        seg_add(lc,tree[t].tag);
        seg_add(rc,tree[t].tag);
        tree[t].tag=0;
    }
}
void build(int t,int l,int r){
    tree[t].l=l,tree[t].r=r;
    if(l==r){
        tree[t].sum=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    up(t);
}
void ask(int t){
    if(ql<=tree[t].l&&tree[t].r<=qr){
        ans+=tree[t].sum;
        return;
    }
    down(t);
    int mid = (tree[t].l + tree[t].r) >> 1;
    if(ql<=mid)ask(lc);
    if(qr>mid)ask(rc);
    return;
}
void add(int t){
    if(ql<=tree[t].l&&tree[t].r<=qr){
        seg_add(t,qk);
        return;
    }
    down(t);
    int mid=(tree[t].l+tree[t].r)>>1;
    if(ql<=mid) add(lc);
    if(qr>mid)add(rc);
    up(t);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int pos;
        cin>>pos;
        if(pos==1){
            cin>>ql>>qr>>qk;
            add(1);
        }else{
            cin>>ql>>qr;
            ans=0;
            ask(1);
            cout<<ans<<endl;
        }
    }
}