#include<bits/stdc++.h>
using namespace std;
struct node{
    int f,s;
}a[1000001];
int n;
int find(int u){
    if (a[u].f != u) {
        a[u].f = find(a[u].f);
    }
    return a[u].f;
}
int finds(int u){
    if (a[u].f != u) {
        a[u].f = find(a[u].f);
    }
    return a[a[u].f].s;
}
void hb(int x){
    int y=x+1;
    x=find(x),y=find(y);
    a[x].f=y;
    a[y].s+=a[x].s;
}
void fl(int x){
    int y=x+1;
    if(y>=n) return;
    a[y].f=y;
    a[x].s-=a[y].s;
}
int main(){
    int T;
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>T;
    for(int i=0;i<n;i++){
        a[i].f=i;
        a[i].s=0;
    }
    while(T--){
        int pos,u;
        cin>>pos>>u;
        switch(pos){
            case 1:
                hb(u);
                break;
            case 2:
                fl(u);
                break;
            case 3:
                a[u].s++;
                a[find(u)].s++;
                break;
            case 4:
                cout<<finds(u)<<endl;
                break;
        }
    }
}