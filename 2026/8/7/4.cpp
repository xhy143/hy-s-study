#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+10;
vector<int>g[maxn];
int n,m,k,a[maxn],cnt,ans[maxn],fa[maxn];
bool bo[maxn];
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void mirage(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    fa[x]=y;
    cnt--;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>a[i];
        bo[a[i]]=1;
    }
    for(int i=0;i<=n-1;i++){
        fa[i]=i;
    }
    cnt=n-k;
    for(int i=0;i<=n-1;i++){
        if(bo[i])continue;
        for(int j:g[i]){
            if(!bo[j])mirage(i,j);
        }
    }
    for(int i=k;i>=1;i--){
        ans[i]=cnt;
        cnt++;
        int u=a[i];
        bo[u]=0;
        for(auto v:g[u]){
            if(!bo[v])mirage(u,v);
        }
    }
    ans[0]=cnt;
    for(int i=0;i<=k;i++)cout<<ans[i]<<endl;
    return 0;
}