#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,l,r;
    freopen("rectangle.in","r",stdin);
    freopen("rectangle.out","w",stdout);
    cin>>n>>l>>r;
    for(int i=1;i<=n/2;i++){
        long long s=i*(n-i);
        if(s>r){
            cout<<-1;
            return 0;
        }
        if(s>=l){
            cout<<i<<' '<<n-i;
            return 0;
        }
    }
}