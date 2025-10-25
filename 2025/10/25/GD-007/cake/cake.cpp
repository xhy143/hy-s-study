#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("cake.in","r",stdin);
    freopen("cake.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n%3==0||m%3==0){
        cout<<0;
        return 0;
    }
    else{
        cout<<min(n,m);
    }
}