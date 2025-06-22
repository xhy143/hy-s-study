#include<bits/stdc++.h>
using namespace std;
int find(int n){
    int ans=0;
    while(n>=1){
        ans+=n%10;
        n/=10;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    for(int i=10;i<=n;i++){
        if(i%find(i)==0){
            cout<<i<<endl;
        }
    }
}