#include<bits/stdc++.h>
using namespace std;
vector<int>a[100001];
int dfs(int d,int deep){
    if(a[d].empty()) return deep;
    int ans=-0x3f3f3f;
    for(auto p:a[d]){
        ans=max(ans,dfs(p,deep+1));
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[x].push_back(i);
    }
    cout<<dfs(1,1);
    return 0;
}