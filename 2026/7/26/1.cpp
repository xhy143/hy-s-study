#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int w[maxn],n;
stack<int>stk;
long long ans=0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    vector<int> left(n+1), right(n+1);
    for(int i=1;i<=n;i++){
        while(!stk.empty()&&w[stk.top()]>=w[i]) stk.pop();
        left[i]=stk.empty()?0:stk.top();
        stk.push(i);
    }
    while(!stk.empty()) stk.pop();
    for(int i=n;i>=1;i--){
        while(!stk.empty()&&w[stk.top()]>=w[i]) stk.pop();
        right[i]=stk.empty()?n+1:stk.top();
        stk.push(i);
    }
    for(int i=1;i<=n;i++){
        long long area=1ll*w[i]*(right[i]-left[i]-1);
        ans=max(ans,area);
    }
    
    cout<<ans<<'\n';
    return 0;
}