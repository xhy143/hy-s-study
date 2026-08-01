#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+10;
string str;
int n,fa[maxn],f[maxn],ans=0;
stack<int>stk;
vector<int>g[maxn];
void dfs(int u,int sum,int top){
    int tmp=0;
    if(str[u-1]=='('){
        stk.push(u);
        f[u]=0;
    }else{
        if(stk.empty()) f[u]=0;
        else{
            tmp=stk.top();
            stk.pop();
            f[u]=f[fa[tmp]]+1;
            sum+=f[u];
        }
    }
    ans^=sum*u;
    for(auto v:g[u]){
        dfs(v,sum,top);
    }
    if(tmp)stk.push(tmp);
    if(!stk.empty()&&str[u-1]=='(')stk.pop();
    return;
}
signed main(){
    cin>>n>>str;
    for(int i=2;i<=n;i++){
        cin>>fa[i];
        g[fa[i]].push_back(i);
    }
    dfs(1,0,0);
    cout<<ans<<endl;
}