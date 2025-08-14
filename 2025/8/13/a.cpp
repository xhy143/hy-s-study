#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
    cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
            a[i]+=a[i-1];
        
    }
    for(int i=0;i<q;i++){
        int e,r;
        cin>>e>>r;
        cout<<a[r]-a[e-1]<<"\n";
    }
    return 0;
}