#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int a[100001],b[100001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    int j=0;
    for(int i=0;i<n;i++){
        if(a[i]<b[j]){
            continue;
        }else{
            j++;
            continue;
        }
    }
    cout<<j;
}