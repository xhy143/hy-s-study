#include<bits/stdc++.h>
using namespace std;
long long ans=1,n;
long long f(int x){
    if(x>1){
        ans*=x;
        return f(x-1);
    }
    return ans;
}
int main(){
    cin>>n;
    cout<<f(n);
}