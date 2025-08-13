#include<bits/stdc++.h>
using namespace std;
int mpp(int* a,int n){
    for(int i=0;i<n;i++){
        bool flag=1;
        for(int j=0;j<=n;j++){
            if(a[i]<a[j]){
                int k=a[i];
                a[i]=a[j];
                a[j]=k;
                flag=false;
            }
        }
        if(flag) break;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
}
int main(){
    int n,a[10001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mpp(a,n);
}