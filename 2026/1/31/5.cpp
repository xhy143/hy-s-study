#include<bits/stdc++.h>
using namespace std;
vector<int>a[1000001];
int ans1,ans2;
int dep=-1;
bool t[1000001]={0};
void dfs(int s,int f,int deep){
    if(deep%2==1) t[s]=1;
    dep=max(deep,dep);
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
    ans1=0;
    for(int i=1;i<=n;i+=2){
        if(t[i]==1) ans1++;
    }
    for(int i=0;i<=n;i+=2){
        if(t[i]==0) ans2++;
    }
    for(int i=1;i<=n;i++){
        if(t[i]==0) cout<<ans2<<' ';
        else{
            cout<<ans1<<' ';
        }
    }
}