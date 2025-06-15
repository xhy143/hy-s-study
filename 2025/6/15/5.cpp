#include<bits/stdc++.h>
using namespace std;
int a[10000001];
int ef(int l,int r,int c){
    int mid=l+(r-l)/2;
    if(l>r){
        return -1;
    }else if(a[mid]==c){
        return mid;
    }
    else if(a[mid]>c){
        return ef(mid-1,r,c);
    }else if(a[mid]<c){
        return ef(l,mid+1,c);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int p;
    cin>>p;
    cout<<ef(0,n,p)+1;
}