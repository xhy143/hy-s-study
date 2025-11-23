#include<bits/stdc++.h>
using namespace std;
int a[100001];
int left(int l,int r,int tar){
    while(l<r){
        int mid=(r-l)/2+l;
        if(a[mid]<tar){
            l=mid+1;
        }
        if(a[mid]>=tar){
            r=mid;
        }
    }
    return l;
}
int right(int l,int r,int tar){
    while(l<r){
        int mid=(r-l)/2+l;
        if(a[mid]<=tar){
            l=mid+1;
        }
        if(a[mid]>tar){
            r=mid;
        }
    }
    return l-1;
}
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        //asdf;kjasdfl;kjasdfl;kjadfl;kjasdfl;kjasdf;lkjasdfl;kjadsfsl;kjasdfjkl;asdflk;jdasflkjdsfjksdf
        int l=left(0,n,x),r=right(0,n,x);
        if(l<0||l>n-1||a[l]!=x){
            l=-1;r=-1;
        }
        cout<<l<<' '<<r<<endl;
    }
}