#include<iostream>
using namespace std;
int main(){
    int ans=1,n;
    cin>>n;
    for(int i=2;i<=n;i++){
        ans+=i*i*i;
    }
    cout<<ans;
}