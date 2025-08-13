#include<bits/stdc++.h>
using namespace std;
int insert(int* a,int n){
    for(int i=1;i<n;i++){
        int k=a[i];
        int j=i-1;
        while(j>=0 && k<a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=k;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}
int main(){
    int n,a[10001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    insert(a,n);
    return 0;
}