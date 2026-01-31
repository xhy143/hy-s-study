#include<bits/stdc++.h>
using namespace std;
vector<int>t[100001];
int maxd=-0x3f3f3f,maxi=0;
int dfs(int s,int dep,int fa){
    maxd=max(dep,maxd);
    maxi=(maxd==dep?s:maxi);
    for(auto v:t[s]){
        if(v==fa) continue;
        
        dfs(v,dep+1,s);
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
    dfs(1,0,0);
    maxd=-114514;
    dfs(maxi,0,0);
    cout<<maxd;
}