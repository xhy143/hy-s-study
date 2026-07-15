#include<bits/stdc++.h>
using namespace std;
int a[1000001],b[1000001],n;
int lowerbit(int x){return (x&(-x));}
void add(int x,int v){
    while(x<=n){
        b[x]^=v;
        x+=lowerbit(x);
    }
}
int find(int x){
    int sum=0;
    while(x>0){
        sum^=b[x];
        x-=lowerbit(x);
    }
    return sum;
}
void _add(int l, int r) {
    add(l, 1);
    add(r + 1, 1);
}
signed main(){
    int q;
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>q;
    while(q--){
        int pos,l,r;
        cin>>pos;
        if(pos==1){
            cin>>l>>r;
            _add(l,r);
        }
        else if(pos==2){
            cin>>l;
            cout<<find(l)<<'\n';
        }
    }
}