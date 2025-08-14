#include<bits/stdc++.h>
using namespace std;
long long n,a[100001],b[100001];
int main(){
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]+a[i];
    }
    int l,r;
    cin>>l>>r;
    for(int i=1;i<=n;i++){
        if(b[i-1]>=l && b[i-1]<=r   &&   b[n]-b[i-1]>=l && b[n]-b[i-1]<=r){
            cout<<i;
            return 0;
        }
    }
    cout<<0; 
    return 0;   
}