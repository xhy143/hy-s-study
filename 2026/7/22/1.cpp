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
    for(int i=1;i<=n;i++){
        int last=0;
        while(!stk.empty()&&w[stk.top()]>w[i]){
            last=stk.top();
            stk.pop();
        }
        if(!stk.empty())rc[stk.top()]=i;
        if(last!=0) lc[i]=last;
        stk.push(i);
    }
    long long ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
        ans1^=1ll*i*(lc[i]+1);
        ans2^=1ll*i*(rc[i]+1);
    }
    cout<<ans1<<' '<<ans2<<'\n';
}