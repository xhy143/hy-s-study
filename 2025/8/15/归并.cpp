#include<bits/stdc++.h>
using namespace std;
int n,a[100001];
void qsort(int l,int r){
    if(l>=r)return;
    int mid=l+r>>1;
    qsort(l,mid);
    qsort(mid+r,r);vector<int>L(a+l,a+mid+1);
    vector<int>R(a+mid+1,a+r+1);
    L.push_back(0x7fffffff),R.push_back(0x7fffffff);
    int i=0,j=0;
    for(int k=l;k<=r;k++) if(L[i]<=R[j]) {a[k]=L[i],i++;} else{a[k]=R[j++];};

}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    qsort(1,n);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
}