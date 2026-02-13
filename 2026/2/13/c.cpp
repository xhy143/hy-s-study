#include<bits/stdc++.h>
#define int long long
#define INF 0x7ffffffffffffff
#define TAT 0
using namespace std;
int d[100001],n,m;
struct node{
    int s,e,w;
};
vector<node>a;
bool p(int s){
    fill(d,d+1+n,INF);
    d[s]=0;
    for(int i=1;i<=n;i++){
        bool flag=0;
        for(int j=0;j<=a.size()-1;j++){
            int s=a[j].s,e=a[j].e,w=a[j].w;
            if(d[s]+w<d[e]){
                d[e]=d[s]+w;
                flag=1;
            }
        }
        if(!flag) break;
        if(i==n&&flag) return true;
    }
    return false;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int p;
        cin>>p;
        a.push_back({0,i,p});
    }
    for(int i=1;i<=m;i++){
        int pos,d,b,c;
        cin>>d>>b>>c;
        a.push_back({d,b,c});
    }
    p(0);
    if(d[n]>=0){
        cout<<d[n];
    }
    return TAT;
}