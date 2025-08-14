#include<bits/stdc++.h>
using namespace std;
int n,s[10001],sr[10001],vis[10001],k;
int sum=0;
void dfs(int step,int j,int qs){
    if(step>=qs){
        int ans=0;
        for(int i=0;i<qs;i++){
            ans+=s[i];
        }
        if(ans==k){
            sum++;
        }
        return;     
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0&&sr[i]>s[step-1]){
            s[step]=sr[i];
            vis[i]=1;
            dfs(step+1,i,qs);
            vis[i]=0;
        }
    }
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>sr[i];
    }
    sort(sr,sr+n);
    for(int i=1;i<=n;i++){
        dfs(0,0,i);
    }
    
    cout<<sum;
    return 0;
}