#include<bits/stdc++.h>
using namespace std;
vector<int>t[1000001];
map<int,int>s;
int dfs(int u,int f){
    s[u]=0;
    for(auto v:t[u]){
        if(v==f) continue;
        s[u]++;
        dfs(v,u);
    }
    return s[u];
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
    int ans=0;
    for(auto v:s){
        if(v.second>1){
            ans+=1;
        }
    }
    cout<<ans;
}