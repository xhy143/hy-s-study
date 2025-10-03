#include<bits/stdc++.h>
using namespace std;
void in(long long* a,int n){
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}
long long v[10001],pri[100001];
int main(){
    long long n,d;
    cin>>n>>d;
    in(v,n);
    in(pri,n);
    int ans=0;
    pri[n]=0;
    for(int i=0;i<n;i++){
        v[i]=v[i]+v[i-1];
    }
    long long zz=0,qzz=0;
    while(zz!=n){
            
    }
}