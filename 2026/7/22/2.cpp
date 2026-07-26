#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+10;
int w[maxn],n,lc[maxn],rc[maxn],root;
stack<int>stk;
void dfs(int u){
    if(u==0) return;
    cout<<u<<' ';
    dfs(lc[u]);
    dfs(rc[u]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int o;
        cin>>o;
        w[o]=i;
    }
    for(int i=1;i<=n;i++){
        int last=0;
        while(!stk.empty()&&w[stk.top()]>w[i]){
            last=stk.top();
            stk.pop();
        }
        if(!stk.empty())rc[stk.top()]=i;
        else root=i;
        if(last!=0) lc[i]=last;
        stk.push(i);
    }
    dfs(root);
    return 0;
}