#include<bits/stdc++.h>
using namespace std;
int n,vis[10001],shu[10001];
void dfs(int depth){
    if(depth==n+1){
        for(int i=1;i<=n;i++){
            cout<<shu[i];
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            shu[depth]=i;
            dfs(depth+1);
            vis[i]--;

        }
    }
}
int main(){
    cin>>n;
    dfs(1);
}