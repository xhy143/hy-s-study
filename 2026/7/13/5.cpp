#include<bits/stdc++.h>
using namespace std;
int main(){
    double a[1001];
    for(int i=0;i<10;i++){
        cin>>a[i];
    }
    sort(a,a+10);
    double ans=0;
    for(int i=1;i<9;i++){
        ans+=a[i];
    }
    ans/=8.0;
    cout<<ans;
}