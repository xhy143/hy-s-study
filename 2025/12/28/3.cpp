#include<bits/stdc++.h>
using namespace std;
long long a[1000001],qzh[1000001];
int main(){
    long long n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        qzh[i]=qzh[i-1]+a[i];
    }
   long long ans=-INT_MAX;
    for(int i=k;i<=n;i++){
        long long q=qzh[i]-qzh[i-k];
        ans=max(ans,q);
    }
    cout<<qzh[n]-ans;
    return 0;
}