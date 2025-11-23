#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,a[10001],ans=0;
    cin>>n;
    int q[10001];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q[i]=a[i]+q[i-1];
    }
    for(int i=1;i<=n;i++){
        if(q[i]==q[n]-q[i]){
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
}