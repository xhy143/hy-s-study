#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int ans=1;
    for(int i=0;i<n;i++){
        if(a[i]>=ans){
            ans++;
        }
    }
    cout<<ans-1;
}