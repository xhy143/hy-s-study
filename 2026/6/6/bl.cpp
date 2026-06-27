#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
const int n=2097152;
int main(){
    freopen("1.in","r",stdin);
    int ans=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        ans+=a;
        cout<<ans<<endl;
    }
}