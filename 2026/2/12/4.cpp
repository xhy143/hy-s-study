#include<bits/stdc++.h>
#define int long long
#define INF 0x7ffffffffffffff
#define TAT 0
using namespace std;
int d[10001],n,m;
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
    for(int i=1;i<=m;i++){
        int s,e,w;
        cin>>s>>e>>w;
        a.push_back({s,e,w});
    }
    for(int i=1;i<=n;i++){
        a.push_back({0,i,0});
    }
    cout<<(!p(0)?"No":"Yes")<<endl;
    return TAT;
}