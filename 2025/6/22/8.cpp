#include<bits/stdc++.h>
using namespace std;
bool find(int n,int ans){
    while(n>=1){
        ans+=n%10;
        n/=10;
    }
    if(ans==20){
        return 0;
    }
    else if(ans!=20){
        return 1;
    }
    return 1;
}
int main(){
    int n,ans=0;
    cin>>n;
    n++;
    while(find(n,0)){
        n++;
    }
    cout<<n;
}