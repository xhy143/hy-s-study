#include<bits/stdc++.h>
using namespace std;
int s[10001],vis[10001];
void dfs(int n,int step){
    if(step>n){
        for(int i=1;i<=n;i++){

            cout<<s[i]<<' ';
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            s[step]=i;
            vis[i]=1;
            dfs(n,step+1);
            vis[i]=0;
        }
    }
}
int main(){
    int n;
    cin>>n;
    dfs(n,1);
    return 0;
}