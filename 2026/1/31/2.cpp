#include<bits/stdc++.h>
using namespace std;
struct node{
    int ls,rs;
}a[1000001];
int m[100001],l[100001];
int idx[100001];
int rebuild(int ms,int es,int len){
    if(len==0) return 0;
    int root=l[es+len-1];
    int rootidx=idx[root];
    a[root].ls=rebuild(ms,es,rootidx-ms);
    a[root].rs=rebuild(rootidx+1,es+rootidx-ms,len-rootidx+ms-1);
    return root;
}
int dfs(int s){
    if(s==0) return 0;
    cout<<(char)s;
    dfs(a[s].ls);
    dfs(a[s].rs);
    return 0;
}
int main(){
    string x,z;
    cin>>x>>z;

    for(int i=0;i<x.length();i++) {
        m[i]=(int)x[i];
        idx[m[i]]=i;
    }
    for(int i=0;i<z.length();i++) l[i]=(int)z[i];
    int root=rebuild(0,0,z.length());
    dfs(root);
}
