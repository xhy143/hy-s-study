#include<bits/stdc++.h>
using namespace std;
int n,m,a[10001],cf[100001];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cf[i]=a[i]-a[i-1];
    }
    while(m--){
        int s,e,f;
        cin>>s>>e>>f;
        cf[s]+=f;cf[e+1]-=f;
    }
    for(int i=1;i<=n;i++){
        a[i]=cf[i]+a[i-1];
    }
    sort(a+1,a+n+1);
    cout<<a[1];
}