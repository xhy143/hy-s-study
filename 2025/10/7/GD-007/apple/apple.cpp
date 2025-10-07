#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int ans1=0,ans2=0,n;
    cin>>n;
    while(n){
        ans1++;
        if(!ans2&&n%3==1) ans2=ans1;
        n=n-ceil(n/3.0);
    }
    cout<<ans1<<' '<<ans2;
}