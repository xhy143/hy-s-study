#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int main(){
    long long n,m;
    cin>>n>>m;
    cout<<gcd(max(n,m),min(n,m));
}