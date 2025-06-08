#include<bits/stdc++.h>
using namespace std;
int ans=0,n;
int qh(int x){
    if(x>0){
        ans+=x;
        return qh(x-2);
    }
    return ans;
}
int main(){
    cin>>n;
    cout<<qh(n);
}
