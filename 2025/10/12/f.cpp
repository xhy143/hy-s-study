#include<bits/stdc++.h>
using namespace std;
struct node{
    int xh,cj;
    string name;
}a[10001];
bool cmp(node b,node c){
   return (b.cj==c.cj)?(b.xh<c.xh):(b.cj>c.cj);
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].xh>>a[i].name>>a[i].cj;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        cout<<a[i].xh<<' '<<a[i].name<<' '<<a[i].cj<<endl;
    }
}