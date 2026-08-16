#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int x,y;
};
struct info{
    int d,u,v;
    bool operator<(const info&oth)const{
        return d>oth.d;
    }
};
vector<node>g;
vector<info>l;
signed main(){
    int n;
    freopen("second.in","r",stdin);
    freopen("second.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        g.push_back({x,y});
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x1=g[i].x,y1=g[i].y,x2=g[j].x,y2=g[j].y;
            int dx=x1-x2;
            int dy=y1-y2;
            l.push_back({dx*dx+dy*dy,i,j});
        }
    }
    sort(l.begin(),l.end());
    for(int i=0;i<n;i++){
        vector<int>top;
        for(auto now:l){
            int u=now.u,v=now.v,d=now.d;
            if(u==i||v==i)continue;
            if(top.empty()||d!=top.back()){
                top.push_back(d);   
            }
            if(top.size()>=3)break;
        }
        if(top.size()<=2)cout<<0<<endl;
        else cout<<top[1]<<endl;
    }
}