#include<bits/stdc++.h>
using namespace std;
vector<int>t[100001];
int ans[100001];
int dfs(int p){
    if(t[p].empty()){
        ans[p]=1;
        return 1;
    }
    ans[p]=1;
    for(auto v:t[p]){
        ans[p]+=dfs(v);
    }
    return ans[p];
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int p;
        cin>>p;
        t[p].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
}