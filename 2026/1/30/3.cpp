#include<bits/stdc++.h>
using namespace std;
vector<int>t[100001];
int cz[1000001],siz[1000001];
int dfs(int d,int fa){
    siz[d]=1;
    for(auto v:t[d]){
        if(v==fa) continue;
        dfs(v,d);
        siz[d]+=siz[v];
        if(cz[d]==0||siz[v]>siz[cz[d]]){
            cz[d]=v;
        }else if(siz[v]==siz[cz[d]]){
            cz[d]=min(v,cz[d]);
        }
    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        t[x].push_back(y);
        t[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        cout<<cz[i]<<' ';
    }
}