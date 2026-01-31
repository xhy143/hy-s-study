#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[100001],v[1000001];
vector<int>son[100001];
long long mins(int s){
    if(son[s].empty()) return INT_MAX;
    int ans=0;
    for(auto p:son[s]){
        ans+=dp[p];
    }
    return ans;
}
signed main(){
    int n;
    cin>>n;
    memset(v,0x3f,sizeof(v));
    for(int i=2;i<=n;i++){
        int p;
        cin>>p;
        son[p].push_back(i);
    }
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=n;i>=1;i--){
        dp[i]=min(v[i],mins(i));
    }
    cout<<dp[1];
    return 0;
}