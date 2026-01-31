#include<bits/stdc++.h>
using namespace std;
vector<int>t[100001];
int siz[100001];
int n,ansi=-1;
int dfs(int s,int fa){ 
    siz[s]=1;
    int maxs=-0x3f3f3f;
    for(auto v:t[s]){
        if(v==fa) continue;
        dfs(v,s);
        siz[s]+=siz[v];
        maxs=max(maxs,siz[v]);
    }
    maxs=max(maxs,n-siz[s]);
    if(maxs<=n/2) if(ansi==-1||ansi>s) ansi=s;
    return 0;
}
int ans=0;
void dffs(int s,int f,int deep){
    ans+=deep;
    for(auto v:t[s]){
        if(v==f) continue;
        dffs(v,s,deep+1);
    }
    
}
int main(){
    
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        t[x].push_back(y);
        t[y].push_back(x);
    }
    dfs(1,0);
    dffs(ansi,0,0);
    cout<<ans;
}