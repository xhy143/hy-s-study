#include<bits/stdc++.h>
using namespace std;
int choose(int* a,int n){
    for(int j=0;j<n;j++){
        int pos=j;
        for(int i=j;i<n;i++){
            if(a[i]<a[pos]){
                pos=i;
            }
        }
        swap(a[j],a[pos]);
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
    choose(a,n);
    return 0;
}