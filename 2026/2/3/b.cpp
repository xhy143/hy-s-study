#include<bits/stdc++.h>
using namespace std;
struct node{
    int ls,rs;
}a[1000001];
int m[100001],l[100001];
int idx[100001];
int rebuild(int ms,int es,int len){
    if(len<=0) return 0;
    int root=l[es];
    int rootidx=idx[root];
    int l1=rootidx-ms;
    int l2=len-l1-1;
    a[root].ls=rebuild(ms,es+1,l1);
    a[root].rs=rebuild(rootidx+1,es+l1+1,l2);
    return root;
}
int dfs(int s){
    if(s==0) return 0;

    dfs(a[s].ls);
    dfs(a[s].rs);
    cout<<s<<' ';
    return 0;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>m[i];
        idx[m[i]]=i;
    }
    for(int i=0;i<n;i++) {
        cin>>l[i];
    }
    int root=rebuild(0,0,n);
    dfs(root);
}
