#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[100001],cf[100001];
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        
        cf[i]=a[i]-a[i-1];
    }
    while(k--){
        int l,r,p;
        cin>>l>>r>>p;
        cf[l]+=p;
        cf[r+1]-=p;
    }
    for(int i=1;i<=n;i++){
        a[i]=a[i-1]+cf[i];
        a[0]=cf[0];
        cout<<a[i]<<' ';
    }
}