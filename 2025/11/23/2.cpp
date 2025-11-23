#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){

    return a>b;
}
int main(){
    int n,a[10001];
    cin>>n;
    int k;
    cin>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int maxans=-0x3f3f3f;
    for(int i=0;i<n;i++){
        int ans=0;
        for(int j=i;j<n;j++){
            if(a[j]-a[i]>k){
                break;
            }
            ans+=a[j];
        }
        maxans=max(ans,maxans);
    }
    cout<<maxans;
}