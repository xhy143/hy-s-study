#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000001],b[1000001],n;
int lowerbit(int x){return (x&(-x));}
void add(int x,int v){
    while(x<=n){
        b[x]+=v;
        x+=lowerbit(x);
    }
}
int find(int x){
    int sum=0;
    while(x>0){
        sum+=b[x];
        x-=lowerbit(x);
    }
    return sum;
}
void _add(int l, int r, int x) {
    add(l, x);
    add(r + 1, -x);
}
signed main(){
    int q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>a[i];
        add(i+1,a[i]-a[i-1]);
    }
    while(q--){
        int pos,x,y;
        cin>>pos;
        if(pos==1){
            int l,y,v;
            cin>>l>>y>>v;
            _add(l,y,v);
        }
        else if(pos==2){
            cin>>y;
            cout<<find(y)<<endl;
        }
    }
}