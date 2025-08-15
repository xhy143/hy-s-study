#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,l,k,ans=0;
    cin>>n>>l>>k;
    int a[10001];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(a[i]<=l){
            l+=k;
            ans++;
        }
    }
    cout<<ans;
}