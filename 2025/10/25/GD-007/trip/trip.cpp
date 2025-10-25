#include<bits/stdc++.h>
using namespace std;
int a[1000001];
bool tmp(int a,int b){
    return a>b;
}
int main(){
    freopen("trip.in","r",stdin);
    freopen("trip.out","w",stdout);
    int m,n,t,ans=0;
    cin>>m>>n>>t;
    for(int i=0;i<t;i++){
        cin>>a[i];
    }
    int alice=0;
    sort(a,a+t,tmp);
    for(int i=0;i<t;i++){
        if(alice<n){
            alice+=(a[i]-n+alice);
        }else{
            alice=a[i]+n;
        }
        ans++;
        if(alice>m){
            break;
        }
    }
    cout<<alice<<endl;
    if(alice>m){
        cout<<ans;
    }else{
        cout<<0;
    }
}