#include<bits/stdc++.h>
using namespace std;
int n,a[100001];
void qsort(int l,int r){
    if(l>=r){
        return ;
    }
    swap(a[l],a[(l+r)/2]);
    int p=a[l];
    int i=l,j=r;
    while(i<j){
        while(i<j&&a[j]>=p)j--;
        while(i<j&&a[i]<=p)i++;
        swap(a[i],a[j]);
    }
    swap(a[i],a[l]);
    qsort(l,i-1);
    qsort(i+1,r);
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