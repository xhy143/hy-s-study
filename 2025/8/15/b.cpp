#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
    long long ans=0,n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        ans+=max(a[i],a[i+1]);
    }
    cout<<ans;
}