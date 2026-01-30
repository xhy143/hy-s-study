#include<bits/stdc++.h>
using namespace std;
vector<int>t[100001];
int f[100001],deep[100001];
int dfs(int d,int fa,int dep){
    f[d]=fa;
    deep[d]=dep;
    for(auto v:t[d]){
        if(v==fa) continue;
        dfs(v,d,dep+1);
    }
    return 0;
}
int z(int x,int y){
    while(deep[x]<deep[y]) y=f[y];
    while(deep[y]<deep[x]) x=f[x];
    while(x!=y){
        x=f[x];
        y=f[y];
    }
    cout<<x<<endl;
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
    dfs(1,0,1);
    int T;
    cin>>T;
    while(T--){
        int x,y;
        cin>>x>>y;
        z(x,y);
    }
}