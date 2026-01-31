#include<bits/stdc++.h>
using namespace std;
struct node{
    int ls,rs;
}a[1000001];
int vis[1000001];
void dfs(int s,int deep){
    if(s==0)return ;
    if(vis[deep]==0) {
        cout<<s<<endl;
        vis[deep]=1;
    }
    dfs(a[s].rs,deep+1);
    dfs(a[s].ls,deep+1);
}
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].ls>>a[i].rs;
    }
    dfs(1,1);
}