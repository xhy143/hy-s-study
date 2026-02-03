#include<bits/stdc++.h>
using namespace std;
vector<int>a[200001];
int ans1,ans2;
int t[200001];
void dfs(int s,int f,int deep){
    if(deep%2==1) t[s]=1;
    for(auto v:a[s]){
        if(v==f) continue;
        dfs(v,s,deep+1);
    }
}
int main(){
    int n;
    cin>>n;
    
    for(int i=1;i<n;i++){
        int c,b;
        cin>>c>>b;
        a[c].push_back(b);
        a[b].push_back(c);
    }
    dfs(1,0,0);
    ans1=0,ans2=0;
    for(int i=1;i<=n;i+=1){
        if(t[i]==1) ans1++;
        else ans2++;
    }
    for(int i=1;i<=n;i++){
        if(t[i]==0) cout<<ans2<<' ';
        else{
            cout<<ans1<<' ';
        }
    }
}