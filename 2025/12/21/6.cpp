#include<bits/stdc++.h>
using namespace std;
int main(){
    int R[100001];
    int n,r,a[100001];
    cin>>n>>r;
    R[0]=r;
    for(int i=0;i<n;i++){
        a[i]=R[i]%100+1;
        if(i==0) continue;
        R[i]=(R[i-1]*6807+2831)%20170;
        
    }
    sort(a,a+n);
    int qzh[100001];
    int ans=a[0];
    for(int i=1;i<n;i++){
        qzh[0]=a[0];
        qzh[i]=qzh[i-1]+a[i];
        cout<<qzh[i]<<endl;
        ans+=qzh[i];
    }
    cout<<ans;
}