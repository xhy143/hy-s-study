#include<bits/stdc++.h>
using namespace std;
int jc(int n){
    int ans=1;
    for(int i=2;i<=n;i++){
        ans*=i;
    }
    return ans;
}
int main(){
    int k,ans=0;
    cin>>k;
    for(int i=1;i<=k;i++){
        ans+=jc(i);
    }
    cout<<ans;
}