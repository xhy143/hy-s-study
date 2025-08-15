#include<bits/stdc++.h>
using namespace std;
struct jm{
    int yy;
    int hx;
}a[100001];
bool cmp(jm a,jm b){
    return a.hx<b.hx;
}
int main(){
    int n,s,ans=0;
    cin>>n>>s;
    for(int i=0;i<n;i++){
            cin>>a[i].yy>>a[i].hx;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        if(s>a[i].hx){
            s+=(a[i].hx+a[i].yy);
            ans++;
        }
    }
    cout<<ans;
}