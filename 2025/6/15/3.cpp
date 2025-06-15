#include<bits/stdc++.h>
using namespace std;
int sl[10000001];
int ef(int c,int l,int r,int mid){
    mid=l+(r-l)/2;
    if(l>r){
        return -1;
    }
    else if(sl[mid]==c){
        return mid;
    }
    else if(sl[mid]<c){
        return ef(c,mid+1,r,0);
    }
    else if(sl[mid]>c){
        return ef(c,l,mid-1,0);
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>sl[i];
    }
    int c;
    cin>>c;
    cout<<ef(c,1,n,0);
}