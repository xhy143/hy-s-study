#include<bits/stdc++.h>
using namespace std;
int n,a[1001],b[1001],x,k;
void dy(){
    for(int i=0;i<n;i++){
        a[i]=b[i];
    }
}
int main(){
    
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++){
        a[i]=i;
        b[i]=i;
    }
    while(k--){
        int m=n/2;
        int c[1001],d[1001];
        int j=1;
        for(int i=1;i<=m;i++){
            c[j]=a[i];
            j+=2;
        }
        j=2;
        for(int i=m+1;i<=n;i++){
            d[j]=a[i];
            j+=2;
        }
        for(int i=1;i<n;i++){
            b[i]=(i%2==0?d[i]:c[i]);
        }
        dy();
    }
    cout<<a[x];
}