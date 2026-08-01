#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+10;
int w[maxn],n,lc[maxn],rc[maxn];
stack<int>stk;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    vector<int>r(n+1),l(n+1);
    for(int i=1;i<=n;i++){
        while(!stk.empty()&&w[stk.top()]>=w[i]){
            stk.pop();
        }
        l[i]=(stk.empty()?0:stk.top());
        stk.push(i);
    }
    while(!stk.empty())stk.pop();
    for(int i=n;i>=1;i--){
        while(!stk.empty()&&w[stk.top()]>=w[i]){
            stk.pop();
        }
        r[i]=(stk.empty()?n+1:stk.top());
        stk.push(i);
    }
    long long ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
        long long s=1LL*w[i]*(r[i]-l[i]-1);
        ans1=max(ans1,s);
    }
    cout<<ans1<<'\n';
    return 0;
}