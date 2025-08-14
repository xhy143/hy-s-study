#include<bits/stdc++.h>
using namespace std;
int a[1000001],b[10000001];
int main(){
    cin.tie(0),cout.tie(0);
        int t,n;
        cin>>t>>n;
        for(int i=1;i<=n;i++){
            int l,r;
            cin>>l>>r;
            a[l]++;
            a[r+1]--;
        }
        for(int i=1;i<=t;i++){
            a[i]=a[i]+a[i-1];
            
            cout<<a[i]<<endl;
        }
        return 0;
}