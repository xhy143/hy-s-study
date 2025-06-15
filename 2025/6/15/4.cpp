#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int sl[10000001],sl2[10000001];
int ef(int l,int r,int zs){
    int mid=l+(r-l)/2;
    if(l>r){
        return -1;
    }
    else if(sl[mid]==zs){
        int pos= ef(l,mid-1,zs);
        if(pos!=-1){
            return pos;
        }
        return mid;
    }
    else if(sl[mid]<zs){
        return ef(mid+1,r,zs);
    }
    else if(sl[mid]>zs){
        return ef(l,mid-1,zs);
    }
    return -1;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&sl[i]);
    }
    int p;
    scanf("%d",&p);
    for(int i=0;i<p;i++){
        scanf("%d",&sl2[i]);
    }
    for(int i=0;i<p;i++){
        int k=ef(0,n-1,sl2[i]);
        if(k==-1){
            cout<<-1<<' ';
            continue;
        }
        printf("%d ",k+1);
    }
}
