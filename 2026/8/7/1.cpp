#include<bits/stdc++.h>
using namespace std;
#define int long long
bool oke(int a,int b,int c,int x,int y,int z,int r){
    int d=(a-x)*(a-x)+(b-y)*(b-y)+(c-z)*(c-z);
    return d<=(4*r*r);
}
int fa[1001];
vector<int>f1,f2;
struct node{
    int x,y,z,pos;
};
vector<node>g;
void init(){
    f1.clear();f2.clear();
    g.clear();
    for(int i=0;i<=1000;i++){
        fa[i]=i;
    } 
}
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void hb(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return;
    fa[x]=y;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,h,r;
        init();
        cin>>n>>h>>r;
        for(int i=1;i<=n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            g.push_back({x,y,z,i});
            if(z<=r)f1.push_back(i);
            if(h-z<=r)f2.push_back(i);
        }
        for(auto v:g){
            for(auto u:g){
                int a=v.x,b=v.y,c=v.z,pos=v.pos,x=u.x,y=u.y,z=u.z,i=u.pos;
                if(oke(x,y,z,a,b,c,r)){
                    hb(i,pos);
                }
            }
        }
        bool flag=0;
        for(auto i:f1){
            for(auto j:f2){
                if(find(i)==find(j)){
                    cout<<"Yes"<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag)break;
        }
        if(!flag)cout<<"No"<<endl;
    }
}